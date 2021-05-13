NAME = libasm.a

SRC = ./src/ft_strlen.s ./src/ft_strcpy.s ./src/ft_strcmp.s ./src/ft_write.s ./src/ft_read.s ./src/ft_strdup.s

SRC_BONUS = ./src/ft_list_size_bonus.s ./src/ft_list_push_front_bonus.s ./src/ft_atoi_base_bonus.s ./src/ft_list_sort_bonus.s

OBJ = $(SRC:.s=.o)

OBJ_BONUS = $(SRC_BONUS:.s=.o)

.s.o:
	nasm -f elf64 $< -o $@

all : $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus : $(OBJ) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf libasm
	rm -rf test
	rm -rf test_bonus

re: fclean all

test: all
	clang-9 -o test main.c -L. -lasm

test_bonus: bonus
	clang-9 -o test_bonus main_bonus.c -L. -lasm

.PHONY: all clean fclean re test test_bonus
