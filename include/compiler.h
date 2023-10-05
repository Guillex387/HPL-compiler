#ifndef COMPILER_H_
#define COMPILER_H_

#include "lexer.h"
#include <list>
#include <string>

class Compiler {
  public:
    Compiler(const std::list<Token>& tokens,
             const std::string& format,
             const int memory);

    std::string Compile() const;
  private:
    std::list<Token> tokens_;
    std::string format_;
    int memory_;
};

#endif
