# MacOS Build Instructions

> Requires XCode, libtiff, etc.

## wxWidgets 3.2.0

```bash
$ git clone https://github.com/wxWidgets/wxWidgets.git
$ cd wxWidgets
$ git checkout v3.2.0
$ git submodule update --init --recursive
```

Build wxWidgets:

```bash
$ mkdir build-cocoa-debug && cd build-cocoa-debug
$ ../configure --enable-debug CXXFLAGS="-I/opt/homebrew/include"
$ make -j$(nproc)
```

Now make the samples:

```bash
$ cd samples && make -j$(nproc)
$ cd ..
```

And finally the demos:

```bash
$ cd demos && make -j$(nproc)
$ cd ..
```
