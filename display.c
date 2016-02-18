#include "my.h"

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
      my_putchar('\n');
      l++;
    }
  my_putstr("*********\n");
}

void	player_say(int l, int n)
{
  my_putstr("Player removed ");
  my_put_nbr(n);
  my_putstr(" match(es) from line ");
  my_put_nbr(l);
  my_putstr("\n");
}

void	ia_say(int l, int n)
{
  my_putstr("AI removed ");
  my_put_nbr(n);
  my_putstr(" match(es) from line ");
  my_put_nbr(l);
  my_putstr("\n");
}
