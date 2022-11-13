#pragma once
#include <exception>
#include <string>

class FractionException: public std::exception
{
    public:
        FractionException(const std::string& error);
        const char* what() const noexcept override;
    private:
        std::string error_text;
};