#pragma once
#include <vector>
#include <iostream>

template<typename T>
inline void print_vector(const std::vector<T>& vec)
{
	std::cout << "[";
	for (const T & t : vec)
	{
		std::cout << t;
		if (&t != &vec.back())
		{
			std::cout << " , ";
		}
	}
	std::cout << "]" << std::endl;
}