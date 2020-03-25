#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;
	Filled = false;
	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 62;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 8;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}

void Output::SetDrawColor(int n) 
{
	if (n == 1) { UI.DrawColor = BLUE; }
	else if (n == 2) { UI.DrawColor = RED; }
	else if (n == 3) { UI.DrawColor = GREEN; }
	else if (n == 4) { UI.DrawColor = WHITE; }
	else if (n == 5) { UI.DrawColor = BLACK; }
}

void Output::SetFillColor(int n)
{
	if (n == 1) { UI.FillColor = BLUE; }
	else if (n == 2) { UI.FillColor = RED; }
	else if (n == 3) { UI.FillColor = GREEN;}
	else if (n == 4) { UI.FillColor = WHITE; }
	else if (n == 5) { UI.FillColor = BLACK;  }
}

void Output::SetFillColor()
{
	Filled = true;
}

bool Output::GetFillColor() {
	return Filled;
}

Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Rectangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\Circle.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Triangle.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Line.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Black.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\White.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Red.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Blue.jpg";
	MenuItemImages[ITM_CHN_CLR] = "images\\MenuItems\\changecolor.jpg";
	MenuItemImages[ITM_CHN_FILL] = "images\\MenuItems\\Fillcolor.jpg";
	MenuItemImages[ITM_PICK] = "images\\MenuItems\\PickHide.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_DELE] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_SEL] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[ITM_CPY] = "images\\MenuItems\\Copy.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	pWind->DrawRectangle(0, 0, UI.width, 50);

	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICK1] = "images\\MenuItems\\GAMEBEGIN.jpg";
	MenuItemImages[ITM_SHAPE] = "images\\MenuItems\\Shape.jpg";
	MenuItemImages[ITM_COLOR] = "images\\MenuItems\\Color.jpg";
	MenuItemImages[ITM_BOTH] = "images\\MenuItems\\Both.jpg";
	MenuItemImages[ITM_BACK] = "images\\MenuItems\\Back.jpg";


	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

string Output::getCrntDrawColor1() const
{
	if (UI.DrawColor == WHITE) {
		return "WHITE";
	}
	else if (UI.DrawColor == BLACK) {
		return "BLACK";
	}
	else if (UI.DrawColor == BLUE) {
		return "BLUE";
	}
	else if (UI.DrawColor == GREEN) {
		return "GREEN";
	}
	else if (UI.DrawColor == RED) {
		return "RED";
	}
}
string Output::getCrntFillColor1() const 
{
	if (UI.FillColor == WHITE) {
		return "WHITE";
	}
	else if (UI.FillColor == BLACK) {
		return "BLACK";
	}
	else if (UI.FillColor == BLUE) {
		return "BLUE";
	}
	else if (UI.FillColor == GREEN) {
		return "GREEN";
	}
	else if (UI.FillColor == RED) {
		return "RED";
	}
}
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,5);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}
void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 5);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 5);

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}
void Output::DrawCircle(Point P1, Point P2, GfxInfo CirGfxInfo, bool selected) const
{
	int r;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CirGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr, 5);
	drawstyle style;
	if (CirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CirGfxInfo.FillClr);
	}
	else
		style = FRAME;
	r = sqrt(((P1.x - P2.x) * (P1.x - P2.x)) + ((P1.y - P2.y) * (P1.y - P2.y)));

	pWind->DrawCircle(P1.x, P1.y, r, style);
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}
