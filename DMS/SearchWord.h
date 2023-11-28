#pragma once
#include <string>
#include "Dictionary.h"
namespace FinalProject 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SearchWord
	/// </summary>
	public ref class SearchWord : public System::Windows::Forms::Form
	{
	public:
		SearchWord(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		SearchWord(Form^ frm1)
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
		~SearchWord()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Form^ previousForm;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ back;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SearchWord::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->back = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(223, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(166, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter Word";
			this->label1->UseMnemonic = false;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(442, 79);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(243, 34);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &SearchWord::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(223, 274);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(131, 32);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Meaning";
			this->label2->UseMnemonic = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(437, 277);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 29);
			this->label3->TabIndex = 3;
			this->label3->Text = L"label3";
			this->label3->Click += gcnew System::EventHandler(this, &SearchWord::label3_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(442, 137);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(132, 42);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Enter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SearchWord::button1_Click);
			// 
			// back
			// 
			this->back->Location = System::Drawing::Point(2, 13);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(75, 23);
			this->back->TabIndex = 5;
			this->back->Text = L"Back";
			this->back->UseVisualStyleBackColor = true;
			this->back->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SearchWord::back_MouseClick);
			// 
			// SearchWord
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(993, 529);
			this->Controls->Add(this->back);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(1011, 576);
			this->MinimumSize = System::Drawing::Size(1011, 576);
			this->Name = L"SearchWord";
			this->Text = L"Word Search";
			this->Load += gcnew System::EventHandler(this, &SearchWord::SearchWord_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	string sWord;
	string retStr;
	String^ inpword = this->textBox1->Text;
	MarshalString(inpword, sWord);
	retStr = Obj.search(sWord);
	String^ RetStr = gcnew String(retStr.c_str());
	this->label3->Text = RetStr;
}
void MarshalString(String^ s, string& os)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}
private: System::Void SearchWord_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void back_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->Hide();
	previousForm->Show();
}
};
}
