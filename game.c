#include "my.h"

void	start(int plateau[4][7], int tab[4][2])
{
  int		end;
  int		*ptr;

  ptr = &end;
  while(end != 1)
    {
      player(plateau,tab);
      display(plateau);
      result(ptr,plateau);
      if (end == 1)
	{
	my_putstr("You lost, too bad..\n");
	}
      if (end != 1)
	{
	  IA_Play(plateau,tab);
	  display(plateau);
	  result(ptr,plateau);
	  if (end == 1)
	    {
	      my_putstr("I lost.. snif.. but I'll get you next time !!\n");
	    }
	}
    }
}

void	player(int plateau[4][7], int tab[4][2])
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
  tab[0][1]=l;
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

