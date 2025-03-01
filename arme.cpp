#include "arme.h"
#include "utils.h"

/**
 * \file arme.cpp
 * \brief Implémentation de la classe Arme.
 */

/**
 * \brief Constructeur de la classe Arme.
 * Initialise le bonus d'attaque de l'arme à une valeur aléatoire.
 * \see generateRandomValue()
 */
Arme::Arme() {
    bonusAttaque = generateRandomValue();
}

/**
 * \brief Récupère le bonus d'attaque de l'arme.
 * \return Le bonus d'attaque de l'arme.
 */
int Arme::getBonusAttaque() {
    return bonusAttaque;
}

/**
 * \brief Modifie le bonus d'attaque de l'arme.
 * \param bonusAttaque Le nouveau bonus d'attaque de l'arme.
 */
void Arme::setBonusAttaque(int bonusAttaque) {
    this->bonusAttaque = bonusAttaque;
}