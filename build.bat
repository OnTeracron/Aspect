REM This is a temporary builder for the WINDOWS installation, and compilation of Aspect. It is specifically designed to work with CMake 3.29.0, PowerShell, and x86_64 capable machines.
REM Note that CMake will not come pre-installed with Aspect -- you must install it using either this file, or another method.
REM After compilation, the executable should be located in "./bin/aspect.exe". As of now, Aspect is not automatically added to PATH.
REM Lastly, free to tweak this file to handle your preferred building method.

@echo off

REM Install CMake if necessary.
if not exist "cmake-3.29.0-windows-x86_64\bin\cmake.exe" (
    echo CMake is not installed. Downloading and installing CMake...
    powershell -Command "Invoke-WebRequest 'https://github.com/Kitware/CMake/releases/download/v3.29.0/cmake-3.29.0-windows-x86_64.zip' -OutFile 'cmake.zip'"
    powershell -Command "Expand-Archive -Path 'cmake.zip' -DestinationPath '.'"
    del cmake.zip
)

REM Configure the build type, and compile Aspect using CMake.
cd /d "%~dp0"
if not exist build mkdir build
cd build
..\cmake-3.29.0-windows-x86_64\bin\cmake -DCMAKE_BUILD_TYPE=Release ..
..\cmake-3.29.0-windows-x86_64\bin\cmake --build .

pause