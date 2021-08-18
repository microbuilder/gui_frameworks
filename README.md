# GUI Frameworks

Simple boilerplate for common cross-platform GUI frameworks

| Folder   | Compiler | Description              |
|----------|----------|--------------------------|
| `gtk+`   | C        | GTK+3                    |
| `gtk+go` | Go       | Golang wrapper for GTK+3 |
| `sdl1.2` | C++      | SDL 1.2 (1)              |
| `sdl2`   | C++      | SDL 2 (2)                |

1. SDL 1.2 enables framebuffer rendering and doesn't depend on OpenGL, etc.
    Useful for embedded devices.
2. SDL 2 is much faster than SDL 1.2 but has no framebuffer and requires OpenGL.

# But, Why?

The purpose of this repository is to provide a starting point to test various
GUI ideas for small Linux embedded devices with displays, while being able to
develop prototypes on a full desktop OS like Linux or OS X.

It can also provide the basis of a very minimalistic cross-platform app, such
as viewing sensor data when combined with libusb, etc.