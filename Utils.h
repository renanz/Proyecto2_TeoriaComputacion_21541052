#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

class Utils
{
    public:
        Utils();
        virtual ~Utils();

        void toUpper(string * cadena);
        vector<string> split(string line, char delim);

    protected:

    private:
};

#endif // UTILS_H
