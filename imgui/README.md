# imGui

Basic example of imGui based on Conan library manager.

## Setup 

### MacOS/Linux

Install and configure `conan` manager:

```bash
$ brew install conan
$ conan profile detect --force
```

Clone and build the imgui example from conan:

```bash
$ git clone https://github.com/conan-io/examples2.git
$ cd examples2/examples/libraries/imgui/introduction
$ conan install . --output-folder=build --build=missing
$ cd build
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
$ ./dear-imgui-conan
```
