#include "my.h"

void	main()
{
  int	i;
  int	x;
  int	*end;
  
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
  while(end != 1)
    {
      ask(plateau);
      display(plateau);
      result(plateau);
      //end=1;
    }
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
      my_putchar('\n\n');
      l++;
    }
  my_putstr("*********\n");
}

void	ask(int plateau[4][7])
{
  int	l;
  int	n;

  my_putstr("\nVotre tour de jouer !\n");
  my_putstr("\nQuelle ligne\n");
  scanf("%d",&l);
  my_putstr("\nCombien\n");
  scanf("%d", &n);
  l = l-1;
  
  int i;
  
  i=0;
  while(n>0)
    {
      if (plateau[l][i]==0)
	i++;
      if (plateau[l][i]==1)
	{
	  plateau[l][i]=0;
	  i++;
	  n--;
	}
    }
}

void	result(int plateau[4][7])
{
  int	l; //ligne
  int	n; //numero
  int	i;
  
  i = 0;
  l = 0;
  while(l < 4)
    {
      n = 0;
      while(n < 7)
	{
	  if (plateau[l][n]==0)
	    {
	      n++;
	      i++;
	    }
	  if (plateau[l][n]==1)
	    n++;
	}
      l++;
    }
  if (i == 28)
    {
    printf("\n\n##FIN!##\n\n");
    return EXIT_SUCCESS;
    }
}
