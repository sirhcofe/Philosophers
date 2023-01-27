NAME		=	libphilo.a

M_OBJS_DIR	=	mandatory/objects/
M_OBJS		=	$(addprefix $(M_OBJS_DIR), $(notdir $(M_SRC:.c=.o)))
M_SRC		=	mando.c		\
				check_arg.c	\
				error.c		\
				ft_atoi.c	\
				init.c

B_OBJS_DIR	=	bonus/objects/
B_OBJS		=	$(addprefix $(B_OBJS_DIR), $(B_SRC:.c=.o))
B_SRC		=	

OBJS_DIR	=	mandatory	\
				bonus

vpath %.c $(OBJS_DIR)

FLAGS		=	-Wall -Wextra -Werror

$(NAME):		$(M_OBJS) $(B_OBJS)
			@ar rc $(NAME) $(M_OBJS) $(B_OBJS)

all:			$(NAME) mphilo

$(M_OBJS_DIR)%.o: %.c
			mkdir -p $(M_OBJS_DIR)
			@echo "Compiling: $<"
			gcc $(FLAGS) -c $< -o $@

mphilo:			mandatory/mando.c
			gcc $(FLAGS) -g3 mando.c -o philo
			@echo " ---------------------------- "
			@echo "|    Mandatory Philo Done    |"
			@echo " ---------------------------- "

bonus:			$(B_OBJS) bphilo
			@ar rc $(NAME) 

clean:
			rm mandatory/objects
			rm bonus/objects

fclean:			clean
			rm ft