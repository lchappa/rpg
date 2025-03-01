#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <array>
#include <memory>
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "personnage.h"
#include "arme.h"
#include "armure.h"
#include "potion.h"


/**
 * \file utils.h
 * \brief Librairie contenant des fonctions utilitaires.
 */

/**
 * \brief Génère une valeur aléatoire avec des paliers de probabilités : 
 * 65% de probabilité que la valeur soit entre 1 et 30,
 * 25% de probabilité que la valeur soit entre 31 et 40,
 * 10% de probabilité que la valeur soit entre 41 et 50.
 * \return Une valeur aléatoire.
 */
inline int generateRandomValue() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> range_dist({65, 25, 10});

    int range = range_dist(gen);

    switch(range) {
        case 0:
            return std::uniform_int_distribution<>(1, 30)(gen);
        case 1:
            return std::uniform_int_distribution<>(31, 40)(gen);
        case 2:
            return std::uniform_int_distribution<>(41, 50)(gen);
        default:
            return 0;
    }
}

/**
 * \brief Génère un inventaire avec des objets aléatoires. Chaque type d'objet a une probabilité de 25% d'apparaître, et 25% de chance d'avoir un emplacement vide.
 * \param inventaire Référence à un tableau d'objets uniques à remplir.
 */
inline void generateInventory(std::array<std::unique_ptr<Objet>, 10>& inventaire) {
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

/**
 * \brief Génère un objet aléatoire (Arme, Armure, ou Potion).
 * \return Un pointeur unique vers l'objet généré.
 */
inline std::unique_ptr<Objet> generateObjet() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 2);
    int randomValue = dist(gen);
    switch (randomValue) {
        case 0:
            return std::make_unique<Arme>();
        case 1:
            return std::make_unique<Armure>();
        case 2:
            return std::make_unique<Potion>();
    }
}

inline void afficherInventaire(Personnage& personnage) {
    auto& inventaire = personnage.getInventaire();
    for (size_t i = 0; i < inventaire.size(); ++i) {
        auto& objet = inventaire[i];
        std::cout << "Slot " << i << ": ";
        if (objet != nullptr) {
            std::cout << objet->getType();
            std::cout << (objet->getType() == "Arme" ? " (" + std::to_string(static_cast<Arme*>(objet.get())->getBonusAttaque()) + ")" :
                    objet->getType() == "Armure" ? " (" + std::to_string(static_cast<Armure*>(objet.get())->getBonusDefense()) + ")" : "");
            std::cout << std::endl;
        } else {
            std::cout << "Emplacement vide" << std::endl;
        }
    }
}

/**
 * \brief Génère des statistiques aléatoires pour un personnage.
 * \param personnage Référence à un objet Personnage dont les statistiques doivent être générées.
 */
inline void generateStats(Personnage& personnage) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist_HP(100, 150);
    std::uniform_int_distribution<> dist_atk(1, 15);
    std::uniform_int_distribution<> dist_def(1, 15);

    personnage.setPointsDeVie(dist_HP(gen));
    personnage.setAttaque(dist_atk(gen));
    personnage.setDefense(dist_def(gen));
}

/**
 * \brief Affiche les statistiques et l'inventaire d'un personnage.
 * \param joueur Référence à un objet Personnage dont les statistiques et l'inventaire doivent être affichés.
 */
inline void afficherStats(Personnage& personnage) {
    std::cout << "Stats du personnage : " << std::endl;
    std::cout << "PV : " << personnage.getPointsDeVie();
    std::cout << " Attaque : " << personnage.getAttaque() << " + " << personnage.getBonusAttaque();
    std::cout << " Défense : " << personnage.getDefense() << " + " << personnage.getBonusDefense() << std::endl;
    std::cout << "Inventaire : " << std::endl;
    afficherInventaire(personnage);
}

inline void afficherMenuIdle() {
    std::cout << "---------------------------- Menu : ----------------------------" << std::endl;
    std::cout << "1. Prochaine rencontre" << std::endl;
    std::cout << "2. Afficher inventaire" << std::endl;
    std::cout << "3. Sauvegarder et quitter" << std::endl;
}

