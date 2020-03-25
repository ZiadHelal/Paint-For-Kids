#include "CCircle.h"
#include <iostream>
#include <fstream>


CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius = P2;
}

CCircle::CCircle(Point P1, int R, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	Radius.x = P1.x;
	Radius.y = P1.y + R;
}


bool CCircle::CheckBorder(Point P) {
	double dist;
	dist = sqrt((double)((Center.x - Radius.x)*(Center.x - Radius.x)) + (double)((Center.y - Radius.y)*(Center.y - Radius.y)));
	double dist1;
	dist1 = sqrt((double)((Center.x - P.x)*(Center.x - P.x)) + (double)((Center.y - P.y)*(Center.y - P.y)));
	if (dist1 <= dist) {
		return true;
	}
	else {
		return false;
	}
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCircle to draw a circle on the screen	
	pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
}

void CCircle::PrintInfo(Output * pOut) 
{
	string a = "(" + to_string(Center.x) + "," + to_string(Center.y) + ")";
	string b = to_string((int)GetR());
	pOut->PrintMessage("Circle with ID = " + to_string(GetID()) + ": " + "Center: " + a + " - Radius: " + b);
}

double CCircle::GetR() const
{
	double dist;
	dist = sqrt((double)((Center.x - Radius.x)*(Center.x - Radius.x)) + (double)((Center.y - Radius.y)*(Center.y - Radius.y)));
	return dist;
}

void CCircle::Save(ofstream &OutFile)
{
	OutFile << "CIRCLE" << "\t" << GetID() << "\t" << Center.x << "\t" << Center.y << "\t" << (int)GetR() << "\t";
	OutFile << clr_to_str(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << clr_to_str(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}
void CCircle::Load(ifstream &InFile)
{
	string Draw, Fill;
	int R;
	InFile >> ID >> Center.x >> Center.y >> R >> Draw >> Fill;
	FigGfxInfo.DrawClr = str_to_clr(Draw);
	if (Fill == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = str_to_clr(Fill);
	}
}

CFigure* CCircle::MakeCopy()
{
	CFigure* pFig = new CCircle(Center, Radius, FigGfxInfo);
	return pFig;
}

CFigure * CCircle::Paste(Point P)
{
	Point P1;
	P1.y = P.y;
	P1.x = P.x + GetR();
	CFigure* Pasted = new CCircle(P, P1, FigGfxInfo);
	return Pasted;
}

CFigure * CCircle::newFigure()
{
	CFigure* NewOne = new CCircle(Center, Radius, FigGfxInfo);
	return NewOne;
}
