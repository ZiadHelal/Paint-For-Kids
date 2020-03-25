#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::SetID(int n)
{
	ID = n;
}

int CFigure::GetID() const
{
	return ID;
}

string CFigure::clr_to_str(color clr)
{
	if (clr == WHITE) {
		return "WHITE";
	}
	else if (clr == BLACK) {
		return "BLACK";
	}
	else if (clr == BLUE) {
		return "BLUE";
	}
	else if (clr == GREEN) {
		return "GREEN";
	}
	else if (clr == RED) {
		return "RED";
	}
}

color CFigure::str_to_clr(string clr)
{
	if (clr == "WHITE") {
		return WHITE;
	}
	else if (clr == "BLACK") {
		return BLACK;
	}
	else if (clr == "BLUE") {
		return BLUE;
	}
	else if (clr == "GREEN") {
		return GREEN;
	}
	else if (clr == "RED") {
		return RED;
	}
}