# SDL2 Sample App

```bash
$ make clean all
$ ./app
```

## OS X

### Library Management

```bash
$ brew install sdl2 sdl2_ttf sdl2_image
```

For convenience, copy the contents of the `include` folders of:

- /usr/local/Cellar/sdl2/2.0.16/
- /usr/local/Cellar/sdl2_ttf/2.0.15/
- /usr/local/Cellar/sdl2_image/2.0.5/

... to the local application `include` folders.

#### Dependency Check

The LLVM equivalent to Linux's `ldd` is `otool`:

```bash
$ otool -L app
app:
        /usr/local/opt/sdl2/lib/libSDL2-2.0.0.dylib (compatibility version 17.0.0, current version 17.0.0)
        /usr/local/opt/sdl2_ttf/lib/libSDL2_ttf-2.0.0.dylib (compatibility version 15.0.0, current version 15.1.0)
        /usr/local/opt/sdl2_image/lib/libSDL2_image-2.0.0.dylib (compatibility version 3.0.0, current version 3.3.0)
        /usr/lib/libc++.1.dylib (compatibility version 1.0.0, current version 905.6.0)
        /usr/lib/libSystem.B.dylib (compatibility version 1.0.0, current version 1292.100.5)
```

## Ubuntu 20.04

```bash
$ sudo apt-get install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev
```
