#include	"my.h"
#include	<unistd.h>
#include	<stdlib.h>

void		my_putchar(char a)
{
  write(1, &a, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

void		my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb *= (-1);
    }
  if (nb > 9)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

void		my_error(char *str)
{
  my_putstr(str);
  exit(EXIT_FAILURE);
}
