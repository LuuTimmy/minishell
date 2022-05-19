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

static int	nword(char const *s, char *c)
{
	int	i;
	int nbword;

	i = 0;
	nbword = 0;
	while (s[i] != '\0')
	{
		if (verifset(s[i], c) == 0)
		{
			while (verifset(s[i], c) == 0 && s[i] != '\0')
				i++;
			nbword++;
		}
		else if (verifset(s[i], c) == 1)
		{
			while (verifset(s[i], c) == 1 && s[i] != '\0')
				i++;
			nbword++;
		}
	}
	return (nbword);
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

static char	**putword(char **fstr, const char *s, char *c)
{
	int		nword;
	size_t	len;
	int		i;
	char *temp;

	nword = 0;
	i = 0;
	while (s[i] != '\0')
	{
		len = 0;
		if (verifset(s[i + len], c) == 0)
			while (verifset(s[i + len], c) == 0 && s[i + len] != '\0')
				len++;
		else
			while (verifset(s[i + len], c) == 1 && s[i + len] != '\0')
				len++;
		temp = ft_substr(s, i, len);
		fstr[nword] = ft_strtrim(temp, " ");
		free(temp);
		if (fstr[nword] == NULL)
			ft_free(fstr);
		i += len;
		nword++;
	}
	return (fstr);
}

char	**mini_split(char const *s, char *c)
{
	char	**fstr;
	int		nbword;

	if (s == NULL)
		return (NULL);
	nbword = nword(s, c);
	fstr = (char **) malloc (sizeof (char *) * (nbword + 1));
	if (!fstr)
		return (NULL);
	fstr[nbword] = 0;
	putword(fstr, s, c);
	return (fstr);
}