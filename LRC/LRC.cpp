#include <stdexcept>
#include <iostream>
#include "List.h"

List<uint> generate_LRC_parity_16bit(List<uint> &bitList)
{
    if (bitList.length() != 16)
    {
        throw std::invalid_argument("Length of list of bits for LRC check must be exactly 16 bits");
    }

    List<uint> parityBits;

    for (int i = 0; i < 4; i++)
    {
        int parityBit = bitList[i + 0 * 4] ^ bitList[i + 1 * 4] ^ bitList[i + 2 * 4] ^ bitList[i + 3 * 4];
        parityBits.push_back(parityBit);
    }

    return parityBits;
}

List<uint> LRC_check_16bit(List<uint> bitList)
{
    if (bitList.length() != 20)
    {
        throw std::invalid_argument("Length of list of bits for LRC check must be exactly 20 bits (16 data bits + 4 parity bits)");
    }

    List<uint> badColumns;

    for (int i = 0; i < 4; i++)
    {
        if (1 == bitList[i + 0 * 4] ^ bitList[i + 1 * 4] ^ bitList[i + 2 * 4] ^ bitList[i + 3 * 4] ^ bitList[i + 4 * 4]) // if odd number of bits it means something wrong
        {
            badColumns.push_back(i);
        }
    }

    if (badColumns.length() > 0)
        std::cout << "The following columns have an error: " << badColumns << std::endl;

    return badColumns;
}