#pragma once
#include"Action.h"
#include"..\Figures\CFigure.h"

class PasteAction :public Action
{
private:
	Point P;
	CFigure* Figure;
	CFigure* NewOne;
public:
	PasteAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};