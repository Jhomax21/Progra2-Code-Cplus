#pragma once

namespace Project54 {

	using namespace System;//String, Rectangle 
	using namespace System::ComponentModel;//Controles, componentes
	using namespace System::Collections;//Colecciones de objetos
	using namespace System::Windows::Forms;//Form
	using namespace System::Data;//Cargar datos de una BD
	using namespace System::Drawing;//Dibujar, Imágenes, Rectas, Circulos...

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_dibujar;
	protected:
	private: System::Windows::Forms::GroupBox^ gbx_primitiva;
	private: System::Windows::Forms::RadioButton^ rdb_rectangulo;
	private: System::Windows::Forms::RadioButton^ rdb_circulo;
	private: System::Windows::Forms::RadioButton^ rdb_recta;
	private: System::Windows::Forms::Button^ btn_borrar;




	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;




	protected:

	protected:

	private:
		System::ComponentModel::Container ^components;
		void InitializeComponent(void)
		{
			this->btn_dibujar = (gcnew System::Windows::Forms::Button());
			this->gbx_primitiva = (gcnew System::Windows::Forms::GroupBox());
			this->rdb_rectangulo = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_circulo = (gcnew System::Windows::Forms::RadioButton());
			this->rdb_recta = (gcnew System::Windows::Forms::RadioButton());
			this->btn_borrar = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->gbx_primitiva->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_dibujar
			// 
			this->btn_dibujar->Location = System::Drawing::Point(16, 207);
			this->btn_dibujar->Margin = System::Windows::Forms::Padding(4);
			this->btn_dibujar->Name = L"btn_dibujar";
			this->btn_dibujar->Size = System::Drawing::Size(235, 28);
			this->btn_dibujar->TabIndex = 2;
			this->btn_dibujar->Text = L"Dibujar";
			this->btn_dibujar->UseVisualStyleBackColor = true;
			this->btn_dibujar->Click += gcnew System::EventHandler(this, &MyForm::dibujar_primitiva);
			// 
			// gbx_primitiva
			// 
			this->gbx_primitiva->Controls->Add(this->rdb_rectangulo);
			this->gbx_primitiva->Controls->Add(this->rdb_circulo);
			this->gbx_primitiva->Controls->Add(this->rdb_recta);
			this->gbx_primitiva->Location = System::Drawing::Point(16, 15);
			this->gbx_primitiva->Margin = System::Windows::Forms::Padding(4);
			this->gbx_primitiva->Name = L"gbx_primitiva";
			this->gbx_primitiva->Padding = System::Windows::Forms::Padding(4);
			this->gbx_primitiva->Size = System::Drawing::Size(235, 167);
			this->gbx_primitiva->TabIndex = 3;
			this->gbx_primitiva->TabStop = false;
			this->gbx_primitiva->Text = L"Primitva Grafica";
			// 
			// rdb_rectangulo
			// 
			this->rdb_rectangulo->AutoSize = true;
			this->rdb_rectangulo->Location = System::Drawing::Point(21, 79);
			this->rdb_rectangulo->Margin = System::Windows::Forms::Padding(4);
			this->rdb_rectangulo->Name = L"rdb_rectangulo";
			this->rdb_rectangulo->Size = System::Drawing::Size(101, 21);
			this->rdb_rectangulo->TabIndex = 2;
			this->rdb_rectangulo->Text = L"Rectángulo";
			this->rdb_rectangulo->UseVisualStyleBackColor = true;
			// 
			// rdb_circulo
			// 
			this->rdb_circulo->AutoSize = true;
			this->rdb_circulo->Location = System::Drawing::Point(21, 121);
			this->rdb_circulo->Margin = System::Windows::Forms::Padding(4);
			this->rdb_circulo->Name = L"rdb_circulo";
			this->rdb_circulo->Size = System::Drawing::Size(72, 21);
			this->rdb_circulo->TabIndex = 1;
			this->rdb_circulo->Text = L"Círculo";
			this->rdb_circulo->UseVisualStyleBackColor = true;
			// 
			// rdb_recta
			// 
			this->rdb_recta->AutoSize = true;
			this->rdb_recta->Checked = true;
			this->rdb_recta->Location = System::Drawing::Point(21, 38);
			this->rdb_recta->Margin = System::Windows::Forms::Padding(4);
			this->rdb_recta->Name = L"rdb_recta";
			this->rdb_recta->Size = System::Drawing::Size(66, 21);
			this->rdb_recta->TabIndex = 0;
			this->rdb_recta->TabStop = true;
			this->rdb_recta->Text = L"Recta";
			this->rdb_recta->UseVisualStyleBackColor = true;
			// 
			// btn_borrar
			// 
			this->btn_borrar->Location = System::Drawing::Point(16, 242);
			this->btn_borrar->Margin = System::Windows::Forms::Padding(4);
			this->btn_borrar->Name = L"btn_borrar";
			this->btn_borrar->Size = System::Drawing::Size(235, 28);
			this->btn_borrar->TabIndex = 4;
			this->btn_borrar->Text = L"Borrar";
			this->btn_borrar->UseVisualStyleBackColor = true;
			this->btn_borrar->Click += gcnew System::EventHandler(this, &MyForm::borrar_formulario);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(258, 36);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 22);
			this->numericUpDown1->TabIndex = 11;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(460, 93);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 22);
			this->numericUpDown2->TabIndex = 12;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(258, 93);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 22);
			this->numericUpDown3->TabIndex = 13;
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(460, 36);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(120, 22);
			this->numericUpDown4->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(138, 377);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 36);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Login";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(113, 298);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 16;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(113, 335);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 17;
			this->textBox2->UseSystemPasswordChar = true;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 301);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(57, 17);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Usuario";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(22, 340);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 17);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Contraseña";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1365, 453);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->btn_borrar);
			this->Controls->Add(this->gbx_primitiva);
			this->Controls->Add(this->btn_dibujar);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Mi Formulario";
			this->gbx_primitiva->ResumeLayout(false);
			this->gbx_primitiva->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void dibujar_primitiva(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graficador = this->CreateGraphics();
		int x = Int16::Parse(numericUpDown1->Text);
		int y = Int16::Parse(numericUpDown4->Text);
		int x1 = Int16::Parse(numericUpDown3->Text);
		int y1 = Int16::Parse(numericUpDown2->Text);
		
		Point p1 = Point(x, y);
		Point p2 = Point(x1, y1);
		Pen^ lapicero = gcnew Pen(Color::Red, 5);
		if (rdb_recta->Checked)
		{
			graficador->DrawLine(lapicero, p1, p2);
		}
		Rectangle area_rectangulo = Rectangle(x, y, 500, 300);
		if (rdb_rectangulo->Checked)
		{
		
			graficador->DrawRectangle(lapicero, area_rectangulo);
		}
		if (rdb_circulo->Checked)
		{
			graficador->DrawEllipse(lapicero, area_rectangulo);
	    }
	}
	private: System::Void borrar_formulario(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graficador = this->CreateGraphics();
		graficador->Clear(Color::White);
	}

private: System::Void domainUpDown1_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void domainUpDown3_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void domainUpDown2_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void domainUpDown4_SelectedItemChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
  
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
 private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	 
	 if (textBox1->Text == "hola" && textBox2->Text=="chau")
	 {
		 MessageBox::Show("Bienvenido");
	 }
	 else 
     if (textBox1->Text != "hola" && textBox2->Text == "chau")
		 {
			 MessageBox::Show("El usuario es incorrecto");
		 }
	 else
		 if (textBox1->Text != "hola" && textBox2->Text != "chau")
		 {
			 MessageBox::Show("El usuario y la contraseña no son correctos");
		 }
	 else
	 {
		 MessageBox::Show("La Contraseña no es correcta");
	 }
 }
};
}
