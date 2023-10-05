#include "../include/lexer.h"
#include <list>
#include <locale>
#include <codecvt>

Lexer::Lexer(const std::string& str) : buffer_{str} {}

std::list<Token> Lexer::Parse(const bool comments) {
  std::list<Token> tokens;
  std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv;

  for (const char32_t token_char : conv.from_bytes(buffer_)) {
    Token token{GetToken_(token_char)};
    if (!comments && token == Token::COMMENT) continue;
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
