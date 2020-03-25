#include "LoadAction.h"
#include <fstream>
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"

LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{}

void LoadAction::ReadActionParameters()
{}

void LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Action: Please Enter File Name: ");
	string FileName = pIn->GetSrting(pOut);
	ifstream InFile(FileName + ".txt");
	if (InFile.is_open()) {
		pOut->ClearDrawArea();
		pManager->DeleteFigures();
		string	Figure, Draw, Fill;
		int FigCount;
		InFile >> Draw >> Fill;
		InFile >> FigCount;
		pOut->SetDrawColor(str_int(Draw));
		pOut->SetFillColor(str_int(Fill));
		GfxInfo FigInfo;
		FigInfo.isFilled = false;
		FigInfo.BorderWdth = 8;
		for (int i = 0; i < FigCount; i++) {
			InFile >> Figure;
			Point P1, P2, P3;
			P1.x = 0;
			P1.x = 0;
			P2.x = 0;
			P2.x = 0;
			P3.x = 0;
			P3.x = 0;
			CFigure* pFig;
			if (Figure == "RECT") {
				pFig = new CRectangle(P1, P2, FigInfo);
			}
			else if (Figure == "TRIANG") {
				pFig = new CTriangle(P1, P2, P3, FigInfo);
			}
			else if (Figure == "CIRCLE") {
				pFig = new CCircle(P1, 0, FigInfo);
			}
			else if (Figure == "LINE") {
				pFig = new CLine(P1, P2, FigInfo);
			}
			pFig->Load(InFile);
			pManager->AddFigure(pFig);
		}
	}
	InFile.close();
}
	
int LoadAction::str_int(string msg)
{
	if (msg == "BLUE") { return 1; }
	if (msg == "RED") { return 2; }
	if (msg == "GREEN") { return 3; }
	if (msg == "WHITE") { return 4; }
	if (msg == "BLACK") { return 5; }
}
color LoadAction::str_clr(string msg)
{
	if (msg == "BLUE") { return BLUE; }
	if (msg == "RED") { return RED; }
	if (msg == "GREEN") { return GREEN; }
	if (msg == "WHITE") { return WHITE; }
	if (msg == "BLACK") { return BLACK; }
}