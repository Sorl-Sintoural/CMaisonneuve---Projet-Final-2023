---
marp: true
paginate : false
---
<!-- color : black -->
<!-- backgroundColor : purple -->

# CMaisonneuve---Projet-Final-2023 : Cible et moniteur de pointage  

## Participants

- Olivier De Thomasis
- Louis Tran

---

## Contexte et objectifs

Une solution permettant aux utilisateurs compétitifs et récréatifs de pratiquer leurs tirs.  

L'objectif du projet est d'offrir une nouvelle façon de connaitre les résultats des tirs sur le coup avec le moins de délai et d'erreurs possible. On veut 
enlever toute possibilité d'erreur humaine et de triche.  

---

![Arbitre payé](./Medias/arbitre_payé.png)

---

## Description du produit développé

Le produit développé est un système électronique composé de deux modules.  

Les deux modules comportent un microcontrôleur qui traite les données et contrôle les périphériques connectés, et une carte de communication sans-fil pour envoyer l'information entre les deux modules

Le module de cible capte les tirs à l'aide des capteurs de vibration et calcul le point du tir selon le niveau choisis pour l'envoyer sans-fil au module moniteur.

Le module du moniteur contient un microcontrôleur capable de traiter rapidement les données reçu sans-fil et d'afficher à l'aide de cinq DELs et un écran le nombre de tir restant et le pointage.

---

### Schémas bloc
![Schémas Bloc](./Medias/Schemas%20Bloc.png)

---

## Résultats et conclusion

- Une démonstration fonctionnel du produit a été réalisé. Il intègre l’électronique et le programme embarqué.
- Le système est capable de détecter les tirs sur les différents cibles (base, petites, grandes), d'envoyer les données et de réagir en fonction.

*Ajouter une photo du produit réaliser ou de la carte électronique* **(obligatoire)**

---

## Logiciels utilisés

- [MPLAB X IDE](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
- [EasyEDA](https://easyeda.com/)
- [Tinkercad](https://www.tinkercad.com/)

---

## Mots clés

- Capteur de vibration (interrupteur) à DEL
- Microcontrôleur
- SPI & I<sup>2</sup>C
- Communication sans-fil

---

## Liens

- [Boitier module cible](https://www.tinkercad.com/things/dE0z3pwDIlJ) *sur Tinkercad*
- [Boitier module moniteur](https://www.tinkercad.com/things/a5hYljk0EOl) *sur Tinkercad*
- [Module cible circuit imprimé](https://oshwlab.com/pjt_end_2023/cible_2023) *sur Open Source Hardware Lab*
- [Module moniteur circuit imprimé](https://oshwlab.com/pjt_end_2023/moniteur_2023) *sur Open Source Hardware Lab*
- [Programmes embarqué](https://github.com/Sorl-Sintoural/CMaisonneuve---Projet-Final-2023.git) *sur Github*

---