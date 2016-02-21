#ifndef	_MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

/*main*/
void		result(int *end, int plateau[4][7]);
void		fill_up(int plateau[4][7]);
/*game*/
void		start(int plateau[4][7], int tab[4][2]);
void		player(int plateau[4][7], int tab[4][2]);
/*ia*/
void		IA_Play(int plateau[4][7], int tab[4][2]);
int		calc_m(int plateau[4][7], int tab[4][2]);
void		calc_l(int plateau[4][7], int tab[4][2]);
void		test_ia(int tab[4][2]);
void		check_player(int plateau[4][7],int tab[4][2]);
void		rm(int plateau[4][7],int tab[4][2], int line, int all);
/*display*/
void		display(int plateau[4][7]);
void		player_say(int l, int n);
void		ia_say(int l, int n);
/*ask*/
int		negatif(char *str);
int		my_getnbr(char *str);
int		ask();
/*basics*/
void		my_putchar(char a);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
void		my_error(char *str);
int		ask();

#endif
