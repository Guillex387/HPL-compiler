#include "../include/chunk.h"
#include <cstdio>
#include <string>

ChunkGenerator::ChunkGenerator() {}

std::string ChunkGenerator::Header(const int memory) const {
  std::string output;
  output.resize(kHeaderFmt.length() + 10);
  sprintf(&output[0], kHeaderFmt.c_str(), "%u", memory);
  return output;
}

std::string ChunkGenerator::Footer() const {
  return kFooterFmt;
}

std::string ChunkGenerator::Next() const {
  return kNextFmt;
}

std::string ChunkGenerator::Prev() const {
  return kPrevFmt;
}

std::string ChunkGenerator::Inc() const {
  return kIncFmt;
}

std::string ChunkGenerator::Dec() const {
  return kDecFmt;
}

std::string ChunkGenerator::Loop(const int id) const {
  std::string output;
  output.resize(kLoopFmt.length() + 10);
  sprintf(&output[0], kLoopFmt.c_str(), id, id);
  return output;
}

std::string ChunkGenerator::End(const int id) const {
  std::string output;
  output.resize(kEndFmt.length() + 10);
  sprintf(&output[0], kEndFmt.c_str(), id, id);
  return output;
}

std::string ChunkGenerator::Show(const bool ascii) const {
  return ascii ? kShowAsciiFmt : kShowFmt;
}
