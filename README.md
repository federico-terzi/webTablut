![alt text](logo.png "webTablut")


A WebAssembly port of the [O(sarracino) engine](https://github.com/federico-terzi/osarracino) to play Tablut online.

You can [Play it HERE](https://federicoterzi.com/webTablut/).

# Why

I wanted to learn a bit of WebAssembly lately, so I decided to port our high-performance C++ Tablut engine to the web.

# Compiling the engine

This project ships a stripped out version of the engine and can be compiled by installing the Emscripten toolchain.

```
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/emsdk/fastcomp/emscripten/cmake/Modules/Platform/Emscripten.cmake
make
```

