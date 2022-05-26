#include "parsing.h"

int verifset(char c, char *set)
{
    int i;

    i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strstr(char *str)
{
	int	i;
	char temp;

	i = 1;
	temp = str[0];
	while (str[i] != '\0')
	{
		if (str[i] == temp)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_free(char **fstr)
{
	int	i;

	i = 0;
	while (fstr[i])
	{
		free(fstr[i]);
		i++;
	}
	free(fstr);
}