#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	virtual bool CheckBorder(Point);
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* MakeCopy();
	virtual CFigure* Paste(Point P);
	virtual CFigure* newFigure();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &InFile);
};

#endif