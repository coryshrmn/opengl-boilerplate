opengl-boilerplate
==================

Boilerplate for OpenGL using GLFW and GLEW

## TODO ##
* Include GL bits inherent to most common needs
* Expand "Usage"
* Add vertex, geometry, and fragment shaders
* test cmake build on windows (mingw). probably needs modification
* test cmake build on OS X, probably works

## Required Packages ##
* `gl`
* `glu`
* `glew3`
* `glfw`
* `mingw32` [windows only]
* `cmake` [optional]
* `pkg-config` [optional]

## Usage ##
For use in your own projects if you haven't started development yet:
`git clone https://github.com/b-willard/opengl-boilerplate.git . && rm -rf .git`

## Build ##
### Linux ###

    mkdir build
    cd build
    cmake ..
    make

### OS X (untested) ###

    mkdir build
    cd build
    cmake -G Xcode ..
    xcodebuild

### MinGW (probably doesn't work yet) ###

    mkdir build
    cd build
    cmake -G "MinGW Makefiles"
    make

Note: if cmake is not an option, please modify Makefile to reflect your environment.
