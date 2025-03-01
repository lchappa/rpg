#include "personnage.h"
#include "utils.h"

/**
 * \file personnage.cpp
 * \brief Implémentation de la classe Personnage.
 */

Personnage::Personnage() {
    generateStats(*this);
}

void Personnage::attaquerPersonnage(Personnage& cible) {
    int dmg = attaque + bonusAttaque - cible.getDefense() - cible.getBonusDefense();
    dmg > 0 ? cible.setPointsDeVie(cible.getPointsDeVie() - dmg) : cible.setPointsDeVie(cible.getPointsDeVie());
    std::cout << "L'attaque a infligé " << dmg << " points de dégâts." << std::endl;
}

void Personnage::equiperArme(Arme& arme) {
    if(&arme != armeEquipee) {
        armeEquipee = &arme;
        setBonusAttaque(arme.getBonusAttaque());
        std::cout << "Arme équipée." << std::endl;
    } else {
        std::cout << "Arme déjà équipée." << std::endl;
    }
}

void Personnage::equiperArmure(Armure& armure) {
    if(&armure != armureEquipee) {
        armureEquipee = &armure;
        setBonusDefense(armure.getBonusDefense());
        std::cout << "Armure équipée." << std::endl;
    } else {
        std::cout << "Armure déjà équipée." << std::endl;
    }
}

void Personnage::utiliserPotion(Potion& potion) {
    getPointsDeVie() + potion.getPVrendus() > PVmax ? setPointsDeVie(PVmax) : setPointsDeVie(getPointsDeVie() + potion.getPVrendus());
}

void Personnage::setPointsDeVie(int pointsDeVie) {
    this->pointsDeVie = pointsDeVie;
}

void Personnage::setAttaque(int attaque) {
    this->attaque = attaque;
}

void Personnage::setDefense(int defense) {
    this->defense = defense;
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