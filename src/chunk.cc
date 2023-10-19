#include "../include/chunk.h"
#include <cstdio>
#include <string>
#include <format>

ChunkGenerator::ChunkGenerator() {}

std::string ChunkGenerator::Header(const int memory) const {
  return std::vformat(kHeaderFmt, std::make_format_args(memory));
}

std::string ChunkGenerator::Footer() const {
  return kFooterFmt;
}

std::string ChunkGenerator::Next(const size_t acc) const {
  return std::vformat(kNextFmt, std::make_format_args(acc));
}

std::string ChunkGenerator::Prev(const size_t acc) const {
  return std::vformat(kPrevFmt, std::make_format_args(acc));
}

std::string ChunkGenerator::Inc(const size_t acc) const {
  return std::vformat(kIncFmt, std::make_format_args(acc));
}

std::string ChunkGenerator::Dec(const size_t acc) const {
  return std::vformat(kDecFmt, std::make_format_args(acc));
}

std::string ChunkGenerator::Loop(const int id) const {
  return std::vformat(kLoopFmt, std::make_format_args(id));
}

std::string ChunkGenerator::End(const int id) const {
  return std::vformat(kEndFmt, std::make_format_args(id));
}

std::string ChunkGenerator::Show(const bool ascii) const {
  return ascii ? kShowAsciiFmt : kShowFmt;
}
