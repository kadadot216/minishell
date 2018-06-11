/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** Prompt utilities functions
*/

#include "my.h"
#include "gnl.h"
#include <stdlib.h>

char	*gnl_is_valid(char *str)
{
	if (str == NULL || my_strcmp(str, "\0") == 0)
		return (NULL);
	else
		return (str);
}

char	**prompt_is_valid(char **prompt)
{
	if (prompt == NULL || my_strcmp(prompt[0], "\0") == 0)
		return (NULL);
	else
		return (prompt);
}

char	**wait_for_prompt(char **prompt)
{
	char	*gnl_prompt = NULL;

	my_putstr("$>");
	gnl_prompt = get_next_line(0);
	if (!gnl_is_valid(gnl_prompt))
		return (NULL);
	else {
		prompt = my_strtotab(gnl_prompt, " ");
		return (prompt_is_valid(prompt));
	}
}
