#pragma once
#include <stdlib.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

ref struct NeuralClass {
	int id;
	Color color;
};
ref class TwoDPoint
{

protected:
	int X;
	int Y;
public:
	TwoDPoint(int _x, int _y) {
		X = _x;
		Y = _y;
	}
	TwoDPoint() {}
	int GetX() {
		return X;
	}
	int GetY() {
		return Y;
	}
	void SetX(int _x) {
		X = _x;
	}
	void SetY(int _y) {
		Y = _y;
	}

	void Set(TwoDPoint^ _point) {
		X = _point->GetX();
		Y = _point->GetY();
	}
};/*
ref class SpacePoint : TwoDPoint
{
	//int id;
	int Class;
	Color color;
public:
	/*int GetId() {
		return id;
	}
	void SetId(int _id) {
		id = _id;
	}
	Color GetColor() {
		return color;
	}
	void SetColor(Color _color) {
		color = _color;
	}
	void SetClass(int _class) {
		Class = _class;
	}
	int GetClass() {
		return Class;
	}
};*/
ref class TwoDSpace
{
public:
	//array<SpacePoint^>^ Points = gcnew array<SpacePoint^>(100);
	array<NeuralClass^>^ Classes = gcnew array<NeuralClass^>(10);
	TwoDPoint^ Ordinate = gcnew TwoDPoint(0, 0);
	TwoDSpace(System::Windows::Forms::PictureBox^ Box) {
		Picture = Box;
		Width = Box->Width;
		Height = Box->Height;
		Bit = gcnew Bitmap(Width, Height);
		//Picture->BackColor = Color::Bisque;
		calculateOrdinatePoint();
		//drawRectangle(0, 0, Width, Height, Color::Bisque);
		//drawGrid(100);


		//drawLine(gcnew Line(1, gcnew TwoDPoint(200, 00)), 2);


	}
	void Init() {
		
		Picture->CreateGraphics()->FillRectangle(Brushes::Bisque, 0, 0, Width, Height);
		drawGrid(20, Color::FromArgb(18, Color::Red));
		drawGrid(100, Color::FromArgb(75, Color::Red));
		drawReferanceLines();
		//drawLine(100, -100, 300, 300, Color::Blue);
		//drawRectangle(100, 100, 20, 20, Color::Blue, 1);
	}
	int generrateRandom() {
		//srand(time(0));
		return rand();
	}
	bool addClass(Color color) {
		if (NumberOfClass < 9) {
			NeuralClass^ Temp_Class = gcnew NeuralClass();
			Temp_Class->color = color;
			NumberOfClass++;
			if (NumberOfClass == 1) {
				Temp_Class->id = 1;
			}
			else if (NumberOfClass == 2) {
				Temp_Class->id = -1;
			}
			else {
				Temp_Class->id = NumberOfClass;
			}
			
			Classes[NumberOfClass] = Temp_Class;

			return true;
		}
		else {
			return false;
		}
	}
	int getPointCount() {
		return PointCount;
	}
	//2 nokta haricinde tüm ekrana çizgi çizdirme eylemi için
	void drawFullLine(double factor1,double factor2,double factor3,Color color) {
		int minX = Width / -2;
		int minY = (factor3 - minX * factor1) / factor2;
		int maxX = Width / 2;
		int maxY = (factor3 - maxX * factor1) / factor2;
		Picture->CreateGraphics()->DrawLine(gcnew Pen(color,2),0,Height/2 - minY,Width,Height/2 - maxY);

		/*
		double y1 = 0;
		for (int i = -Width/2+factor3; i < Width/2+factor3; i++) {
			//y1 = -(factor1 / factor2) * i + factor3 / factor2;
			y1 = (factor3 - factor1 * i) / factor2;
			//y1 = (-(i * factor1) + factor3) / factor2;
			drawFillRectangle(i-factor3,y1,2,2);
		}	*/	
	}
	void drawMark(int x, int y, Color color) {
		Pen^ pen = gcnew Pen(color, 1);
		if (isInPictureBox(x - 5, y - 5)) {
			Picture->CreateGraphics()->DrawRectangle(pen, x - 5, y - 5, 10, 10);
			Picture->CreateGraphics()->DrawLine(pen, x - 5, y - 5, x + 5, y + 5);
			Picture->CreateGraphics()->DrawLine(pen, x - 5, y + 5, x + 5, y - 5);
		}
	}
	int getClassNumber() {
		return NumberOfClass;
	}
private:
	int Width = 0;
	int Height = 0;
	int PointCount = 0;
	int NumberOfClass = 0;
	Bitmap^ Bit;
	PictureBox^ Picture;
	//initialize fonksiyonu. ordinat noktasýný Setliyor
	void drawReferanceLines() {
		drawLine(-Width / 2, 0, Width / 2, 0, Color::Black, 2);
		drawLine(0, -Height / 2, 0, Height / 2, Color::Black, 2);
	}
	void calculateOrdinatePoint() {
		Ordinate->Set(gcnew TwoDPoint(Picture->Width / 2, Picture->Height / 2));
	}
	void drawGrid(int range, Color color) {
		//Veritical Lines
		for (int i = Width / 2; i > -Width / 2; i = i - range) {
			drawLine(i, Height / 2, i, -Height / 2, color, 1);
		}
		//Horizontal Lines
		for (int i = -Height / 2; i < Height / 2; i = i + range) {
			drawLine(Width / 2, i, -Width / 2, i, color, 1);
		}

	}
	void drawLine(int x1, int y1, int x2, int y2, Color color, int width) {
		x1 = Ordinate->GetX() + x1;
		y1 = Ordinate->GetY() - y1;
		x2 = Ordinate->GetX() + x2;
		y2 = Ordinate->GetY() - y2;
		if (isInPictureBox(x1, y1) && isInPictureBox(x2, y2)) {
			Pen^ pen = gcnew Pen(color, width);
			Picture->CreateGraphics()->DrawLine(pen, x1, y1, x2, y2);
		}

	}
	void drawLine(int x1, int y1, int x2, int y2, Color color) {
		x1 = Ordinate->GetX() + x1;
		y1 = Ordinate->GetY() - y1;
		x2 = Ordinate->GetX() + x2;
		y2 = Ordinate->GetY() - y2;
		if (isInPictureBox(x1, y1) && isInPictureBox(x2, y2)) {
			Pen^ pen = gcnew Pen(color, 1);
			Picture->CreateGraphics()->DrawLine(pen, x1, y1, x2, y2);
		}

	}
	void drawLine(TwoDPoint^ pt1, TwoDPoint^ pt2, Color color, int width) {
		pt1->Set(gcnew TwoDPoint(Ordinate->GetX() + pt1->GetX(), Ordinate->GetY() - pt1->GetY()));
		pt2->Set(gcnew TwoDPoint(Ordinate->GetX() + pt2->GetX(), Ordinate->GetY() - pt2->GetY()));
		if (isInPictureBox(pt1->GetX(), pt1->GetY()) && isInPictureBox(pt2->GetX(), pt2->GetY())) {
			Pen^ pen = gcnew Pen(color, width);
			Picture->CreateGraphics()->DrawLine(pen, pt1->GetX(), pt1->GetY(), pt2->GetX(), pt2->GetY());
		}
	}
	void drawRectangle(int x, int y, int width, int height, Color color, int border) {
		Pen^ pen = gcnew Pen(color, border);
		x = Ordinate->GetX() + x - height / 2;
		y = Ordinate->GetY() - y - width / 2;
		if (isInPictureBox(x, y)) {
			Picture->CreateGraphics()->DrawRectangle(pen, x, y, width, height);
		}
	}
	void drawFillRectangle(int x, int y, int width, int height ) {
		x = Ordinate->GetX() + x - height / 2;
		y = Ordinate->GetY() - y - width / 2;
		if (isInPictureBox(x, y)) {
			Picture->CreateGraphics()->FillRectangle(Brushes::Black, x, y, width, height);
		}
	}
	bool isInPictureBox(int x, int y) {
		if (x >= 0 && x <= Width && y >= 0 && y <= Height) {
			return true;
		}
		else {
			return false;
		}
	}
};

