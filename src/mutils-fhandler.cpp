//===------------------------------------------------===//
//
// Implementation of mutils-fhandler.h
//
// Please refer to the header for documentation and
// information.
//
//===------------------------------------------------===//

#include "include/mutils-fhandler.h"
#include <iostream>

mu::FileHandler::FileHandler(const std::string& _filename) : filename(_filename)
{
  this->filename = _filename;
  this->file.open(this->filename, std::ios::in | std::ios::out | std::ios::app);
}

mu::FileHandler::~FileHandler()
{
  if (this->file.is_open()) {
    this->file.close();
    std::cout << "[INFO]: Succesfully closed file stream\n";
  } else {
    std::cout << "[ERROR]: Unable to close an unreachable file stream\n";
  }
}

bool mu::FileHandler::write(const std::string& _content)
{
  if (this->file.is_open()) {
    this->file << _content << "\n";
    return true;
  } else {
    std::cout << "[ERROR]: Unable to write to an unreachable file\n";
    return false;
  }
}

std::string mu::FileHandler::read()
{
  std::string contents;

  if (this->file.is_open()) {
    this->file.seekg(0, std::ios::beg);
    std::string line;
    while (std::getline(this->file, line)) {
      contents += line + "\n";
    }
  } else {
    std::cout << "[ERROR]: Unable to read from an unreachable file\n";
  }

  return contents;
}