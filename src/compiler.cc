#include <cstdlib>
#include <iostream>
#include <list>
#include <stack>

#include "../include/chunk.h"
#include "../include/compiler.h"
#include "../include/lexer.h"


Compiler::Compiler(const std::list<Token>& tokens,
             const bool ascii,
             const int memory) :
  tokens_{tokens}, ascii_{ascii}, memory_{memory} {}

bool Compiler::IsAcc_(const Token token) const {
  switch (token) {
    case Token::LOOP:
      return false;
    case Token::END:
      return false;
    case Token::SHOW:
      return false;
    default:
      return true;
  }
}

std::list<TokenAccumulated> Compiler::Optimize_() const {
  std::list<TokenAccumulated> result;
  if (tokens_.empty()) return result;

  Token last_token{tokens_.front()};
  size_t accumulated{0};
  for (const Token token : tokens_) {
    if (!IsAcc_(token) || token != last_token) {
      result.push_back(TokenAccumulated{accumulated, last_token});
      accumulated = 0;
    }
    last_token = token;
    accumulated++;
  }
  result.push_back(TokenAccumulated{accumulated, last_token});

  return result;
}

std::string Compiler::Compile() const {
  std::string output;
  ChunkGenerator generator;
  std::stack<size_t> loop_id;
  size_t seed{0};

  output += generator.Header(memory_);
  for (const auto& token_acc : this->Optimize_()) {
    Token token{token_acc.second};
    size_t acc{token_acc.first};

    switch (token) {
      case Token::NEXT:
        output += generator.Next(acc);
        break;
      case Token::PREV:
        output += generator.Prev(acc);
        break;
      case Token::INC:
        output += generator.Inc(acc);
        break;
      case Token::DEC:
        output += generator.Dec(acc);
        break;
      case Token::LOOP:
        loop_id.push(seed);
        output += generator.Loop(seed);
        ++seed;
        break;
      case Token::END:
        if (loop_id.empty()) {
          std::cerr << "Loop end without open the loop\n";
          std::exit(EXIT_FAILURE);
        }
        output += generator.End(loop_id.top());
        loop_id.pop();
        break;
      case Token::SHOW:
        output += generator.Show(ascii_);
        break;
      default:
        break;
    }
  }

  output += generator.Footer();

  if (!loop_id.empty()) {
    std::cerr << "Loop " << loop_id.top() + 1 << " not closed\n";
    std::exit(EXIT_FAILURE);
  }

  return output;
}
