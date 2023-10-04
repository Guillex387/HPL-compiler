#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

#include "../include/lexer.h"

int main() {
  std::string filename;
  std::cin >> filename;
  std::ifstream file{filename};
  Lexer lexer{file};
  for (const auto token : lexer.Parse()) {
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
  file.close();
}
