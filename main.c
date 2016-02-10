#include "my.h"

void	main()
{
  int	i;
  int	x;
  int	end;
  
  i = 0;
  x = 1;
  //Creation plateau
  int	plateau[4][7] = {{0,0,0,1,0,0,0},
			 {0,0,1,1,1,0,0},
			 {0,1,1,1,1,1,0},
			 {1,1,1,1,1,1,1}};
  //Debut jeu
  printf("\n##START##\n");
  display(plateau);
  ask(plateau);
  display(plateau);
  
  
}

void	display(int plateau[4][7])
{
  int l; //ligne
  int n; //numero
  
  l = 0;
  printf("*********\n");
  while(l < 4)
    {
      n = 0;
      printf("*");
      while(n < 7)
	{
	  if (plateau[l][n]==0)
	    printf(" ");
	  if (plateau[l][n]==1)
	    printf("I");
	  n++;
	}
      printf("*");
      printf("\n");
      l++;
    }
  printf("*********");
}

void	ask(int plateau[4][7])
{
  int	l;
  int	n;
  
  printf("\nQuelle ligne\n");
  printf("\nCombien\n");
  l = 3;
  n = 4;
  l = l-1;
  n = n-1;
  plateau[l][n]=0;
}
