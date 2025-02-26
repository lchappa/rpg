#include "arme.h"
#include "potion.h"
#include "armure.h"
#include <iostream>

using namespace std;

int main() {
    Arme a;
    Potion p;
    Armure ar;

    cout << "Type de l'objet : " << a.getType() << endl;
    cout << "Valeur de l'objet : " << a.getBonusAttaque() << endl;
    cout << "Type de l'objet : " << p.getType() << endl;
    cout << "Valeur de l'objet : " << p.getPVrendus() << endl;
    cout << "Type de l'objet : " << ar.getType() << endl;
    cout << "Valeur de l'objet : " << ar.getBonusDefense() << endl;
    return 0;
}