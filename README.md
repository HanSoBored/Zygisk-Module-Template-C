# Zygisk Module Template (C Version)

A minimalist [Zygisk](https://github.com/topjohnwu/Magisk) module template written in pure C for the [ReZygisk](https://github.com/PerformanC/ReZygisk) framework.

## Overview

This repository is a complete rewrite of the original [Zygisk Module Sample](https://github.com/topjohnwu/zygisk-module-sample) from C++ to pure C. It is designed for developers who prefer the simplicity and performance of C or who want to avoid the overhead of the C++ standard library.

### Key Features
- **Pure C implementation**: No C++, no classes, no namespaces.
- **Minimalist**: Uses `-DANDROID_STL=none` for the smallest possible binary size.
- **Direct API Access**: Interacts directly with the Zygisk C-style ABI.
- **Optimized for ReZygisk**: Built with compatibility for the ReZygisk framework in mind.

## References

- **Original Template**: [topjohnwu/zygisk-module-sample](https://github.com/topjohnwu/zygisk-module-sample) (C++ version)
- **Framework**: [ReZygisk](https://github.com/PerformanC/ReZygisk)

## Building

### Prerequisites
- Android SDK & NDK
- **CMake** & **Ninja** (If building on `aarch64` Linux/Termux, ensure you install native versions via `apt install cmake ninja-build`)

### Configuration
If you are building on a non-x86_64 system (like aarch64), create a `local.properties` file in the root directory:
```properties
sdk.dir=/path/to/your/android-sdk
cmake.dir=/usr
```

### Build Command
Run the following command to generate the flashable zip:
```sh
./gradlew :module:zipRelease
```
The output zip will be located in `module/release/`.

## License
This project follows the licensing of the original template where applicable.
