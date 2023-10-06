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

#endif
