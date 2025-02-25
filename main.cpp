#include "objet.h"
#include <iostream>

using namespace std;

int main() {
    Objet o;
    Objet o2;
    cout << "Type de l'objet : " << o.getType() << endl;
    cout << "Valeur de l'objet : " << o.getValeur() << endl;
    cout << "Type de l'objet : " << o2.getType() << endl;
    cout << "Valeur de l'objet : " << o2.getValeur() << endl;
    return 0;
}