#pragma once

#include "Action.h"

//Add Triangle Action class
class AddTriAction : public Action
{
private:
	Point P1, P2, P3; //Triangles Corners
	GfxInfo RectGfxInfo;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute();

};