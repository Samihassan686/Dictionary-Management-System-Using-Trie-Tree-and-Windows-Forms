#pragma once
#include "Dictionary.h"

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddWord
	/// </summary>
	public ref class AddWord : public System::Windows::Forms::Form
	{
	public:
		AddWord(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		AddWord(Form^ frm1)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			previousForm = frm1;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddWord()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Form^ previousForm;
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ Word;
	private: System::Windows::Forms::TextBox^ Meaning;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddWord::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Word = (gcnew System::Windows::Forms::TextBox());
			this->Meaning = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(183, 161);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Word";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(183, 217);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(209, 36);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Enter Meaning";
			// 
			// Word
			// 
			this->Word->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Word->Location = System::Drawing::Point(439, 161);
			this->Word->Name = L"Word";
			this->Word->Size = System::Drawing::Size(255, 34);
			this->Word->TabIndex = 2;
			// 
			// Meaning
			// 
			this->Meaning->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Meaning->Location = System::Drawing::Point(439, 217);
			this->Meaning->Name = L"Meaning";
			this->Meaning->Size = System::Drawing::Size(255, 34);
			this->Meaning->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(439, 286);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 40);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Enter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddWord::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(13, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &AddWord::button2_MouseClick);
			// 
			// AddWord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(993, 529);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Meaning);
			this->Controls->Add(this->Word);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(1011, 576);
			this->MinimumSize = System::Drawing::Size(1011, 576);
			this->Name = L"AddWord";
			this->Text = L"AddWord";
			this->Load += gcnew System::EventHandler(this, &AddWord::AddWord_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddWord_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	void MarshalString(String^ s, string& os) 
	{
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
    }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ word = this->Word->Text;
		String^ meaning = this->Meaning->Text;
		string sWord, sMeaning;
		
		MarshalString(word, sWord);
		MarshalString(meaning, sMeaning);
		Obj.AddWord(sWord, sMeaning);


	}
private: System::Void button2_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->Hide();
	previousForm->Show();
}
};
}
