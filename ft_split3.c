#include "parsing.h"

static  int nbword(char *str, char s)
{
    int	i;
	int	nbword;

	i = 0;
	nbword = 0;
	while (str[i])
	{
        if (verifset(str[i], "\"\'") == 1)
			if (ft_strstr((char *)str + i) > 0)
				i += ft_strstr((char *)str + i);
            else
                return (-1);
		if (str[i + 1] == '\0')
		{
			if (str[i] != s)
				nbword++;
			return (nbword);
		}
		if (str[i] != s && (str[i + 1] == s || str[i + 1] == '\0'))
			nbword++;
		i++;
	}
	return (nbword);
}

static char    *ft_minicpy(char *str, int len)
{
    int i;
    int j;
    int k;
    char *fstr;

    j = 0;
    i = 0;
    fstr = (char *) malloc (sizeof(char) * len + 1);
    if (fstr == NULL)
        return (NULL);
    while (j < len)
    {
        if (verifset(str[i], "\"\'") == 1)
        {
            k = ft_strstr((char *)str + i);
            ft_strlcpy(fstr + j, str + i + 1, k);
            i += k;
            j += k - 2;
        }
        else
            fstr[j] = str[i];
        j++;
        i++;
    }
    fstr[len] = '\0';
    return (fstr);
}

static char     **putword(char **fstr, char *str, char s)
{
    int		nword;
	int     len;
	int		i;
    int     nbquote;

	nword = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == s)
			i++;
		else
		{
			len = 0;
            nbquote = 0;
			while (str[i + len] != s && str[i + len] != '\0')
            {
                if (verifset(str[i + len], "\"\'") == 1)
                {
				    len += ft_strstr((char *)str + i + len);
                    nbquote++;
                }
				len++;
            }
			fstr[nword] = ft_minicpy(str + i, len - (nbquote * 2));
			i += len;
			nword++;
		}
	}
	return (fstr);
}

char    **nano_split(char *str, char s)
{
    int nword;
    char **fstr;

    if (str == NULL)
        return (NULL);
    nword = nbword(str, s);
    printf("%d", nword);
    fstr = (char **) malloc (sizeof(char *) * (nword + 1));
    if (fstr == NULL)
        return (NULL);
    fstr = putword(fstr, str, s);
    fstr[nword] = 0;
    for (int i = 0; fstr[i] != 0; i++)
        printf("%s\n", fstr[i]);
    return (NULL);
}