#include "my.h"

void	main()
{
  int		i;
  int		x;
  int		*end;
  int		*bufia;
  int		*buffer;
  
  bufia = 1;
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
      ask(&buffer,plateau);
      display(plateau);
      result(&end,plateau);
      if (end == 1)
	my_putstr("Vous avez perdu !\n");
      if (end != 1)
	{
	  IA_Play(&buffer,&bufia,plateau);
	  display(plateau);
	  result(&end,plateau);
	  if (end == 1)
	    my_putstr("Vous avez gagné !\n");
	}
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
	    my_putchar('|');
	  n++;
	}
      my_putchar('*');
      my_putchar('\n\n');
      l++;
    }
  my_putstr("*********\n");
}

void	ask(int *buffer, int plateau[4][7])
{
  int	i;
  int	l;
  int	n;
  
  my_putstr("\nVotre tour de jouer !\n");
  my_putstr("\nQuelle ligne\n");
  scanf("%d",&l);
  my_putstr("\nCombien\n");
  scanf("%d", &n);
  l = l-1;
  i=0;

  if(l>3 || l<0)
      my_error("Vous avez rentrez un ligne inexistante !\n");
  if (n > 3 || n == buffer )
    my_error("Vous avez entrez plus de 3 alumettes ! \n");
  while(n>0)
    {
      if (n == 42)
	n = 0;
      if (plateau[l][i]==0)
	i++;
      if (plateau[l][i]==1)
	{
	  plateau[l][i]=0;
	  i++;
	  n--;
	}
    }
  *buffer=n;
}

void	result(int *end, int plateau[4][7])
{
  int	l;
  int	n;
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
      *end = 1;
    }
}

void	IA_Play(int *buffer, int *bufia, int plateau[4][7])
{
  int	l;
  int	n;
  int	i;

  my_putstr("\nNow let's me play ...\n");
  l=1;
  n=2;
  i=0;
  *bufia = 7;
  if (n == buffer)
    {
      if (buffer == 1)
	n++;
      if (buffer == 2)
	n++;
    }
  while(n>0)
    {
      if (l == 4)
	{
	  l = 0;
	}
      if (i == 8)
	{
	  i=0;
	  l++;
	}
      if (plateau[l][i]==0)
	i++;
      if (plateau[l][i]==1)
	{
	  plateau[l][i]=0;
	  i++;
	  n--;
	}
    }
  *buffer=n;
}
