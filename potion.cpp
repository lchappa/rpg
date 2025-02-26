#include "potion.h"

/**
 * \file potion.cpp
 * \brief Implémentation de la classe Potion.
 */

/**
 * \brief Constructeur de la classe Potion.
 * Initialise les points de vie rendus par la potion à 30.
 */
Potion::Potion() {
    PVrendus = 30;
}

/**
 * \brief Récupère le nombre de points de vie rendus par la potion.
 * \return Le nombre points de vie rendus par la potion.
 */
int Potion::getPVrendus() {
    return PVrendus;
}