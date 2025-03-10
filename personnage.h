#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>
#include <array>
#include <memory>
#include <random>
#include "objet.h"
#include "arme.h"
#include "armure.h"
#include "potion.h"

/**
 * \file Personnage.h
 * \brief Déclaration de la classe Personnage.
 */

/**
 * \class Personnage
 * \brief Classe représentant un personnage.
 */

class Personnage {
    protected:
        int PVmax;
        int pointsDeVie;
        int attaque;
        int defense;
        int bonusAttaque;
        int bonusDefense;
        Arme* armeEquipee = nullptr;
        Armure* armureEquipee = nullptr;
        std::array<std::unique_ptr<Objet>, 10> inventaire;

    public:
        Personnage();
        virtual ~Personnage() {}
        void attaquerPersonnage(Personnage& cible);
        void equiperArme(Arme& arme);
        void equiperArmure(Armure& armure);
        void utiliserPotion(Potion& potion);
        void setPointsDeVie(int pointsDeVie);
        void setAttaque(int attaque);
        void setDefense(int defense);
        void setBonusAttaque(int bonusAttaque);
        void setBonusDefense(int bonusDefense);
        void ajouterObjet(std::unique_ptr<Objet> objet);
        bool inventairePlein();
        int getPointsDeVie();
        int getAttaque();
        int getDefense();
        int getBonusAttaque();
        int getBonusDefense();
        std::array<std::unique_ptr<Objet>, 10>& getInventaire();
};


#endif