#pragma once
#include <list>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "TwoDSpace.h"

#define learningSpeed 0.1
#define cycleOutLimit 800000
#define weightFirstValue 0.1
#define NormalizationFactor 50

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

class SpacePoint;
class Neuron;
class PointClass;
class Network;
class Input {
public:
	Input() {

	}
	double input = 2;
};
class Connection {
	double weight = weightFirstValue;
	Neuron* backNeuronPtr;
	Neuron* frontNeuronPtr;
	Input* input;

	Connection* front;
public:

	Connection(double _weight) {
		weight = _weight;
		backNeuronPtr = nullptr;
	}
	Connection(double _weight, Input* _input) {
		weight = _weight;
		input = _input;
		backNeuronPtr = nullptr;
	}

	Connection* Front() {
		return front;
	}
	void SetFront(Connection* _front) {
		front = _front;
	}
	double GetWeight() {
		return weight;
	}
	double GetValue() {
		if (backNeuronPtr == nullptr) {
			return input->input;
		}
		else {
			//return backNeuronPtr->Getfnet();
		}
	}
	void setInput(double _input) {
		input->input = _input;
	}
	void SetWeight(double _weight) {
		weight = _weight;
	}
};

class SpacePoint {
	int X;
	int Y;
	int Id;
	int classId;
public:
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
	void SetId(int _Id) {

	}
	void SetClassId(int _classId) {
		classId = _classId;
	}
	int GetId() {
		return Id;
	}
	int GetClassId() {
		return classId;
	}
	SpacePoint(int _X, int _Y, int _Id) {
		X = _X;
		Y = _Y;
		Id = _Id;
		classId = _Id;
	}
};
class Neuron
{
	
