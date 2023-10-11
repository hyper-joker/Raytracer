##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	src/vector3D.cpp \
		src/main.cpp \
		src/Sphere.cpp \
		src/rectangle3D.cpp \
		src/Ray.cpp \
		src/Lighting.cpp \
		src/bootstrapMain.cpp \
		src/Camera.cpp \
		src/errors.cpp \
		src/raytracer.cpp \
		src/parser.cpp \
		src/Point3D.cpp \

OBJ	=	$(SRC:.cpp=.o)

NAME =	BS_RAYTRACER

CC	=	g++

RM	=	rm -f

CFLAGS	= -Wall -Wextra -Werror -sfml-graphics -lsfml-window -lsfml-system -I./include

all:    $(NAME)

$(NAME): $(OBJ)
	make

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
