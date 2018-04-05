#ifndef INTERMEDIADOR_H
#define INTERMEDIADOR_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct NoTerminal{
    char caracter;
    vector<string> producciones;
};

struct Terminal {
    string caracteres;
};


class Intermediador
{
    public:
        Intermediador();
        virtual ~Intermediador();

        void menu();


    protected:

    private:
        void recorrer(vector<NoTerminal *> noTerminales);
        vector<NoTerminal *> noTerminales (vector<string> producciones);
};

#endif // INTERMEDIADOR_H
