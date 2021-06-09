#include <iostream>
#include "Hamming/Hamming.cpp"

int main()
{
    hamming_code_16bit({1, 0, 0, 1,
                        1, 0, 0, 0,
                        1, 0, 1, 0,
                        1, 0, 0, 1});
}