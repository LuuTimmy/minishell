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

int	nbverifvar(char *str, char quote, int len)
{
	int	i;
	int l;
	int lvar;
	char *test = "cho";
	i = 0;
	l = 0;
	lvar = 0;
	while (i < len && str[i] != '\0')
	{
		if (str[i] == '$' && verifset(str[i + 1], " \0") == 0 && quote != '\'')
		{
			while (verifset(str[i + l], " \0$") == 0)
				l++;
			lvar += ft_strlen(test); //verifenvir
			i += l;
		}
		i++;
	}
	return (len - l + lvar);
}

char *ft_minicpy(char *str, int len, char quote)
{
	int		i;
	int		l;
	char	*temp;
	int lenline;
	int	j;
	char *test = "cho";

	i = 0;
	l = 0;
	j = 0;
	int k = 0;
	lenline = nbverifvar(str, quote, len);

	// return (temp);
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
            fstr[nword] = ft_minicpy((char *)str + i, len, temp); //ft_substr(str, i, len);
			if (fstr[nword] == NULL)
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