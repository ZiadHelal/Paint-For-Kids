#include "CRectangle.h"
#include <fstream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


bool CRectangle::CheckBorder(Point P)
{
	if (P.x >= Corner1.x && P.x <= Corner2.x && P.y >= Corner1.y && P.y <= Corner2.y) {
		return true;
	}
	else {
		return false;
	}
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::PrintInfo(Output * pOut)
{
	string a = "(" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")";
	string b = "(" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	pOut->PrintMessage("Rectangle with ID = " + to_string(GetID()) + ": " + "1st Corner: " + a + " - 2nd Corner: " + b);
}

void CRectangle::Save(ofstream &OutFile)
{
	OutFile << "RECT" << "\t" << GetID() << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t";
	OutFile << clr_to_str(FigGfxInfo.DrawClr) << "\t";
	if (FigGfxInfo.isFilled)
		OutFile << clr_to_str(FigGfxInfo.FillClr) << endl;
	else
		OutFile << "NO_FILL" << endl;
}

void CRectangle::Load(ifstream &InFile)
{
	string Draw, Fill;
	InFile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Draw >> Fill;
	FigGfxInfo.DrawClr = str_to_clr(Draw);
	if (Fill == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = str_to_clr(Fill);
	}
}

CFigure* CRectangle::MakeCopy()
{
	CFigure * pFig = new CRectangle(Corner1, Corner2, FigGfxInfo);
	return pFig;
}

CFigure* CRectangle::Paste(Point P)
{
	int x = Corner2.x - Corner1.x;
	int y = Corner2.y - Corner1.y;
	Point P1;
	P1.x = P.x + x;
	P1.y = P.y + y;
	CFigure* Figure = new CRectangle(P, P1, FigGfxInfo);
	return Figure;
}

CFigure * CRectangle::newFigure()
{
	CFigure* NewOne = new CRectangle(Corner1, Corner2, FigGfxInfo);
	return NewOne;
}