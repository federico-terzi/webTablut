# webTablut
A WebAssembly port of the O(sarracino) engine to play Tablut online

# Compiling the Engine
```
mkdir build
cd build

cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/emsdk/fastcomp/emscripten/cmake/Modules/Platform/Emscripten.cmake

make
```

```
calculate_move = Module.cwrap('calculate_move', null, ['array', 'number', 'number'])

var arr = new Int32Array([0, 0, 0, 2, 2, 2, 0, 0, 0,
                          0, 0, 0, 0, 2, 0, 0, 0, 0,
                          0, 0, 0, 0, 1, 0, 0, 0, 0,
                          2, 0, 0, 0, 1, 0, 0, 0, 2,
                          2, 2, 1, 1, 3, 1, 1, 2, 2,
                          2, 0, 0, 0, 1, 0, 0, 0, 2,
                          0, 0, 0, 0, 1, 0, 0, 0, 0,
                          0, 0, 0, 0, 2, 0, 0, 0, 0,
                          0, 0, 0, 2, 2, 2, 0, 0, 0]);

calculate_move(arr, 1, 1);
```
