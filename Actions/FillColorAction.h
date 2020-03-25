#pragma once

#include "Action.h"
#include"..\DEFS.h"
#include "..\Figures\CFigure.h"
//Change Fill Color Action class
class FillColorAction : public Action
{
private:
	int color;
	ActionType Act;
	bool Selected;
	CFigure* Figure;
	GfxInfo FigInfo;
public:
	FillColorAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};