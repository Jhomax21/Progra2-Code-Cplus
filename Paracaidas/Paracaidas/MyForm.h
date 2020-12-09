#pragma once
#include "control.h"
namespace Paracaidas {

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
			//
			//TODO: Add the constructor code here
			//
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpmapa = gcnew Bitmap("Imagenes//cielo.png");
			bmpavion = gcnew Bitmap("Imagenes//avion.png");
			bmpgavi= gcnew Bitmap("Imagenes//gaviotas.png");
			bmpp = gcnew Bitmap("Imagenes//person.png");
			bmpavion->MakeTransparent(bmpavion->GetPixel(4,4));
			bmpgavi->MakeTransparent(bmpgavi->GetPixel(0, 0));
			bmpp->MakeTransparent(bmpp->GetPixel(0, 0));
			controladora = new Controller(bmpavion,bmpgavi);
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
		Bitmap^ bmpmapa;
		Bitmap^ bmpavion;
		Bitmap^ bmpgavi;
		Bitmap^ bmpp;
		Controller* controladora;

	private: System::Windows::Forms::Timer^  timer1;
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
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(986, 548);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		buffer->Graphics->Clear(SystemColors::Control);
		buffer->Graphics->DrawImage(bmpmapa, 0, 0, bmpmapa->Width * 1.1, bmpmapa->Height * 0.9);
		controladora->drawEverything(buffer->Graphics,bmpavion);
		controladora->moveEverything(buffer->Graphics);
		controladora->drawgavio(buffer->Graphics, bmpgavi,bmpp);
		controladora->movega(buffer->Graphics);
		controladora->colision(buffer->Graphics, bmpp);
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode) {
		case Keys::G:
			controladora->guardar();
		case Keys::R:
			controladora->restaurar();
		}
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		controladora->restaurar();
	}
	};
}
