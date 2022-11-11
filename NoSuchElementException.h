#ifndef NO_SUCH_ELEMENT_EXCEPTION_H
#define NO_SUCH_ELEMENT_EXCEPTION_H

#include <exception>

class NoSuchElementException : public std::exception {
  public:
    const char *what() {
        return "NoSuchElementException";
    }
};

#endif
