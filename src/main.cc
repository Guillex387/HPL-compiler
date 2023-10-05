#include <codecvt>
#include <fstream>
#include <iostream>
#include <list>
#include <locale>
#include <string>

#include "../include/lexer.h"
#include "../include/tools.h"
#include "../include/chunk.h"
#include "../include/compiler.h"

int main(const int argc, const char** argv) {
  std::string file_name{argv[1]};
  std::string file{ReadFile(file_name)};
  Lexer lexer{file};
  std::list<Token> tokens{lexer.Parse()};
  Compiler compiler{tokens, "%u\\n", 30000};
  std::cout << compiler.Compile();
  return 0;
}
