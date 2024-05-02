Changelog 02.05.2024:

Switched the primary operating system support for Linux.
Removed the temporary build.bat installation file.
Improved the handling of the file manager and removed dirent.h.
Made lexer_get_next_token a bit less tedious by abstractifying it.
Added compile_flags.txt to .gitignore for systems that use .clangd.
Added Makefile to .gitignore for contributors
Removed the version-specific CMake directory from .gitignore.
Improved CMakeLists.txt altogether
Made cli.c a bit less redundant