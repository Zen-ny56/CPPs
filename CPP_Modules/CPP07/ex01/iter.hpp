#pragma once

#include <iostream>
#include <string>

template <typename T>
void iter(T* array, size_t length, void	(*function)(T&))
{
	for (size_t i = 0; i < length; ++i)
		function(array[i]);  // Apply the function to each element
}