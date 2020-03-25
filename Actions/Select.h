#pragma once
#include "Action.h"
#include"..\DEFS.h"
#include "d:\CCE\Programming Techniques\Project\Phase2 - Project Framework\Figures\CFigure.h"


class SelectAction : public Action
{
private:
	Point Check;
	CFigure* figure;
public:
	SelectAction(ApplicationManager *pApp);


	//Reads Select parameters
	virtual void ReadActionParameters();

	//Excute Select Action
	virtual void Execute();
};