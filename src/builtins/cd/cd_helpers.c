/*
** EPITECH PROJECT, 2018
** cd_helpers.c
** File description:
** Helper functions for ms_cd
*/

#include <unistd.h>
#include "my.h"
#include "builtins/cd.h"

char	*ms_cd_get_cd(void)
{
	char	buffer[GETCWD_MAXSIZE] = {'\0'};
	char	*current_dir = NULL;

	if (getcwd(buffer, GETCWD_MAXSIZE) == NULL) {
		my_puterror("Error during getcwd call\n");
		return (current_dir);
	} else {
		current_dir = my_strdup(buffer);
		return (current_dir);
	}
}

void	update_last_dir(char *last_dir, char *curr_dir)
{
	my_memset(last_dir, '\0', my_strlen(last_dir));
	my_strcpy(last_dir, curr_dir);
}

void	init_last_dir_once(char *last_dir, char *curr_dir)
{
	if (last_dir[0] == '\0') {
		my_strcpy(last_dir, curr_dir);
	}
}

