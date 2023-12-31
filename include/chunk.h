#ifndef CHUNK_H_
#define CHUNK_H_

#include <string>

const std::string kHeaderFmt =
  "section .data\n"
  "\tfmt: db \"%u\", 0xa, 0x0\n"
  "section .bss\n"
  "\tmem: resb {}\n"
  "section .text\n"
  "extern printf\n"
  "global _start\n"
  "print_num:\n"
  "\tpush rcx\n"
  "\tlea rdi, fmt\n"
  "\txor rsi, rsi\n"
  "\tmov byte sil, [mem+rcx]\n"
  "\tcall printf\n"
  "\tpop rcx\n"
  "\tret\n"
  "print_ascii:\n"
  "\tpush rcx\n"
  "\tmov rax, 1\n"
  "\tmov rdi, 1\n"
  "\tlea rsi, [mem+rcx]\n"
  "\tmov rdx, 1\n"
  "\tsyscall\n"
  "\tpop rcx\n"
  "\tret\n"
  "_start:\n"
  "\txor rcx, rcx\n";

const std::string kFooterFmt =
  "; Kernel exit\n"
  "\tmov rax, 60\n"
  "\tmov rdi, 0\n"
  "\tsyscall\n";

const std::string kNextFmt =
  "; Next cell x{0}\n"
  "\tadd rcx, {0}\n";

const std::string kPrevFmt =
  "; Prev cell x{0}\n"
  "\tsub rcx, {0}\n";

const std::string kIncFmt =
  "; Increment cell x{0}\n"
  "\txor rdx, rdx\n"
  "\tmov byte dl, [mem+rcx]\n"
  "\tadd rdx, {0}\n"
  "\tmov byte [mem+rcx], dl\n";

const std::string kDecFmt =
  "; Decrement cell x{0}\n"
  "\txor rdx, rdx\n"
  "\tmov byte dl, [mem+rcx]\n"
  "\tsub rdx, {0}\n"
  "\tmov byte [mem+rcx], dl\n";

const std::string kLoopFmt =
  "; Loop begin\n"
  "loop_{0}:\n"
  "\txor rax, rax\n"
  "\txor rdx, rdx\n"
  "\tmov byte dl, [mem+rcx]\n"
  "\tcmp rdx, rax\n"
  "\tje loop_{0}_end\n";

const std::string kEndFmt =
  "; Loop end\n"
  "\tjmp loop_{0}\n"
  "loop_{0}_end:\n";

const std::string kShowFmt =
  "; Show cell\n"
  "\tcall print_num\n";

const std::string kShowAsciiFmt =
  "; Show cell\n"
  "\tcall print_ascii\n";

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
     * @param memory Number of cells
     */
    std::string Header(const int memory) const;

    /**
     * Generate the kernel exit
     */
    std::string Footer() const;

    /**
     * Generate the next code
     */
    std::string Next(const size_t acc) const;

    /**
     * Generate the prev code
     */
    std::string Prev(const size_t acc) const;

    /**
     * Generate the inc code
     */
    std::string Inc(const size_t acc) const;

    /**
     * Generate the dec code
     */
    std::string Dec(const size_t acc) const;

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
    std::string Show(const bool ascii) const;
};

#endif
