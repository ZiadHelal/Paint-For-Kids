#pragma once

#include "Action.h"

class LoadAction :public Action
{
public:
	LoadAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	int str_int(string msg);
	color str_clr(string msg);
};