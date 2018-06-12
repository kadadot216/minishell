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
	if (prompt == NULL)
		return (NULL);
	else
		return (prompt);
}

static char	**sanitize_prompt(char *gnl_prompt)
{
	char	**prompt = NULL;

	if (gnl_prompt == NULL) {
		return (NULL);
	} else {
		prompt = my_strtotab(gnl_prompt, " ");
		return (prompt);
	}
}

char	**wait_for_prompt(char **prompt)
{
	char	*gnl_prompt = NULL;

	my_putstr("$>");
	gnl_prompt = get_next_line(0);
	prompt = sanitize_prompt(gnl_prompt);
	return (prompt);
}
