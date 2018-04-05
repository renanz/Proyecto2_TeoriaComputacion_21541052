#include "Utils.h"

Utils::Utils()
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}


void Utils::toUpper(char * cadena)
{
    transform((*cadena).begin(), (*cadena).end(), (*cadena).begin(), ::toupper);
}

vector<string> Utils::split(string line, char delim)
{
    int len = line.length();
    vector<string> subArray;

    for (int j = 0, k = 0; j < len; j++) {
        if (line[j] == delim) {
            string ch = line.substr(k, j - k);
            k = j+1;
            subArray.push_back(ch);
        }
        if (j == len - 1) {
            string ch = line.substr(k, j - k+1);
            subArray.push_back(ch);
        }
    }
    return subArray;
}
