#include "Intermediador.h"

Intermediador::Intermediador()
{
    //ctor
}

Intermediador::~Intermediador()
{
    //dtor
}




void Intermediador::recorrer(vector<NoTerminal *> noTerminales)
{
    string str;
    ifstream file;
    if(!file.is_open())
       file.open("archivo.txt");
    while(!file.eof())
    {
        getline(file, str, '\n');
        char * cstr = new char [str.length()+1];
        strcpy(cstr,str.c_str());
        cout<< str <<endl;
    }
    file.close();

    cout << "\n\n\n\n";

    for (int i = 0; i < noTerminales.size(); i++)
    {
        NoTerminal noTerm = *noTerminales[i];
        cout << noTerm.caracter << "-> ";
        for (int j = 0; j < noTerm.producciones.size(); j++)
        {
            cout << noTerm.producciones[j] << "\n\t";
        }
        cout << endl;
    }
}



vector<NoTerminal *> Intermediador::noTerminales(vector<string> producciones)
{
    vector<NoTerminal *> no_teminales;

    //Recorrer listado de producciones creadas
    for (int i = 0; i < producciones.size(); i++)
    {
        string produccion = producciones[i];

        char name = (produccion.length() > 4) ? toupper(produccion[1]): name;
        string prod = produccion.substr(5, produccion.length()-1);

        NoTerminal no_terminal;

        if(no_teminales.empty())
        {
            no_terminal.caracter = name;
            no_terminal.producciones.push_back(prod);
            no_teminales.push_back(&no_terminal);
            cout << no_teminales[0]->caracter << "->" << no_teminales[0]->producciones[0]<< endl;
        }
        else
        {
            bool esta = false;
            int lugar;
            for(int j = 0; j < no_teminales.size(); j++)
            {
                if(no_teminales[j]->caracter == name)
                {
                    esta = true;
                    lugar = j;
                }
            }
            if(esta)
            {
                no_teminales[lugar]->producciones.push_back(prod);
                cout << no_teminales[lugar]->caracter << "->" << no_teminales[lugar]->producciones[no_teminales[lugar]->producciones.size()-1]<< endl;
            }
            else
            {
                no_terminal.caracter = name;
                no_terminal.producciones.push_back(prod);
                no_teminales.push_back(&no_terminal);
                cout << no_teminales[no_teminales.size()-1]->caracter << "->" << no_teminales[no_teminales.size()-1]->producciones[0]<< endl;
            }
        }

    }


    for (int i = 0; i < no_teminales.size(); i++)
    {
        NoTerminal * noTerm = no_teminales[i];
        cout << noTerm->caracter << "-> ";
        vector<string> vect = noTerm->producciones;
        cout << vect.size() << endl;
        for (int j = 0; j < vect.size(); j++)
        {
            cout << vect[j] << "\tadios\n\t";
        }
        cout << endl;
    }



    return no_teminales;
}



void Intermediador::menu()
{
    cout << "Bienvenido\n\nPara salir presione el numero 9" <<endl;
    cout << "----------------------" <<endl;

    cout << "Para ingresar la gramatica debe de seguir el siguiente formato:";
    cout << "\n\t1.- Para no terminales introducir el caracter entre[ ]";
    cout << "\n\t2.-Para terminales introducir el caracter entre ( )";
    cout << "\n\t3.-Las producciones deben llevar un ->";
    cout << "\n\t4.- Para epsilon, utilizar el caracter ~";
    cout << "\n\t5.- El nombre del no terminal debe de ser unicamente de un caracter";
    cout << "\n\tEjemplo: [S]->(a)[SS](bbb) o [S]->(~)";

    vector<string> producciones;
    string prod = "";
    cout << "\n\nFavor ingresar la primera produccion de la gramatica: ";
    cin >> prod;
    producciones.push_back(prod);

    int otra = 0;
    do
    {
        cout << "Desea ingresar otra produccion?\n\t1.-Si\n\t2.-No\n\tSu eleccion: ";
        cin >> otra;
        if(otra != 1) break;
        cout << "\n\nFavor ingresar la siguiente produccion de la gramatica: ";
        cin >> prod;
        producciones.push_back(prod);
    }while(otra == 1);

    vector<NoTerminal *> a = noTerminales(producciones);
    recorrer(a);
}

