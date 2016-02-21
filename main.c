#include "my.h"

void	main()
{
  int	plateau[4][7];
  int	tab[4][2];
  
  fill_up(plateau);
  display(plateau);
  start(plateau,tab);
}

void	fill_up(int plateau[4][7])
{
  int	line;
  int	matches;
  
  line = 0;
  matches = 0;
  while(line <= 3)
    {
      if (matches >= 3 - line && matches <= 3 + line)
	{
	  plateau[line][matches] = 1;
	}
      else
	{
	  plateau[line][matches]= 0;
	}
      matches++;
      if (matches > 6)
	{
	  line++;
	  matches = 0;
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
