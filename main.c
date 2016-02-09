#include "my.h"

void	main()
{
  int	i;
  int	end;
  
  i = 0;
  struct game game;
  while (i < 16)
    {
      game.plateau[i]=1;
      i++;
    }
  while (end != 1)
    {
      display(&game);
      ask(&game);
      display(&game);
    }
  
}

void	display(game *game)
{
  int	i;

  i = 0;
   printf("************\n");
  while (i < 16)
    {
      //Placement pyramide
       if (i == 0)
	printf("*    ");
      if (i == 1)
	printf("*   ");
      if (i == 4)
	printf("*  ");
      if (i == 9)
	printf("* ");
      //Supression d'alum
      if (game->plateau[i] == 1)
	printf("I");
      if (game->plateau[i] == 0)
	printf(" ");
      //Placement pyramide
      if (i == 0 || i == 3 || i == 8)
	printf("\n");
      i++; 
    }
   printf("\n***********\n\n"); 
}
  void	ask(game *game)
  {
  int	line;
  int	num;

  // printf("\nQuelle ligne ?\n");
  //scanf(" %d", &line);
  printf("\nCombien ?");
  scanf(" %d", &num);
  if(num == 2)
    game->plateau[num] = 0;
  }
/*
void	newask(game *game)
{
game->plateau[1]=0;
printf("new ask result \n");
  display(game);
  
}
*/
