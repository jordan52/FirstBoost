# FirstBoost
This is a sample project that I was going to use to illustrate how one might structure a cuda runtime app built with cmake, tested with google test, that might just happen to use boost.

I might still do it... but wanted to get something out on github so i could work on it while my kid is using the machine with the gpu in it.

## vs code setup

There's a lot here I didn't write. for example, you need the c/c++ exension, nvidia nsight, cmake, etc.

BUT! if you get error squiggles under `include <cuda_runtime.h>;` and it complains it cannot find those headers, you need to add the path to `/usr/local/cuda-12.5/include` to the c/c++ configuration. To do that, open the command pallet (command shift p) and type 'C/C++' and find the edit configuration option. I chose UI, but you could do the json one, too. end goal is to add cuda's include folder to the c/c++ intellisense configuration. then the squiggles will be gone and you can right click on a cuda function and "go to definition"

## build & test

Do an out-of-source build to a directory called 'build' then run the tests

```
cmake -S . -B build
cd build
make
```

Alternatively, I somehow have everything set up properly in vs code so that there is a button at the bottom that says "Run CTest" - it will compile and run the tests for me inside the IDE. If you don't see that and want it, go to the CMake plugin, hit the gear, scroll way down to Cmake > Options: Status Bar Visibility and set it to visible. 

## debug

add a launch config that looks like this:
```
{
    "name": "CUDA C++: Launch",
    "type": "cuda-gdb",
    "request": "launch",
    "program": "${workspaceFolder}/build/FirstBoost"
}
```

## todo
- get debugging to work - testing is great, but you're going to need to step through code...
- get CudaHelpers to actually use cuda instead of just being a placeholder.