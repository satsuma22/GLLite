# GLLite

## Table of Contents
- [About the Project](#about-the-project)
- [Building](#building)

## About the Project
GLLite provides basic abstractions for OpenGL and therefore minimizes boilerplate-code. This project also includes a collection of apps (just one for now) that facilitate some basic tasks (for example rendering a image from a buffer of pixel values onto the screen).

## Building
Clone the repo:
```bash
git clone https://github.com/satsuma22/GLLite.git
```
Create a build folder in the root directory and navigate in to it:
```bash
cd GLLite
mkdir build
cd build
```
Generate the build files by running cmake:
```bash
cmake ..
```
Once the build is configured, you can build the project by running:
```bash
cmake --build .
```
or by compiling the project using the selected build system (for example, visual studios on windows).
