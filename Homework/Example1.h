#include <time.h>
#include <stdlib.h> 
#include "TwoDSpace.h"
#include "DM.h"
#pragma once
class NeuronExample
{
public:
	float input[3] = { 0 };
	float w[3] = { 0 };
	int pointNumber = 0;
	float x1[100];
	float x2[100];
	float x3[100];
	int classId[100];
	float learingSpeed = 0.1;
	float fnet = 0;
	int activeResult = 0;
	NeuronExample()
	{		
		setRandomWeight();
	}
	void setRandomWeight() {
		srand(time(0));
		for (int i = 0; i < 3; i++) {			
			w[i] = rand() / RAND_MAX;
		}
		
	} 
	void fnetCalculate() {
		fnet = 0;
		for (int i = 0; i < 3; i++) {
			fnet = fnet + (w[i] * input[i]);
		}
	}
	int ActiveFunc() {
		if (fnet > 0) {
			activeResult = 1;
		}
		else {
			activeResult = -1;
		}
		return activeResult;
	}/*
	void setPoints(array<SpacePoint^>^ Points) {
		pointNumber = 0;
		for (int i = 0; i < Points->Length; i++) {
			if (Points[i] == nullptr) {
				break;
			}
			pointNumber++;
			x1[i] = Points[i]->GetX();
			x2[i] = Points[i]->GetY();
			x3[i] = -1;
			classId[i] = Points[i]->GetClass();
		}
	}*/
	void Train() {
		for (int i = 0; i < pointNumber; i++) {
			input[0] = x1[i];
			input[1] = x2[i];
			input[2] = x3[i];
			fnetCalculate();
			ActiveFunc();
			if ((classId[i] - activeResult) != 0) {
				w[0] = w[0] + (learingSpeed * (classId[i] - activeResult) * x1[i]);
				w[1] = w[1] + (learingSpeed * (classId[i] - activeResult) * x2[i]);
				w[2] = w[2] + (learingSpeed * (classId[i] - activeResult) * x3[i]);
			}		
		}
	}
	void Trainer(int count) {
		for(int i = 0; i < count; i++)
		{
			Train();
		}
	}
};

