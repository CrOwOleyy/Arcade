##
## EPITECH PROJECT, 2026
## Arcade
## File description:
## Main Makefile
##

NAME = arcade

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -IArcade/src
SHARED_FLAGS = -fPIC -shared

HAS_SDL2_REAL = $(shell pkg-config --exists sdl2 && echo 1 || (test -f /usr/include/SDL2/SDL.h && echo 1 || echo 0))
SDL2_CFLAGS = $(shell pkg-config --cflags sdl2 2>/dev/null || echo "-I/usr/include -I/usr/include/SDL2")
SDL2_LIBS = $(shell pkg-config --libs sdl2 2>/dev/null || echo "-lSDL2") -lSDL2_ttf

SRC_DIR = Arcade/src
CORE_DIR = $(SRC_DIR)/core
GAMES_DIR = $(SRC_DIR)/games
GRAPHICALS_DIR = $(SRC_DIR)/graphicals
LIB_DIR = lib

CORE_SRCS = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/DrawableText/DrawableText.cpp \
	$(SRC_DIR)/GameEvents/GameEvents.cpp \
	$(CORE_DIR)/Menu.cpp \
	$(CORE_DIR)/Keyboard.cpp \
	$(CORE_DIR)/HighScoreManager.cpp \
	$(CORE_DIR)/BackgroundMusicPlayer.cpp \
	$(CORE_DIR)/AudioSystem.cpp \
	$(CORE_DIR)/LibraryHandler.cpp \
	$(CORE_DIR)/ArcadeCore.cpp

NCURSES_SRC = $(GRAPHICALS_DIR)/ncurses/NCurses.cpp
SFML_SRC = $(GRAPHICALS_DIR)/sfml/Sfml.cpp
SDL2_SRC = $(GRAPHICALS_DIR)/sdl2/SDL2Module.cpp
SDL2_STUB_SRC = $(GRAPHICALS_DIR)/sdl2/SDL2Stub.cpp
SNAKE_SRC = $(GAMES_DIR)/Snake.cpp
DEMINEUR_SRC = $(GAMES_DIR)/minesweeper.cpp

ifeq ($(HAS_SDL2_REAL),1)
SDL2_BUILD_SRC = $(SDL2_SRC)
SDL2_BUILD_CFLAGS = $(SDL2_CFLAGS)
SDL2_BUILD_LIBS = $(SDL2_LIBS)
else
SDL2_BUILD_SRC = $(SDL2_STUB_SRC)
SDL2_BUILD_CFLAGS =
SDL2_BUILD_LIBS =
endif

CORE_OBJS = $(CORE_SRCS:.cpp=.o)

NCURSES_LIB = $(LIB_DIR)/arcade_ncurses.so
SFML_LIB = $(LIB_DIR)/arcade_sfml.so
SDL2_LIB = $(LIB_DIR)/arcade_sdl2.so
SNAKE_LIB = $(LIB_DIR)/arcade_snake.so
MINESWEEPER_LIB = $(LIB_DIR)/arcade_minesweeper.so

GRAPHICAL_LIBS = \
	$(NCURSES_LIB) \
	$(SFML_LIB) \
	$(SDL2_LIB)

GAME_LIBS = \
	$(SNAKE_LIB) \
	$(MINESWEEPER_LIB)

ALL_LIBS = $(GRAPHICAL_LIBS) $(GAME_LIBS)

all: $(NAME) $(ALL_LIBS)

core: $(NAME)

games: $(GAME_LIBS)

graphicals: $(GRAPHICAL_LIBS)

$(NAME): $(CORE_OBJS)
	$(CXX) $(CORE_OBJS) -o $(NAME) -ldl -lSDL2

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(NCURSES_LIB): $(NCURSES_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) $(SHARED_FLAGS) $(NCURSES_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o -o $(NCURSES_LIB) -lncurses

$(SFML_LIB): $(SFML_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) $(SHARED_FLAGS) $(SFML_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o -o $(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

$(SDL2_LIB): $(SDL2_BUILD_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) $(SDL2_BUILD_CFLAGS) $(SHARED_FLAGS) $(SDL2_BUILD_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o -o $(SDL2_LIB) $(SDL2_BUILD_LIBS)

$(SNAKE_LIB): $(SNAKE_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) $(SHARED_FLAGS) $(SNAKE_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o -o $(SNAKE_LIB)

$(MINESWEEPER_LIB): $(DEMINEUR_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o | $(LIB_DIR)
	$(CXX) $(CXXFLAGS) $(SHARED_FLAGS) $(DEMINEUR_SRC) Arcade/src/DrawableText/DrawableText.o Arcade/src/GameEvents/GameEvents.o -o $(MINESWEEPER_LIB)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

clean:
	$(RM) $(CORE_OBJS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)
	$(RM) $(ALL_LIBS)

re: fclean all