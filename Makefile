NAME	=	so_long

SRCS	=	src/check_error.c				src/read_file.c			src/game.c\
			src/init_map.c					src/so_long.c			src/get_next_line_utils.c\
			src/get_next_line.c				src/utils.c				src/check_map.c\
			src/image.c						src/image2.c			src/movement.c\
			src/animation.c					src/ft_itoa.c



HEADER	=	includes/so_long.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

LIBMLX	=	-L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

INC		=	-I includes -I minilibx_opengl_20191021

CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(INC) $(LIBFT) $(LIBMLX) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all
