/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** Prompt utilities functions
*/

#include "my.h"
#include "gnl.h"
#include <stdlib.h>

int	is_prompt_allocated(char **prompt)
{
	return (prompt != NULL);
}

int	is_prompt_empty(char **prompt)
{
	if (!is_prompt_allocated(prompt)) {
		return (0);
	} else if (prompt[0] == '\0') {
		return (1);
	}
}

char	**set_prompt(char *input)
{
	char	**prompt = NULL;

	if (input == NULL) {
		return (prompt);
	} else {
		input = my_remove_trailing_spaces(input);
		prompt = my_strtotab(input, " ");
		return (prompt);
	}
}

char	**wait_for_prompt(char *cwd)
{
	char	*gnl_prompt = NULL;
	char	**prompt = NULL;

	my_putstr("[");
	my_putstr(cwd);
	my_putstr("]> ");
	gnl_prompt = get_next_line(0);
	if (!gnl_prompt) {
		return (NULL);
	}
	prompt = set_prompt(gnl_prompt);
	return (prompt);
}
