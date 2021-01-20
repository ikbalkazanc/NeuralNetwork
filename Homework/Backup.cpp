/*
void drawReferanceLines() {
	Line^ verticalLine = gcnew Line(Vertical, gcnew TwoDPoint(400, 400));
	Line^ horizontalLine = gcnew Line(Horizontal, gcnew TwoDPoint(400, 400));
	drawLine(verticalLine, 2, Color::Black);
	drawLine(horizontalLine, 2, Color::Black);
}
void drawGrid(int range) {
	Line^ verticalLine;
	Line^ horizontalLine;
	//Horizontal
	for (int i = Width / 2; i < Width; i = i + range) {
		horizontalLine = gcnew Line(Horizontal, gcnew TwoDPoint(400, i));
		drawLine(horizontalLine, 1, Color::Red);
	}
	for (int i = Width / 2; i > 0; i = i - range) {
		horizontalLine = gcnew Line(Horizontal, gcnew TwoDPoint(i, i));
		drawLine(horizontalLine, 1, Color::Red);
	}
	//Vertical
	for (int i = Height / 2; i < Height; i = i + range) {
		verticalLine = gcnew Line(Vertical, gcnew TwoDPoint(i, i));
		drawLine(verticalLine, 1, Color::Red);
	}
	for (int i = Height / 2; i > 0; i = i - range) {
		verticalLine = gcnew Line(Vertical, gcnew TwoDPoint(i, i));
		drawLine(verticalLine, 1, Color::Red);
	}
}
void drawLine(Line^ _line) {
	//Eðik çizgileri çiziyor
	if (_line->GetLineType() == Slant) {
		for (int i = (-1) * _line->GetCenterPoint()->GetX(); i < Width; i++) {
			drawRectangle(i + _line->GetCenterPoint()->GetX(), (i - (Width / 2)) * _line->GetSlope() * (-1) + Ordinate->GetY() - _line->GetCenterPoint()->GetY(), 1, 1, Color::Black);
		}
	}
	//dikey çizgileri çiziyor
	else if (_line->GetLineType() == Vertical) {
		for (int i = 0; i < Height; i++) {
			drawRectangle(_line->GetCenterPoint()->GetX(), i, 1, 1, Color::Black);
		}
	}
	//yatay çizgileri çiziyor
	else if (_line->GetLineType() == Horizontal) {
		for (int i = 0; i < Width; i++) {
			drawRectangle(i, _line->GetCenterPoint()->GetY(), 1, 1, Color::Black);
		}
	}
}
void drawLine(Line^ _line, int bold, Color color) {
	//Eðik çizgileri çiziyor
	if (_line->GetLineType() == Slant) {
		for (int i = (-1) * _line->GetCenterPoint()->GetX(); i < Width; i++) {
			drawRectangle(i + _line->GetCenterPoint()->GetX(), (i - (Width / 2)) * _line->GetSlope() * (-1) + Ordinate->GetY() - _line->GetCenterPoint()->GetY(), bold, bold, color);
		}
	}
	//dikey çizgileri çiziyor
	else if (_line->GetLineType() == Vertical) {
		for (int i = 0; i < Height; i++) {
			drawRectangle(_line->GetCenterPoint()->GetX(), i, bold, bold, color);
		}
	}
	//yatay çizgileri çiziyor
	else if (_line->GetLineType() == Horizontal) {
		for (int i = 0; i < Width; i++) {
			drawRectangle(i, _line->GetCenterPoint()->GetY(), bold, bold, color);
		}
	}
}
void drawLine(Line^ _line, int bold) {
	//Eðik çizgileri çiziyor
	if (_line->GetLineType() == Slant) {
		for (int i = (-1) * _line->GetCenterPoint()->GetX(); i < Width; i++) {
			drawRectangle(i + _line->GetCenterPoint()->GetX(), (i - (Width / 2)) * _line->GetSlope() * (-1) + Ordinate->GetY() - _line->GetCenterPoint()->GetY(), bold, bold, Color::Black);
		}
	}
	//dikey çizgileri çiziyor
	else if (_line->GetLineType() == Vertical) {
		for (int i = 0; i < Height; i++) {
			drawRectangle(_line->GetCenterPoint()->GetX(), i, bold, bold, Color::Black);
		}
	}
	//yatay çizgileri çiziyor
	else if (_line->GetLineType() == Horizontal) {
		for (int i = 0; i < Width; i++) {
			drawRectangle(i, _line->GetCenterPoint()->GetY(), bold, bold, Color::Black);
		}
	}
}
//picbox güncelliyor
void update() {
	Picture->Image = Bit;
}
void drawRectangle(int x, int y, int width, int height) {
	for (int i = y; i < y + height; i++) {
		for (int j = x; j < x + width; j++) {
			drawPoint(j, i, Color::Black);
		}
	}
	update();
}
void drawRectangle(int x, int y, int width, int height, Color color) {
	for (int i = y; i < y + height; i++) {
		for (int j = x; j < x + width; j++) {
			drawPoint(j, i, color);
		}
	}
	update();
}
void drawPoint(int x, int y, Color color) {
	//sadece picture box içini boyuyuor.
	if (x < Width && x > 0 && y < Height && y > 0) {
		Bit->SetPixel(x, y, color);
	}
}*/


#pragma once/*
#include "TwoDPoint.h"
enum LineType {
	Horizontal,
	Vertical,
	Slant
};
ref class Line
{
public:
	Line(double _slope) {
		slope = _slope;
	}
	Line(double _slope,TwoDPoint^ _center) {
		slope = _slope;
		center = _center;
	}
	Line(LineType _type) {
		Type = _type;
	}
	Line(LineType _type, TwoDPoint^ _center) {
		Type = _type;
		center = _center;
	}
	double GetSlope() {
		return slope;
	}
	void SetSlope(double _slope) {
		slope = _slope;
	}
	TwoDPoint^ GetCenterPoint() {
		return center;
	}
	void SetCenterPoint(TwoDPoint^ _center) {
		center = _center;
	}
	LineType GetLineType() {
		return Type;
	}
private:
	double slope;
	LineType Type = Slant;
	TwoDPoint^ center = gcnew TwoDPoint(0,0);
};
*/
