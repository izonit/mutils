//===------------------------------------------------===//
//
// Mutils - basic Logger usage example (log to file)
//
//===------------------------------------------------===//

#include <Mutils/mutils-logger.h> // Include the installed library

int main()
{
  mu::Logger logger(mu::LogLevel::INFO, "output.txt"); /* Initialize the logger instance with
                                                        * destination of output.txt */
                                                       //===========================================
  logger.log("Logger works", mu::LogLevel::INFO);      /* Log "Logger works" to the destination with
                                                        * the level of INFO */
}