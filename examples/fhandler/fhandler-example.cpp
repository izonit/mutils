//===------------------------------------------------===//
//
// Mutils - basic FileHandler usage example
//
//===------------------------------------------------===//

#include <iostream>
#include <mutils-fhandler.h> // Include the installed library

int main()
{
  mu::FileHandler file("test.txt"); // Create a file object with the name of "test.txt"
  file.write("Hello, World!");      // Write to the file
  std::cout << file.read();         // Read the file and print it to stdout
}

/* The file stream will be closed automatically, since the destructor closing it is called when leaving
 * the scope */