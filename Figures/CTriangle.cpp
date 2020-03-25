#include "CTriangle.h"
#include <fstream>
#include <iostream>

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


bool CTriangle::CheckBorder(Point P)
{
	double Area = abs((Corner1.x*(Corner2.y - Corner3.y) + Corner2.x*(Corner3.y - Corner1.y) + Corner3.x*(Corner1.y - Corner2.y)) / 2.0);
	double Area1 = abs((P.x*(Corner2.y - Corner3.y) + Corner2.x*(Corner3.y - P.y) + Corner3.x*(P.y - Corner2.y)) / 2.0);
	double Area2 = abs((Corner1.x*(P.y - Corner3.y) + P.x*(Corner3.y - Corner1.y) + Corner3.x*(Corner1.y - P.y)) / 2.0);
	double Area3= abs((Corner1.x*(Corner2.y - P.y) + Corner2.x*(P.y - Corner1.y) + P.x*(Corner1.y - Corner2.y)) / 2.0);
	if (Area == Area1 + Area2 + Area3) {
		return true;
	}
	else {
		return false;
	}
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

void CTriangle::PrintInfo(Output * pOut)
{
	string a = "(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
	string b = "(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	string c = "(" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ")";
	pOut->PrintMessage("Triangle with ID = " + to_string(GetID()) + ": " + "1st Vertex: " + a + " - 2nd Vertex: " + b + " -3rd Vertex: " + c);
}

void CTriangle::Save(ofstream &OutFile)
{
	OutFile << "TRIANG" << "\t" << GetID() << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << Corner3.x << "\t" << Corner3.y << "\t";
	OutFile << clr_to_str(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << clr_to_str(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CTriangle::Load(ifstream &InFile)
{
	string Draw, Fill;
	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y>> Draw >> Fill;
	FigGfxInfo.DrawClr = str_to_clr(Draw);
	if (Fill == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = str_to_clr(Fill);
	}
}
CFigure* CTriangle::MakeCopy()
{
	CFigure* pFig = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
	return pFig;
}

CFigure* CTriangle::Paste(Point P)
{
	Point P1, P2;
	int x, y;
	x = Corner2.x - Corner1.x;
	y = Corner2.y - Corner1.y;
	P1.x = P.x + x;
	P1.y = P.y + y;
	x = Corner3.x - Corner1.x;
	y = Corner3.y - Corner1.y;
	P2.x = P.x + x;
	P2.y = P.y + y;
	CFigure* Figure = new CTriangle(P, P1, P2, FigGfxInfo);
	return Figure;
}

CFigure * CTriangle::newFigure()
{
	CFigure* NewOne = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
	return NewOne;
}