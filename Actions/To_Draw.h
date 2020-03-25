#pragma once

#include "Action.h"

class To_Draw:public Action
{
public:
	To_Draw(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	int str_int(string msg);
};