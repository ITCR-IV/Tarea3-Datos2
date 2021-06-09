#include <bits/stdc++.h>
using namespace std;

// Apply XOR to 2 data bit with the same length
string XOR(string dataChain1, string dataChain2)
{

    string result = "";

    int n = dataChain2.length();

    for(int i = 1; i < n; i++)
    {
        if (dataChain1[i] == dataChain2[i])
            result += "0";
        else
            result += "1";
    }
    return result;
}

// Division modulo-2
string division(string divident, string divisor)
{

    int pick = divisor.length();

    string tmp = divident.substr(0, pick);

    int n = divident.length();

    while (pick < n)
    {
        if (tmp[0] == '1')

            // Replace the divident by the result of XOR and pull 1 bit down
            tmp = XOR(divisor, tmp) + divident[pick];
        else

            // If leftmost bit is '0'.
            // If the leftmost bit of the dividend (or the
            // part used in each step) is 0, the step cannot
            // use the regular divisor; we need to use an
            // all-0s divisor.
            tmp = XOR(std::string(pick, '0'), tmp) +
                  divident[pick];

        pick += 1;
    }

    // For the last n bits, we have to carry it out
    // normally as increased value of pick will cause
    // Index Out of Bounds.
    if (tmp[0] == '1')
        tmp = XOR(divisor, tmp);
    else
        tmp = XOR(std::string(pick, '0'), tmp);

    return tmp;
}

void encodeData(string data, string key)
{
    int l_key = key.length();

    // Appends n-1 zeroes at end of data
    string appended_data = (data + std::string(l_key - 1, '0'));

    string remainder = division(appended_data, key);

    // Appends the reminder to the data to be send
    string codeword = data + remainder;
    cout << "Residuo de la division : "
         << remainder << "\n";
    cout << "Informacion codificada (Data + residuo) :"
         << codeword << "\n";
}

