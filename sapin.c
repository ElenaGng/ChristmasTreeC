#include <stdio.h>
#include <stdlib.h>

int	my_tailleBaseSapin(int blocMax)
{
  int blocCourant; //bloc actuel en evaluation
  int ligneCourante; //ligne actuelle en evaluation
  int ligneMax; //numero de lignes
  int tailleBaseSapin;//numero maximun de etoiles

  blocCourant = 1;
  ligneCourante = 1;
  tailleBaseSapin = 1; //la premiere ligne du premier bloc a 1 etoile
  ligneMax = 4; //le premier bloc a 4 lignes max

  while (blocCourant <= blocMax)
    {
      while (ligneCourante <= ligneMax)
	{
	  tailleBaseSapin = tailleBaseSapin + 2;
	  ligneCourante++;
	}
      ligneMax++;
      ligneCourante = 1;
      blocCourant++;
      tailleBaseSapin = tailleBaseSapin - blocCourant -(blocCourant%2);
          }
  return(tailleBaseSapin);
}

void	formationEtoile(int tailleBaseSapin, int blocMax)
{
  int blocCourant; //bloc actuel en evaluation
  int ligneCourante; //ligne actuelle en evaluation
  int ligneMax; //numero de lignes
  int positionDebutEtoile;
  int positionFinEtoile;
  int positionCourante; //le compteur fait pour le boucle while parcour toute la ligne jusqu'a le debut

  blocCourant = 1;
  ligneCourante = 1;
  ligneMax = 4; //le premier bloc a 4 lignes max
  positionDebutEtoile = (tailleBaseSapin + 1)/2; //initialiser la position du debut de etoile (le plus a gauche)
  positionFinEtoile = positionDebutEtoile; //initialiser la position de debut egale position final, parce qu'on a 1 seule *
  positionCourante = 0;  
  while (blocCourant <= blocMax)
    {
      while (ligneCourante <= ligneMax)
	{
	  while (positionCourante < positionDebutEtoile)
	    {
	      printf(" ");
	      positionCourante++;
	    }
	  while (positionCourante <= positionFinEtoile)
	    {
	      printf("*");
	      positionCourante++;
	    }
	  printf("\n");
	  ligneCourante++;
	  positionDebutEtoile--;
	  positionFinEtoile++;
	  positionCourante = 0;
	}
      ligneCourante = 1; //initialiser la ligne courante    
      ligneMax++; //le bloc suivant a toujours une ligne en plus du bloc precedent
      blocCourant++;
      
      positionDebutEtoile = positionDebutEtoile + 1 + ((blocCourant - blocCourant%2)/2);
      positionFinEtoile = positionFinEtoile - 1 - ((blocCourant - blocCourant%2)/2);
    }  
}


void	tronc(int tailleBaseSapin, int blocMax)
{
  int centreSapin;
  int ajoutReduitTronc;
  int debutSapin;
  int finSapin;
  int etageTronc;
  
  ajoutReduitTronc= (blocMax - blocMax%2)/2;
  debutSapin = ((tailleBaseSapin + 1)/2) - ajoutReduitTronc;
  finSapin = ((tailleBaseSapin + 1)/2) + ajoutReduitTronc;
  //(tailleBaseSapin + 1)/2 est le centre du sapin
  etageTronc = 1;
  
  while (etageTronc <= blocMax)
    {
      for (int compteur = 0; compteur < debutSapin; compteur++)
	{
	  printf(" ");
	}
      for (int compteur = debutSapin; compteur <= finSapin; compteur++)
	{
	  printf("|");
	}
      printf("\n");
      etageTronc++;
    }  
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    {
      int tailleBaseSapin;
      int blocMax = atoi(argv[1]);
      tailleBaseSapin = my_tailleBaseSapin(blocMax);
      formationEtoile(tailleBaseSapin, blocMax);
      tronc(tailleBaseSapin, blocMax);      

      if (atoi(argv[1]) == 0 || atoi(argv[1]) <= 0)
	{
	  printf("Erreur");
	  return (-1);
	}      
      return(0);
    }
  
  if (argc != 2)
    {
      printf("Erreur");
      return (0);
    }
}
