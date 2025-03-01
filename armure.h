#ifndef ARMURE_H
#define ARMURE_H

#include "objet.h"

/**
 * \file armure.h
 * \brief Déclaration de la classe Armure.
 */

/**
 * \class Armure
 * \brief Classe représentant un objet de type Armure.
 */
class Armure : public Objet {
    private:
        int bonusDefense;
    public:
        Armure();
        int getBonusDefense();
        void setBonusDefense(int bonusDefense);
        std::string getType() const override { return "Armure"; }
};

#endif