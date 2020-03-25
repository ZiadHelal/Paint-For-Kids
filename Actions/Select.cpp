#include "Select.h"
#include "D:\CCE\Programming Techniques\Project\Phase2 - Project Framework\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager * pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Action Select: Select a Figure");

	pIn->GetPointClicked(Check.x, Check.y);
	figure = pManager->GetFigure(Check.x, Check.y);


	//pOut->ClearStatusBar();
}

void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (figure == NULL) {
		pOut->ClearStatusBar();
	}
	else if(!figure->IsSelected()) {
		figure->SetSelected(true);
		figure->PrintInfo(pOut);
		}
	else if (figure->IsSelected()) {
		figure->SetSelected(false);
		pOut->ClearStatusBar();
	}
	
	 

	pManager->UpdateInterface();
	
}