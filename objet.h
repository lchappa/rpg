#ifndef OBJET_H
#define OBJET_H

#include <string>

/**
 * \file Objet.h
 * \brief Déclaration de la classe Objet.
 */

/**
 * \class Objet
 * \brief Classe représentant un objet.
 */
class Objet {
    private:
        /**
         * \brief Type de l'objet : Potion, Arme ou Armure.
         * \see getType()
         */
        std::string type;
        /**
         * \brief Valeur de l'objet : Points de vie rendus si Potion, Bonus d'attaque si Arme ou Bonus de défense si Armure.
         * \see getValeur()
         */
        int valeur;


    public:
        /**
         * \brief Constructeur de la classe Objet.
         */
        Objet();
        /**
         * \brief Destructeur de la classe Objet.
         */
        ~Objet();
        /**
         * \brief Getter pour le type de l'objet.
         */
        std::string getType();
        /**
         * \brief Getter pour la valeur de l'objet.
         */
        int getValeur();
};

#endif