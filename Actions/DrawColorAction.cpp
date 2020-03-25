#include "DrawColorAction.h"


#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawColorAction::DrawColorAction(ApplicationManager * pApp) :Action(pApp)
{}

void DrawColorAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	Figure = pManager->GetLastSelected();
	if (Figure == NULL) {
		Selected = false;
		pOut->PrintMessage("Change Draw Color: Select a color");
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
		pOut->PrintMessage("Change Draw Color for selected figure: Select a color");

		Act = pIn->GetUserAction();
		if (Act == BLACK1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Black.");
			FigInfo.DrawClr = BLACK;
			color = 5;
		}
		else if (Act == WHITE1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is White.");
			FigInfo.DrawClr = WHITE;
			color = 4;
		}
		else if (Act == RED1) {
			pOut->ClearStatusBar();
			FigInfo.DrawClr = RED;
			pOut->PrintMessage("Color chosen is Red.");
			color = 2;
		}
		else if (Act == GREEN1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Green.");
			FigInfo.DrawClr = GREEN;
			color = 3;
		}
		else if (Act == BLUE1) {
			pOut->ClearStatusBar();
			pOut->PrintMessage("Color chosen is Blue.");
			FigInfo.DrawClr = BLUE;
			color = 1;
		}
	}
}

void DrawColorAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (Selected) {
		Figure->ChngDrawClr(FigInfo.DrawClr);
		Figure->SetSelected(false);
	}
	else
	{
		pOut->SetDrawColor(color);
	}
}