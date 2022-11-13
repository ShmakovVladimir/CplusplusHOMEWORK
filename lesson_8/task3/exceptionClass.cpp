#include "exceptionClass.hpp"

FractionException::FractionException(const std::string& error): error_text{error}
{

}
const char* FractionException::what() const noexcept
{ 
    return error_text.c_str(); 
}