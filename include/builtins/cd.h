/*
** EPITECH PROJECT, 2018
** cd.h
** File description:
** Header file for ms_cd_handle and friends.c
*/

#ifndef __CD_H__
#define __CD_H__

#define GETCWD_MAXSIZE (4096)

#include "shell/shell.h"

enum	filetype_bitmask_e {
	S_IFMT = 0170000,
	S_IFSOCK = 0140000,
	S_IFLNK = 0120000,
	S_IFREG = 0100000,
	S_IFBLK = 0060000,
	S_IFDIR = 0040000,
	S_IFCHR = 0020000,
	S_IFIFO = 0010000
};

enum	cd_checking_status_e {
	CD_NEXISTS = -1,
	CD_NOTDIR = 0,
	CD_ISDIR = 1,
};

void	update_last_dir(char *last_dir, char *curr_dir);
void	init_last_dir_once(char *last_dir, char *curr_dir);
void	interpret_cd_status(enum cd_checking_status_e status, char **prompt);
void	cd_sanitize_exceptions(char *arg, char *cwd);
char	*ms_cd_get_cd(void);
char	*setup_cd_path(shell_t *shell);
int	test_cd_path(char *cd_path);
int	test_absolute_path(char **prompt);
int	cd_right_nb_args(int ac);
int	arg_uses_currdir_notation(char const *arg);
int	arg_uses_parentdir_notation(char const *arg);

#endif
