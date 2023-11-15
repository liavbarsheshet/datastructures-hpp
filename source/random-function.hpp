#include <type_traits>
#include <random>

#include "exceptions.hpp"

namespace DS_HPP
{
    namespace UTIL
    {
        template <typename Number>
        class Random;
    }
}

/**
 * Represents a generic abstract random function object.
 */
template <typename Number>
class DS_HPP::UTIL::Random
{

public:
    /**
     * Generates a random number within the specified range [min, max).
     *
     * @param min - The minimum number in the range.
     * @param max - The maximum number in the range.
     * @return A randomly generated number.
     */
    virtual Number operator()(const Number &min, const Number &max)
    {
        static_assert(
            std::is_same<Number, short>::value ||
                std::is_same<Number, unsigned short>::value ||
                std::is_same<Number, int>::value ||
                std::is_same<Number, unsigned int>::value ||
                std::is_same<Number, long>::value ||
                std::is_same<Number, unsigned long>::value ||
                std::is_same<Number, long long>::value ||
                std::is_same<Number, unsigned long long>::value,
            "Basic random designed to work with built-in integer types.");

        Number _max = max - 1;

        if (min < 0 || _max < min)
            throw DS_HPP::EXC::InvalidInput("Invalid min or max.");

        if (_max == min)
            return min;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<Number> dist(min, _max);
        return dist(gen);
    }
};
