#pragma once

#include "CFigure.h"

class CCircle : public CFigure {
private:
	Point Center;
	Point Radius;
public:
	virtual bool CheckBorder(Point);
	double GetR() const;
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle(Point, int, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* MakeCopy();
	virtual CFigure* Paste(Point P);
	virtual CFigure* newFigure();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &InFile);
};