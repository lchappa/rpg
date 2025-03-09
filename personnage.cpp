/**
 * \file personnage.cpp
 * \brief Implémentation de la classe Personnage.
 */

#include "personnage.h"
#include "utils.h"

/**
 * \brief Constructeur de la classe Personnage.
 * Initialise les statistiques du personnage en appelant la fonction generateStats.
 */
Personnage::Personnage() {
    generateStats(*this);
}

/**
 * \brief Attaque un autre personnage.
 * \param cible Référence vers le personnage cible.
 * Calcule les dégâts en fonction de l'attaque et de la défense des personnages, et réduit les points de vie de la cible.
 */
void Personnage::attaquerPersonnage(Personnage& cible) {
    int dmg = attaque + bonusAttaque - cible.getDefense() - cible.getBonusDefense();
    dmg > 0 ? cible.setPointsDeVie(cible.getPointsDeVie() - dmg) : cible.setPointsDeVie(cible.getPointsDeVie());
    std::cout << "L'attaque a infligé " << dmg << " points de dégâts." << std::endl;
}

/**
 * \brief Équipe une arme.
 * \param arme Référence vers l'arme à équiper.
 * Met à jour le bonus d'attaque du personnage.
 */
void Personnage::equiperArme(Arme& arme) {
    if (&arme != armeEquipee) {
        armeEquipee = &arme;
        setBonusAttaque(arme.getBonusAttaque());
        if (dynamic_cast<Ennemi*>(this) == nullptr) {
            std::cout << "Arme équipée." << std::endl;
        }
    } else {
        if (dynamic_cast<Ennemi*>(this) == nullptr) {
            std::cout << "Arme déjà équipée." << std::endl;
        }
    }
}

/**
 * \brief Équipe une armure.
 * \param armure Référence vers l'armure à équiper.
 * Met à jour le bonus de défense du personnage.
 */
void Personnage::equiperArmure(Armure& armure) {
    if (&armure != armureEquipee) {
        armureEquipee = &armure;
        setBonusDefense(armure.getBonusDefense());
        if (dynamic_cast<Ennemi*>(this) == nullptr) {
            std::cout << "Armure équipée." << std::endl;
        }
    } else {
        if (dynamic_cast<Ennemi*>(this) == nullptr) {
            std::cout << "Armure déjà équipée." << std::endl;
        }
    }
}

/**
 * \brief Utilise une potion.
 * \param potion Référence vers la potion à utiliser.
 * Augmente les points de vie du personnage en fonction des PV rendus par la potion.
 */
void Personnage::utiliserPotion(Potion& potion) {
    getPointsDeVie() + potion.getPVrendus() > PVmax ? setPointsDeVie(PVmax) : setPointsDeVie(getPointsDeVie() + potion.getPVrendus());
}

/**
 * \brief Définit les points de vie du personnage.
 * \param pointsDeVie Nombre de points de vie à définir.
 */
void Personnage::setPointsDeVie(int pointsDeVie) {
    this->pointsDeVie = pointsDeVie;
}

/**
 * \brief Définit l'attaque du personnage.
 * \param attaque Valeur de l'attaque à définir.
 */
void Personnage::setAttaque(int attaque) {
    this->attaque = attaque;
}

/**
 * \brief Définit la défense du personnage.
 * \param defense Valeur de la défense à définir.
 */
void Personnage::setDefense(int defense) {
    this->defense = defense;
}

/**
 * \brief Définit le bonus d'attaque du personnage.
 * \param bonusAttaque Valeur du bonus d'attaque à définir.
 */
void Personnage::setBonusAttaque(int bonusAttaque) {
    this->bonusAttaque = bonusAttaque;
}

/**
 * \brief Définit le bonus de défense du personnage.
 * \param bonusDefense Valeur du bonus de défense à définir.
 */
void Personnage::setBonusDefense(int bonusDefense) {
    this->bonusDefense = bonusDefense;
}

/**
 * \brief Obtient les points de vie du personnage.
 * \return Nombre de points de vie du personnage.
 */
int Personnage::getPointsDeVie() {
    return pointsDeVie;
}

/**
 * \brief Obtient l'attaque du personnage.
 * \return Valeur de l'attaque du personnage.
 */
int Personnage::getAttaque() {
    return attaque;
}

/**
 * \brief Obtient la défense du personnage.
 * \return Valeur de la défense du personnage.
 */
int Personnage::getDefense() {
    return defense;
}

/**
 * \brief Obtient le bonus d'attaque du personnage.
 * \return Valeur du bonus d'attaque du personnage.
 */
int Personnage::getBonusAttaque() {
    return bonusAttaque;
}

/**
 * \brief Obtient le bonus de défense du personnage.
 * \return Valeur du bonus de défense du personnage.
 */
int Personnage::getBonusDefense() {
    return bonusDefense;
}

/**
 * \brief Obtient l'inventaire du personnage.
 * \return Référence vers le tableau d'objets uniques représentant l'inventaire du personnage.
 */
std::array<std::unique_ptr<Objet>, 10>& Personnage::getInventaire() {
    return inventaire;
}

/**
 * \brief Ajoute un objet à l'inventaire du personnage.
 * \param objet Pointeur unique vers l'objet à ajouter.
 * \return true si l'objet a été ajouté, false sinon.
 */
void Personnage::ajouterObjet(std::unique_ptr<Objet> objet) {
    for (auto &slot : inventaire) {
        if (slot == nullptr) {
            slot = std::move(objet);
            std::cout << "Objet ajouté à l'inventaire." << std::endl;
        }
    }
    std::cout << "Inventaire plein, impossible d'ajouter l'objet." << std::endl;
}

/**
 * \brief Vérifie si l'inventaire du personnage est plein.
 * \return true si l'inventaire est plein, false sinon.
 */
bool Personnage::inventairePlein() {
    for (const auto &slot : inventaire) {
        if (slot == nullptr) {
            return false;
        }
    }
    return true;
}