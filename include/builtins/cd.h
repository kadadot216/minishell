/*
** EPITECH PROJECT, 2018
** cd.h
** File description:
** Header file for ms_cd_handle and friends.c
*/

#ifndef __CD_H__
#define __CD_H__

#define GETCWD_MAXSIZE (4096)

char	*ms_cd_get_cd(void);

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

#endif
