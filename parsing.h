#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include <stdio.h>

char	**mini_split(char const *s, char *c);
void	ft_free(char **fstr);
int     verifset(char c, char *set);

#endif