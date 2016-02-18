#include "my.h"

int		negatif(char *str)
{
  int		a;
  int		neg;

  a = 0;
  neg = 0;
  while (str[a])
    {
      if (str[a] == '-')
	neg++;
      a++;
    }
  if ((neg % 2) != 0)
    return (-1);
  else
    return (1);
}

int		my_getnbr(char *str)
{
  int		a;
  int		b;
  int		c;

  a = 0;
  b = 0;
  if (b >= 2147483647)
    return (0);
  c = negatif(str);
  while (str[a] == '+')
    a++;
  while (str[a] == '-')
    a++;
  while (str[a] != 0 && str[a] >= '0' && str[a] <= '9')
    {
      b = b * 10 + (str[a] - '0');
      a++;
    }
  b = b * c;
  return (b);
}

int	ask()
{
  int	rep;
  char	buf[50];
  read(0,buf,50);
  rep = my_getnbr(buf);
  return rep; 
}
