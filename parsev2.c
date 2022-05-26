#include "parsing.h"

static int	nbverifvar(char *str)
{
	int	i;
	int l;
	int lvar;
	int actualquote;

	i = 0;
	l = 0;
	lvar = 0;
	actualquote = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && actualquote == 0)
			actualquote = 1;
		else if (str[i] == '\'' && actualquote == 1)
			actualquote = 0;
		if (str[i] == '$' && str[i + 1] != '\0' && verifset(str[i + 1], " $\'\"") == 0 && actualquote == 0)
		{
            l++;
            while (str[i + 1] != '\0' && verifset(str[i + 1], " $\'\"") == 0)
            {
                l++;
                i++;
            }
			lvar += 3; //verifenvir
		}
		i++;
	}
	//printf("%ld - %d + %d = %ld\n", ft_strlen(str),l ,lvar, ft_strlen(str) - l + lvar);
	return (ft_strlen(str) - l + lvar);
}

char *putarg(char *str, int len)
{
	char *test = "clo";
    char *fstr;
	int actualquote;
	int	i;
	int j;

	i = 0;
	j = 0;
	actualquote = 0;
    fstr = (char *) malloc (sizeof(char) * (len + 1));
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && actualquote == 0)
			actualquote = 1;
		else if (str[i] == '\'' && actualquote == 1)
			actualquote = 0;
		if (str[i] == '$' && str[i + 1] != '\0' && verifset(str[i + 1], " \'\"") == 0 && actualquote == 0)
		{
			while (str[i + 1] != '\0' && verifset(str[i + 1], "$\"\' ") == 0)
				i++;
			i++;
			// //cherchENV;
			j += ft_strlcpy(fstr + j, test, ft_strlen(test) + 1);
		}
		else
		{
			fstr[j] = str[i];
			i++;
			j++;
		}
	}
    fstr[len] = '\0';
    return (fstr);
}

char **parsev2(char *str)
{
    int len;
    char *temp;
	char **fstr;

    len = nbverifvar(str);
    temp = putarg(str, len);
	fstr = nano_split(temp, 32);
	free(temp);
    return (fstr);
}