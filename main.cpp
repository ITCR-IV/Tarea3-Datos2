#include <iostream>
#include "Hamming/Hamming.cpp"
#include "LRC/LRC.cpp"
#include "CRC/CRC.cpp"

int main()
{
    // bits
    List<uint> bits = {1, 0, 0, 1,
                       1, 0, 0, 0,
                       1, 0, 1, 0,
                       1, 0, 0, 1};

    // hamming code test
    hamming_code_16bit(bits);

    // LRC test
    List<uint> parityLRC = generate_LRC_parity_16bit(bits);
    bits[3] = !bits[3];
    bits[9] = !bits[9];
    LRC_check_16bit(bits + parityLRC);

    List<int> l1 = {1, 2, 3};

    std::cout << l1 + List<int>({6, 9, 4, 2, 0}) << std::endl;
    l1 += {7, 14, 21};
    l1.print();

    //Cyclic Redundancy Check test
    int data_, key_;
    std::cout << "Ingrese la informacion (bits): ";
    std::cin >> data_;

    std::cout << "Ingrese los K bits del dividendo: ";
    std::cin >> data_;

    std::string data = std::to_string(data_);
    std::string key = std::to_string(key_);

    encodeData(data, key);
    return 0;
}