# SDL 1.2 Sample

## Why SDL 1.2?

SDL 1.2 can directly use the Linux framebuffer, taking control of the
console window, for example. This allows for more flexbility than SDL2
which relies on OpenGL (making it faster!), but doesn't have the same
portability as a result.

## Building

```bash
$ make clean all
$ ./app
```
