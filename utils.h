#ifndef UTILS_H
#define UTILS_H

#include <random>

/**
 * \file utils.h
 * \brief Librairie contenant des fonctions utilitaires.
 */

/**
 * \brief Génère une valeur aléatoire avec des paliers de probabilités : 
 * 65% de probabilité que la valeur soit entre 1 et 30,
 * 25% de probabilité que la valeur soit entre 31 et 40,
 * 10% de probabilité que la valeur soit entre 41 et 50.
 * \return Une valeur aléatoire.
 */
inline int generateRandomValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> range_dist({65, 25, 10});

    int range = range_dist(gen);

    switch(range) {
        case 0:
            return std::uniform_int_distribution<>(1, 30)(gen);
        case 1:
            return std::uniform_int_distribution<>(31, 40)(gen);
        case 2:
            return std::uniform_int_distribution<>(41, 50)(gen);
        default:
            return 0;
    }
}

#endif