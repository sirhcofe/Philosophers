NAME		=	libphilo.a

M_OBJS_DIR	=	mandatory/objects/
M_OBJS		=	$(addprefix $(M_OBJS_DIR), $(M_SRC:.c=.o))
M_SRC		=	

B_OBJS_DIR	=	bonus/objects/
B_OBJS		=	$(addprefix $(B_OBJS_DIR), $(B_SRC:.c=.o))
B_SRC		=	

FLAGS		=	-Wall -Wextra -Werror

$(NAME):		$(M_OBJS) $(B_OBJS)
			@ar rc $(NAME) $(M_OBJS) $(B_OBJS)

all:			$(NAME) mphilo

$(M_OBJS_DIR)%.o: %.c
			mkdir -p $(OBJS_DIR)
			@echo "Compiling: $<"
			gcc $(FLAGS) -c $< -o $@

mphilo:			mandatory/mando.c
			gcc $(FLAGS) -g3 mando.c -o philo
			@echo " ---------------------------- "
			@echo "|    Mandatory Philo Done    |"
			@echo " ---------------------------- "

bonus:			$(B_OBJS) bphilo
			@ar rc $(NAME) 