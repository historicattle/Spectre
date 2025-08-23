# Spectre

## Overview

Spectre is a terminal-based system monitoring and debugging tool for comprehensive process analysis, currently under active development.

## Current Development Status

The project is in early development phase. Currently implemented:
- **Compilation Module (Tracer)**: A component that handles configurable compilation processes
- Basic configuration file parsing
- Command execution infrastructure

## Planned Features

- **System Call Tracing**: Monitor and log all system calls made by target processes
- **Memory Analysis**: Track stack memory usage and heap allocations
- **Memory Leak Detection**: Identify and report memory leaks in real-time
- **Interactive TUI**: Terminal-based user interface for efficient monitoring using FTXUI
- **Real-Time Updates**: Dynamic display of process information and statistics
- **Process Filtering**: Select specific processes to monitor
- **Export Functionality**: Save analysis results for later review

## Requirements

- C++17 compatible compiler
- CMake 3.10 or higher.
- Administrative privileges (will be required for system call tracing)


## Project Structure

- `tracer/` - Core compilation and execution functionality
- `tui/` - The Terminal User Interface components


## Usage

The project is not yet ready for end-user usage. Full command-line options will be implemented in future releases.

## License

This project is licensed under the MIT License.

## Contributing

Please read our [Code of Conduct](CODE_OF_CONDUCT.md) before contributing to the project.