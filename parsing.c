#include "parsing.h"

char *parsing()
{
    
}

int main(int argc, char **argv, char **env)
{
    char *str;
	char *goodstr;
    char *set;
	char **s;
	int i = 0;

    str = "bonbon <<yolo < Je suis un chocolat   $lion | gentil | et kangourou > punaise >>>> fzefz >> $a";
	goodstr = "& echo salut > yo\" le\'s gens\"";
    set = "$";

    s = mini_split(goodstr, set);
	i = 0;
	while (s[i] != NULL)
	{
		if (s[i][0] == 0)
			return (0);
		if (verifset(s[i][0], set) == 1 && ft_strlen(s[i]) >= 2)
		{
			if (ft_strlen(s[i]) == 2)
			{
				if (s[i][0] != s[i][1])
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	i = 0;
	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
	ft_free(s);
    return (0);
}