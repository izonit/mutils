//===------------------------------------------------===//
//
// File handling wrapper around the standard library
// provided functions.
//
// Consists of a class with file operation methods
// and utility features.
//
// Originally created: 07.03.2025 (DD.MM.YYYY)
// Author: mizorint (a.k.a. izonit)
//
//===------------------------------------------------===//

#pragma once

#include <fstream>

namespace mu {
  class FileHandler {
  private:
    // Name of the opened file (if any file is even opened)
    std::string filename;

    // Opened file
    std::fstream file;

  public:
    // Constructor with the name of the file the class is opening
    FileHandler(const std::string& _filename);

    // Destructor closes the file stream when called
    ~FileHandler();

    /* Write a string to the file (puts a new line at the end)
     * Returns true if operation is successful, false if faulty */
    bool write(const std::string& content);

    // Read from a file
    std::string read();
  };
} // namespace mu