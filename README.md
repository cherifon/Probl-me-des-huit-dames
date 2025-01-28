# Problème des n-reines

## Objectif

Le problème des n-reines est un problème d'optimisation combinatoire dont l'énoncé est le suivant : placer n reines sur un échiquier de taille n×n de telle sorte qu'aucune reine ne puisse en menacer une autre. Autrement dit, deux reines ne doivent pas se trouver sur la même ligne, la même colonne ou la même diagonale.

## Exemple

Pour n = 4, une solution possible est la suivante :

```console
| | |X| |
|X| | | |
| | | |X|
| |X| | |
```

## Implémentation

L'objectif de ce projet est d'implémenter une fonction qui renvoie toutes les solutions possibles au problème des n-reines pour une taille donnée n. Pour ce faire, 
on utilise un algorithme de backtracking.

```console
Backtrack(x)
    if x is not a solution
        return false
    if x is a new solution
        add to list of solutions
    backtrack(expand x)
```
