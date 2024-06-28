# C++ Template

[![Lint](https://github.com/oparsons22/CppTemplate/actions/workflows/lint.yml/badge.svg)](https://github.com/oparsons22/CppTemplate/actions/workflows/lint.yml)
[![Format](https://github.com/oparsons22/CppTemplate/actions/workflows/format.yml/badge.svg)](https://github.com/oparsons22/CppTemplate/actions/workflows/format.yml)
[![Build](https://github.com/oparsons22/CppTemplate/actions/workflows/build.yml/badge.svg)](https://github.com/oparsons22/CppTemplate/actions/workflows/build.yml)
[![Test](https://github.com/oparsons22/CppTemplate/actions/workflows/test.yml/badge.svg)](https://github.com/oparsons22/CppTemplate/actions/workflows.test.yml)

This is a template for C++ projects.

This repository uses submodules so ensure to include the `--recursive` option when cloning:

```shell
git clone --recursive https://github.com/oparsons22/CppTemplate
```

Run the following command to update the submodules.

```shell
git submodule update --recursive --remote
```

> [!important]
> Replace all instances of `CppTemplate` with the repository name.

## Structure

The project structure is described below, remove as necessary:

```text
|-- CMakeLists.txt
|-- README.md
|-- build/      <- Object files
|-- data/       <- Project data
|  `-- bin/     <- Executable files
|-- extern/     <- Git submodules
|-- include/    <- Header files
|-- src/        <- Source files
`-- test/       <- Unit tests
```

> [!important]
> If the project contains no header files, remove any references to `include` or `.hpp` in any of the workflows in `.github/workflows/`.

## Build

This project uses CMake and Clang++ to build the executable.

Run the following commands to build the executable:

``` shell
mkdir build
cmake -S . -B build -DCMAKE_CXX_COMPILER_LAUNCHER=scan-build
cmake --build build
cp build/compile_commands.json ./ 
```

> [!tip]
> It's recommended to run the above commands before making changes so the compiler can find the headers.

## Unit Tests

[Build](#build) the project and run the following commands to run the unit tests:

```shell
cd build/test
ctest --output-on-failure
```

### Coverage

After running the above commands, run the following commands to generate a coverage HTML report:

```shell
llvm-profdata merge -sparse default.profraw -o merged.profdata
llvm-cov show ./runTests -instr-profile=merged.profdata -format=html -output-dir=coverage_report
```

You can then view the coverage report by opening `coverage_report/index.html`.

## Static Analysis

scan-build is incorporated into the Makefile to perform static analysis of the source code to identify bugs, security vulnerabilities, and potential performance issues at build time.

---

Further static analysis can be performed using [cppcheck](https://sourceforge.net/projects/cppcheck/), [cpplint](https://github.com/cpplint/cpplint) and [clang-tidy](https://clang.llvm.org/extra/clang-tidy/).

``` shell
cppcheck --enable=all src include -I include
```

``` shell
cpplint --recursive .
```

```shell
clang-tidy -p build $(find src -name '*.cpp') $(find include -name '*.hpp')
```
