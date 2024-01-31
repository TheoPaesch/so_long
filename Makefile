NAME	:= so_long

CFLAGS	:= -Wextra -Wall -Werror

LIBMLX	:= ./lib/MLX42
LIBMLXA := $(LIBMLX)/build/libmlx42.a
LIBFTA	:= ./lib/libft/libftprintf.a

INCLUDES	:= -I ./include -I ./lib/libft -I ./lib/libft/gnl -I $(LIBMLX)/include

LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)main.c \
			$(SRCDIR)map_parse.c \
			$(SRCDIR)flood_fill.c \
			$(SRCDIR)ft_mapcheck.c \
			$(SRCDIR)graphics.c \
			$(SRCDIR)movement.c \
			$(SRCDIR)sl_error.c \
			$(SRCDIR)helper.c

OBJS	:= ${SRCS:.c=.o}

HEADERS = include/so_long.h

CC		:= cc

all: $(NAME)

$(LIBFTA):
	@make -C ./lib/libft

$(LIBMLXA):
	@if [ ! -d $(LIBMLX) ]; then git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c $(HEADERS) Makefile
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDES) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(LIBMLXA) $(LIBFTA) $(OBJS)
	@$(CC) $(LIBS) $^ -o $(NAME)

clean:
	@make -C ./lib/libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C ./lib/libft fclean
	@rm -rf $(LIBMLX)
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re