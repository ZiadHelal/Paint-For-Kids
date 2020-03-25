#pragma once

#include "CFigure.h"

class CLine : public CFigure {
private:
	Point Start;
	Point End;
public:
	virtual bool CheckBorder(Point);
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* MakeCopy();
	virtual CFigure* Paste(Point P);
	virtual CFigure* newFigure();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &InFile);
};