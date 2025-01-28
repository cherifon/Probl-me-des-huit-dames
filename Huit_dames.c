// Created by: Cherif Jebali

#include <stdio.h>
#define N 8 //nombre de reines

/*Sur un échiquier, on cherche à placer des reines de telle sorte qu’elles ne soient pas en position de se prendre.
Les reines peuvent se déplacer horizontalement, verticalement ou en diagonale, d’autant de cases qu’elles le souhaitent.
On dit qu’une reine en prend une autre si cette dernière se retrouve sur le chemin de la première.*/

//On va résoudre ce problème en utilisant un algorithme de backtracking.
//Backtrack(x)
    //if x is not a solution
        //return false
    //if x is a new solution
        //add to list of solutions
    //backtrack(expand x) (expand x means generate all possible solutions from x)

int afficherEchiquer(int echiquier[N][N]) // fonction pour afficher l'échiquier
{
    int i,j;
    for(i=0;i<N;i++) 
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",echiquier[i][j]); //on affiche l'échiquier
        }
        printf("\n");
    }
    printf("\n");
}

int verif(int echiquier[N][N],int x,int y) //fonction pour vérifier si on peut placer une reine

/*Cette fonction vérifie si on peut placer une reine à la position x,y de l'échiquier.
On vérifie si il n'y a pas de reine sur la colonne, la diagonale haute gauche et la diagonale basse gauche.
On ne vérifie pas la ligne car on place une reine par colonne.
Les diagonales hautes droites et basses droites ne sont pas à vérifier car on place les reines de gauche à droite.*/

{
    int i,j;
    
    for (i = 0; i < y; i++) //on vérifie la colonne
    {
        if (echiquier[x][i] != 0) //si on trouve une reine
        {
            return 0;
        }
    }
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--) //on vérifie la diagonale haute gauche
    {
        if (echiquier[i][j] != 0)
        {
            return 0;
        }
    }
    for (i = x, j = y; j >= 0 && i < N; i++, j--) //on vérifie la digonale basse gauche
    {
        if (echiquier[i][j] != 0)
        {
            return 0;
        }
    }
    return 1;
}

int c = 0; //compteur pour le nombre de solutions

int placerReine(int echiquier[N][N], int y) //fonction pour placer les reines
{
    int i; //indice de la ligne
    
    if (y == N) //si on a placé N reines, on a trouvé une solution
    {
        c++; 
        printf("Solution numero : %d\n", c); 
        afficherEchiquer(echiquier); //on affiche l'échiquier
    }
    for (i = 0; i < N; i++) //on parcourt les lignes
    {
        if (verif(echiquier, i, y) != 0) //si on peut placer une reine
        {
            echiquier[i][y] = 1; //on la place
            if (placerReine(echiquier, y + 1) != 0) //on passe à la colonne suivante: c'est notre appel récursif
            {
                
                return 1; 
            }
            else 
            {
                echiquier[i][y] = 0; //on enlève la reine, c'est ici qu'est effectué le backtracking
            }
        }
    }
    return 0;
}



void main()
{
    int echiquier[N][N] = {0};
    placerReine(echiquier,0);
}
