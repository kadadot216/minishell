/*
** EPITECH PROJECT, 2018
** data.c
** File description:
** Data structure functions
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int	check_for_args(int ac)
{
	if (ac != 2) {
		perror("Wrong number of arguments.");
		return (0);
	} else
		return (1);
}

int	stat_path(char *path, struct stat *sb)
{
	if (stat(path, sb) == -1) {
		perror("stat failed");
		return (0);
	} else
		return (1);
}
