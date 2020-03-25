#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\DrawColorAction.h"
#include "Actions\FillColorAction.h"
#include "Actions\Select.h"
#include "Actions\DeleteAction.h"
#include "Actions\CopyAction.h"
#include "Actions\CutAction.h"
#include "Actions\PasteAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions\To_Play.h"
#include "Actions\ExitAction.h"
#include "Actions\To_Draw.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = GetLastSelected();
	FigCount = 0;
	Clipboard = NULL;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case CHNG_DRAW_CLR:
			pAct = new DrawColorAction(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new FillColorAction(this);
			break;

		case SELECT:
			pAct = new SelectAction(this);
			break;
			
		case DEL:
			pAct = new DeleteAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case SAVE:	
			pAct = new SaveAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;

		case TO_PLAY:
			pAct = new To_Play(this);
			break;

		case CUT:
			pAct = new CutAction(this);
			break;

		case EXIT:
			pAct = new ExitAction(this);
			break;

		case TO_DRAW:
			pAct = new To_Draw(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
void ApplicationManager::SetIDs()
{
	for (int i = 0; i < FigCount - 1; i++)
	{
		FigList[i]->SetID(i + 1);
	}
}

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = FigCount-1; i >= 0 ; i--) {
		if (FigList[i]->CheckBorder({ x,y })) {
			return FigList[i];
		}
	}
	return NULL;
}
///////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetLastSelected() const
{
	for (int i = FigCount-1; i >= 0 ; i--) {
		if (FigList[i]->IsSelected()) {
			return FigList[i];
		}
	}
	return NULL;
}
/////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetSelected(CFigure * GetLastSelected())
{
	SelectedFig = GetLastSelected();
}
//////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::SetClipboard(CFigure * pFig)
{
	Clipboard = GetLastSelected();
}
//////////////////////////////////////////////////////////////////////////////////
bool ApplicationManager::DeleteSelected() {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			delete FigList[i];
			FigList[i] = NULL;
			FigList[i] = FigList[FigCount - 1];
			CFigure *temp = NULL;
			for (int j = i; j < FigCount; j++) {
				temp = FigList[j];
				FigList[j] = FigList[j + 1];
				FigList[j + 1] = temp;
			}
			FigCount--;
			return true;
		}
	}
	return false;
}
//////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::CopySelected()
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()) {
			Clipboard = FigList[i]->newFigure();
			FigList[i]->SetSelected(false);
		}
	}
}

void ApplicationManager::CutSelected()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected()) {
			Clipboard = FigList[i]->newFigure();
			DeleteSelected();
		}
	}
}

CFigure* ApplicationManager::GetClipboard()
{
	return Clipboard;
}

void ApplicationManager::SaveAll(ofstream &OutFile)
{
	OutFile << pOut->getCrntDrawColor1() << "\t" << pOut->getCrntFillColor1() << endl;
	OutFile << FigCount << endl;
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(OutFile);
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Draw(pOut); //Call Draw function (virtual member fn)
		FigList[i]->SetID(i + 1);
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

void ApplicationManager::DeleteFigures()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
}

void ApplicationManager::CleanUp()
{
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
	delete pIn;
	delete pOut;
	///for further cleanup
	pIn = NULL;
	pOut = NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
