# CLI-Notes

A fast, lightweight command-line note-taking tool written in C.

![Version](https://img.shields.io/badge/version-0.0.1-yellow)
![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/status-early_development-orange)

## Overview
CLI-Notes is a minimalistic tool designed to save, manage, and retrieve your notes without ever leaving the terminal. Because it is written in C, it is incredibly lightweight and fast.

## Features
- **Instant Creation:** Create new notes in seconds.
- **Quick Retrieval:** Open and read notes directly in your terminal.
- **Inline Editing:** Update the contents of existing notes.
- **Easy Deletion:** Remove notes you no longer need.

## Installation

### Prerequisites
To build this project from source, you will need a C compiler installed (such as `gcc` or `clang`).

### Build from Source
1. Clone the repository:
   ```bash
   git clone https://github.com/YOUR_USERNAME/CLI-Notes.git
   ```
2. Navigate to the project directory:
   ```bash
   cd CLI-Notes
   ```
3. Compile the code:
   ```bash
   gcc main.c -o cli-notes
   ```
   *(Note: Replace `main.c` with your actual `.c` filename if different).*

### Windows Users
If you are on Windows, you can either use `gcc` via MinGW/MSYS2, or download the pre-compiled `.exe` file from the latest [Releases](https://github.com/Pacsfury/CLI-Notes/releases) page.

## Usage

> **Note:** Replace `cli-notes` with `./cli-notes` (Linux/macOS) or `cli-notes.exe` (Windows) depending on your system.

### Create a new note
Creates a new note with the specified title.
```bash
cli-notes new --title "yournotename"
```

### Open a note
Prints the title and content of an existing note to the terminal.
```bash
cli-notes open --title "yournotename"
```

### Edit a note
Updates the content of an existing note.
```bash
cli-notes edit --title "notetitle" --cont "your new note content"
```

### Delete a note
Permanently deletes a note.
```bash
cli-notes delete --title "yournotename"
```

### List all notes
Shows the title of all the notes.
```bash
cli-notes list
```

## Roadmap
This project is currently in early development. Upcoming features include:
- [x] `list` command to view all saved notes
- [ ] Search functionality
- [ ] Configuration file for custom storage paths

## Contributing
Contributions, issues, and feature requests are welcome! Feel free to check out the [issues page](https://github.com/Pacsfury/CLI-Notes/issues).

## License
This project is licensed under the MIT License - see the `LICENSE` file for details.
