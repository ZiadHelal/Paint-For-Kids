
#include "FillColorAction.h"


#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillColorAction::FillColorAction(ApplicationManager * pApp) :Action(pApp)
{}

void FillColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Figure = pManager->GetLastSelected();
	if (Figure == NULL) {
		Selected = false;
		pOut->PrintMessage("Change Fill Color: Select a color");

		Act = pIn->GetUserAction();

		if (Act == BLACK1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Black.");
			color = 5;
		}
		else if (Act == WHITE1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is White.");
			color = 4;
		}
		else if (Act == RED1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Red.");
			color = 2;
		}
		else if (Act == GREEN1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Green.");
			color = 3;
		}
		else if (Act == BLUE1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Blue.");
			color = 1;
		}

	}
	else {
		Selected = true;
		pOut->PrintMessage("Change Fill Color for selected figure: Select a color");

		Act = pIn->GetUserAction();

		if (Act == BLACK1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Black.");
			FigInfo.FillClr = BLACK;
			color = 5;
		}
		else if (Act == WHITE1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is White.");
			FigInfo.FillClr = WHITE;
			color = 4;
		}
		else if (Act == RED1) {
			pOut->ClearStatusBar();
			FigInfo.FillClr = RED;
			pOut->PrintMessage("Color chosen is Red.");
			color = 2;
		}
		else if (Act == GREEN1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Green.");
			FigInfo.FillClr = GREEN;
			color = 3;
		}
		else if (Act == BLUE1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Blue.");
			FigInfo.FillClr = BLUE;
		}
	}
}

void FillColorAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (Selected) {
		Figure->ChngFillClr(FigInfo.FillClr);
		Figure->SetSelected(false);
		pOut->ClearDrawArea();
	}
	else
	{
		//pOut->SetFillColor();
		pOut->SetFillColor(color);
		pOut->SetFillColor();
	}
}