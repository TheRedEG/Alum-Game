#ifndef	_MY_H_
#define _MY_H_

#include <unistd.h>
#include <stdlib.h>

/*main*/
void		start(int plateau[4][7]);
void		player(int plateau[4][7]);
void		IA_Play(int *buf, int plateau[4][7]);
void		result(int *end, int plateau[4][7]);

/*display*/
void		display(int plateau[4][7]);
void		player_say(int l, int n);
void		ia_say(int l, int n);

/*ask*/

/*basics*/
void		my_putchar(char a);
void		my_putstr(char *str);
void		my_put_nbr(int nb);
void		my_error(char *str);
int		ask();

#endif
