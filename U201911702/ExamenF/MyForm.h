#pragma once
#include "controladora.h"
#include "archivos.h"
namespace ExamenF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{

			InitializeComponent();
			contador = 0;
			//
			//TODO: Add the constructor code here
			//
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpj = gcnew Bitmap("Imagenes//celes.png");
			bmpr = gcnew Bitmap("Imagenes//rojo.png");
			bmpa = gcnew Bitmap("Imagenes//azul.png");
			archivososes = new File();
			archivososes->readData();
			control = new Controlar(bmpj);
			bmpj->MakeTransparent(bmpj->GetPixel(0, 0));
			bmpr->MakeTransparent(bmpr->GetPixel(0, 0));
			bmpa->MakeTransparent(bmpa->GetPixel(0, 0));
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpj;
		Bitmap^ bmpr;
		Bitmap^ bmpa;
		Controlar* control;
		File* archivososes;
		int contador;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::Timer^  timer5;
	private: System::ComponentModel::IContainer^  components;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Interval = 1000;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(94, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(19, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Tiempo:";
			// 
			// timer4
			// 
			this->timer4->Enabled = true;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// timer5
			// 
			this->timer5->Enabled = true;
			this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(797, 538);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		buffer->Graphics->Clear(Color::Aquamarine);
		control->drawj(buffer->Graphics, bmpj);
		control->drawro(buffer->Graphics, bmpr);
		control->drawa(buffer->Graphics, bmpa);
		control->movea(buffer->Graphics);
		control->moveR(buffer->Graphics);
		control->movej(buffer->Graphics);
		control->colision(buffer->Graphics, bmpj);
		if (contador == archivososes->gett())
		{
			this->timer1->Enabled = false;
			this->timer3->Enabled = false;
			MessageBox::Show("El tiempo termino");
		}
		buffer->Render(g);
	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (control->getr().size() < (rand() % 3) + 1) {
			control->addro(new rojo(25, 25, bmpj->Width, bmpj->Height / 5));
		}
	}
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
		contador++;
		label1->Text = Convert::ToString(contador);
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->timer4->Interval = archivososes->getS()*1000;
		this->timer2->Interval = (archivososes->getS()*2) * 1000;
		this->timer5->Interval = (archivososes->getS() * 3) * 1000;
	}
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (control->getjug().size() < (rand() % 3) + 1) {
		control->addj(new jugador(25, 25, bmpj->Width, bmpj->Height / 5));
	}
}
private: System::Void timer5_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (control->geta().size() < (rand() % 3) + 1) {
		control->adda(new azul(25, 25, bmpa->Width, bmpa->Height / 5));
	}
}
};
}
