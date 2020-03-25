#include "DeleteAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void DeleteAction::ReadActionParameters()
{
	Figure = pManager->GetLastSelected();
}

void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->DeleteSelected()) {
		pOut->ClearDrawArea();
		pOut->PrintMessage("Delete: Successfully deleted selected figure");
		pManager->UpdateInterface();
	}
	else {
		pOut->PrintMessage("No Selected Figure");
	}
	
}