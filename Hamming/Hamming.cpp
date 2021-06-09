#include <stdexcept>
#include <iostream>
#include "List.h"

uint hamming_code_16bit(List<uint> bitList)
{
    if (bitList.length() != 16)
    {
        throw std::invalid_argument("Length of list of bits for Hamming Code check must be exactly 16 bits");
    }

    uint errorPos = 0;
    size_t total1s = 0;

    for (int i = 0; i < 16; i++)
    {
        if (bitList[i] == 1)
        {
            errorPos = errorPos ^ i;
            total1s++;
        }
    }

    if (total1s % 2 == 0 && errorPos != 0)
    {
        std::cout << "Two errors detected in undetermined positions" << std::endl;
        errorPos = 0;
    }
    else if (errorPos != 0)
    {
        std::cout << "Single error detected in position: " << errorPos << std::endl;
    }

    return errorPos;
};