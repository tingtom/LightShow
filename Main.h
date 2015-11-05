#pragma once
#include <Windows.h>
#include "ROCCAT_Talk.h"

namespace LightShow 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			updateColour(0,0,0);
		}

	protected:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		System::Windows::Forms::ListBox^  listBox1;
		System::Windows::Forms::TextBox^  name;

		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::ColorDialog^  colorDialog1;

		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::Button^  button2;
		System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  rr;
	private: System::Windows::Forms::TextBox^  gg;
	private: System::Windows::Forms::TextBox^  bb;




	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->rr = (gcnew System::Windows::Forms::TextBox());
			this->gg = (gcnew System::Windows::Forms::TextBox());
			this->bb = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(12, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(134, 134);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::listBox1_SelectedIndexChanged);
			// 
			// name
			// 
			this->name->Location = System::Drawing::Point(163, 28);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(233, 20);
			this->name->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(160, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Application name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(160, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Colour";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(321, 123);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(163, 123);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(317, 75);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(79, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Choose";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click);
			// 
			// rr
			// 
			this->rr->Location = System::Drawing::Point(163, 77);
			this->rr->Name = L"rr";
			this->rr->Size = System::Drawing::Size(43, 20);
			this->rr->TabIndex = 8;
			this->rr->TextChanged += gcnew System::EventHandler(this, &Main::r_TextChanged);
			// 
			// gg
			// 
			this->gg->Location = System::Drawing::Point(212, 77);
			this->gg->Name = L"gg";
			this->gg->Size = System::Drawing::Size(47, 20);
			this->gg->TabIndex = 8;
			this->gg->TextChanged += gcnew System::EventHandler(this, &Main::g_TextChanged);
			// 
			// bb
			// 
			this->bb->Location = System::Drawing::Point(265, 77);
			this->bb->Name = L"bb";
			this->bb->Size = System::Drawing::Size(46, 20);
			this->bb->TabIndex = 8;
			this->bb->TextChanged += gcnew System::EventHandler(this, &Main::b_TextChanged);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(408, 160);
			this->Controls->Add(this->bb);
			this->Controls->Add(this->gg);
			this->Controls->Add(this->rr);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->name);
			this->Controls->Add(this->listBox1);
			this->Name = L"Main";
			this->Text = L"LightShow Thingy";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Void Main_Load(System::Object^  sender, System::EventArgs^  e) {

		}

		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			Close();
		}

		System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			System::Windows::Forms::DialogResult result = colorDialog1->ShowDialog();
			if( result == System::Windows::Forms::DialogResult::OK )
			{
				Color c = colorDialog1->Color;
				rr->Text = c.R.ToString();
				gg->Text = c.G.ToString();
				bb->Text = c.B.ToString();

				button3->BackColor = c;
				colour = c;
			}
		}

		Color colour;
		bool save;

		//Limit a value between a min and max
		int checkRange( int val, int min, int max )
		{
			//Check ranges
			val = Math::Max( val, 0 );
			val = Math::Min( val, 255 );
			return val;
		}

		//Update the current colour from a rgb value
		void updateColour(int r, int g, int b)
		{
			//If it's -1 use the current value instead
			r = (r == -1 ? colour.R : r );
			g = (g == -1 ? colour.G : g );
			b = (b == -1 ? colour.B : b );

			//Check ranges
			r = checkRange( r, 0, 255 );
			g = checkRange( g, 0, 255 );
			b = checkRange( b, 0, 255 );

			//Set colour
			colour = Color::FromArgb( 255, r, g, b );
			button3->BackColor = colour;
			rr->Text = r.ToString();
			gg->Text = g.ToString();
			bb->Text = b.ToString();
		}

		//Safely covert a string to a integer
		int stringToInt( System::String ^str )
		{
			try
			{
				return Convert::ToInt32( str );
			}catch( System::Exception ^e ){
				return 0;
			}
		}
	
		System::Void r_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			updateColour( stringToInt( rr->Text ), -1, -1 );
		}

		System::Void g_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			updateColour( -1, stringToInt( gg->Text ), -1 );
		}

		System::Void b_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			updateColour( -1, -1, stringToInt( bb->Text ) );
		}

		ref class Item {
			public:
				String ^str;
				Color colour;
			
				String ^ToString() override
				{
					return str;
				}
		};

		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if( save )
			{
				((Item^)listBox1->SelectedItem)->str = name->Text;
				((Item^)listBox1->SelectedItem)->colour = colour;

				//Remove save mode
				save = false;
				button1->Text = "Add";

				//Reset values
				name->Text = "";
				colour = Color::FromArgb(255,0,0,0);
				updateColour(-1,-1,-1);
				return;
			}

			//Add a new item
			Item ^i = gcnew Item();
			i->str = name->Text;
			i->colour = colour;

			listBox1->DisplayMember = "str";
			listBox1->Items->Add( i );
		}

		System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			//Set data
			Item ^i = (Item^)listBox1->SelectedItem;
			name->Text = i->str;
			updateColour( i->colour.R, i->colour.G, i->colour.B );

			//Enable save mode
			save = true;
			button1->Text = "Save";
		}
	};
}
