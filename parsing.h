#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include <stdio.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

char	**mini_split(char *s, char *c);
char    **nano_split(char *str, char s);
void	ft_free(char **fstr);
int     verifset(char c, char *set);
char	**parse(char *str);
char	**parsev2(char *str);
int		ft_strstr(char *str);

typedef struct s_lst {

	char c;
	struct s_lst *next;

}	t_lst;

#endif