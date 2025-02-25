#include "objet.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <random>

/**
 * \file Objet.cpp
 * \brief Implémentation de la classe Objet.
 */

/**
 * \brief Constructeur de la classe Objet.
 * Crée un objet avec un type et une valeur aléatoires.
 * Le type peut être "arme", "armure" ou "potion".
 * La valeur est un entier entre 10 et 50 pour les armes et armures, et 30 pour les potions.
 */
Objet::Objet() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<std::string> types = {"arme", "armure", "potion"};
    std::uniform_int_distribution<> dis(0, types.size() - 1);
    type = types[dis(gen)];
    
    if (this->type == "arme") {
        valeur = std::uniform_int_distribution<>(10, 50)(gen);
    } else if (this->type == "armure") {
        valeur = std::uniform_int_distribution<>(10, 50)(gen);
    } else if (this->type == "potion") {
        valeur = 30;
    }
}

/**
 * \brief Destructeur de la classe Objet.
 */
Objet::~Objet() {
}

/**
 * \brief Getter pour le type de l'objet.
 * \return Le type de l'objet.
 * \see type
 * \see Objet
 */
std::string Objet::getType() {
    return type;
}

/**
 * \brief Getter pour la valeur de l'objet.
 * \return La valeur de l'objet.
 * \see valeur
 * \see Objet
 */
int Objet::getValeur() {
    return valeur;
}