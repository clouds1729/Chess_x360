## Chess_x360

### Building the Game of Kings... with Google Drive and C++

Drive Chess is an innovative project that combines the power of the Google Drive Realtime API for an online multiplayer experience with a robust offline version built in C++. This project showcases the potential of using diverse technologies for game development.

### Features

#### Online Version
- **User Authentication**: Built-in user authentication via Google Drive.
- **Easy Invitations**: Friends can join the game by sharing the Drive file.
- **User-Owned Data**: Players own their game data, stored securely on their Drive accounts.
- **Conflict Resolution**: Google Drive handles conflicting actions between players seamlessly.
- **Real-Time Multiplayer**: Allows multiple players to move pieces around a shared chess board in real-time.

#### Offline Version
- **Standalone Application**: Built using C++ and SFML for a rich graphical experience.
- **Local Gameplay**: Play against another player locally on the same machine.
- **Basic Movement**: Move pieces around the chess board with basic validation.
- **No Internet Required**: Enjoy the game offline without needing an internet connection.

### Getting Started

#### Online Version

To start playing the online version, refer to the detailed [README](online/README.md) in the `online` folder.

#### Offline Version

To start playing the offline version, refer to the detailed [README](offline/README.md) in the `offline` folder.

### Installation

#### Dependencies

- **C++ Compiler**: Ensure you have a C++ compiler installed.
- **CMake**: Used for building the project.
- **SFML**: Simple and Fast Multimedia Library for the offline version.

#### Installing SFML on Windows

1. **Download SFML**: Download the latest version of SFML from [SFML's official website](https://www.sfml-dev.org/download.php).
2. **Extract and Set Up**: Extract the downloaded files and set up the environment variables as per SFML's setup guide.

### Hosting and Storage

Combining Google Drive and GitHub provides a seamless experience for the online version, hosting the entire game for free and ensuring player data is securely stored on their own Drive accounts.

### Future Potential

Drive Chess is a proof of concept showcasing the potential for multiplayer turn-based games using Google Drive. The offline version highlights the flexibility of the project by providing a robust standalone application.

### What's Next?

---

Hopefully this example inspires you to leverage both online and offline technologies for your own multiplayer game projects. Enjoy playing Drive Chess and happy coding!

---

