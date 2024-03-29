/*
** EPITECH PROJECT, 2018
** strtab.h
** File description:
** Header file for strtab.h
*/

#ifndef __MY_STRTAB_H__
#define __MY_STRTAB_H__

int	my_show_word_array(char *const *tab);
int	my_strtablen(char **tab);
char	**my_free_strtab(char **tab);
char	**my_strtab_nclone(char **dest, char *const *src, int n);
char	**my_strtab_null(char **tab, int height);
char	**my_strtab_realloc(char **tab, int size);
char	**my_strtabcat(char **dest, char **src);
char	**my_strtabcpy(char **dest, const char **src);
char	**my_strtabdup(char **tab);
char	**my_strtabptncpy(char **dest, char **src, int n);
char	**my_strtotab(char *str, const char *delim);
char	**my_strtotabpt(char *str, const char *delim);
char	*my_strtab_to_strwtok(char **tab, char *delim);

#endif

