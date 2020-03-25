#include "ExitAction.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


ExitAction::ExitAction(ApplicationManager* pApp):Action(pApp)
{}

void ExitAction::ReadActionParameters()
{}

void ExitAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Exit Action");
	pManager->CleanUp();
}