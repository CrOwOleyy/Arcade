# Arcade Platform

Une plateforme de divertissement modulaire et performante permettant de jouer à une variété de jeux classiques à travers différents moteurs graphiques. Conçu pour la flexibilité et l'extensibilité, l'Arcade Platform utilise le chargement dynamique de modules pour offrir une expérience de jeu fluide et personnalisable.

## Contributeurs & Contact
Pour toute question ou collaboration concernant l'interface et le cœur du projet, vous pouvez contacter l'équipe de développement :
- **Ryad Younes :** ryad.younes@epitech.eu
- **Katia Pontre :** katia.pontre@epitech.eu
- **Julien Leiner :** julien.leiner@epitech.eu

---

## Sommaire
1. [Fonctionnalités](#fonctionnalités)
2. [Installation](#installation)
3. [Utilisation](#utilisation)
4. [Architecture Technique](#architecture-technique)
5. [Contrôles](#contrôles)
6. [Extension de la Plateforme](#extension-de-la-plateforme)

---

## Fonctionnalités
- **Multi-Affichage** : Support natif pour Ncurses (terminal), SFML et SDL2.
- **Switch à Chaud** : Changez de moteur graphique en pleine partie sans perdre votre progression.
- **Jeux Classiques** : Inclus nativement avec Snake et Minesweeper.
- **Gestion des Scores** : Système persistant de suivi des meilleurs scores par jeu.
- **Audio Immersif** : Support complet pour les effets sonores (SFX) et la musique de fond.

---

## Installation

Le projet se compile à l'aide de l'outil `make`. Assurez-vous d'avoir les dépendances (SDL2, SFML, Ncurses) installées sur votre système.

```bash
# Compiler l'intégralité de la plateforme et des modules
make
```

### Commandes de build
- `make core` : Compile l'exécutable principal.
- `make games` : Compile les modules de jeux.
- `make graphicals` : Compile les modules d'affichage.
- `make clean` / `make fclean` : Nettoie les fichiers temporaires et les binaires.

---

## Utilisation

Pour lancer la plateforme, exécutez le binaire principal en spécifiant la bibliothèque graphique de démarrage :

```bash
./arcade ./lib/arcade_x.so # A choisir entre arcade_ncurses.so, arcade_sfml.so, arcade_sdl2.so  
```

Naviguez dans le catalogue de jeux, gérez vos scores et profitez de l'expérience Arcade.

---

## Architecture Technique

L'Arcade Platform repose sur une architecture découplée en trois couches :

### 1. Le Core Engine
Le cerveau du système. Il gère le cycle de vie des modules, la file d'attente des événements utilisateurs et la synchronisation entre la logique de jeu et le rendu graphique.

### 2. Moteurs de Rendu (`IDisplay`)
Des modules interchangeables qui traduisent l'état du jeu en visuels. Que vous préfériez la simplicité du terminal (Ncurses) ou la puissance de la 2D (SDL2/SFML), la plateforme s'adapte instantanément.

### 3. Modules de Jeux (`IGame`)
Toute la logique de jeu est encapsulée dans des bibliothèques partagées. Cette isolation garantit qu'un bug dans un jeu ne fera pas planter la plateforme entière.

---

## Contrôles

### Menu Principal
- **Flèches / ZS** : Navigation.
- **Entrée / E** : Valider / Lancer.
- **L** : Alterner entre les moteurs graphiques.
- **H** : Mode Challenge (Hardcore).
- **Échap** : Quitter.

### En Jeu
- **Flèches / ZSQD** : Contrôles directionnels.
- **P** : Menu Pause.
- **M** : Silence / Musique.
- **L** : Changer de rendu graphique en direct.
- **Échap** : Quitter la session.

---

## Extension de la Plateforme

L'Arcade Platform est conçue pour être étendue. Pour ajouter un nouveau jeu ou un nouveau moteur graphique, il suffit de créer une bibliothèque partagée (`.so`) implémentant l'interface correspondante et de la placer dans le dossier `lib/`. La plateforme la détectera automatiquement au prochain lancement.

---

*© 2026 Geekos Society / Pepepak*
