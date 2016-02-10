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
  my_putstr("\n##START##\n");
  display(plateau);
  ask(plateau);
  display(plateau);
  
  
}

void	display(int plateau[4][7])
{
  int l; //ligne
  int n; //numero
  
  l = 0;
  my_putstr("*********\n");
  while(l < 4)
    {
      n = 0;
      my_putchar('*');
      while(n < 7)
	{
	  if (plateau[l][n]==0)
	    my_putchar(' ');
	  if (plateau[l][n]==1)
	    my_putchar('I');
	  n++;
	}
      my_putchar('*');
      my_putchar('\n');
      l++;
    }
  my_putstr("*********");
}

void	ask(int plateau[4][7])
{
  int	l;
  int	n;
  
  my_putstr("\nQuelle ligne\n");
  my_putstr("\nCombien\n");
  l = 3;
  n = 4;
  l = l-1;
  n = n-1;
  plateau[l][n]=0;
}
