#pragma once

#include <iostream>

template <typename T>
T max(const T& a, const T& b)
{
    return (a > b) ? a : b;
}

template <typename T>
T min(const T& a, const T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
void swap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;

}