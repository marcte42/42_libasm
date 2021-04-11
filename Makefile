NAME = libasm.a

SRC = ./src/ft_strlen.s ./src/ft_strcpy.s ./src/ft_strcmp.s ./src/ft_write.s ./src/ft_read.s ./src/ft_strdup.s ./src/ft_list_size.s ./src/ft_list_push_front.s

OBJ = $(SRC:.s=.o)

.s.o:
	nasm -f elf64 $< -o $@

all : $(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -g -no-pie main.c $(NAME) -o libasm

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf libasm
