/*
** EPITECH PROJECT, 2018
** str.h
** File description:
** Header file for str functions
*/

#ifndef __MY_STR_H__
#define __MY_STR_H__

void	my_memset(char *str, char c, unsigned int size);
int	my_strcmp(char const *s1, char const *s2);
int	my_strlen(char const *str);
int	my_strlentok(char const *str, char const c);
int	my_strncmp(char const *s1, char const *s2, int n);
char	*my_strcat(char *dest, char const *src);
char	*my_strcpy(char *dest, char const *src);
char	*my_strdup(char const *src);
char	*my_strncat(char *dest, char const *src, int nb);
char	*my_strncpy(char *dest, char const *src, int n);
char	*my_strndup(char const *src, int n);

#endif
