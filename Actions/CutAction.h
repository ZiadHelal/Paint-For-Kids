#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

class CutAction :public Action
{
private:
	CFigure * Figure;
public:
	CutAction(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};