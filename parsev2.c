#include "parsing.h"

static int	nbverifvar(char *str)
{
	int	i;
	int l;
	int lvar;

	i = 0;
	l = 0;
	lvar = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$' && str[i + 1] != '\0' && verifset(str[i + 1], " \'\"") == 0)
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
	printf("%ld %d %d === %ld", ft_strlen(str), l, lvar, ft_strlen(str) - l + lvar);
	return (ft_strlen(str) - l + lvar);
}

char *putarg(char *str, int len)
{
	char *test = "clo";
    char *fstr;
	int actualquote;
	int	i;
	int j;
	int k;

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
			k = 0;
			j += ft_strlcpy(fstr + j, test, ft_strlen(test) + 1);
			// while (test[k] != '\0')
			// {
			// 	fstr[j] = test[k];
			// 	k++;
			// 	j++;
			// }
		}
		else
		{
			fstr[j] = str[i];
			i++;
			j++;
		}
	}
    fstr[len] = '\0';
	printf("%s", fstr);
    return (fstr);
}

char **parsev2(char *str)
{
    int len;
    char *temp;
    len = nbverifvar(str);
    temp = putarg(str, len);
    return (NULL);
}