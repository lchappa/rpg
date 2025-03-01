#ifndef ARME_H
#define ARME_H

#include "objet.h"

/**
 * \file arme.h
 * \brief Déclaration de la classe Arme.
 */

/**
 * \class Arme
 * \brief Classe représentant un objet de type Arme.
 */
class Arme : public Objet {
    private:
        int bonusAttaque;
    public:
        Arme();
        int getBonusAttaque();
        void setBonusAttaque(int bonusAttaque);
        std::string getType() const override { return "Arme"; }
};



#endif