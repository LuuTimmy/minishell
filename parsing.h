#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include <stdio.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

char	**mini_split(char const *s, char *c);
void	ft_free(char **fstr);
int     verifset(char c, char *set);

#endif