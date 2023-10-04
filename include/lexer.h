#ifndef TOKENS_H_
#define TOKENS_H_

#include <iostream>
#include <vector>

// 👉
const char32_t kNextCell{128073};
// 👈
const char32_t kPrevCell{128072};
// 👆
const char32_t kIncCell{128070};
// 👇
const char32_t kDecCell{128071};
// 🤜
const char32_t kLoopCell{129308};
// 🤛
const char32_t kLoopEndCell{129307};
// 👊
const char32_t kShowCell{128074};

/**
 * Enum for represent the tokens of the language
 */
enum class Token {
  NEXT,
  PREV,
  INC,
  DEC,
  LOOP,
  END,
  SHOW,
  COMMENT
};

/**
 * A class for parse the input file into tokens
 */
class Lexer {
  public:
    /**
     * Constructor for lexer
     *
     * @param stream The input stream for read the text language
     */
    Lexer(std::istream& stream);

    /**
     * Parse the input stream to a vector of tokens
     */
    std::vector<Token> Parse();

  private:
    /**
     * Parse a letter to obtain the token
     *
     * @param letter The emoji
     * @return The token associated with the letter
     */
    Token GetToken_(const char32_t letter) const;

    std::istream& stream_;
};

#endif
