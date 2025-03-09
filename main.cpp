#include "arme.h"
#include "potion.h"
#include "armure.h"
#include "personnage.h"
#include "ennemi.h"
#include "allie.h"
#include "utils.h"
#include <iostream>

using namespace std;

int main() {
    Personnage personnage;
    checkForSave(personnage);
    afficherStats(personnage);

    while (true) {
        afficherMenuIdle();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Prochaine rencontre..." << std::endl;
                switch(determinerRencontre()){
                    case 0: {
                        cout << "Vous avez rencontré un ennemi ! Vous vous préparez au combat !" << endl;
                        Ennemi ennemi;
                        combat(personnage, ennemi);
                        break;
                    }
                    case 1: {
                        cout << "Vous avez rencontré un allié ! Il vous offre un de ses objets !" << endl;
                        Allie allie;
                        recupererObjets(personnage, allie);
                        break;
                    }
                    case 2: {
                        if (personnage.inventairePlein()) {
                            cout << "Objet rencontré, mais inventaire déjà plein" << endl;
                        } else {
                            // Génère l'objet et affiche son type et ses statistiques
                            auto objet = generateObjet();
                            cout << "Objet rencontré : " << objet->getType();
                            if (objet->getType() == "Arme") {
                                cout << " (" << static_cast<Arme*>(objet.get())->getBonusAttaque() << ")" << endl;
                            } else if (objet->getType() == "Armure") {
                                cout << " (" << static_cast<Armure*>(objet.get())->getBonusDefense() << ")" << endl;
                            } else {
                                cout << endl;
                            }

                            cout << "Souhaitez-vous le ramasser ? (1: Oui, 0: Non)" << endl;
                            int ramasser;
                            std::cin >> ramasser;
                            if (ramasser == 1) {
                                personnage.ajouterObjet(std::move(objet));
                                cout << "Objet ajouté dans l'inventaire." << endl;
                            } else {
                                cout << "Vous avez décidé de ne pas ramasser l'objet." << endl;
                            }
                        }
                        break;
                    }
                }
                afficherStats(personnage);
                break;
            case 3:
                exportSaveFile(personnage);
                return 0;
            default:
                std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
                break;
        }

        if (personnage.getPointsDeVie() == 0) {
            cout << "Vous n'avez plus de PV. Fin du jeu." << endl;
            return 0;
        }
    }

    return 0;
}