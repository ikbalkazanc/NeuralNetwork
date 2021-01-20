#pragma once
#include <iostream>
#include <time.h>       
#include <stdlib.h>
#include <math.h>
#include "TwoDSpace.h"
#include "Network.h"
#include "DM.h"

#define COUNT_OF_INPUT 3
#define COUNT_OF_FIRST_LAYER 2


namespace Homework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{

	public:

		Main(void)
		{
			InitializeComponent();
			Space = gcnew TwoDSpace(this->pictureBox);
			//
			//TODO: Add the constructor code here
			//

			network = new Network(new int[] {COUNT_OF_INPUT, COUNT_OF_FIRST_LAYER});
			dm = new DM<int>();
			//example = new NeuronExample();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		DM<int>* dm;
		//NeuronExample* example;
		Network* network;
		TwoDSpace^ Space;
		Color MainColor = Color::Red;
	private: System::Windows::Forms::Label^ cordx;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ cordy;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::Button^ Add;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TrackBar^ trackR;
	private: System::Windows::Forms::Label^ labelR;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TrackBar^ trackG;
	private: System::Windows::Forms::Label^ labelB;
	private: System::Windows::Forms::Label^ labelG;
	private: System::Windows::Forms::TrackBar^ trackB;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ rand;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

	private: System::Windows::Forms::ListBox^ listBox2;

	private: System::Windows::Forms::Button^ clear_button;


	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ normalization;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->cordx = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->cordy = (gcnew System::Windows::Forms::Label());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rand = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelB = (gcnew System::Windows::Forms::Label());
			this->labelG = (gcnew System::Windows::Forms::Label());
			this->labelR = (gcnew System::Windows::Forms::Label());
			this->trackB = (gcnew System::Windows::Forms::TrackBar());
			this->trackG = (gcnew System::Windows::Forms::TrackBar());
			this->trackR = (gcnew System::Windows::Forms::TrackBar());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->clear_button = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->normalization = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// cordx
			// 
			this->cordx->AutoSize = true;
			this->cordx->Location = System::Drawing::Point(839, 12);
			this->cordx->Name = L"cordx";
			this->cordx->Size = System::Drawing::Size(20, 13);
			this->cordx->TabIndex = 1;
			this->cordx->Text = L"X: ";
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 500;
			this->timer->Tick += gcnew System::EventHandler(this, &Main::timer_Tick);
			// 
			// cordy
			// 
			this->cordy->AutoSize = true;
			this->cordy->Location = System::Drawing::Point(880, 12);
			this->cordy->Name = L"cordy";
			this->cordy->Size = System::Drawing::Size(17, 13);
			this->cordy->TabIndex = 3;
			this->cordy->Text = L"Y:";
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(12, 12);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(800, 800);
			this->pictureBox->TabIndex = 10;
			this->pictureBox->TabStop = false;
			this->pictureBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Main::pictureBox_MouseClick);
			// 
			// Add
			// 
			this->Add->Location = System::Drawing::Point(883, 174);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(54, 25);
			this->Add->TabIndex = 11;
			this->Add->Text = L"+";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &Main::Add_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rand);
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->Controls->Add(this->labelB);
			this->groupBox1->Controls->Add(this->labelG);
			this->groupBox1->Controls->Add(this->labelR);
			this->groupBox1->Controls->Add(this->trackB);
			this->groupBox1->Controls->Add(this->trackG);
			this->groupBox1->Controls->Add(this->trackR);
			this->groupBox1->Location = System::Drawing::Point(949, 28);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 171);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Color";
			// 
			// rand
			// 
			this->rand->Location = System::Drawing::Point(129, 137);
			this->rand->Name = L"rand";
			this->rand->Size = System::Drawing::Size(62, 20);
			this->rand->TabIndex = 15;
			this->rand->Text = L"rand";
			this->rand->UseVisualStyleBackColor = true;
			this->rand->Click += gcnew System::EventHandler(this, &Main::rand_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(23, 137);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 20);
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// labelB
			// 
			this->labelB->AutoSize = true;
			this->labelB->Location = System::Drawing::Point(20, 107);
			this->labelB->Name = L"labelB";
			this->labelB->Size = System::Drawing::Size(29, 13);
			this->labelB->TabIndex = 13;
			this->labelB->Text = L"B : 0";
			// 
			// labelG
			// 
			this->labelG->AutoSize = true;
			this->labelG->Location = System::Drawing::Point(20, 65);
			this->labelG->Name = L"labelG";
			this->labelG->Size = System::Drawing::Size(30, 13);
			this->labelG->TabIndex = 13;
			this->labelG->Text = L"G : 0";
			// 
			// labelR
			// 
			this->labelR->AutoSize = true;
			this->labelR->Location = System::Drawing::Point(20, 27);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(42, 13);
			this->labelR->TabIndex = 13;
			this->labelR->Text = L"R : 255";
			// 
			// trackB
			// 
			this->trackB->Location = System::Drawing::Point(70, 98);
			this->trackB->Maximum = 255;
			this->trackB->Name = L"trackB";
			this->trackB->Size = System::Drawing::Size(121, 45);
			this->trackB->TabIndex = 10;
			this->trackB->Scroll += gcnew System::EventHandler(this, &Main::trackB_Scroll);
			// 
			// trackG
			// 
			this->trackG->Location = System::Drawing::Point(70, 65);
			this->trackG->Maximum = 255;
			this->trackG->Name = L"trackG";
			this->trackG->Size = System::Drawing::Size(121, 45);
			this->trackG->TabIndex = 10;
			this->trackG->Scroll += gcnew System::EventHandler(this, &Main::trackG_Scroll);
			// 
			// trackR
			// 
			this->trackR->Location = System::Drawing::Point(70, 27);
			this->trackR->Maximum = 255;
			this->trackR->Name = L"trackR";
			this->trackR->Size = System::Drawing::Size(121, 45);
			this->trackR->TabIndex = 10;
			this->trackR->Scroll += gcnew System::EventHandler(this, &Main::TrackR_Scroll);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(842, 34);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(95, 134);
			this->listBox1->TabIndex = 14;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(828, 34);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(13, 140);
			this->pictureBox2->TabIndex = 15;
			this->pictureBox2->TabStop = false;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(841, 288);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(308, 524);
			this->listBox2->TabIndex = 17;
			// 
			// clear_button
			// 
			this->clear_button->Location = System::Drawing::Point(1065, 205);
			this->clear_button->Name = L"clear_button";
			this->clear_button->Size = System::Drawing::Size(84, 23);
			this->clear_button->TabIndex = 19;
			this->clear_button->Text = L"Clear";
			this->clear_button->UseVisualStyleBackColor = true;
			this->clear_button->Click += gcnew System::EventHandler(this, &Main::clear_button_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(841, 233);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(119, 23);
			this->button5->TabIndex = 22;
			this->button5->Text = L"Perceptron Rule";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Main::button5_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(841, 205);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 23);
			this->button1->TabIndex = 23;
			this->button1->Text = L"Delta Rule";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click_1);
			// 
			// normalization
			// 
			this->normalization->Location = System::Drawing::Point(842, 262);
			this->normalization->Name = L"normalization";
			this->normalization->Size = System::Drawing::Size(119, 23);
			this->normalization->TabIndex = 24;
			this->normalization->Text = L"Normalization";
			this->normalization->UseVisualStyleBackColor = true;
			this->normalization->Click += gcnew System::EventHandler(this, &Main::normalization_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Peru;
			this->ClientSize = System::Drawing::Size(1161, 823);
			this->Controls->Add(this->normalization);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->clear_button);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Add);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->cordy);
			this->Controls->Add(this->cordx);
			this->Name = L"Main";
			this->Text = L"Main";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		Space->Init();
		pictureBox1->BackColor = MainColor;
		timer->Enabled = false;
	}
	private: System::Void pictureBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		cordx->Text = "X :" + e->X.ToString();
		cordy->Text = "Y :" + e->Y.ToString();
		if (listBox1->SelectedIndex > -1) {
			//kordinat düzelemine iþaret konuluyor
			Space->drawMark(e->X, e->Y, Space->Classes[listBox1->SelectedIndex + 1]->color);
			//picturebox koordinat dönüþümü yapýlýyor
			int optX = e->X - Space->Ordinate->GetX();
			int optY = Space->Ordinate->GetY() - e->Y;
			//class'ýn bias deðeri hesaplanýyor
			int classNumber = 0;
			if (listBox1->SelectedIndex == 0) {
				classNumber = 1;
			}
			else if (listBox1->SelectedIndex == 1) {
				classNumber = 2;
			}
			else if (listBox1->SelectedIndex == 2) {
				classNumber = 3;
			}
			else if (listBox1->SelectedIndex == 3) {
				classNumber = 4;
			}
			else if (listBox1->SelectedIndex == 4) {
				classNumber = 5;
			}

			//yeni bir point oluþturuluyor
			SpacePoint* pt = new SpacePoint(optX, optY, classNumber);
			//point memory'e aktarýlýyor2
			network->addPoint(pt);

			listBox2->Items->Add("Class" + (listBox1->SelectedIndex + 1) + "'e noktaeklendi (" + optX + "," + optY + ")");
		}
		else {
			MessageBox::Show("Herhangi bir sýnýf seçilmemiþ.");
		}
	}
	private: System::Void TrackR_Scroll(System::Object^ sender, System::EventArgs^ e) {
		MainColor = Color::FromArgb(trackR->Value, trackG->Value, trackB->Value);
		labelR->Text = "R : " + trackR->Value;
		pictureBox1->BackColor = MainColor;
	}
	private: System::Void trackG_Scroll(System::Object^ sender, System::EventArgs^ e) {
		MainColor = Color::FromArgb(trackR->Value, trackG->Value, trackB->Value);
		labelG->Text = "G : " + trackG->Value;
		pictureBox1->BackColor = MainColor;
	}
	private: System::Void trackB_Scroll(System::Object^ sender, System::EventArgs^ e) {
		MainColor = Color::FromArgb(trackR->Value, trackG->Value, trackB->Value);
		labelB->Text = "B : " + trackB->Value;
		pictureBox1->BackColor = MainColor;
	}
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Space->addClass(MainColor)) {
			listBox1->Items->Add("CLASS" + (Space->getClassNumber()));
			pictureBox2->CreateGraphics()->DrawRectangle(gcnew Pen(MainColor), 0, 13 * (Space->getClassNumber() - 1), 13, 13);
			pictureBox2->CreateGraphics()->DrawLine(gcnew Pen(MainColor), 0, 13 * (Space->getClassNumber() - 1), 13, 13 * (Space->getClassNumber() - 1) + 13);
			pictureBox2->CreateGraphics()->DrawLine(gcnew Pen(MainColor), 13, 13 * (Space->getClassNumber() - 1), 0, 13 * (Space->getClassNumber() - 1) + 13);
			rand_Click(sender, e);
		}
		else {
			MessageBox::Show("Maksimum sýnýf tanýmlamasýna(10) ulaþýldý.");
		}
	}
	private: System::Void rand_Click(System::Object^ sender, System::EventArgs^ e) {
		trackR->Value = Space->generrateRandom() % 255;
		trackG->Value = Space->generrateRandom() % 255;
		trackB->Value = Space->generrateRandom() % 255;
		labelR->Text = "R : " + trackR->Value;
		labelG->Text = "G : " + trackG->Value;
		labelB->Text = "B : " + trackB->Value;
		MainColor = Color::FromArgb(trackR->Value, trackG->Value, trackB->Value);
		pictureBox1->BackColor = MainColor;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//int cycle = network->Neurons.front()->TrainAsPerceptronRule(network->Points);
		int cycle = network->Neurons.front()->TrainAsDeltaRule(network->Points);
		listBox2->Items->Add("W[0]= " + network->getWeights()[0]);
		listBox2->Items->Add("W[1]= " + network->getWeights()[1]);
		listBox2->Items->Add("W[2]= " + network->getWeights()[2]);
		Space->drawFullLine(network->getWeights()[0], network->getWeights()[1], network->getWeights()[2], Color::Blue);
		if (cycle == -1)
		{
			listBox2->Items->Add("1 milyon kere döngü koþuldu ancak eðitim bitmedi.");
		}
		else
		{
			listBox2->Items->Add(cycle + " döngü sayýsý ile eðitim tamamlandý.");
		}

	}

	private: System::Void clear_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Space->Init();
		for (auto n : network->Points) {
			n = nullptr;
		}
		network = new Network(new int[] {COUNT_OF_INPUT, COUNT_OF_FIRST_LAYER});
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		network->Neurons.front()->TrainAsPerceptronRule(network->ConvertClassDesiredNumbersWithNumber(1));
		listBox2->Items->Add("W[0]= " + network->getWeights()[0]);
		listBox2->Items->Add("W[1]= " + network->getWeights()[1]);
		listBox2->Items->Add("W[2]= " + network->getWeights()[2]);
		Space->drawFullLine(network->getWeights()[0], network->getWeights()[1], network->getWeights()[2], Color::Blue);
		if (network->Neurons.front()->numberOfCycle == -1)
		{
			listBox2->Items->Add("2 milyon kere döngü koþuldu ancak eðitim bitmedi.");
		}
		else
		{
			listBox2->Items->Add(network->Neurons.front()->numberOfCycle + " döngü sayýsý ile eðitim tamamlandý.");
		}
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		network->TrainAsPerceptron(Space->Classes);
		int counter = 0;
		for (auto n : network->Neurons) {
			double* arr = n->GetWeight();
			double arr2[] = { arr[0], arr[1], arr[2] };
			listBox2->Items->Add("W[0]= " + arr2[0]);
			listBox2->Items->Add("W[1]= " + arr2[1]);
			listBox2->Items->Add("W[2]= " + arr2[2]);

			Space->drawFullLine(arr2[0], arr2[1], arr2[2], Color::FromArgb(n->R, n->G, n->B));

			if (n->numberOfCycle == cycleOutLimit)
			{
				listBox2->Items->Add(cycleOutLimit + " kere döngü koþuldu ancak eðitim bitmedi.");
			}
			else
			{
				listBox2->Items->Add(n->numberOfCycle + " döngü sayýsý ile eðitim tamamlandý.");
			}
			counter++;
		}


	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		network->TrainAsDelta(Space->Classes);
		int counter = 0;
		for (auto n : network->Neurons) {
			double* arr = n->GetWeight();
			double arr2[] = { arr[0],arr[1],arr[2] };
			listBox2->Items->Add("W[0]= " + arr2[0]);
			listBox2->Items->Add("W[1]= " + arr2[1]);
			listBox2->Items->Add("W[2]= " + arr2[2]);

			Space->drawFullLine(arr2[0], arr2[1], arr2[2], Color::FromArgb(n->R, n->G, n->B));

			if (n->numberOfCycle == cycleOutLimit)
			{
				listBox2->Items->Add(cycleOutLimit + " kere döngü koþuldu ancak eðitim bitmedi.");
			}
			else
			{
				listBox2->Items->Add(n->numberOfCycle + " döngü sayýsý ile eðitim tamamlandý.");
			}
			counter++;
		}
	}
	private: System::Void normalization_Click(System::Object^ sender, System::EventArgs^ e) {
		////////////////////////////////////////////////////
		double mini_batch_mean_x = 0;
		double mini_batch_mean_y = 0;
		for (auto n : network->Points) {
			mini_batch_mean_x = n->GetX() + mini_batch_mean_x;
		}
		for (auto n : network->Points) {
			mini_batch_mean_y = n->GetY() + mini_batch_mean_y;
		}
		mini_batch_mean_x = mini_batch_mean_x / network->Points.size();
		mini_batch_mean_y = mini_batch_mean_y / network->Points.size();
		////////////////////////////////////////////////////
		double mini_batch_variance_x = 0;
		double mini_batch_variance_y = 0;
		for (auto n : network->Points) {
			mini_batch_variance_x = mini_batch_variance_x + ((n->GetX() - mini_batch_mean_x) * (n->GetX() - mini_batch_mean_x));
		}
		for (auto n : network->Points) {
			mini_batch_variance_y = mini_batch_variance_y + ((n->GetY() - mini_batch_mean_y) * (n->GetY() - mini_batch_mean_y));
		}
		mini_batch_variance_x = mini_batch_variance_x / network->Points.size();
		mini_batch_variance_y = mini_batch_variance_y / network->Points.size();
		////////////////////////////////////////////////////
		double normalize_x = 0;
		double normalize_y = 0;
		int new_x = 0;
		int new_y = 0;
		std::list<SpacePoint*> TempPoints = network->Points;
		clear_button_Click(sender, e);
		//her nokta yeniden normalize þekilde oluþturuluyor
		for (auto n : TempPoints) {
			normalize_x = (n->GetX() - mini_batch_mean_x) / Math::Sqrt(mini_batch_variance_x);
			normalize_y = (n->GetY() - mini_batch_mean_y) / Math::Sqrt(mini_batch_variance_y);

			new_x = NormalizationFactor * normalize_x + pictureBox->Size.Width / 2;
			new_y = NormalizationFactor * (-normalize_y) + pictureBox->Size.Height / 2;

			network->addPoint(new SpacePoint(new_x, new_y, n->GetClassId()));
			Space->drawMark(new_x, new_y, Space->Classes[n->GetClassId()]->color);
		}
		////////////////////////////////////////////////////
	}
	};

}
