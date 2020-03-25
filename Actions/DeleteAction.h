#pragma once

#include "Action.h"
#include "d:/CCE/Programming Techniques/Project/Phase2 - Project Framework/Figures/CFigure.h"

class DeleteAction : public Action
{
private:
	CFigure* Figure;
public:
	DeleteAction(ApplicationManager *pApp);

	//Reads delete parameters
	virtual void ReadActionParameters();

	//delete selected figure
	virtual void Execute();
};