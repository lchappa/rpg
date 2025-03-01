#include "ennemi.h"
#include "utils.h"

/**
 * \file ennemi.cpp
 * \brief Implémentation de la classe Ennemi.
 */

Ennemi::Ennemi() {
    generateInventory(this->inventaire);

    Arme* bestArme = nullptr;
    Armure* bestArmure = nullptr;
    int highestBonusAttaque = 0;
    int highestBonusDefense = 0;

    for (const auto& slot : getInventaire()) {
        if (slot) {
            if (slot->getType() == "Arme") {
                Arme* arme = static_cast<Arme*>(slot.get());
                if (arme->getBonusAttaque() > highestBonusAttaque) {
                    highestBonusAttaque = arme->getBonusAttaque();
                    bestArme = arme;
                }
            } else if (slot->getType() == "Armure") {
                Armure* armure = static_cast<Armure*>(slot.get());
                if (armure->getBonusDefense() > highestBonusDefense) {
                    highestBonusDefense = armure->getBonusDefense();
                    bestArmure = armure;
                }
            }
        }
    }

    if (bestArme) {
        equiperArme(*bestArme);
    }
    if (bestArmure) {
        equiperArmure(*bestArmure);
    }
}