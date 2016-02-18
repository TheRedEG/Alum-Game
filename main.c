#include "my.h"

void	main()
{
  int	plateau[4][7];
  
  fill_up(plateau);
  display(plateau);
  start(plateau);
}

void	fill_up(int plateau[4][7])
{
  int	i;
  int	u;
  
  i = 0;
  u = 0;
  while(i <= 3)
    {
      if (u >= 3 - i && u <= 3 + i)
	{
	  plateau[i][u] = 1;
	}
      else
	plateau[i][u]= 0;
      u++;
      if (u >6)
	{
	  i++;
	  u = 0;
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
