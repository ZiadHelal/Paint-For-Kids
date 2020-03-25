#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	BLACK1,			//Color Black
	WHITE1,			//Color White
	RED1,			//Color Red
	GREEN1,			//Color Green
	BLUE1,			//Color Blue
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	SELECT,			//Select a figure
	COPY,			//Copy a figure
	CUT,			//Cut a figure
	PASTE,			//Paste a figure
	EXIT,			//Exit the application
	PICKHIDE,		//Move to Pick&Hide

	RE25,			//Resize 1/4
	RE50,			//Resize 1/2
	RE200,			//Resize 2
	RE400,			//Resize 4

	PICK,			//Shape Type
	HIDE,			//Color Type
	BOTH,			//Both Type

	DRAWING_AREA,	//A click on the drawing area
	PLAY_AREA,		//A click on the playing area

	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders
	
};

#endif