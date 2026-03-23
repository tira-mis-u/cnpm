@echo off

set PATH=C:\msys64\mingw64\bin;%PATH%
set CMAKE_PREFIX_PATH=C:\Qt\6.5.0\mingw_64

rmdir /s /q build

cmake -S . -B build -G "MinGW Makefiles"
cmake --build build

build\StudentMS.exe

pause