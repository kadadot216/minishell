/*
** EPITECH PROJECT, 2018
** strtab.h
** File description:
** Header file for strtab.h
*/

#ifndef __MY_STRTAB_H__
#define __MY_STRTAB_H__

char	**my_strtabcpy(char **dest, const char **src);
char	**my_strtotabpt(char *str, const char *delim);
char	**my_strtotab(char *str, const char *delim);
int	my_strtablen(char **tab);
char	**my_strtabdup(char **tab);
int	my_free_strtab(char **tab, int height);

#endif

