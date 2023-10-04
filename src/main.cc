#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

#include "../include/lexer.h"
#include "../include/tools.h"

int main(const int argc, const char** argv) {
  std::string file_name{argv[1]};
  std::string hand_code{ReadFile(file_name)};

  Lexer lexer{hand_code};
  for (const auto token : lexer.Parse(true)) {
    switch (token) {
      case Token::NEXT:
        std::cout << "NEXT\n";
        break;
      case Token::PREV:
        std::cout << "PREV\n";
        break;
      case Token::INC:
        std::cout << "INC\n";
        break;
      case Token::DEC:
        std::cout << "DEC\n";
        break;
      case Token::LOOP:
        std::cout << "LOOP\n";
        break;
      case Token::END:
        std::cout << "LOOP END\n";
        break;
      case Token::SHOW:
        std::cout << "SHOW\n";
        break;
      case Token::COMMENT:
        std::cout << "COMMENT\n";
    }
  }
}
