/*
** EPITECH PROJECT, 2018
** prompt.c
** File description:
** Prompt utilities functions
*/

#include "my.h"
#include "gnl.h"
#include "prompt.h"
#include <stdlib.h>

void		remove_empty_prompt(prompt_t prompt)
{
	free(prompt);
	prompt = NULL;
}

prompt_t	set_empty_prompt(void)
{
	prompt_t	empty = NULL;

	empty = malloc(sizeof(prompt_t));
	empty->cmd = NULL;
	empty->args = NULL;
	return (empty);
}

int		is_prompt_unallocated(prompt_t prompt)
{
	return (prompt != NULL);
}

int		is_prompt_empty(prompt_t prompt)
{
	if (!is_prompt_unallocated(prompt)) {
		return (0);
	} else if (prompt->args == NULL && prompt->cmd == NULL) {
		return (1);
	} else {
		return (0);
	}
}

/* Setup a prompt_t structure and fill it from input
 * returns NULL if fail
 */
prompt_t	set_prompt(char	*input)
{
	prompt_t	prompt = set_empty_prompt();
	char		**promptab = NULL;
	unsigned int	promptablen = 0;

	promptab = my_strtotab(input, " ");
	if (!promptab) {
		remove_empty_prompt(prompt);
		return (NULL);
	} 
	prompt->cmd = promptab[0];
	promptablen = my_strtablen(promptab);
	if (promptablen > 1) {
		prompt->args = my_strtabdup(&promptab[1]);
	}
	return (prompt);
}

prompt_t	wait_for_prompt(void)
{
	char		*gnl_prompt = NULL;
	prompt_t	prompt = NULL;

	my_putstr("$>");
	gnl_prompt = get_next_line(0);
	prompt = set_prompt(gnl_prompt);
	if (!is_prompt_unallocated(prompt)) {
		return (NULL);
	} else {
		return (prompt);
	}
}
