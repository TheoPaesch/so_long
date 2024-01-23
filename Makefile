NAME	:= so_long

CFLAGS	:= -Wextra -Wall -Werror -g

SAN_LDFLAG =

LIBMLX	:= ./lib/MLX42

INCLUDES	:= -I ./include -I ./lib/libft -I ./lib/libft/gnl -I $(LIBMLX)/include

LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)main.c \
			$(SRCDIR)map_parse.c \
			$(SRCDIR)flood_fill.c \
			$(SRCDIR)ft_mapcheck.c \
			$(SRCDIR)graphics.c \
			$(SRCDIR)movement.c \
			$(SRCDIR)sl_error.c

OBJS	:= ${SRCS:.c=.o}

HEADERS = include/so_long.h

CC		:= cc

ifdef LEAKS
	SAN_LDFLAG += -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize
endif

all: libmlx $(NAME)

libft:
	@make -C ./lib/libft

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) libft
	@$(CC) $(OBJS) $(LIBS) $(SAN_LDFLAG) ./lib/libft/libftprintf.a -o $(NAME)

clean:
	@make -C ./lib/libft clean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C ./lib/libft fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx