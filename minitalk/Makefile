

SERVER = server

CLIENT = client

SRC_CLIENT = client.c

SRC_SERVER = server.c

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

OBJ_SERVER = $(SRC_SERVER:.c=.o) 

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC = gcc -g

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): 
			make -C ./libft 
			make -C ./ft_printf
			@echo la libreria risulta compilata o mio signore oscuro
			$(CC) $(FLAGS) -o server $(SRC_SERVER) $(LIBFT) $(PRINTF)

$(CLIENT): 
			make -C ./libft 
			make -C ./ft_printf
			$(CC) $(FLAGS) -o client $(SRC_CLIENT) $(LIBFT) $(PRINTF)

clean: 
			make clean -C ./libft 
			make clean -C ./ft_printf
			$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
			@echo abbiamo rimosso la libreria mio oscuro signore

fclean:		clean 
			make fclean -C ./libft
			make fclean -C ./ft_printf
			$(RM) server client
			@echo abbiamo rimosso la libreria e buttato la spazzatura mio oscuro signore

re:			fclean all 
