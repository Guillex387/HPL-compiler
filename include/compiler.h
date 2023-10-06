#ifndef COMPILER_H_
#define COMPILER_H_

#include "lexer.h"
#include <list>
#include <string>

/**
 * A class to compile the hand lang tokens into assembly
 */
class Compiler {
  public:
    /**
     * Compiler constructor
     *
     * @param tokens List of tokens to parse
     * @param ascii Check if the cells are printed in ascii or decimal
     * @param memory Assign the ammount of cells of the program
     */
    Compiler(const std::list<Token>& tokens,
             const bool ascii,
             const int memory);

    /**
     * Compile the array of token in assembly code
     */
    std::string Compile() const;
  private:
    std::list<Token> tokens_;
    bool ascii_;
    int memory_;
};

#endif
