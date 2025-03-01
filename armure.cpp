#include "armure.h"
#include "utils.h"

/**
 * \file armure.cpp
 * \brief Implémentation de la classe Armure.
 */

/**
 * \brief Constructeur de la classe Armure.
 * Initialise le bonus de défense de l'armure à une valeur aléatoire.
 * \see generateRandomValue()
 */
Armure::Armure() {
    bonusDefense = generateRandomValue();
}

/**
 * \brief Récupère le bonus de défense de l'armure.
 * \return Le bonus de défense de l'armure.
 */
int Armure::getBonusDefense() {
    return bonusDefense;
}

/**
 * \brief Modifie le bonus de défense de l'armure.
 * \param bonusDefense Le nouveau bonus de défense de l'armure.
 */
void Armure::setBonusDefense(int bonusDefense) {
    this->bonusDefense = bonusDefense;
}