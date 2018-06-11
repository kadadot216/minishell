/*
** EPITECH PROJECT, 2018
** main.h
** File description:
** Header file for main.c
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#include <sys/stat.h>

int	check_for_args(int ac);
int	stat_path(char *path, struct stat *sb);

#endif
