#include"ResizeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ResizeAction::ResizeAction(ApplicationManager* pApp, ActionType A):Action(pApp),Type(A)
{}

void ResizeAction::ReadActionParameters()
{
	Figure = pManager->GetLastSelected();
}

void ResizeAction::Execute()
{
/*	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (Figure == NULL) {
		pOut->PrintMessage("NO Selected Figure to resize");
	}
	else {
		if (Type == RE25) {
			pOut->PrintMessage("resizing the fiure by 1/4");
			Figure->Resize(1);
		}
		if (Type == RE50) {
			pOut->PrintMessage("resizing the fiure by 1/2");
			Figure->Resize(2);
		}
		if (Type == RE200) {
			pOut->PrintMessage("resizing the fiure by 2");
			Figure->Resize(3);
		}
		if (Type == RE200) {
			pOut->PrintMessage("resizing the fiure by 4");
			Figure->Resize(4);
		}
	}
	pOut->ClearDrawArea();
	pManager->UpdateInterface();*/
}