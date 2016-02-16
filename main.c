#include "my.h"

void	main()
{
  int	plateau[4][7] = {{0,0,0,1,0,0,0},
			 {0,0,1,1,1,0,0},
			 {0,1,1,1,1,1,0},
			 {1,1,1,1,1,1,1}};
  
  my_putstr("\n");
  display(plateau);
  start(plateau);
}

void	start(int plateau[4][7])
{
  int		*end;
  int		*bufia;
  int		*buffer;
  
  bufia = 1;
  while(end != 1)
    {
      player(&buffer,plateau);
      display(plateau);
      result(&end,plateau);
      if (end == 1)
	my_putstr("You lost, too bad..\n");
      if (end != 1)
	{
	  IA_Play(&buffer,&bufia,plateau);
	  display(plateau);
	  result(&end,plateau);
	  if (end == 1)
	    my_putstr("I lost.. snif.. but I'll get you next time !!\n");
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

void	player(int *buffer, int plateau[4][7])
{
  int	i;
  int	l;
  int	n;
  
  my_putstr("\nYour turn:\nLine: ");
  scanf("%d",&l);
  my_putstr("\nMatches:");
  scanf("%d", &n);
  l = l-1;
  i=0;
  if(l>3 || l<0)
    my_error("Error : this line is out of range\n");
  if (n > 3 || n == buffer || n<=0)
    my_error("Error : invalid number of matches\n");
  *buffer=n;
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
      printf("\n\n");
      *end = 1;
    }
}

void	IA_Play(int *buffer, int *bufia, int plateau[4][7])
{
  int	l;
  int	n;
  int	i;

  my_putstr("\nAI's turn\n");
  l=1;
  n=2;
  i=0;
  *bufia = 7;
  if (n == *buffer)
    {
      if (*buffer == 1)
	n++;
      if (*buffer == 2)
	n++;
    }
  *buffer=n;
  printf("AI removed %d match(es) from line %d\n",n,l);
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
}
