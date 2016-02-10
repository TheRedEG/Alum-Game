#ifndef	_MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//main
void		display(int plateau[4][7]);
void		ask(int plateau[4][7]);
void		result(int plateau[4][7]);

void		my_putchar(char a);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
void		my_error(char *str);

typedef struct game game;
struct game
{
  int	plateau[4][7];
  //Debut jeu
};

#endif
