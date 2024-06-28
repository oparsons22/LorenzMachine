# Develop a simulation of a Lorenz Cipher Machine

[![Lint](https://github.com/oparsons22/LorenzMachine/actions/workflows/lint.yml/badge.svg)](https://github.com/oparsons22/LorenzMachine/actions/workflows/lint.yml)
[![Format](https://github.com/oparsons22/LorenzMachine/actions/workflows/format.yml/badge.svg)](https://github.com/oparsons22/LorenzMachine/actions/workflows/format.yml)
[![Build](https://github.com/oparsons22/LorenzMachine/actions/workflows/build.yml/badge.svg)](https://github.com/oparsons22/LorenzMachine/actions/workflows/build.yml)
[![Test](https://github.com/oparsons22/LorenzMachine/actions/workflows/test.yml/badge.svg)](https://github.com/oparsons22/LorenzMachine/actions/workflows.test.yml)

This repository uses submodules so ensure to include the `--recursive` option when cloning:

```shell
git clone --recursive https://github.com/oparsons22/LorenzMachine
```

Run the following command to update the submodules.

```shell
git submodule update --recursive --remote
```

## Introduction

This case study focuses on simulating a cipher machine called the Lorenz SZ40 (SZ is derived from the word Schlüsselzusatz meaning cipher attachment) used by Adolf Hitler in the Second World War for encrypting important messages such as battle plans. The machine was thought to be unbreakable by Hitler and in fact, the Russians used the machine for several years following the war for the same reason. However, some very clever men at Bletchley Park managed to crack the cipher without ever seeing the machine and in the process created one of the first “computers” called Colossus.

## Description of Lorenz Machine

The Lorenz SZ40 cipher machine comes in two parts: a Lorenz teleprinter machine connected to an encryption device. The teleprinter machine was a standard piece of communications equipment used internationally from the mid-1930s through the war and was adapted for use with an encryption device on Hitler’s orders. Every letter of a message is typed on the teleprinter keyboard, converted to a 5-bit representation known as a Baudot-Murray ITA2 code (see Table 1 for more details), and then passed into the encryption device. The resulting encrypted letter is then transmitted via radio or telephone line. Telephone line transmission could not easily be intercepted but radio transmissions could and were by the Allies. The cipher was eventually cracked at Bletchley Park giving the Allies a distinct advantage during the Second World War.

![image](https://user-images.githubusercontent.com/84073912/232764816-219829e8-a854-498f-908e-f12ee50edae6.png)

|      Letter      |  Code   |
|:----------------:|:-------:|
|       NULL       | `00000` |
|      SPACE       | `00100` |
|        Q         | `10111` |
|        W         | `10011` |
|        E         | `00001` |
|        R         | `01010` |
|        T         | `10000` |
|        Y         | `10101` |
|        U         | `00111` |
|        I         | `00110` |
|        O         | `11000` |
|        P         | `10110` |
|        A         | `00011` |
|        S         | `00101` |
|        D         | `01001` |
|        F         | `01101` |
|        G         | `11010` |
|        H         | `10100` |
|        J         | `01011` |
|        K         | `01111` |
|        L         | `10010` |
|        Z         | `10001` |
|        X         | `11101` |
|        C         | `01110` |
|        V         | `11110` |
|        B         | `11001` |
|        N         | `01100` |
|        M         | `11100` |
| CARRIAGE RETURN  | `01000` |
|    LINE FEED     | `00010` |
| SHIFT TO FIGURES | `11011` |
| SHIFT TO LETTERS | `11111` |

> [!note]
> Several non-printable codes shall be replaced with the following printable characters.

|      Letter      | Character |
|:----------------:|:---------:|
|       NULL       |    `*`    |
| CARRIAGE RETURN  |    `,`    |
|    LINE FEED     |    `-`    |
| SHIFT TO FIGURES |    `!`    |
| SHIFT TO LETTERS |    `.`    |

This device has 12 rotor wheels each with a unique number of configurable pins that can either be pushed in or pulled out (giving a binary value 0 or 1). Altogether there are 501 pins across all 12 wheels. During the normal operation of the device, each pin in each wheel will be set to a predefined “value” giving a total configuration of 501 pin settings. You will be provided with a data file, ***pinsettings.dat***, containing the settings that are to be used as a stream of 0s and 1s. Table 2 gives the order of the pins by wheel and the number of pins per wheel, e.g. the first 43 binary values represent the pin settings for the Ψ1 wheel. The total number of possible initial settings for this device is 1.6 x 1019. Any device that wants to be able to decrypt a message must also have the same initial settings for all 12 wheels. Anyone wishing to crack the cipher would need to discover these pin settings. These were changed daily which led Hitler to believe it could not be broken.

| Wheel Number |  Name  | Number of Pins |
|:------------:|:------:|:--------------:|
|      1       | `psi1` |       43       |
|      2       | `psi2` |       47       |
|      3       | `psi3` |       51       |
|      4       | `psi4` |       53       |
|      5       | `psi5` |       59       |
|      6       | `m37`  |       37       |
|      7       | `m61`  |       61       |
|      8       | `chi1` |       41       |
|      9       | `chi2` |       31       |
|      10      | `chi3` |       29       |
|      11      | `chi4` |       26       |
|      12      | `chi5` |       23       |

The 12 device wheels can be subdivided into two groups of 5 (called Chi Χ and Psi Ψ) and 2 single motor wheels (called M37 and M61). Table 2 gives details of each wheel in the device. The 5 Chi Χ and 5 Psi Ψ wheels correspond to the 5-bit Baudot-Murray ITA2 code representation of each character in the message. A simple XOR (exclusive-OR) operation is used to encrypt each letter in the message. Firstly, the current pin “value” (0 or 1) of each corresponding wheel in the Chi Χ and Psi Ψ group are XOR together to create a new 5-bit key. Secondly, each corresponding bit of the 5-bit Baudot-Murray ITA2 code is XOR with the 5-bit key. This new 5-bit code can then be converted back into an encrypted letter. The advantage of using an XOR operation for encrypting a letter is that by applying the same operation a second time the original letter is revealed.

The device has been made even more secure by changing the encryption key after each letter is encrypted. This happens by rotating the device wheels. There is a simple algorithm that governs which wheels rotate after each letter is encrypted. Firstly, all 5 Chi Χ wheels rotate every time. Secondly, if the current setting of M37 is 1 then all 5 Psi Ψ wheels are rotated. Thirdly, if the current setting of M61 is 1 then M37 is rotated. Finally, M61 is rotated every time. The wheel rotations must be applied in this order.

## Class Diagram

![image](https://user-images.githubusercontent.com/84073912/232771908-ea0b8568-ca08-4290-8a71-59ce16f53a12.png)

> [!tip]
> `HELLO WORLD` should encrypt to `JWMFM-XFV,K`

## Structure

The project structure is described below:

```text
|-- CMakeLists.txt
|-- README.md
|-- build/      <- Object files
|  `-- bin/     <- Executable files
|-- data/       <- Project data
|-- extern/     <- Git submodules
|-- include/    <- Header files
|-- src/        <- Source files
`-- test/       <- Unit tests
```

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
