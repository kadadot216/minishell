##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for PSU_minishell1
##

CC		=	gcc
DBCC		=	gcc -g
RM		=	rm -f

#	Library settings
LIB_DIR		=	lib
LIB_NAMEDIR	=	my
LIB_PATH	=	$(LIB_DIR)/$(LIB_NAMEDIR)

LIB_HDPATH	=	$(LIB_PATH)/include

LIB_HDSRC	=	my.h		\
			str.h		\
			strtab.h	\
			debug.h
			

LIB_HDS		=	$(addprefix $(LIB_HDPATH)/, $(LIB_HDSRC))

LIB_SRCS	=	str/my_strcmp.c		\
			str/my_strcpy.c		\
			str/my_strlen.c		\
			str/my_strncat.c	\
			str/my_strncmp.c	\
			str/my_strncpy.c 	\
			str/my_strdup.c 	\
			str/my_memset.c 	\
			str/my_strcat.c 	\
			strtab/my_strtabcpy.c	\
			strtab/my_strtabdup.c	\
			strtab/my_strtablen.c	\
			strtab/my_strtotabpt.c	\
			strtab/my_strtotab.c	\
			strtab/my_free_strtab.c	\
			strtab/my_my_strtab_isempty.c	\
			debug/my_show_word_array.c	\
			my_putchar.c		\
			my_puterror.c		\
			my_putstr.c

LIB_SRC		=	$(addprefix $(LIB_PATH)/, $(LIB_SRCS))
LIB_OBJ		=	$(LIB_SRC:.c=.o)
LIB_NAME	=	lib$(LIB_NAMEDIR).a

#	Program settings
HDPATH		=	./include
CFLAGS		+=	-I$(HDPATH)
NAME		=	mysh
LDFLAGS		=	-L./lib
LIBFLAG		=	-lmy -lgnl
SRC		=	src/checking.c		\
			src/prompt.c		\
			src/my_getenv.c		\
			src/builtins.c		\
			src/launch_cmd.c
			
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

fclean:	clean
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
