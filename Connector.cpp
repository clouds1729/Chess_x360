#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <iostream>
#include <string>
#include <cstdio>   // For FILE, popen, pclose
#include <cstring>  // For memset
#include <unistd.h> // For read, write
#include <fcntl.h>  // For pipe, fcntl
#include <sys/wait.h> // For waitpid

// Define sleep function for cross-platform compatibility
#ifdef _WIN32
#include <windows.h>
#define Sleep(x) Sleep(x)
#else
#include <unistd.h>
#define Sleep(x) usleep(x * 1000)
#endif

// Define HANDLE and other Windows-specific types
#ifdef _WIN32
typedef HANDLE PIPE_HANDLE;
#else
typedef int PIPE_HANDLE; // Placeholder for non-Windows systems
#define INVALID_HANDLE_VALUE (-1)
#endif

// Define STARTUPINFO structure for Windows (used only on Windows)
#ifdef _WIN32
STARTUPINFO sti = {0};
#endif

// Define PROCESS_INFORMATION structure for Windows (used only on Windows)
#ifdef _WIN32
PROCESS_INFORMATION pi = {0};
#endif

PIPE_HANDLE pipin_w, pipin_r, pipout_w, pipout_r;
char buffer[2048];
DWORD writ, excode, read_size, available;

void ConnectToEngine(const char* path)
{
    pipin_w = pipin_r = pipout_w = pipout_r = INVALID_HANDLE_VALUE;

#ifdef _WIN32
    SECURITY_ATTRIBUTES sats = {0};
    sats.nLength = sizeof(sats);
    sats.bInheritHandle = TRUE;
    sats.lpSecurityDescriptor = NULL;

    CreatePipe(&pipout_r, &pipout_w, &sats, 0);
    CreatePipe(&pipin_r, &pipin_w, &sats, 0);

    sti.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    sti.wShowWindow = SW_HIDE;
    sti.hStdInput = pipin_r;
    sti.hStdOutput = pipout_w;
    sti.hStdError = pipout_w;

    CreateProcess(NULL, (LPSTR)path, NULL, NULL, TRUE, 0, NULL, NULL, &sti, &pi);
#else
    // Non-Windows implementation (using popen for process creation)
    FILE* pout = popen(path, "r");
    pipout_r = fileno(pout);
    pipout_w = pipout_r;
    pipin_r = pipout_r;
    pipin_w = pipout_w;
#endif
}

std::string getNextMove(std::string position)
{
    std::string str;
    position = "position startpos moves " + position + "\ngo\n";

    write(pipin_w, position.c_str(), position.length());
    Sleep(500);

    available = 0;
    ioctl(pipout_r, FIONREAD, &available);

    do
    {
        memset(buffer, 0, sizeof(buffer));
        read_size = read(pipout_r, buffer, sizeof(buffer));
        if (read_size <= 0)
            break;
        str += buffer;
    } while (read_size >= sizeof(buffer));

    int n = str.find("bestmove");
    if (n != -1)
        return str.substr(n + 9, 4);

    return "error";
}

void CloseConnection()
{
    write(pipin_w, "quit\n", 5);
#ifdef _WIN32
    if (pipin_w != INVALID_HANDLE_VALUE)
        CloseHandle(pipin_w);
    if (pipin_r != INVALID_HANDLE_VALUE)
        CloseHandle(pipin_r);
    if (pipout_w != INVALID_HANDLE_VALUE)
        CloseHandle(pipout_w);
    if (pipout_r != INVALID_HANDLE_VALUE)
        CloseHandle(pipout_r);
    if (pi.hProcess != NULL)
        CloseHandle(pi.hProcess);
    if (pi.hThread != NULL)
        CloseHandle(pi.hThread);
#else
    // Non-Windows implementation
    if (pipin_w != INVALID_HANDLE_VALUE)
        close(pipin_w);
    if (pipin_r != INVALID_HANDLE_VALUE)
        close(pipin_r);
    if (pipout_w != INVALID_HANDLE_VALUE)
        close(pipout_w);
    if (pipout_r != INVALID_HANDLE_VALUE)
        close(pipout_r);
#endif
}

#endif // CONNECTOR_H