SRCS = main.c addPlayers.c displayPlayersInfos.c utils.c editPlayerInfo.c \
		searchForAplayer.c teamStatistics.c
	
OBJS = $(SRCS:.c=.o)
NAME = projetSAS

$(NAME) : $(OBJS)
	gcc $(OBJS) -o $(NAME)
%.o : %.c header.h
	gcc -c $< -o $@
clean :
	rm -f $(OBJS)
fclean : clean 
	rm -f $(NAME)
re : fclean $(NAME)
	
