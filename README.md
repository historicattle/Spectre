# Spectre

A terminal-based system monitoring and debugging tool for comprehensive process analysis.

## Overview

Spectre provides real-time monitoring and analysis of system processes with focus on:

- **System Call Tracing**: Monitor and log all system calls made by target processes
- **Memory Analysis**: Track stack memory usage and heap allocations
- **Memory Leak Detection**: Identify and report memory leaks in real-time
- **Interactive TUI**: Terminal-based user interface for efficient monitoring

## Features

- Real-time system call monitoring with detailed parameter logging
- Stack memory usage tracking and visualization
- Heap allocation monitoring with allocation/deallocation tracking
- Memory leak detection with source location identification
- Process filtering and selection capabilities
- Export functionality for analysis results
- Low-overhead monitoring suitable for production environments

## Requirements

- Windows 10/11 or Linux
- Administrative privileges (required for system call tracing)
- C++17 compatible compiler
- CMake 3.15 or higher

## Building

```bash
mkdir build
cd build
cmake ..
cmake --build . --config Release
```

## Usage

Run with administrative privileges:

```bash
# Monitor specific process by PID
./spectre --pid <process_id>

# Monitor process by name
./spectre --process <process_name>

# Monitor with custom output file
./spectre --pid <process_id> --output trace.log
```

## Command Line Options

- `--pid <id>`: Target process ID
- `--process <name>`: Target process name
- `--output <file>`: Output file for trace data
- `--help`: Display usage information

## License

This project is licensed under the MIT License.