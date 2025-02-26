#ifndef POTION_H
#define POTION_H

#include "objet.h"

/**
 * \file potion.h
 * \brief Déclaration de la classe Potion.
 */

/**
 * \class Potion
 * \brief Classe représentant un objet de type Potion.
 */
class Potion : public Objet {
    private:
        int PVrendus;
    public:
        Potion();
        int getPVrendus();
        std::string getType() const override { return "Potion"; }
};


#endif