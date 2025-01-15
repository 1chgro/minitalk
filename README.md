# Minitalk

## Overview
Minitalk is a 42 Network project that introduces inter-process communication (IPC) through signals in Unix systems. The goal is to create a communication program consisting of a server and a client. The server receives messages sent by the client and displays them.

## Features
- Communication between client and server using Unix signals (`SIGUSR1` and `SIGUSR2`).
- Send and display ASCII characters one bit at a time.
- Handle edge cases such as null strings and invalid PIDs.

### Files
- **server.c**: Implements the server program that listens for and processes messages from the client.
- **client.c**: Implements the client program that encodes and sends messages to the server.
- **minitalk.h**: Contains shared function prototypes, macros, and headers.
- **Makefile**: Automates compilation of the project.

## Usage

### Compilation
Use the provided `Makefile` to compile the project:
```sh
make
```
This generates the `server` and `client` executables.

### Running the Server
Start the server to obtain its Process ID (PID):
```sh
./server
```
The server will output its PID. For example:
```
Server PID: 12345
```

### Sending a Message
Run the client with the server's PID and the message you want to send:
```sh
./client <server_pid> "Your message here"
```
Example:
```sh
./client 12345 "Hello, world!"
```

The server will display the message upon receiving it.

## Requirements
- Handle errors gracefully, such as invalid PIDs or signal interruptions.
- The communication should be precise, ensuring all characters are sent and received correctly.

## Bonus
- Support Unicode characters.
- Add a feature for the client to acknowledge that the message was successfully received.

## Resources
- [Unix Signals](https://man7.org/linux/man-pages/man7/signal.7.html)
- [Signal Handling in C](https://www.geeksforgeeks.org/signals-c-language/)
