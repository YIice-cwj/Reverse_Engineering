@echo off
setlocal
if not exist build mkdir build
cd build
cmake .. -G "MinGW Makefiles"
cmake --build .
cd ..
echo Build completed!