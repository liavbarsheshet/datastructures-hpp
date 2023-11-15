#include <cstdlib>
#include <exception>
#include <string>

#ifndef _DS_HPP_EXCEPTIONS
#define _DS_HPP_EXCEPTIONS

namespace DS_HPP
{
    namespace EXC
    {
        class IndexOutOfRange;
        class InvalidInput;
        class UndefinedReference;
    }
}

class DS_HPP::EXC::IndexOutOfRange : public std::runtime_error
{
public:
    IndexOutOfRange() : std::runtime_error("Invalid index used to access data structure.") {}
};

class DS_HPP::EXC::UndefinedReference : public std::runtime_error
{
public:
    UndefinedReference() : std::runtime_error("Could not dereference undefined reference.") {}
};

class DS_HPP::EXC::InvalidInput : public std::runtime_error
{
public:
    InvalidInput(const std::string &message) : std::runtime_error(message) {}
};

#endif
