#Astraserve - Multithreaded HTTP Web Server in C++

A high-performance, multithreaded HTTP web server built from scratch in modern C++ using low-level POSIX sockets and a custom thread pool.

 This project demonstrates systems programming, concurrency, networking, and clean modular architecture — similar to the core design of real production web servers.

---

## Features

-  **Custom thread pool** for handling concurrent clients
-  **TCP socket programming** using POSIX APIs
-  **HTTP request parsing** (GET support)
-  **Static file serving**
-  **Thread-safe logging**
-  **Modular and extensible architecture**
-  **Handles multiple clients simultaneously**

---

##  Architecture

```
Client (Browser )
        │
        ▼
   WebServer (accept connections)
        │
        ▼
   Thread Pool
        │
        ▼
 Request Handler
   ├── HTTP Request Parser
   ├── File System (static content)
   └── HTTP Response Builder
        │
        ▼
      Client
```

---

##  Design Principles

- **Separation of concerns** — each module owns its responsibility
- **RAII-friendly structure** — resources are managed through object lifetimes
- **Scalable concurrency model** — fixed thread pool avoids unbounded thread creation
- **Minimal shared state** — reduces locking overhead
- **Locking only where required** — targeted synchronization for performance

---



## How It Works

1. Server creates a **listening socket** on the configured port
2. Incoming client connections are **accepted**
3. Each connection is **pushed into a task queue**
4. Worker threads **pick tasks** from the queue
5. HTTP request is **parsed**
6. Requested file is **read from disk**
7. HTTP response is **generated and sent** back to the client

---

## Concurrency Model

Instead of spawning a thread per request, the server uses:

- A **fixed number of worker threads**
- A **synchronized task queue**
- **Condition variables** for efficient wake-up

This approach:

- Reduces context switching
- Prevents thread explosion
- Improves performance under load

---

## Build & Run

### Compile

```bash
g++ main.cpp core/*.cpp http/*.cpp network/*.cpp utils/*.cpp -pthread 
./a.out
```

###  Run

```bash
./a.out
```

### Open in browser

```
http://localhost:8080
```

---


## Contributions

Contributions, issues, and feature requests are welcome! Feel free to open a pull request or file an issue.
