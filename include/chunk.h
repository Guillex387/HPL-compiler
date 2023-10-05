#ifndef CHUNK_H_
#define CHUNK_H_

#include <string>

const std::string kHeaderFmt =
  "section .data\n"
  "\tfmt: db \"%s\", 0xa, 0x0\n"
  "section .bss\n"
  "\tmem: resb %d\n"
  "section .text\n"
  "extern printf\n"
  "global _start\n"
  "_start:\n"
  "\txor rcx, rcx\n";

const std::string kFooterFmt =
  "\tmov rax, 60\n"
  "\tmov rdi, 0\n"
  "\tsyscall\n";

const std::string kNextFmt =
  "\tinc rcx\n";

const std::string kPrevFmt =
  "\tdec rcx\n";

const std::string kIncFmt =
  "\txor rdx, rdx\n"
  "\tmov byte dl, [mem+rcx]\n"
  "\tinc rdx\n"
  "\tmov byte [mem+rcx], dl\n";

const std::string kDecFmt =
  "\txor rdx, rdx\n"
  "\tmov byte dl, [mem+rcx]\n"
  "\tdec rdx\n"
  "\tmov byte [mem+rcx], dl\n";

const std::string kLoopFmt =
  "loop_%d:\n"
  "\txor rax, rax\n"
  "\txor rdx, rdx\n"
  "\tmov byte dl, [mem+rcx]\n"
  "\tcmp rdx, rax\n"
  "\tje loop_%d_end\n";

const std::string kEndFmt =
  "\tjmp loop_%d\n"
  "loop_%d_end:\n";

const std::string kShowFmt =
  "\tpush rcx\n"
  "\tlea rdi, fmt\n"
  "\txor rsi, rsi\n"
  "\tmov byte sil, [mem+rcx]\n"
  "\tcall printf\n"
  "\tpop rcx\n";

/**
 * Generates the code of token in assembly
 */
class ChunkGenerator {
  public:
    /**
     * Default constructor of chunk generator
     */
    ChunkGenerator();

    /**
     * Generate header of assembly code
     *
     * @param format C format for print the cells values
     * @param memory Number of cells
     */
    std::string Header(const std::string& format, const int memory) const;

    /**
     * Generate the kernel exit
     */
    std::string Footer() const;

    /**
     * Generate the next code
     */
    std::string Next() const;

    /**
     * Generate the prev code
     */
    std::string Prev() const;

    /**
     * Generate the inc code
     */
    std::string Inc() const;

    /**
     * Generate the dec code
     */
    std::string Dec() const;

    /**
     * Generate the loop begin code
     *
     * @param id The id of the loop
     */
    std::string Loop(const int id) const;

    /**
     * Generate the loop end code
     *
     * @param id The id of the loop
     */
    std::string End(const int id) const;

    /**
     * Generate the code to print the cell value
     */
    std::string Show() const;
};

#endif
