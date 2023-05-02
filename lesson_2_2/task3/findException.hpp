#pragma once
#include <exception>
#include <string>

class BinSearchException: public std::exception
{
    public:
        BinSearchException(const std::string& error);
        const char* what() const noexcept override;
    private:
        std::string error_text;
};