#include "../include/tools.h"
#include <cstdlib>
#include <fstream>

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
