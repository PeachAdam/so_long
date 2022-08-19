NAME		=	so_long

SRCS_FILES	= 	${shell find ./src -name "*.c"}	\
				${shell find ./inc/gnl -name "*.c"}

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

LIB_DIR		=	./inc/libft
MLX_DIR		=	mlx

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
RM			=	rm -f

all:		$(NAME)

%.o:		%.c ./inc/so_long.h
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			@make -C $(MLX_DIR)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIB_DIR)/libft.a $(OBJS) -o $(NAME)
			@clear

clean:
			@make clean -C $(MLX_DIR)
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS)

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
