#include "PasteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

PasteAction::PasteAction(ApplicationManager *pApp):Action(pApp)
{}

void PasteAction::ReadActionParameters()
{
	Figure = pManager->GetClipboard();
}

void PasteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (Figure == NULL)
	{
		pOut->PrintMessage("NO Figure Selected. Please Select a Figure that is copied or cut.");
	}
	else {
		pOut->PrintMessage("Click at the desired location for the figure.");
		pIn->GetPointClicked(P.x, P.y);
		NewOne = Figure->Paste(P);
		pManager->AddFigure(NewOne);
		//pOut->ClearDrawArea();
		pOut->ClearStatusBar();
		pManager->UpdateInterface();
	}
}	