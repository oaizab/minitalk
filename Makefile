SDIR	=	src
SRCSC	=	client/client.c \
			client/init.c \
			client/handler.c \
			client/res.c \
			client/message.c

SRCSS	=	server/server.c \
			server/init.c \
			server/handler.c

SRCSB	=

ODIR	=	obj
OBJSC	=	$(addprefix $(ODIR)/,$(SRCSC:.c=.o))
OBJSS	=	$(addprefix $(ODIR)/,$(SRCSS:.c=.o))

OBJSB	=	$(addprefix $(ODIR)/,$(SRCSB:.c=.o))

IDIR	=	inc
INCL	=	minitalk.h
HEADER	=	$(addprefix $(IDIR)/,$(INCL)) libft/inc/libft.h
INCLUDE	=	-I$(IDIR) -Ilibft/inc

LIBS	=	-Llibft/lib -lft

NAME	=	minitalk
CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror -g
OUTPUT	=	./

# ----------------Colors------------------------------------------------------
BLUE	=	\033[0;34m
CYAN	=	\033[0;36m
GREEN	=	\033[0;32m
YELLOW	=	\033[1;33m
CLEAR	=	\033[m
# ----------------------------------------------------------------------------

all: client server

$(ODIR)/%.o: $(SDIR)/%.c $(HEADER)
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling $(GREEN)$(basename $(@F))$(CLEAR)"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

client: $(OBJSC)
	@echo "------------------------libft-----------------------"
	@make -C libft
	@echo "------------------------done------------------------"
	@mkdir -p $(OUTPUT)
	@echo "$(CYAN)Creating  $(YELLOW)client ...$(CLEAR)"
	@$(CC) $(OBJSC) $(LIBS) -o $(OUTPUT)/client

server: $(OBJSS)
	@echo "------------------------libft-----------------------"
	@make -C libft
	@echo "------------------------done------------------------"
	@mkdir -p $(OUTPUT)
	@echo "$(CYAN)Creating  $(YELLOW)server ...$(CLEAR)"
	@$(CC) $(OBJSS) $(LIBS) -o $(OUTPUT)/server

bonus: server client

clean:
	@make -C libft clean
	@$(RM) $(OBJS) $(OBJSB) $(ODIR)

fclean: clean
	@make -C libft fclean
	@$(RM) $(OUTPUT)/server $(OUTPUT)/client

re: fclean all

.PHONY: all clean fclean re