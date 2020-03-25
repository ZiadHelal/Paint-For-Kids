#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include <fstream>
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{}

void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();
	pOut->PrintMessage("Save Graph. Please Enter Name of the file: ");
	File = pIn->GetSrting(pOut);
	pOut->PrintMessage("Saved Success.");
}

void SaveAction::Execute()
{
	ReadActionParameters();
	ofstream SavedFile(File + ".txt");
	pManager->SaveAll(SavedFile);
	SavedFile.close();
}