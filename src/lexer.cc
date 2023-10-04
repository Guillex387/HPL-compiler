#include "../include/lexer.h"
#include <vector>
#include <locale>
#include <codecvt>

Lexer::Lexer(std::istream& stream) : stream_{stream} {}

std::vector<Token> Lexer::Parse() {
  std::vector<Token> tokens;

  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;
  std::string buffer;
  std::string token_str;
  while (stream_ >> token_str) buffer += token_str;

  for (const char32_t token_char : conv.from_bytes(buffer)) {
    Token token{GetToken_(token_char)};
    // if (token == Token::COMMENT) continue;
    tokens.push_back(token);
  }

  return tokens;
}

Token Lexer::GetToken_(const char32_t letter) const {
  switch (letter) {
    case kNextCell:
      return Token::NEXT;
    case kPrevCell:
      return Token::PREV;
    case kIncCell:
      return Token::INC;
    case kDecCell:
      return Token::DEC;
    case kLoopCell:
      return Token::LOOP;
    case kLoopEndCell:
      return Token::END;
    case kShowCell:
      return Token::SHOW;
  }
  return Token::COMMENT;
}
