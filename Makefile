##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for PSU_minishell1
##

CC		=	gcc -W -Wall -Werror -Wextra
DBCC		=	gcc -g
RM		=	rm -f

#	Library settings
LIB_DIR		=	lib
LIB_NAMEDIR	=	my
LIB_PATH	=	$(LIB_DIR)/$(LIB_NAMEDIR)

LIB_HDPATH	=	$(LIB_PATH)/include

LIB_HDSRC	=	my.h		\
			str.h		\
			strtab.h
			

LIB_HDS		=	$(addprefix $(LIB_HDPATH)/, $(LIB_HDSRC))

LIB_SRCS	=	str/my_strcmp.c			\
			str/my_strcpy.c			\
			str/my_strlen.c			\
			str/my_strlentok.c		\
			str/my_strncat.c		\
			str/my_strncmp.c		\
			str/my_strncpy.c 		\
			str/my_strdup.c 		\
			str/my_strndup.c 		\
			str/my_memset.c 		\
			str/my_strcat.c 		\
			strtab/my_strtabcpy.c		\
			strtab/my_strtabdup.c		\
			strtab/my_strtablen.c		\
			strtab/my_strtotab.c		\
			strtab/my_free_strtab.c		\
			strtab/my_strtab_null.c		\
			strtab/my_strtab_realloc.c	\
			strtab/my_strtabptncpy.c	\
			strtab/my_strtab_to_strwtok.c	\
			strtab/my_show_word_array.c	\
			strtab/my_strtabcat.c		\
			my_remove_trailing_spaces.c	\
			my_putchar.c			\
			my_puterror.c			\
			my_putstr.c

LIB_SRC		=	$(addprefix $(LIB_PATH)/, $(LIB_SRCS))
LIB_OBJ		=	$(LIB_SRC:.c=.o)
LIB_NAME	=	lib$(LIB_NAMEDIR).a

#	Program settings
HDPATH		=	./include
CFLAGS		+=	-I$(HDPATH)
NAME		=	minish
LDFLAGS		=	-L./lib
LIBFLAG		=	-lmy -lgnl
SRC		=	src/shell/shell.c			\
			src/shell/prompt.c			\
			src/shell/prompt_type.c			\
			src/shell/path.c			\
			src/shell/path_exec.c			\
			src/shell/cmd_dispatcher.c		\
			src/shell/env.c				\
			src/builtins/builtins_table.c		\
			src/builtins/ms_cd.c			\
			src/builtins/cd/cd_path_setup.c		\
			src/builtins/cd/cd_helpers.c		\
			src/builtins/cd/cd_checking.c		\
			src/builtins/cd/cd_path_test.c		\
			src/builtins/cd/cd_path_transform.c	\
			src/builtins/ms_env.c			\
			src/builtins/ms_setenv.c		\
			src/builtins/ms_setenv_checks.c		\
			src/builtins/ms_unsetenv.c		\
			src/builtins/ms_exit.c	
			
MAIN		=	src/main.c

OBJ		=	$(SRC:.c=.o)
OBJ		+=	$(MAIN:.c=.o)

#	Tests settings
TEST_NAME	=	unit_tests
TEST_SRC	=	tests/criterion.c
TEST_FLAGS	=	--coverage -lcriterion

GDB_MAIN	=	src/main.c
GDB_NAME	=	gdb.out


.PHONY: tclean gclean fclean lclean lfclean $(NAME)

all:	lib $(NAME)

#	Library rules
lib:	libh liba

libh:
	@mkdir -p $(HDPATH)
	cp $(LIB_HDS) $(HDPATH)

liba:	$(LIB_OBJ)
	ar rc $(LIB_DIR)/$(LIB_NAME) $^

libclean:
	$(RM) $(LIB_OBJ)

libfclean: libclean
	rm -rf $(LIB_DIR)/$(HDPATH)
	$(RM) $(LIB_DIR)/$(LIB_NAME)

re: libfclean fclean all

#	Program rules
#

$(NAME): lib
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(MAIN) $(SRC) $(LIBFLAG)

clean:
	$(RM) $(OBJ)

fclean:	clean libfclean
	$(RM) $(HDTGR)
	$(RM) $(LIBTGR)
	$(RM) $(NAME)

#	Tests rules
gdb:	gclean lib
	$(DBCC) $(CFLAGS) $(LDFLAGS) -o $(GDB_NAME) $(GDB_MAIN) $(SRC)	\
		$(LIB_SRC) -lgnl

gclean:
	$(RM) $(GDB_NAME)

tests_run:
	$(CC) $(CFLAGS) -o $(TEST_NAME) $(TEST_SRC) $(SRC) $(TEST_FLAGS)
	./$(TEST_NAME)

tclean:
	$(RM) *.gc*
	$(RM) $(TEST_NAME)

cclean: tclean gclean fclean libfclean
