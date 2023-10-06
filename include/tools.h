#ifndef TOOLS_H_
#define TOOLS_H_

#include <iostream>
#include <string>

/**
 * Function to read a file and store the contents in a string
 *
 * @param file_name
 */
std::string ReadFile(const std::string& file_name);

/**
 * Function to write a string in a file
 *
 * @param file_name
 * @param content
 */
void WriteFile(const std::string& file_name, const std::string& content);

/**
 * Converts the assembly output to an executable
 *
 * @param asm_file
 * @param output_file Name of the output binary
 */
void LinkProgram(const std::string& asm_file, const std::string& output_file);

#endif
