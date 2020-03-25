#pragma once

#include "Action.h"
#include"..\DEFS.h"
#include "..\Figures\CFigure.h"
#include "..\defs.h"

//Change Draw Color Action class
class DrawColorAction : public Action
{
private:
	ActionType Act;
	bool Selected;
	int color;
	Point ChooseClr;
	CFigure *Figure;
	GfxInfo FigInfo;
public:
	DrawColorAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};