inline void loadSaveFile(Personnage& personnage, const std::string& saveFileName) {
    std::ifstream saveFile(saveFileName);
    if (saveFile.is_open()) {
        std::string line;
        while (std::getline(saveFile, line)) {
            std::istringstream iss(line);
            std::string key;
            if (std::getline(iss, key, ',')) {
                std::string value;
                if (std::getline(iss, value)) {
                    try {
                        if (key == "PVmax") {
                            personnage.setPointsDeVie(std::stoi(value));
                        } else if (key == "Attaque") {
                            personnage.setAttaque(std::stoi(value));
                        } else if (key == "BonusAttaque") {
                            personnage.setBonusAttaque(std::stoi(value));
                        } else if (key == "Defense") {
                            personnage.setDefense(std::stoi(value));
                        } else if (key == "BonusDefense") {
                            personnage.setBonusDefense(std::stoi(value));
                        } else if (key.find("Slot") != std::string::npos) {
                            size_t slotIndex = std::stoi(key.substr(5));
                            if (slotIndex < personnage.getInventaire().size()) {
                                if (value.find("Arme") != std::string::npos) {
                                    auto arme = std::make_unique<Arme>();
                                    size_t pos = value.find("(");
                                    if (pos != std::string::npos) {
                                        arme->setBonusAttaque(std::stoi(value.substr(pos + 1, value.find(")") - pos - 1)));
                                    }
                                    personnage.getInventaire()[slotIndex] = std::move(arme);
                                } else if (value.find("Armure") != std::string::npos) {
                                    auto armure = std::make_unique<Armure>();
                                    size_t pos = value.find("(");
                                    if (pos != std::string::npos) {
                                        armure->setBonusDefense(std::stoi(value.substr(pos + 1, value.find(")") - pos - 1)));
                                    }
                                    personnage.getInventaire()[slotIndex] = std::move(armure);
                                } else if (value.find("Potion") != std::string::npos) {
                                    personnage.getInventaire()[slotIndex] = std::make_unique<Potion>();
                                }
                            } else {
                                std::cerr << "Index de slot invalide: " << slotIndex << std::endl;
                            }
                        }
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Erreur de conversion: " << e.what() << std::endl;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Valeur hors de portée: " << e.what() << std::endl;
                    }
                }
            }
        }
        saveFile.close();
        std::cout << "Chargement réussi depuis le fichier " << saveFileName << std::endl;
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier de sauvegarde." << std::endl;
    }
}

/**
 * \brief Vérifie s'il existe des fichiers de sauvegarde avec l'extension .txt et demande à l'utilisateur s'il souhaite en charger un ou commencer sans sauvegarde.
 */
inline void checkForSave(Personnage& personnage) {
    std::vector<std::string> saveFiles;

    for (auto& entry : std::filesystem::directory_iterator(".")) {
        if (entry.path().extension() == ".txt") {
            saveFiles.push_back(entry.path().string());
        }
    }

    if (!saveFiles.empty()) {
        std::cout << "Des fichiers de sauvegarde ont été trouvés. Voulez-vous en charger un ? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            std::cout << "Choisissez un fichier de sauvegarde à charger :" << std::endl;
            for (size_t i = 0; i < saveFiles.size(); ++i) {
                std::cout << i + 1 << ". " << saveFiles[i] << std::endl;
            }
            size_t fileChoice;
            std::cin >> fileChoice;
            if (fileChoice > 0 && fileChoice <= saveFiles.size()) {
                std::cout << "Chargement de la sauvegarde " << saveFiles[fileChoice - 1] << "..." << std::endl;
                loadSaveFile(personnage, saveFiles[fileChoice - 1]);
            } else {
                std::cout << "Choix invalide. Aucune sauvegarde n'a été chargée" << std::endl;
            }
        } else {
            std::cout << "Commencer sans sauvegarde." << std::endl;
        }
    } else {
        std::cout << "Aucun fichier de sauvegarde trouvé. Commencer sans sauvegarde." << std::endl;
    }
}

inline void exportSaveFile(Personnage& personnage) {
    std::string saveFileName;
    while (true) {
        std::cout << "Entrez le nom du fichier de sauvegarde : ";
        std::cin >> saveFileName;
        saveFileName += ".txt";

        if (std::filesystem::exists(saveFileName)) {
            std::cout << "Le fichier existe déjà. Voulez-vous l'écraser ? (y/n): ";
            char choice;
            std::cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                break;
            } else {
                std::cout << "Veuillez entrer un nouveau nom de fichier." << std::endl;
            }
        } else {
            break;
        }
    }

    std::ofstream saveFile(saveFileName);
    if (saveFile.is_open()) {
        saveFile << "PVmax," << personnage.getPointsDeVie() << "\n";
        saveFile << "Attaque," << personnage.getAttaque() << "\n";
        saveFile << "BonusAttaque," << personnage.getBonusAttaque() << "\n";
        saveFile << "Defense," << personnage.getDefense() << "\n";
        saveFile << "BonusDefense," << personnage.getBonusDefense() << "\n";
        saveFile << "Inventaire\n";
        auto& inventaire = personnage.getInventaire();
        for (size_t i = 0; i < inventaire.size(); ++i) {
            auto& objet = inventaire[i];
            saveFile << "Slot " << i << ",";
            if (objet != nullptr) {
                saveFile << objet->getType();
                if (objet->getType() == "Arme") {
                    saveFile << " (" << static_cast<Arme*>(objet.get())->getBonusAttaque() << ")";
                } else if (objet->getType() == "Armure") {
                    saveFile << " (" << static_cast<Armure*>(objet.get())->getBonusDefense() << ")";
                }
            } else {
                saveFile << "Emplacement vide";
            }
            saveFile << "\n";
        }
        saveFile.close();
        std::cout << "Sauvegarde réussie dans le fichier " << saveFileName << std::endl;
    } else {
        std::cerr << "Erreur lors de l'ouverture du fichier de sauvegarde." << std::endl;
    }
}

#endif