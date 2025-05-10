# My_Top

A custom implementation of the Linux `top` command, displaying real-time system statistics and process information.

![image](https://github.com/user-attachments/assets/dd2ab3c1-23d5-49b7-9e5c-28a12098c658)

## Description

`my_top` is a system monitoring tool that provides a dynamic real-time view of system performance. It shows:

- System uptime and load averages
- Task statistics (total, running, sleeping, stopped, zombie)
- CPU usage statistics
- Memory and swap usage
- Process list with detailed information:
  - PID (Process ID)
  - USER (Process Owner)
  - PR (Priority)
  - NI (Nice value)
  - VIRT (Virtual Memory)
  - RES (Physical Memory)
  - SHR (Shared Memory)
  - S (Process Status)

## Features

- Real-time system monitoring
- Process information display
- Memory usage statistics
- CPU performance metrics
- Interactive interface using ncurses
- Auto-refresh every 2 seconds

## Building the Project

```sh
make        # Build the project
make clean  # Clean object files
make fclean # Clean everything
make re     # Rebuild the project
```

## Usage

```sh
./my_top
```

### Controls

- `q` - Quit the program

## Requirements

- GCC compiler
- Make build system
- NCurses library
- Linux operating system

## Technical Implementation

- Written in C
- Uses NCurses for terminal interface
- Reads system information from proc filesystem
- Implements linked lists for data management
- Memory-leak free implementation
- Error handling for system calls
