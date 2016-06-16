###############################################################
# Program:
#     Prove 13, Project - Asteroids
#     Brother Comeau, CS165
# Author:
#     Nathan Tagg
###############################################################

OS := $(shell uname)
ifeq ($(OS),Darwin)
	LFLAGS = -framework GLUT -framework OpenGL
else
	LFLAGS = -lglut -lGLU -lGL
endif


###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o 
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h point.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

game.o: game.cpp game.h 
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
