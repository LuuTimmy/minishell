#include "parsing.h"

char **putpath(char **env)
{
	int i;
	char *nopath;
	char **split;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
		{
			nopath = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
			split = ft_split(nopath, ':');
			free(nopath);
			return (split);
		}
		i++;
	}
	return (NULL);
}

char **parsing(char *line, char *set)
{
    char **str;
    int i;

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
    ft_free(str);
    return (NULL);
}

void sigint(int sig_no)
{
	printf("\nMinishell ");
}

int main(int argc, char **argv, char **env)
{
    char *str;
    char **commandsplit;
    str = readline("Minishell ");
    // str = "bonbon << yolo < Je suis un chocolat $lion | gentil | et kangourou > punaise >> fzefz >> $a";
    // str = "& echo salut > yo\" le\'s gens\"";
    // str = "echo | zegzeg";
    commandsplit = parsing(str, "><|&");
	printf("%s", str);
    free(str);

	// signal
	// struct sigaction action;

	// memset(&action, 0, sizeof(action));
	// action.sa_handler = &sigint;
	// sigaction(SIGINT, &action, NULL);
	// char *str = readline("Minishell ");
	// printf("%s", str);
	// free(str);
    return (0);
}