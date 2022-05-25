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

static int	nword(char *s, char *c)
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
			{
				if (verifset(s[i], "\"\'") == 1)
					if (ft_strstr((char *)s + i) > 0)
						i += ft_strstr((char *)s + i);
					else
						return (-1);
				i++;
			}
		}
		else if (verifset(s[i], c) == 1)
			while (verifset(s[i], c) == 1 && s[i] != '\0')
				i++;
		nbword++;
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

static char	**putword(char **fstr, char *s, char *c)
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
			{
				if (verifset(s[i + len], "\"\'") == 1)
					if (ft_strstr((char *)s + i + len) > 0)
						len += ft_strstr((char *)s + i + len);
					else
						return (NULL);
				len++;
			}
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

char	**mini_split(char *s, char *c)
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
	fstr = putword(fstr, s, c);
	return (fstr);
}