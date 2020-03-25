#pragma once
#include "Action.h"
#include "d:\CCE\Programming Techniques\Project\Phase2 - Project Framework\Figures\CFigure.h"

class CopyAction :public Action
{
private:
	CFigure* Check;
public:
	CopyAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	static CFigure* Copy(CFigure* pFig);

	virtual void Execute();
};