	double fnet = 0;
	double activeFuncResult = 0;
	std::list<Connection*> Connections;
	int sgn(double number)
	{
		if (number > 0)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	double sigmoid(double number, int delta)
	{
		number = number / 10000;
		//sigmoid fonksiyonu için sonsuz deðerler belirleniyor
		if (exp(-number * delta) == INFINITY) {
			return 1;
		}
		else if (exp(-number * delta) == 0) {
			return -1;
		}
		double t = exp(-1 * delta * number);
		double s = (2 / (1 + t)) - 1;
		return s;
	}
	double tanh(double number)
	{
		return (2 / (1 + exp(-2 * number))) - 1;
	}
public:
	int R = 0;
	int G = 0;
	int B = 0;
	int numberOfCycle = 0;
	int layer = 0;
	int classNumber = 0;
	Neuron() {}
	void addConnection(Connection* _connection) {
		if (!Connections.empty()) {
			Connections.back()->SetFront(_connection);
		}
		Connections.push_back(_connection);
	}
	void TrainAsPerceptronRule(std::list<SpacePoint*> points) {
		int error = 0;
		double inp[3] = { 0 };
		int cycleNumber = 0;
		int d = 0;
		//Eðitim baþlýyor
		while (true)
		{
			//Yeni noktalar eðitilmeden önce hata sýfýrlanýyor
			error = 0;
			//Her nokta için eðitm baþlýyor
			for (auto n : points) {
				//class id'si (1 veya -1) içeri aktarýlýyor
				classNumber = n->GetClassId();
				//input deðerleri baðlara yükleniyor
				inp[0] = n->GetX();
				inp[1] = n->GetY();
				inp[2] = -1;
				//baðlara input deðerleri yükleniyor
				Connections.front()->setInput(inp[0]);
				Connections.front()->Front()->setInput(inp[1]);
				Connections.front()->Front()->Front()->setInput(inp[2]);
				fnet = 0;
				//fnet hesaplanýyor
				for (auto n : Connections) {
					fnet = fnet + n->GetValue() * n->GetWeight();
				}
				//beklenen deðer hesaplanýyor
				d = classNumber - sgn(fnet);
				//aðýrlýklar yeniden iþleniyor
				if (d != 0) {
					//her bað için aðýrlýk hesaplanýyor
					for (auto n : Connections) {
						//w = w(delta) + (learningspeed * (beklenen deðer - sgn(fnet)) * x))
						n->SetWeight(n->GetWeight() + (learningSpeed * (d)*n->GetValue()));
					}
					//eðer beklenen deðer 0 deðilse error döngü sonu için arttýrýlýyor
					error++;
				}
			}
			//Eðer error yoksa dngü bitiyor
			if (error == 0)
			{
				numberOfCycle =  cycleNumber;
				break;
			}
			//Eðer bugda kaldýðý düþünülür ise döngü kýrlýr
			if (cycleNumber > cycleOutLimit)
			{
				numberOfCycle = cycleOutLimit;
				break;
			}
			//Döngü hesaplanýyor
			cycleNumber++;
		}
		numberOfCycle = cycleNumber;
		return;
	}
	int TrainAsDeltaRule(std::list<SpacePoint*> points) {
		double error = 0;
		double totalError = 0;
		double inp[3] = { 0 };
		int cycleNumber = 0;
		double d = 0;
		double o = 0;
		//Eðitim baþlýyor
		while (true)
		{
			//Yeni noktalar eðitilmeden önce hata sýfýrlanýyor
			error = 0;
			totalError = 0;
			//Her nokta için eðitm baþlýyor
			for (auto n : points) {
				//class id'si (1 veya -1) içeri aktarýlýyor
				classNumber = n->GetClassId();
				//input deðerleri baðlara yükleniyor
				inp[0] = n->GetX();
				inp[1] = n->GetY();
				inp[2] = -1;
				//baðlara input deðerleri yükleniyor
				Connections.front()->setInput(inp[0]);
				Connections.front()->Front()->setInput(inp[1]);
				Connections.front()->Front()->Front()->setInput(inp[2]);
				fnet = 0;
				//fnet hesaplanýyor
				for (auto n : Connections) {
					fnet = fnet + n->GetValue() * n->GetWeight();
				}
				
				o = sigmoid(fnet, 2);
				d = classNumber - o;
				//aðýrlýklar yeniden iþleniyor
				if (d != 0) {
					//her bað için aðýrlýk hesaplanýyor
					for (auto n : Connections) {
						//w = w(delta) + (learningspeed * (beklenen deðer - sgn(fnet)* ( 1/2 (beklenen-sgn(fnet))^2 ) * x))
						error = 0.5 * (1 - o * o);
						totalError = totalError + d;
						double delta = learningSpeed * d * error * n->GetValue();
						n->SetWeight(n->GetWeight() + delta);
					}
					//eðer beklenen deðer 0 deðilse error döngü sonu için arttýrýlýyor
				}
			}
			//Eðer error yoksa dngü bitiyor
			if (totalError < 0.00005 && totalError != 0)
			{
				break;
			}
			//Eðer bugda kaldýðý düþünülür ise döngü kýrlýr
			if (cycleNumber > cycleOutLimit)
			{
				cycleNumber = cycleOutLimit;
				break;
			}
			//Döngü hesaplanýyor
			cycleNumber++;
		}
		numberOfCycle =  cycleNumber;
		return cycleNumber;
	}
	double GetFnet() {
		return fnet;
	}
	void SetInputs(double* inputs) {
		int temp = 0;
		for (auto n : Connections) {
			n->setInput(inputs[temp]);
			temp++;
		}
	}
	double* GetWeight() {
		double arr[3];
		int i = 0;
		for (auto n : Connections) {
			arr[i] = n->GetWeight();
			i++;
		}
		return arr;
	}
};

class Network {
	
public:
	std::list<Neuron*> Neurons;
	std::list<SpacePoint*> Points;
	std::list<Input*> Inputs;
	//std:list<Classes*> Classes;
	Network(int input[]) {
		/*
		Neuron* neuron = new Neuron();
		for (int i = 0; i < input; i++) {
			srand(time(0));
			double t = RAND_MAX;
			neuron->addConnection(new Connection(rand() / t));
		}
		Neurons.push_back(neuron);
		*/
		for (int i = 0; i < input[0]; i++) {
			Input* networkInput = new Input();
			Inputs.push_back(networkInput);
		}
		int layer = 0;
		while (input[layer] > 0) {
			layer++;
			//eðer ilk katmansa inputlarý baðlýyoruz
			if (layer == 1) {
				for (int i = 0; i < input[1]; i++) {
					Neuron* neuron = new Neuron();
					neuron->layer = layer;
					for (auto n : Inputs) {
						srand(time(0));
						double t = RAND_MAX;
						neuron->addConnection(new Connection(rand() / t, n));
					}
					Neurons.push_back(neuron);
				}
			}
			//eðer deðilse bir önceki katmanlar baðlanýyor
			else {

			}
		}
	}
	void TrainAsPerceptron(array<NeuralClass^>^ classes) {
		int i = 1;
		for (auto n : Neurons) {
			n->TrainAsPerceptronRule(ConvertClassDesiredNumbersWithNumber(i));
			n->R = classes[i]->color.R;
			n->G = classes[i]->color.G;
			n->B = classes[i]->color.B;
			i++;
		}
	}
	void TrainAsDelta(array<NeuralClass^>^ classes){
		int i = 1;
		for (auto n : Neurons) {
			n->TrainAsDeltaRule(ConvertClassDesiredNumbersWithNumber(i));
			n->R = classes[i]->color.R;
			n->G = classes[i]->color.G;
			n->B = classes[i]->color.B;
			i++;
		}
	}
	//one vs all için class ýd lerinin setliyor.
	std::list<SpacePoint*> ConvertClassDesiredNumbersWithNumber(int id) {
		for (auto n : Points) {
			if (n->GetId() == id) {
				n->SetClassId(-1);
			}
			else {
				n->SetClassId(1);
			}
		}
		return Points;
	}
	void setInput(double* inputs) {
		for (auto n : Neurons) {
			n->SetInputs(inputs);
		}
	}
	double getFnet() {
		return Neurons.back()->GetFnet();
	}
	double* getWeights() {
		return  Neurons.front()->GetWeight();
	}
	void setClass(int id) {
		Neurons.front()->classNumber = id;
	}
	void addPoint(SpacePoint* point) {
		Points.push_back(point);
	}
};
