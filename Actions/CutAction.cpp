#include "CutAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Output.h"

CutAction::CutAction(ApplicationManager * pApp):Action(pApp)
{}

void CutAction::ReadActionParameters()
{
	Figure = pManager->GetLastSelected();
}

void CutAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (Figure == NULL) {
		pOut->PrintMessage("Select a Figure First to Cut.");
	}
	else {
		pManager->CutSelected();
		pOut->PrintMessage("Cut Action Succeded");
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
	}
}