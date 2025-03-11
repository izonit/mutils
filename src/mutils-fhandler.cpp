//===------------------------------------------------===//
//
// Implementation of mutils-fhandler.h
//
// Please refer to the header for documentation and
// information.
//
//===------------------------------------------------===//

#include "include/mutils-fhandler.h"
#include "include/mutils-logger.h"
#include <iostream>

mu::FileHandler::FileHandler(const std::string& _filename) : filename(_filename)
{
  this->filename = _filename;
  this->file.open(this->filename, std::ios::in | std::ios::out | std::ios::app);
}

mu::FileHandler::~FileHandler()
{
  if (this->file.is_open()) {
    mu::Logger(LogLevel::INFO).log("Succesfully closed file stream", LogLevel::INFO);
    this->file.close();
  } else {
    mu::Logger(LogLevel::ERROR)
        .log("[ERROR]: Unable to close an unreachable file stream", LogLevel::ERROR);
  }
}

bool mu::FileHandler::write(const std::string& _content)
{
  if (this->file.is_open()) {
    this->file << _content << "\n";
    return true;
  } else {
    mu::Logger(LogLevel::ERROR).log("[ERROR] : Unable to write to an unreachable file", LogLevel::ERROR);
    return false;
  }
}

std::string mu::FileHandler::read()
{
  std::string contents;

  if (this->file.is_open()) {
    this->file.clear();
    this->file.seekg(0, std::ios::beg);
    std::string line;
    while (std::getline(this->file, line)) {
      contents += line + "\n";
    }
  } else {
    mu::Logger(LogLevel::ERROR).log("[ERROR]: Unable to read from an unreachable file", LogLevel::ERROR);
  }

  return contents;
}