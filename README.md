# Treasure Venture

*Treasure Venture* is a PC text adventure game. Written in the C programming language, it's available in two versions: CLI and GUI. "CLI" stands for "Command-Line Interface", and is the version which runs in the terminal, whereas "GUI" stands for "Graphics User Interface" and this version opens a window. The GUI is made with GTK4, a C library.  

Note that the GUI version can only be compiled for Unix-based systems, while the CLI version is cross-platform. GTK may be a cross-platform library, developing the GUI for Windows is not a straight-forward process, and it's not my priority at this time. Also, as I don't own a Mac, I cannot confirm whether the GUI works on MacOS, but once again GTK is meant to work on Mac as well.  

---

A text adventure game is a game that is interacted with through written commands, and which only displays written text. There is no graphical element.  

This project differs from a classic text adventure in that *Treasure Venture* offers suggestions when the player is lost. Since this reveals the plot, it's usually considered as spoiling the player's enjoyment. Even so, I've allowed myself to make the handling of the game more accessible.  

*Treasure Venture* understands several commands, can save the ongoing game, and has events. An example of event is to have the doors lock up behind the player when they cross the mansion's threshold for the first time. It also contains a mini-game entitled "[Twenty Squares](https://github.com/TheLycorisRadiata/c_game_twentysquares)", that I leave you to discover as well as the game itself.  

