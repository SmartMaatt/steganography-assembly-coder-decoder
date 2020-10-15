#pragma once

namespace SteganographyJA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyść wszystkie używane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panelButton1;
	protected:
	private: System::Windows::Forms::Panel^  panel2;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButtonEncode;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Label^  InfoLabel1;
	private: System::Windows::Forms::TextBox^  infoTextBox;
	private: System::Windows::Forms::Panel^  panelControl;
	private: System::Windows::Forms::Panel^  panelButtons;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  threadsLabel;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::RadioButton^  radioButtonC;
	private: System::Windows::Forms::RadioButton^  radioButtonASM;
	private: System::Windows::Forms::Panel^  panel3;

	private: System::Windows::Forms::Panel^  panelLogo;
	private: System::Windows::Forms::Label^  MainLabel;
	private: System::Windows::Forms::Button^  showFileButton;
	private: System::Windows::Forms::Button^  saveFileButton;
	private: System::Windows::Forms::Button^  encryptButton;
	private: System::Windows::Forms::Button^  ChessButton;
	private: System::Windows::Forms::Panel^  panelBottom;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::TextBox^  plainTextBox;
	private: System::Windows::Forms::Panel^  panelMain;
	private: System::Windows::Forms::Label^  modeLabel;
	private: System::Windows::Forms::Label^  algorythmLabel;

	protected:





























	protected:























	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obsługi projektanta — nie należy modyfikować
		/// jej zawartości w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panelButton1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonEncode = (gcnew System::Windows::Forms::RadioButton());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->InfoLabel1 = (gcnew System::Windows::Forms::Label());
			this->infoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->panelControl = (gcnew System::Windows::Forms::Panel());
			this->panelButtons = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->threadsLabel = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->radioButtonC = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonASM = (gcnew System::Windows::Forms::RadioButton());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panelLogo = (gcnew System::Windows::Forms::Panel());
			this->MainLabel = (gcnew System::Windows::Forms::Label());
			this->showFileButton = (gcnew System::Windows::Forms::Button());
			this->saveFileButton = (gcnew System::Windows::Forms::Button());
			this->encryptButton = (gcnew System::Windows::Forms::Button());
			this->ChessButton = (gcnew System::Windows::Forms::Button());
			this->panelBottom = (gcnew System::Windows::Forms::Panel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->plainTextBox = (gcnew System::Windows::Forms::TextBox());
			this->panelMain = (gcnew System::Windows::Forms::Panel());
			this->algorythmLabel = (gcnew System::Windows::Forms::Label());
			this->modeLabel = (gcnew System::Windows::Forms::Label());
			this->panelButton1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panelControl->SuspendLayout();
			this->panelButtons->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panelLogo->SuspendLayout();
			this->panelBottom->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->panelMain->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelButton1
			// 
			this->panelButton1->Controls->Add(this->panel2);
			this->panelButton1->Controls->Add(this->panel1);
			this->panelButton1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelButton1->Location = System::Drawing::Point(10, 0);
			this->panelButton1->Margin = System::Windows::Forms::Padding(0);
			this->panelButton1->Name = L"panelButton1";
			this->panelButton1->Size = System::Drawing::Size(199, 50);
			this->panelButton1->TabIndex = 25;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->modeLabel);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(0);
			this->panel2->Name = L"panel2";
			this->panel2->Padding = System::Windows::Forms::Padding(4, 0, 0, 0);
			this->panel2->Size = System::Drawing::Size(257, 25);
			this->panel2->TabIndex = 10;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButtonEncode);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel1->Location = System::Drawing::Point(0, 25);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
			this->panel1->Size = System::Drawing::Size(199, 25);
			this->panel1->TabIndex = 9;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Dock = System::Windows::Forms::DockStyle::Left;
			this->radioButton2->Location = System::Drawing::Point(85, 0);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(78, 25);
			this->radioButton2->TabIndex = 24;
			this->radioButton2->Text = L"Decode";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButtonEncode
			// 
			this->radioButtonEncode->AutoSize = true;
			this->radioButtonEncode->Checked = true;
			this->radioButtonEncode->Dock = System::Windows::Forms::DockStyle::Left;
			this->radioButtonEncode->Location = System::Drawing::Point(8, 0);
			this->radioButtonEncode->Name = L"radioButtonEncode";
			this->radioButtonEncode->Size = System::Drawing::Size(77, 25);
			this->radioButtonEncode->TabIndex = 23;
			this->radioButtonEncode->TabStop = true;
			this->radioButtonEncode->Text = L"Encode";
			this->radioButtonEncode->UseVisualStyleBackColor = true;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->InfoLabel1);
			this->panel7->Controls->Add(this->infoTextBox);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel7->Location = System::Drawing::Point(219, 50);
			this->panel7->Margin = System::Windows::Forms::Padding(0);
			this->panel7->Name = L"panel7";
			this->panel7->Padding = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->panel7->Size = System::Drawing::Size(470, 162);
			this->panel7->TabIndex = 27;
			// 
			// InfoLabel1
			// 
			this->InfoLabel1->AutoSize = true;
			this->InfoLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InfoLabel1->Location = System::Drawing::Point(10, 3);
			this->InfoLabel1->Margin = System::Windows::Forms::Padding(0);
			this->InfoLabel1->Name = L"InfoLabel1";
			this->InfoLabel1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->InfoLabel1->Size = System::Drawing::Size(151, 20);
			this->InfoLabel1->TabIndex = 22;
			this->InfoLabel1->Text = L"Operation Status";
			// 
			// infoTextBox
			// 
			this->infoTextBox->Location = System::Drawing::Point(10, 29);
			this->infoTextBox->Margin = System::Windows::Forms::Padding(4);
			this->infoTextBox->Multiline = true;
			this->infoTextBox->Name = L"infoTextBox";
			this->infoTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->infoTextBox->Size = System::Drawing::Size(435, 121);
			this->infoTextBox->TabIndex = 17;
			// 
			// panelControl
			// 
			this->panelControl->BackColor = System::Drawing::SystemColors::Control;
			this->panelControl->Controls->Add(this->panel7);
			this->panelControl->Controls->Add(this->panelButtons);
			this->panelControl->Controls->Add(this->panelLogo);
			this->panelControl->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelControl->Location = System::Drawing::Point(0, 0);
			this->panelControl->Margin = System::Windows::Forms::Padding(0);
			this->panelControl->Name = L"panelControl";
			this->panelControl->Size = System::Drawing::Size(732, 212);
			this->panelControl->TabIndex = 28;
			// 
			// panelButtons
			// 
			this->panelButtons->Controls->Add(this->panel6);
			this->panelButtons->Controls->Add(this->panel5);
			this->panelButtons->Controls->Add(this->panel4);
			this->panelButtons->Controls->Add(this->panel3);
			this->panelButtons->Controls->Add(this->panelButton1);
			this->panelButtons->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelButtons->Location = System::Drawing::Point(0, 50);
			this->panelButtons->Margin = System::Windows::Forms::Padding(0);
			this->panelButtons->Name = L"panelButtons";
			this->panelButtons->Padding = System::Windows::Forms::Padding(10, 0, 10, 0);
			this->panelButtons->Size = System::Drawing::Size(219, 162);
			this->panelButtons->TabIndex = 26;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->numericUpDown1);
			this->panel6->Controls->Add(this->button1);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel6->Location = System::Drawing::Point(10, 125);
			this->panel6->Name = L"panel6";
			this->panel6->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
			this->panel6->Size = System::Drawing::Size(199, 25);
			this->panel6->TabIndex = 29;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(8, 1);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(61, 22);
			this->numericUpDown1->TabIndex = 5;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(73, 0);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 25);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Set threads";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->threadsLabel);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel5->Location = System::Drawing::Point(10, 100);
			this->panel5->Name = L"panel5";
			this->panel5->Padding = System::Windows::Forms::Padding(4, 0, 0, 0);
			this->panel5->Size = System::Drawing::Size(199, 25);
			this->panel5->TabIndex = 28;
			// 
			// threadsLabel
			// 
			this->threadsLabel->AutoSize = true;
			this->threadsLabel->Location = System::Drawing::Point(4, 6);
			this->threadsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->threadsLabel->Name = L"threadsLabel";
			this->threadsLabel->Size = System::Drawing::Size(77, 17);
			this->threadsLabel->TabIndex = 4;
			this->threadsLabel->Text = L"3.Threads:";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->radioButtonC);
			this->panel4->Controls->Add(this->radioButtonASM);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(10, 75);
			this->panel4->Name = L"panel4";
			this->panel4->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
			this->panel4->Size = System::Drawing::Size(199, 25);
			this->panel4->TabIndex = 27;
			// 
			// radioButtonC
			// 
			this->radioButtonC->AutoSize = true;
			this->radioButtonC->Checked = true;
			this->radioButtonC->Dock = System::Windows::Forms::DockStyle::Left;
			this->radioButtonC->Location = System::Drawing::Point(66, 0);
			this->radioButtonC->Margin = System::Windows::Forms::Padding(0);
			this->radioButtonC->Name = L"radioButtonC";
			this->radioButtonC->Size = System::Drawing::Size(38, 25);
			this->radioButtonC->TabIndex = 7;
			this->radioButtonC->TabStop = true;
			this->radioButtonC->Text = L"C";
			this->radioButtonC->UseVisualStyleBackColor = true;
			// 
			// radioButtonASM
			// 
			this->radioButtonASM->AutoSize = true;
			this->radioButtonASM->Dock = System::Windows::Forms::DockStyle::Left;
			this->radioButtonASM->Location = System::Drawing::Point(8, 0);
			this->radioButtonASM->Margin = System::Windows::Forms::Padding(0);
			this->radioButtonASM->Name = L"radioButtonASM";
			this->radioButtonASM->Size = System::Drawing::Size(58, 25);
			this->radioButtonASM->TabIndex = 6;
			this->radioButtonASM->Text = L"ASM";
			this->radioButtonASM->UseVisualStyleBackColor = true;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->algorythmLabel);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(10, 50);
			this->panel3->Name = L"panel3";
			this->panel3->Padding = System::Windows::Forms::Padding(4, 0, 0, 0);
			this->panel3->Size = System::Drawing::Size(199, 25);
			this->panel3->TabIndex = 26;
			// 
			// panelLogo
			// 
			this->panelLogo->Controls->Add(this->MainLabel);
			this->panelLogo->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelLogo->Location = System::Drawing::Point(0, 0);
			this->panelLogo->Margin = System::Windows::Forms::Padding(0);
			this->panelLogo->Name = L"panelLogo";
			this->panelLogo->Size = System::Drawing::Size(732, 50);
			this->panelLogo->TabIndex = 25;
			// 
			// MainLabel
			// 
			this->MainLabel->AutoSize = true;
			this->MainLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->MainLabel->Location = System::Drawing::Point(18, 9);
			this->MainLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->MainLabel->Name = L"MainLabel";
			this->MainLabel->Size = System::Drawing::Size(249, 32);
			this->MainLabel->TabIndex = 14;
			this->MainLabel->Text = L"BMP Stegonography";
			// 
			// showFileButton
			// 
			this->showFileButton->Location = System::Drawing::Point(15, 5);
			this->showFileButton->Margin = System::Windows::Forms::Padding(4);
			this->showFileButton->Name = L"showFileButton";
			this->showFileButton->Size = System::Drawing::Size(130, 30);
			this->showFileButton->TabIndex = 0;
			this->showFileButton->Text = L"Open text file";
			this->showFileButton->UseVisualStyleBackColor = true;
			// 
			// saveFileButton
			// 
			this->saveFileButton->Location = System::Drawing::Point(291, 5);
			this->saveFileButton->Margin = System::Windows::Forms::Padding(4);
			this->saveFileButton->Name = L"saveFileButton";
			this->saveFileButton->Size = System::Drawing::Size(120, 30);
			this->saveFileButton->TabIndex = 1;
			this->saveFileButton->Text = L"Save text file";
			this->saveFileButton->UseVisualStyleBackColor = true;
			// 
			// encryptButton
			// 
			this->encryptButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->encryptButton->ForeColor = System::Drawing::Color::Green;
			this->encryptButton->Location = System::Drawing::Point(587, 0);
			this->encryptButton->Margin = System::Windows::Forms::Padding(4);
			this->encryptButton->Name = L"encryptButton";
			this->encryptButton->Size = System::Drawing::Size(130, 37);
			this->encryptButton->TabIndex = 12;
			this->encryptButton->Text = L"Encrypting";
			this->encryptButton->UseVisualStyleBackColor = true;
			// 
			// ChessButton
			// 
			this->ChessButton->Location = System::Drawing::Point(153, 5);
			this->ChessButton->Margin = System::Windows::Forms::Padding(4);
			this->ChessButton->Name = L"ChessButton";
			this->ChessButton->Size = System::Drawing::Size(130, 30);
			this->ChessButton->TabIndex = 13;
			this->ChessButton->Text = L"Open key file";
			this->ChessButton->UseVisualStyleBackColor = true;
			// 
			// panelBottom
			// 
			this->panelBottom->Controls->Add(this->showFileButton);
			this->panelBottom->Controls->Add(this->saveFileButton);
			this->panelBottom->Controls->Add(this->encryptButton);
			this->panelBottom->Controls->Add(this->ChessButton);
			this->panelBottom->Location = System::Drawing::Point(0, 563);
			this->panelBottom->Name = L"panelBottom";
			this->panelBottom->Size = System::Drawing::Size(732, 50);
			this->panelBottom->TabIndex = 30;
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox->Location = System::Drawing::Point(15, 15);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(340, 335);
			this->pictureBox->TabIndex = 3;
			this->pictureBox->TabStop = false;
			// 
			// plainTextBox
			// 
			this->plainTextBox->Dock = System::Windows::Forms::DockStyle::Right;
			this->plainTextBox->Location = System::Drawing::Point(377, 15);
			this->plainTextBox->Margin = System::Windows::Forms::Padding(4);
			this->plainTextBox->Multiline = true;
			this->plainTextBox->Name = L"plainTextBox";
			this->plainTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->plainTextBox->Size = System::Drawing::Size(340, 335);
			this->plainTextBox->TabIndex = 2;
			// 
			// panelMain
			// 
			this->panelMain->Controls->Add(this->pictureBox);
			this->panelMain->Controls->Add(this->plainTextBox);
			this->panelMain->Location = System::Drawing::Point(0, 200);
			this->panelMain->Margin = System::Windows::Forms::Padding(0);
			this->panelMain->Name = L"panelMain";
			this->panelMain->Padding = System::Windows::Forms::Padding(15);
			this->panelMain->Size = System::Drawing::Size(732, 365);
			this->panelMain->TabIndex = 29;
			// 
			// algorythmLabel
			// 
			this->algorythmLabel->AutoSize = true;
			this->algorythmLabel->Location = System::Drawing::Point(4, 7);
			this->algorythmLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->algorythmLabel->Name = L"algorythmLabel";
			this->algorythmLabel->Size = System::Drawing::Size(87, 17);
			this->algorythmLabel->TabIndex = 5;
			this->algorythmLabel->Text = L"2.Algorythm:";
			// 
			// modeLabel
			// 
			this->modeLabel->AutoSize = true;
			this->modeLabel->Location = System::Drawing::Point(3, 7);
			this->modeLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->modeLabel->Name = L"modeLabel";
			this->modeLabel->Size = System::Drawing::Size(59, 17);
			this->modeLabel->TabIndex = 5;
			this->modeLabel->Text = L"1.Mode:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 613);
			this->Controls->Add(this->panelControl);
			this->Controls->Add(this->panelBottom);
			this->Controls->Add(this->panelMain);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Steganography JA";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panelButton1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panelControl->ResumeLayout(false);
			this->panelButtons->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panelLogo->ResumeLayout(false);
			this->panelLogo->PerformLayout();
			this->panelBottom->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->panelMain->ResumeLayout(false);
			this->panelMain->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel5_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void panel4_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void panel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
private: System::Void LabelLogo_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
