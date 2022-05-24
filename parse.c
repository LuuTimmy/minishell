#include "parsing.h"

int	countword(char *str, char *set)
{
	char temp;
	int nb;
	int i;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == '\0' && verifset(str[i + 1], set) == 0)
			return (nb + 1);
		if (str[i] == '\"' || str[i] == '\'')
		{
			temp = str[i];
			i++;
			while (str[i] != temp)
				i++;
			nb++;
		}
		else if (verifset(str[i], set) == 0 && verifset(str[i + 1], set) == 1)
			nb++;
		i++;
	}
	return (nb);
}

static char	**putword(char **fstr, const char *str, char *set)
{
	int		nword;
	size_t	len;
	int		i;
	char temp;

	nword = 0;
	i = 0;
	while (str[i] != '\0')  //"echo yo\" l'e gens\""
	{
		if (str[i] == 32)
            i++;
        else
        {
            len = 0;
            temp = 0;
            if (str[i] == '\"' || str[i] == '\'')
            {
                temp = str[i];
                i++;
                while (str[i + len] != temp) //"echo yo\" l'e gens\""
				    len++;
            }
            while (verifset(str[i + len], set) == 0 && str[i + len] != '\0')
				len++;
            fstr[nword] = ft_substr(str, i, len);
			if (!fstr[nword])
				ft_free(fstr);
			i += len;
            if (temp != 0)
                i++;
			nword++;
        }
	}
	return (fstr);
}

char **parse(char *str)
{
	int nbword;
	char **fstr;

	nbword = countword(str, " \"\'");
	fstr = (char **) malloc (sizeof (char *) * (nbword + 1));
	if (str == NULL)
		return (NULL);
	fstr[nbword] = 0;
	fstr = putword(fstr, str, " \"\'");
	for (int i = 0; fstr[i] != NULL; i++)
		printf("%s\n", fstr[i]);
}