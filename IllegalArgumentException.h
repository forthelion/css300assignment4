#ifndef ILLEGAL_ARGUMENT_EXCEPTION_H
#define ILLEGAL_ARGUMENT_EXCEPTION_H

#include <exception>

class IllegalArgumentException : public std::exception {
  public:
    const char *what() {
        return "IllegalArgumentException";
    }
};

#endif
