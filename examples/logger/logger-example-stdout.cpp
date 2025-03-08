//===------------------------------------------------===//
//
// Mutils - basic Logger usage example (log to stdout)
//
//===------------------------------------------------===//

#include <mutils-logger.h> // Include the installed library

int main()
{
  mu::Logger logger(mu::LogLevel::INFO, std::nullopt); /* Initialize the logger instance with
                                                        * destination of stdout (std::nullopt arg
                                                        * means empty optional argument, e. g.
                                                        * empty destination parameter) */
                                                       //===========================================
  logger.log("Logger works", mu::LogLevel::INFO);      /* Log "Logger works" to the destination with
                                                        * the level of INFO */
}