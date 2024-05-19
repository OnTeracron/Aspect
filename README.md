<div align="center">
  <img src="https://i.imgur.com/LAhLqgx.png" />
</div>

<div align="center">
  <h1>Aspect Programming Language</h1>
</div>

<div align="center">
  <a href="">
    <img src="https://img.shields.io/badge/version-0.3.1-pink" alt="Version Badge">
  </a>
</div>

## About Aspect
Aspect is a lightweight programming language designed to streamline the software development process. It has a statically typed syntax,
making it efficient and reliable for building complex systems while minimizing errors.

## Getting Started

A simple way to build Aspect from it's source code is to use CMake.

CMake can be installed from it's official website, https://cmake.org/.

After it is running natively on your system, you will need to navigate to the root directory of the source code.

Then, execute the following commands in a supported terminal:

```
mkdir build
cd build
cmake ../
sudo make
```

The Aspect executable will then be installed to your bin directory.

### Compiling a file

To compile a file, Aspect allows for using the "-f" flag. This allows for you to input a filename.

You can then, run the following code from the root directory to compile a file to your current path:

```
aspect -f tokenize.ap
```

More support for additional features, such as specifying path locations, and executable names will be added in the future.


## Copyright and Licensing
Copyright (c) 2024 Teracron. All rights reserved.

Any software that is belonging to Teracron, and is incorporated inside of Aspect will be licensed under the [MIT LICENSE](https://github.com/saviongoslee/Aspect/blob/main/README.md).

Some software that is incorporated into Aspect may have separate licensing regulations. Any code utilized under those licenses will contain encapsulated agreements, unless permitted otherwise.
