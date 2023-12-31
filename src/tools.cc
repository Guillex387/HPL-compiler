#include "../include/tools.h"
#include <cstdlib>
#include <fstream>
#include <format>

std::string ReadFile(const std::string& file_name) {
  std::ifstream stream;
  stream.open(file_name);
  if (!stream.is_open()) {
    std::cerr << "Error opening \"" << file_name << "\"\n";
    std::exit(EXIT_FAILURE);
  }

  stream.seekg(0, stream.end);
  auto size{stream.tellg()};
  stream.seekg(0, stream.beg);
  std::string buffer;
  buffer.resize(size);

  stream.read(&buffer[0], size);
  stream.close();

  return buffer;
}

void WriteFile(const std::string& file_name, const std::string& content) {
  std::ofstream stream;
  stream.open(file_name);
  if (!stream.is_open()) {
    std::cerr << "Error opening \"" << file_name << "\"\n";
    std::exit(EXIT_FAILURE);
  }
  stream << content;
  stream.close();
}

void LinkProgram(const std::string& asm_file, const std::string& output_file) {
  std::system(std::format("nasm -felf64 {0} -o temp.o && gcc -no-pie -nostartfiles temp.o -o {1} && rm -f {0} temp.o", asm_file, output_file).c_str());
}
