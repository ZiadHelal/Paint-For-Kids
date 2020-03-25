#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
	bool Filled;
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void SetDrawColor(int n); // changes current Draw color
	void SetFillColor(int n); // changes current Fill color
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void SetFillColor();
	bool GetFillColor();
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const;
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const;
	void DrawCircle(Point P1, Point P2, GfxInfo CirGfxInfo, bool selected) const;
	
	///Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	string getCrntDrawColor1() const; //get string to current drawing color
 	string getCrntFillColor1() const; //get string to current fill color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif