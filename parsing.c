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

int main(int argc, char **argv, char **env)
{
    char *str;
    char **linesplit;
	char **commandsplit;
	int i;
	i = 0;
    //str = readline("Minishell ");
    //str = "bonbon << yolo < Je suis un chocolat lion | gentil | et kangourou > punaise >> fzefz >> $a";
    // str = "echo yo\" l'e gens\"yo\' l\"e gens\'";
	str = "echo yo\" $lol$sal   jo  $plo\"$plop";
	str = " $lol $sal   jo  $plo";
    // char *set;
	// set = "><|&";
    // linesplit = parsing(str, set, env);
	// commandsplit = parse(linesplit[i]);

	printf("%d", nbverifvar(str, '\"', 20));
    return (0);
}