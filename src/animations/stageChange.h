/// @file stageChange.h
/// @brief Déclaration de la classe StageChange pour la gestion des changements de stage.
///
/// La classe StageChange hérite de la classe Onomatope et permet d'afficher un texte indiquant
/// le changement de stage à l'écran pendant une durée déterminée. Elle gère les propriétés du texte
/// telles que le contenu, la couleur, la position, la durée d'affichage, et la taille. Elle fournit
/// également des méthodes pour dessiner le texte à l'écran et mettre à jour son état en fonction du
/// temps écoulé.

#pragma once
#include "onomatope.h"

/// @brief gére un texte qui s'affiche à l'écran pendant un certain temps pour indiquer le changement de stage. <br/>
/// La classe StageChange hérite de la classe Onomatope et permet d'afficher un texte indiquant
/// le changement de stage à l'écran pendant une durée déterminée. Elle gère les propriétés du texte
/// telles que le contenu, la couleur, la position, la durée d'affichage, et la taille. Elle fournit
/// également des méthodes pour dessiner le texte à l'écran et mettre à jour son état en fonction du
/// temps écoulé.
class StageChange : public Onomatope
{
public:
    /// @brief Constructeur de StageChange
    /// @param stage numéro du stage
    StageChange(int stage);

    bool update(float dt) override;

    /// @brief ~StageChange est le destructeur par default de StageChange
    ~StageChange() = default;

private:
    /// @brief convertit un nombre en chiffres romains
    /// @param n nombre à convertir
    std::string toRoman(int n);
};
