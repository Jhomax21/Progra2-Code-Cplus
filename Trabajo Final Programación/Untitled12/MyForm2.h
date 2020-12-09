#pragma once
#include "Controladora.h"
namespace Untitled12 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			m1 = true;
			m2 = true;
			m3 = true;
			m4 = true;
			m5 = true;
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpMapa = gcnew Bitmap("Imagenes//Fondo2.png");
			bmpcn = gcnew Bitmap("Imagenes//Enemy1.png");
			r = gcnew Bitmap("Imagenes//m1.png");
			l = gcnew Bitmap("Imagenes//m2.png");
			control = new controladora();
			//
            //TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		controladora* control;
		Bitmap^ bmpMapa;
		Bitmap^ bmpcn;
		Bitmap^ r;
		Bitmap^ l;
		bool m1,m3,m2,m4,m5;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::Timer^  timer5;
	private: System::Windows::Forms::Timer^  timer6;
	private: System::Windows::Forms::Label^  label1;


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
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer6 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm2::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 9500;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm2::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Interval = 12500;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm2::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Enabled = true;
			this->timer4->Interval = 11500;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm2::timer4_Tick);
			// 
			// timer5
			// 
			this->timer5->Enabled = true;
			this->timer5->Interval = 14000;
			this->timer5->Tick += gcnew System::EventHandler(this, &MyForm2::timer5_Tick);
			// 
			// timer6
			// 
			this->timer6->Enabled = true;
			this->timer6->Interval = 15500;
			this->timer6->Tick += gcnew System::EventHandler(this, &MyForm2::timer6_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(556, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Click a X para cerrar";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(769, 514);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		buffer->Graphics->Clear(SystemColors::Control);
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, bmpMapa->Width * 0.3, bmpMapa->Height * 0.4);
		control->drawcn(buffer->Graphics,bmpcn);
		control->movecorruptn();
		if (!m1) {
			buffer->Graphics->DrawImage(r, 100, 180, r->Width * 0.06, r->Height * 0.06);
		}
		if (!m2) {
			buffer->Graphics->DrawImage(l, 215, 180, l->Width * 0.06, l->Height * 0.06);
		}
		if (!m3)
		{
			r = gcnew Bitmap("Imagenes//m3.png");
		}
		if (!m4)
		{
			l = gcnew Bitmap("Imagenes//m4.png");
		}
		if (!m5)
		{
			r = gcnew Bitmap("Imagenes//m5.png");
		}
		buffer->Render(g);
	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {			
		//this->timer3->Enabled = true;
		m1 = false;
	}
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
		//buffer->Graphics->DrawImage(r, 50, 50, r->Width * 1, r->Height * 1);
	//buffer->Render(g);
		m3 = false;
	}
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
	m2 = false;
}
private: System::Void timer5_Tick(System::Object^  sender, System::EventArgs^  e) {
	m4 = false;
}
private: System::Void timer6_Tick(System::Object^  sender, System::EventArgs^  e) {
	m5 = false;
}
private: System::Void timer7_Tick(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
