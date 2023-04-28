#ifndef _HEAVYEXCEPTION_H_
#define _HEAVYEXCEPTION_H_
#include <iostream>
class TooHeavyException : public std::exception {
public:
    TooHeavyException() = default; 
    const char* what() const noexcept override  {
        return "Greutatea automobilului depasita";
    }
};
#endif