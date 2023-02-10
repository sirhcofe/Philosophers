NAME		=	libphilo.a

OBJS_DIR	=	objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))
SRC			=	check_arg.c			\
				execution.c			\
				execution_utils.c	\
				extras.c			\
				init.c				\
				main.c

FLAGS		=	-Wall -Wextra -Werror

all:			$(NAME) philo

$(NAME):		$(OBJS)
			@ar rc $(NAME) $(OBJS)

$(OBJS_DIR)%.o:	%.c
			mkdir -p $(OBJS_DIR)
			@echo "Compiling: $<"
			gcc $(FLAGS) -g3 -c $< -o $@

philo:			$(NAME) main.c
			gcc $(FLAGS) -g3 main.c -L. -lphilo -o philo
			@echo " ---------------------------- "
			@echo "|      Bonus Philo Done      |"
			@echo " ---------------------------- "

clean:
			rm -rf objects

fclean:			clean
			rm libphilo.a
			rm philo

re:				fclean all