#include <codecvt>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <locale>
#include <string>

#include "../include/lexer.h"
#include "../include/tools.h"
#include "../include/chunk.h"
#include "../include/compiler.h"
#include "../lib/argparse.hpp"

#define VERSION "v0.2.0"

/**
 * Parse the console arguments
 */
argparse::ArgumentParser GetArgs(const int argc, const char** argv) {
  argparse::ArgumentParser program{"hpl", VERSION};

  program.add_description("This a small compiler (linux x86_64) made for the hand programming language");
  program.add_argument("input_file")
    .help("The .hand file that contains the hand code to compile");
  program.add_argument("--decimal")
    .help("Prints the cells in decimal format and not in ascii")
    .default_value(false)
    .implicit_value(true);
  program.add_argument("--asm")
    .help("The output file is the result in assembly")
    .default_value(false)
    .implicit_value(true);
  program.add_argument("--memory")
    .help("Amount of cells in the program")
    .default_value(3000)
    .scan<'i', int>();
  program.add_argument("-o", "--output")
    .help("Set the output file of the code")
    .default_value(std::string{"a.out"});

  try {
    program.parse_args(argc, argv);
  }
  catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    std::exit(1);
  }

  return program;
}

int main(const int argc, const char** argv) {
  auto parsed{GetArgs(argc, argv)};

  std::string input_file{parsed.get("input_file")};
  std::string output_file{parsed.get("-o")};
  bool ascii{parsed["--decimal"] != true};
  bool asm_flag{parsed["--asm"] == true};
  int memory{parsed.get<int>("--memory")};

  std::string input{ReadFile(input_file)};
  Lexer lexer{input};
  std::list<Token> tokens{lexer.Parse()};
  Compiler compiler{tokens, ascii, memory};
  
  if (asm_flag) {
    WriteFile(output_file, compiler.Compile());
  } else {
    WriteFile("temp.s", compiler.Compile());
    LinkProgram("temp.s", output_file);
  }

  return 0;
}
