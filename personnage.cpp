#include "personnage.h"

/**
 * \file personnage.cpp
 * \brief Implémentation de la classe Personnage.
 */

Personnage::Personnage() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 3);

    for (auto& slot : inventaire) {
        int randomValue = dist(gen);
        switch (randomValue) {
            case 0:
                slot = std::make_unique<Arme>();
                break;
            case 1:
                slot = std::make_unique<Armure>();
                break;
            case 2:
                slot = std::make_unique<Potion>();
                break;
            case 3:
                slot = nullptr;
                break;
        }
    }
}

void Personnage::attaquerPersonnage(Personnage& cible) {
    cible.setPointsDeVie(cible.getPointsDeVie() - getAttaque());
}

void Personnage::equiperArme(Arme& arme) {
    if(&arme != armeEquipee) {
        armeEquipee = &arme;
        setBonusAttaque(arme.getBonusAttaque());
    }
}

void Personnage::equiperArmure(Armure& armure) {
    if(&armure != armureEquipee) {
        armureEquipee = &armure;
        setBonusDefense(armure.getBonusDefense());
    }
}

void Personnage::utiliserPotion(Potion& potion) {
    getPointsDeVie() + potion.getPVrendus() > PVmax ? setPointsDeVie(PVmax) : setPointsDeVie(getPointsDeVie() + potion.getPVrendus());
}

void Personnage::setPointsDeVie(int pointsDeVie) {
    this->pointsDeVie = pointsDeVie;
}

void Personnage::setBonusAttaque(int bonusAttaque) {
    this->bonusAttaque = bonusAttaque;
}

void Personnage::setBonusDefense(int bonusDefense) {
    this->bonusDefense = bonusDefense;
}

int Personnage::getPointsDeVie() {
    return pointsDeVie;
}

int Personnage::getAttaque() {
    return attaque;
}

int Personnage::getDefense() {
    return defense;
}

int Personnage::getBonusAttaque() {
    return bonusAttaque;
}

int Personnage::getBonusDefense() {
    return bonusDefense;
}

std::array<std::unique_ptr<Objet>, 10>& Personnage::getInventaire() {
    return inventaire;
}