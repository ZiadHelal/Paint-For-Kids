#include "To_Draw.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"

To_Draw::To_Draw(ApplicationManager* pApp):Action(pApp)
{}

void To_Draw::ReadActionParameters()
{}

void To_Draw::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Switching to Draw Mode. Click anywhere.");
	Point p;
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->DeleteFigures();
	pOut->CreateDrawToolBar();
	pOut->CreateStatusBar();
	ifstream InFile("Original\\Original.txt");
	if (InFile.is_open()) 
	{
		string	Figure, Draw, Fill;
		int FigCount;
		InFile >> Draw >> Fill;
		InFile >> FigCount;
		pOut->SetDrawColor(str_int(Draw));
		pOut->SetFillColor(str_int(Fill));
		for (int i = 0; i < FigCount; i++) {
			GfxInfo GFX = GfxInfo();
			InFile >> Figure;
			Point P = Point();
			if (Figure == "RECT") {
				CRectangle* NewRect = new CRectangle(P, P, GFX);
				NewRect->Load(InFile);
				pManager->AddFigure(NewRect);
			}
			else if (Figure == "TRIANG") {
				CTriangle* NewTri = new CTriangle(P, P, P, GFX);
				NewTri->Load(InFile);
				pManager->AddFigure(NewTri);
			}
			else if (Figure == "LINE") {
				CLine * NewLine = new CLine(P, P, GFX);
				NewLine->Load(InFile);
				pManager->AddFigure(NewLine);
			}
		}
	}
	InFile.close();
}

int To_Draw::str_int(string msg)
{
	if (msg == "BLUE") { return 1; }
	if (msg == "RED") { return 2; }
	if (msg == "GREEN") { return 3; }
	if (msg == "WHITE") { return 4; }
	if (msg == "BLACK") { return 5; }
}