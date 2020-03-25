#pragma once

#include "Action.h"

//Add Line Action class
class AddLineAction : public Action
{
private:
	Point Start, End; //Line Start and End
	GfxInfo RectGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads line parameters
	virtual void ReadActionParameters();

	//Add line to the ApplicationManager
	virtual void Execute();

};