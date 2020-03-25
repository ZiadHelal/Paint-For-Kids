#pragma once

#include "Action.h"

//Add Circle Action class
class AddCircleAction : public Action
{
private:
	Point Center, Radius; //Circle Center and Radius
	GfxInfo RectGfxInfo;
public:
	AddCircleAction(ApplicationManager *pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute();

};