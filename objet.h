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
 * 
 * La classe Objet est une classe de base abstraite pour tous les objets du jeu.
 * Elle définit une interface commune pour obtenir le type de l'objet.
 */
class Objet {
    public:
        /**
         * \brief Destructeur virtuel par défaut.
         */
        virtual ~Objet() = default;

        /**
         * \brief Récupère le type de l'objet.
         * \return Une chaîne de caractères représentant le type de l'objet.
         */
        virtual std::string getType() const = 0;
};

#endif