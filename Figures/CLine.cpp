#include "CLine.h"
#include <fstream>

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Start = P1;
	End = P2;
}

bool CLine::CheckBorder(Point P) 
{
	//check if point lies on the line
	double slope;
	slope = (Start.y - End.y) / (Start.x - End.x);
	double slope1;
	slope1 = (Start.y - P.y) / (Start.x - P.x);
	if (slope1 == slope&&P.x >= Start.x&&P.x <= End.x) {
		return true;
	}
	else {
		return false;
	}
}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(Start, End, FigGfxInfo, Selected);
}

void CLine::PrintInfo(Output * pOut)
{
	string a = "(" + to_string(Start.x) + "," + to_string(Start.y) + ")";
	string b = "(" + to_string(End.x) + "," + to_string(End.y) + ")";
	pOut->PrintMessage("Line with ID = " + to_string(GetID()) + ": " + "Start: " + a + " - End: " + b);
}

CFigure* CLine::MakeCopy()
{
	CFigure * pFig = new CLine(Start, End, FigGfxInfo);
	return pFig;
}

CFigure* CLine::Paste(Point P)
{
	int x, y;
	Point P1;
	x = End.x - Start.x;
	y = End.y - Start.y;
	P1.x = x + P.x;
	P1.y = y + P.y;
	CFigure* Figure = new CLine(P, P1, FigGfxInfo);
	return Figure;
}

void CLine::Save(ofstream &OutFile)
{
	OutFile << "LINE" << "\t" << GetID() << "\t" << Start.x << "\t" << Start.y << "\t" << End.x << "\t" << End.y << "\t";
	OutFile << clr_to_str(FigGfxInfo.DrawClr) << endl;
}

void CLine::Load(ifstream &InFile)
{
	InFile >> ID >> Start.x >> Start.y >> End.x >> End.y;
}

CFigure * CLine::newFigure()
{
	CFigure* NewOne = new CLine(Start, End, FigGfxInfo);
	return NewOne;
}
