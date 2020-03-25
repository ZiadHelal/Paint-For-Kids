#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at center");

	//Read center and store it in Point P 1
	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click for Radius");

	//Read point to get radius and store in point P2
	pIn->GetPointClicked(Radius.x, Radius.y);

	RectGfxInfo.isFilled = pOut->GetFillColor();

	//get drawing, filling colors and pen width from the interface
	
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a circle with the parameters read from the user
	CCircle *C = new CCircle(Center, Radius, RectGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
}