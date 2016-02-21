#include "my.h"

void	IA_Play(int plateau[4][7], int tab[4][2])
{
  int	l;
  int	m;
  int	i;

  calc_l(plateau,tab);
}

// calcule le nombre d'alum restantes sur chaques lignes
void	calc_l(int	plateau[4][7], int tab[4][2])
{
  int	l;
  int	m;
  int	tmp;

  l=0;
  tmp = 0;
  while(l <= 3)
    {
      m = 0;
      while(m <= 6)
	{
	  if (plateau[l][m] == 1)
	    {
	      tmp++;
	    }
	  m++;
	}
      tab[l][0]=tmp;
      l++;
      tmp = 0;
    }
  check_player(plateau,tab);
}

//Detecte ligne touchée
void	check_player(int plateau[4][7], int tab[4][2])
{
  int	buf;

  buf = tab[0][1];
  
  //si une ligne est fini
  if (tab[buf][0] == 0)
    {
      buf++;
      rm(plateau,tab,buf,1);
    }
  else
    {
      while (tab[buf][0] == 0)
	{
	  buf++;
	}
      rm(plateau,tab,buf,0);
    }
}

void	final_rm(int plateau[4][7])
{  
}

void	rm(int plateau[4][7],int tab[4][2], int line, int all)
{
  int i;
  int buf;
  int x;
  
  i = 0; 
  //si la ligne n'est pas vide
  if (all == 0)
    {
      ia_say(line,tab[line][0]);
      while (i <= 6)
	{
	  plateau[line][i] = 0;
	  i++;
	}
    }
  //si vide un ligne
  if (all == 1)
    {
      int i;
      
      i = 0;
      buf=tab[0][1];
      buf++;
      while (tab[buf][0] == 0)
	{
	  if(buf>3)
	    {
	      buf=0;
	    }
	   else
	     {
	       buf++;
	     }
	}
       x = tab[buf][0];
       x--;
       ia_say((buf+1),x);
      while(x > 0)
	{
	  if (plateau[buf][i]== 0)
	    i++;
	  if (plateau[buf][i]== 1)
	    {
	      plateau[buf][i]=0;
	      x--;
	      i++;
	    }
	}
    }
}
