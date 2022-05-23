#include "parsing.h"

char **parsing(char *line, char *set, char **env)
{
    char **str;
	int	i;

	i = 0;
    str = mini_split(line, set);
	while (str[i] != NULL)
	{
		if (str[i][0] == 0)
			return (0);
		if (verifset(str[i][0], set) == 1 && ft_strlen(str[i]) >= 2)
		{
			if (ft_strlen(str[i]) == 2)
			{
				if (str[i][0] != str[i][1])
					return (0);
			}
			else
				return (0);
		}
        i++;
    }
    return (str);
}

// int	countword(char *str, char *set)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (verifset(str[i], set) == 0 && verifset(str[i + 1], set) == 1)
// 			j++;
// 		i++;
// 	}
// 	return (j);
// }

char **parse(char *str)
{
	char **commandsplit;
	int nb;
	int i;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 39)
		{
			i++;
			while (str[i] != 39)
				i++;
			nb++;
		}
		else if (str[i] == 34)
		{
			i++;
			while (str[i] != 34)
				i++;
			nb++;
		}
		else if (str[i] == ' ' && (str[i + 1] != ' ' || verifset(str[i + 1], "\"\'") == 1))
			nb++;
		i++;
	}
	printf("%d", nb);
	return (NULL);
}

int main(int argc, char **argv, char **env)
{
    char *str;
    char **linesplit;
	char **commandsplit;
	int i;
	i = 0;
    //str = readline("Minishell ");
    //str = "bonbon << yolo < Je suis un chocolat lion | gentil | et kangourou > punaise >> fzefz >> $a";
    str = "echo yo\" le\'s gens\"";
    char *set;
	set = "><|&";
    linesplit = parsing(str, set, env);
	commandsplit = parse(linesplit[i]);
    return (0);
}