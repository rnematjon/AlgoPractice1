#pragma once

#include <random>
#include <exception>
#include <vector>
#include <type_traits>

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
inline std::vector<T> generate_random(int size = 10, T min = INT_MIN, T max = INT_MAX)
{
    /*if ((std::is_same_v<T, int>) || (std::is_same_v<T, double>));
    else
        throw std::invalid_argument("This function accepts eather int or double.");
    */
    
    std::vector<T> vec;
    std::random_device rd;
    std::mt19937 mt(rd());

    using uniform_distribution = typename std::conditional< std::is_floating_point<T>::value, std::uniform_real_distribution<T>,
        typename std::conditional<std::is_integral<T>::value, std::uniform_int_distribution<T>, void>::type >::type;

    uniform_distribution dist((T)min, (T)max);
    for (int i = 0; i < size; i++)
    {
        vec.push_back(dist(mt));
    }

    return vec;
}