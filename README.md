![alt text](logo.png "webTablut")
A WebAssembly port of the O(sarracino) engine to play Tablut online

# Compiling the Engine
```
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/emsdk/fastcomp/emscripten/cmake/Modules/Platform/Emscripten.cmake
make
```

