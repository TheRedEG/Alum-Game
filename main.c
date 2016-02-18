#include "my.h"

void	main()
{
  int	plateau[4][7] = {{0,0,0,1,0,0,0},
			 {0,0,1,1,1,0,0},
			 {0,1,1,1,1,1,0},
			 {1,1,1,1,1,1,1}};
  
  display(plateau);
  start(plateau);
}

void	start(int plateau[4][7])
{
  int		end;
  int		*buf;
  int		*ptr;

  ptr = &end;
  buf = 1;
  while(end != 1)
    {
      player(plateau);
      display(plateau);
      result(ptr,plateau);
      if (end == 1)
	{
	my_putstr("You lost, too bad..\n");
	}
      if (end != 1)
	{
	  IA_Play(&buf,plateau);
	  display(plateau);
	  result(ptr,plateau);
	  if (end == 1)
	    {
	      my_putstr("I lost.. snif.. but I'll get you next time !!\n");
	    }
	}
    }
}

void	player(int plateau[4][7])
{
  int	i;
  int	l;
  int	n;
  
  my_putstr("\nYour turn:\nLine: ");
  l = ask();
  my_putstr("Matches:");
  n = ask();
  player_say(l,n);
  l--;
  i=0;
  if(l>3 || l<0)
    my_error("Error : this line is out of range\n");
  if (n<=0)
    my_error("Error : invalid number of matches\n");
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

void	IA_Play(int *buf, int plateau[4][7])
{
  int	l;
  int	n;
  int	i;

  my_putstr("\nAI's turn\n");
  l=2;
  n=2;
  i=0;
  *buf = 7;
  ia_say(l,n);
  l--;
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
      my_putstr("\n");
      *end = 1;
    }
}
