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


std::string Compiler::Compile() const {
  std::string output;
  ChunkGenerator generator;
  std::stack<size_t> loop_id;
  size_t seed{0};

  output += generator.Header(memory_);
  for (const auto token : tokens_) {
    switch (token) {
      case Token::NEXT:
        output += generator.Next();
        break;
      case Token::PREV:
        output += generator.Prev();
        break;
      case Token::INC:
        output += generator.Inc();
        break;
      case Token::DEC:
        output += generator.Dec();
        break;
      case Token::LOOP:
        loop_id.push(seed);
        output += generator.Loop(seed);
        ++seed;
        break;
      case Token::END:
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
