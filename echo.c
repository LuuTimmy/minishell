#include "parsing.h"

int echo (char **cmd)
{
	int i;

	i = 0;
	if (cmd == NULL || cmd[0] != "echo")
		return (0);
	while (cmd[i] != NULL)
		i++;
}