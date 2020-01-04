NAME =	wolf3d 

CFILES = \
src/general_utils.c\
src/keyhooks.c\
src/main.c\
src/parsing.c\
src/rendering.c

OFILES = $(CFILES:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I inc 
STATIC_LIBS = static_libs/*

all : $(OFILES)  
	gcc $(INCLUDES) $(CFLAGS)  $(OFILES) $(TEST) $(STATIC_LIBS) -o $(NAME) -framework OpenGL -framework Appkit

%.o : %.c
	gcc $(INCLUDES) $(CFLAGS)  -c $< -o $@

clean :
	rm $(OFILES)

fclean : clean
	rm $(NAME)
