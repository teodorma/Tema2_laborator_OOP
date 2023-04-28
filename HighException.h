#ifndef _HIGHEXCEPTION_H_
#define _HIGHEXCEPTION_H_
#include <iostream>
class TooHighException : public std::exception {
public:
    TooHighException() = default; 
    const char* what() const noexcept override  {
        return "Inaltimea automobilului depasita";
    }
};
#endif