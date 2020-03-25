#pragma once

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	virtual bool CheckBorder(Point);
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual CFigure* MakeCopy();
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* Paste(Point P);
	virtual CFigure* newFigure();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &InFile);
};