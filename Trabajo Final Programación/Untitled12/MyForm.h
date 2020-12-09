#pragma once
#include "Controladora.h"
#include "Laberinto.h"
#include"Jugador.h"
#include "File.h"
#include <ctime>
#include "MyForm2.h"
namespace Untitled12 {

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
		MyForm(bool s, int vida, int ali, int fin)
		{
			f = true;
			yi = true;
			p = true;
			op = true;
			asa = true;
			this->vida = vida;
			this->ali = ali;
			this->fin = fin;
			srand(time(NULL));
			InitializeComponent();
			cont = 0;
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);
			bmpbase = gcnew Bitmap("Imagenes//Bases.jpeg");
			bmpbloque = gcnew Bitmap("Imagenes//Bloques.jpeg");
			if (s)
			{
				bmpjugador = gcnew Bitmap("Imagenes//Principal.png");
			}
			else
			if(!s)
			{
				bmpjugador = gcnew Bitmap("Imagenes//Principal_2.png");
			}
			bmpaliado = gcnew Bitmap("Imagenes//aliado.png");
			bmpimpos = gcnew Bitmap("Imagenes//aliadoimp.png");
			bmpEnemy = gcnew Bitmap("Imagenes//Enemy1.png");
			bmpasa = gcnew Bitmap("Imagenes//Assasinn.png");
			person = new Personaje(64, 64);
			bmpportal = gcnew Bitmap("Imagenes//portales.png");
			bmpBandera = gcnew Bitmap("Imagenes//Bandera.png");
			bmpfondo = gcnew Bitmap("Imagenes//Perder.png");
			help = gcnew Bitmap("Imagenes//cura.png");
			ccontroladora = new controladora();
			bmpportal->MakeTransparent(bmpportal->GetPixel(0, 0));
			bmpimpos->MakeTransparent(bmpimpos->GetPixel(0, 0));
			map = new Mapa();
			file = new File();
			file->readData();
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
		controladora* ccontroladora;
		Mapa* map;
		Personaje* person;
		File* file;
		Bitmap^ bmpbloque;
		Bitmap^ bmpbase;
		Bitmap^ bmpjugador;
		Bitmap^ bmpaliado;
		Bitmap^ bmpimpos;
		Bitmap^ bmpEnemy;
		Bitmap^ bmpasa;
		Bitmap^ bmpportal;
		Bitmap^ bmpBandera;
		Bitmap^ bmpfondo;
		Bitmap^ help;
		int cont;
		static int conte;
		int vida,ali,fin;
		int elen,term, asas, term2;
		int i;
		bool f,p,op,asa,yi;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;

	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Timer^  timer5;


	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->SuspendLayout();
				 // 
				 // timer3
				 // 
				 this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				 // 
				 // timer2
				 // 
				 this->timer2->Enabled = true;
				 this->timer2->Interval = 1000;
				 this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label1->Location = System::Drawing::Point(97, 10);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(18, 20);
				 this->label1->TabIndex = 0;
				 this->label1->Text = L"0";
				 this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label2->Location = System::Drawing::Point(12, 9);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(79, 21);
				 this->label2->TabIndex = 1;
				 this->label2->Text = L"Tiempo:";
				 this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
				 // 
				 // timer4
				 // 
				 this->timer4->Enabled = true;
				 this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label3->Location = System::Drawing::Point(203, 10);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(0, 20);
				 this->label3->TabIndex = 2;
				 this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click_1);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label4->Location = System::Drawing::Point(134, 10);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(63, 21);
				 this->label4->TabIndex = 3;
				 this->label4->Text = L"Vidas:";
				 // 
				 // timer5
				 // 
				 this->timer5->Interval = 19500;
				 this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
				 this->ClientSize = System::Drawing::Size(1290, 846);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->label1);
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//if (ccontroladora->getEnemies().size() == 4) {
			//bmpEnemy = gcnew Bitmap("Imagenes//assasin.png");
		//}
		asas = 0.6*ali;
		term2= 0.6*ali;
		elen = 0.4*ali;
		term = 0.4*ali;
		buffer->Graphics->Clear(SystemColors::Control);
		ccontroladora->colision(buffer->Graphics);
		if (!ccontroladora->t())
		{
			vida--;
		}
		if (ccontroladora->curo() == 1)
		{
			vida++;
		}
		if (!ccontroladora->pls())
		{
			vida--;
		}
		if (term == ccontroladora->ce() && op )
		{
			MyForm2^ m = gcnew MyForm2();
			m->Show();
			op = false;
			f = false;
			p = false;
			this->timer5->Enabled = true;
		}
		ccontroladora->dibujo(buffer->Graphics, bmpbase, bmpbloque, bmpjugador, bmpaliado, map->getmat(), bmpportal, bmpBandera);
		buffer->Graphics->DrawImage(help, 500, 400, 50,50);
		ccontroladora->drawEverything(buffer->Graphics, bmpEnemy, map->getmat());
		ccontroladora->colisio(buffer->Graphics);
		ccontroladora->drawa(buffer->Graphics, bmpaliado);
		ccontroladora->movea(buffer->Graphics);
		if (cont % 10 == 0) {
			cont += 1;
			ccontroladora->validarTP();
		}
		ccontroladora->drawasa(buffer->Graphics, bmpasa, map->getmat());
		ccontroladora->colisi(buffer->Graphics);
		ccontroladora->moveasa(buffer->Graphics);
		ccontroladora->cso(buffer->Graphics);
		ccontroladora->drawimp(buffer->Graphics, bmpimpos);
		ccontroladora->moveimp(buffer->Graphics);
		ccontroladora->cols(buffer->Graphics);
		if (!ccontroladora->tow())
		{
			vida--;
		}
		if (vida == 0) {
			ccontroladora->perdiste(buffer->Graphics, bmpfondo);
			this->timer1->Enabled = false;
			this->timer2->Enabled = false;
		}
		if (!ccontroladora->ganador()) {
			bmpfondo = gcnew Bitmap("Imagenes//win.png");
			this->timer1->Enabled = false;
			this->timer2->Enabled = false;
		}
		if (cont == fin)
		{
			ccontroladora->perdiste(buffer->Graphics, bmpfondo);
			this->timer1->Enabled = false;
			this->timer2->Enabled = false;
		}
		ccontroladora->ganar(buffer->Graphics, bmpfondo);
		ccontroladora->curar();
		buffer->Render(g);
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		ccontroladora->mapaleatorio();
		timer3->Interval = file->getN() * 1000;
		timer3->Enabled = true;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode) {
		case Keys::Left:
			ccontroladora->moverp(buffer->Graphics, 75); break;
		case Keys::Right:
			ccontroladora->moverp(buffer->Graphics, 77); break;
			
		case Keys::Up:
			ccontroladora->moverp(buffer->Graphics, 72); break;
			
		case Keys::Down:
			ccontroladora->moverp(buffer->Graphics, 80); break;
		}
	}
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		cont++;
		label1->Text = Convert::ToString(cont);
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
		//int enem;

		//enem = 0.4*ali;
		//elen = 2;
		if (ccontroladora->getEnemies().size() == term)
		{
			f = false;
		}
		if (f) {
			if (ccontroladora->getEnemies().size() < elen) {
				ccontroladora->addEnemy(new Enemy(64, 64,
					file->getRandX(), file->getRandY()));
			}
		}
		if (ccontroladora->getaliado().size() == ali)
		{
			p = false;
		}
		if (p) {
			if (ccontroladora->getaliado().size() < ali) {
				ccontroladora->adda(new aliado((rand() % 900)+100, (rand() % 450) + 50, (rand() % 100) + 20));
			}//550,400
		}
		if (ccontroladora->getasa().size() == asas)
		{
			yi = false;
		}
		if (yi) {
			if (!asa) {
				if (ccontroladora->getasa().size() < asas) {
					ccontroladora->addasa(new Assasin(64, 64,
						file->getRandX(), file->getRandY()));
				}
			}
		}

	
		//if (file->getRandX() == person->getX() && file->getRandY() == person->getY() )
		//{
			//MessageBox::Show("colision");

		//}
	}
	private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
		ccontroladora->moveall();
		ccontroladora->moveEverything(buffer->Graphics);
		if (!ccontroladora->a() || !ccontroladora->i())
		{
			if (ccontroladora->getimp().size() < 1) {
				ccontroladora->addimp(new Impostor(300,300,1));
				ccontroladora->getimp().size() == 0;
			}
		}
		label3->Text = Convert::ToString(vida);
		buffer->Render(g);
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label3_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer5_Tick(System::Object^  sender, System::EventArgs^  e) {
		asa = false;
	}
};
}
