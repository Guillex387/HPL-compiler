# HPL-compiler

This a small compiler (linux x86_64) made for the hand programming language.

The [HPL](https://github.com/jesus-seijas-sp/hand-challenge) _(Hand programming language)_ language,
is a challenge made for a technical interview. And is very similar to brainfuck.

## How write HPL code

> Note: check the `examples/` to see code examples in HPL.

This language works with a memory of a defined size of bytes, with all values initialized to 0. This language haves 7 instructions:

- 👉 : moves the memory pointer to the next cell.

- 👈 : moves the memory pointer to the previous cell.

- 👆 : increment the memory cell at the current position.

- 👇 : decreases the memory cell at the current position.

- 🤜 : if the memory cell at the current position is 0, jump just after the corresponding 🤛.

- 🤛 : if the memory cell at the current position is not 0, jump just after the corresponding 🤜.

- 👊 : Display the current character represented by the ASCII code defined by the current position.

- As memory cells are bytes, from 0 to 255 value, if you decrease 0 you'll get 255, if you increment 255 you'll get 0.

- Loops of 🤜 and 🤛 can be nested.

## Install the compiler

The compiler is written in C++, and build it with cmake.

> Note: Before build it, you need to install **g++, gcc, nasm, make, cmake**.

For build it:

```sh
# Clone this repo
git clone https://github.com/Guillex387/HPL-compiler.git
# Create a build/ dir
mkdir build
cd build
# Execute cmake
cmake ..
make
```

Now you have the **hpl** binary for compile HPL code!.

## Usage of compiler

```
$ ./hpl --help

Usage: hpl [--help] [--version] [--decimal] [--asm] [--memory VAR] [--output VAR] input_file

This a small compiler (linux x86_64) made for the hand programming language

Positional arguments:
  input_file     The .hand file that contains the hand code to compile

Optional arguments:
  -h, --help     shows help message and exits
  -v, --version  prints version information and exits
  --decimal      Prints the cells in decimal format and not in ascii
  --asm          The output file is the result in assembly
  --memory       Amount of cells in the program [default: 3000]
  -o, --output   Set the output file of the code [default: "a.out"]
```

## License

HPL-compiler Copyright (c) 2023 Guillex387. All rights reserved.

Licensed under the [MIT license](LICENSE).
