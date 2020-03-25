#pragma once
#include "Action.h"

class To_Play :public Action
{
public:
	To_Play(ApplicationManager * pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};