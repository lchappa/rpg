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