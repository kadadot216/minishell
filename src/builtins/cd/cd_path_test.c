/*
** EPITECH PROJECT, 2018
** cd_path_test.c
** File description:
** Functions that checks the path for the cd builtin
*/

#include "builtins/cd.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	cd_is_a_directory(struct stat *snode)
{
	if ((snode->st_mode & S_IFMT) == S_IFDIR) {
		return (CD_ISDIR);
	} else {
		return (CD_NOTDIR);
	}
}

int	test_cd_path(char *cd_path)
{
	struct stat	cd_path_stat;
	int	stat_status = -1;
	int	is_dir_status = 0;

	stat_status = stat(cd_path, &cd_path_stat);
	if (stat_status == -1) {
		return (stat_status);
	} else {
		is_dir_status = cd_is_a_directory(&cd_path_stat);
		return (is_dir_status);
	}
}
