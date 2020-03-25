#pragma once

#include "Action.h"
#include"..\Figures\CFigure.h"

class ResizeAction :public Action
{
private:
	CFigure* Figure;
	ActionType Type;
public:
	ResizeAction(ApplicationManager* pApp, ActionType A);

	virtual void ReadActionParameters();

	virtual void Execute();
};