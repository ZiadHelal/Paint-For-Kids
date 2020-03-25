#include "To_Play.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

To_Play::To_Play(ApplicationManager* pApp) :Action(pApp)
{}

void To_Play::ReadActionParameters() 
{}

void To_Play::Execute()
{
	Output* pOut = pManager->GetOutput();
	Point p;
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Switching to Play Mode: Press anywhere to go to Play Mode.");
	ofstream SavedFile("Original\\Original.txt");
	pManager->SaveAll(SavedFile);
	SavedFile.close();
	pIn->GetPointClicked(p.x, p.y);
	pOut->ClearStatusBar();
	pOut->CreatePlayToolBar();
	pOut->CreateStatusBar();
}