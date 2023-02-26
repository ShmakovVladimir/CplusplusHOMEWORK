#include "findException.hpp"

BinSearchException::BinSearchException(const std::string& error): error_text{error}
{

}
const char* BinSearchException::what() const noexcept
{ 
    return error_text.c_str(); 
}