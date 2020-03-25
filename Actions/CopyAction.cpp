#include "CopyAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

CopyAction::CopyAction(ApplicationManager *pApp) :Action(pApp)
{}

void CopyAction::ReadActionParameters()
{
	pManager->CopySelected();
	Check = pManager->GetClipboard();
}

void CopyAction::Execute()
{

	Output * pOut = pManager->GetOutput();
	ReadActionParameters();
	if (Check == NULL) {	
		pOut->PrintMessage("Please Select a Figure first");
		pManager->UpdateInterface();
	}
	else
	{
		pManager->CopySelected();
		pOut->PrintMessage("Copy Action Succeeded.");

	}
}

CFigure* CopyAction::Copy(CFigure * pFig)
{
	CFigure* Figure = pFig->MakeCopy();
	return Figure;
}