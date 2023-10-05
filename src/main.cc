#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

#include "../include/lexer.h"
#include "../include/tools.h"
#include "../include/chunk.h"

int main(const int argc, const char** argv) {
  ChunkGenerator generator;

  std::cout << generator.Header("%u", 300);
  // +++
  std::cout << generator.Inc();
  std::cout << generator.Inc();
  std::cout << generator.Inc();
  // [
  std::cout << generator.Loop(1);
  // ->
  std::cout << generator.Next();
  // +++++
  std::cout << generator.Inc();
  std::cout << generator.Inc();
  std::cout << generator.Inc();
  std::cout << generator.Inc();
  std::cout << generator.Inc();
  // <-
  std::cout << generator.Prev();
  // -
  std::cout << generator.Dec();
  // ]
  std::cout << generator.End(1);
  // ->
  std::cout << generator.Next();
  // ++
  std::cout << generator.Inc();
  std::cout << generator.Inc();
  // .
  std::cout << generator.Show();
  std::cout << generator.Footer();
}
