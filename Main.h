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
	using namespace Newtonsoft::Json;
	using namespace System::IO;
	using namespace System::Diagnostics;

	String ^GetActiveWindowTitle( bool title )
	{
		HWND handle = GetForegroundWindow();

		if (!title)
		{
			DWORD pid;
			GetWindowThreadProcessId(handle, &pid);

			try
			{
				Process ^p = Process::GetProcessById((int)pid);
				return p->ProcessName;
			}
			catch (Exception ^e) {
			}
		}
		else {
			wchar_t buffer[256];
			if (GetWindowText(handle, buffer, 256) > 0)
				return gcnew String(buffer);
		}

		return "";
	}

	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			updateColour(0,0,0);
			currentIndex = -1;
		}

	protected:
		~Main()
		{
			//t->RestoreLEDRGB();

			//Save colours
			Colours ^c = gcnew Colours();
			for (int i = 0; i < listBox1->Items->Count; i++)
			{
				Item ^item = (Item^)listBox1->Items[i];
				c->items.Add( item );
			}

			if( c->items.Count > 0 )
				File::WriteAllText( Path::GetFullPath( "colours.json" ), JsonConvert::SerializeObject( c ) );
			
			if (talk)
			{
				talk->set_ryos_kb_SDKmode(FALSE);
				delete talk;
			}

			if (components)
				delete components;
		}

	private:
		Color colour;
		bool save;
		CROCCAT_Talk *talk;
		int currentIndex;

		System::Windows::Forms::ListBox^  listBox1;
		System::Windows::Forms::TextBox^  name;

		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::ColorDialog^  colorDialog1;

		System::Windows::Forms::Button^  button1;

		System::Windows::Forms::Button^  button3;
		System::Windows::Forms::TextBox^  rr;
		System::Windows::Forms::TextBox^  gg;
		System::Windows::Forms::TextBox^  bb;
		System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button2;
			 System::ComponentModel::IContainer^  components;

	private:


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->rr = (gcnew System::Windows::Forms::TextBox());
			this->gg = (gcnew System::Windows::Forms::TextBox());
			this->bb = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 2000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Main::timer1_Tick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(63, 149);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"label3";
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"LightShow";
			this->notifyIcon1->Visible = true;
			this->notifyIcon1->Click += gcnew System::EventHandler(this, &Main::notifyIcon1_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(163, 123);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(71, 23);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Remove";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(63, 162);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"label3";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 149);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(30, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Title:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 162);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Process:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(240, 123);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(408, 180);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->bb);
			this->Controls->Add(this->gg);
			this->Controls->Add(this->rr);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->name);
			this->Controls->Add(this->listBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Main";
			this->ShowInTaskbar = false;
			this->Text = L"LightShow Thingy";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		ref class Item {
			public:
				String ^str;
				Color colour;
			
				String ^ToString() override
				{
					return str;
				}
		};

		ref class Colours {
			public:
				[JsonProperty("items")]
				System::Collections::Generic::List<Item^> items;
		};

		System::Void Main_Load(System::Object^  sender, System::EventArgs^  e) {
			talk = new CROCCAT_Talk();
			if (!talk->init_ryos_talk())
			{
				if (MessageBox::Show("Couldn't find roccat device", "Error", MessageBoxButtons::OK) == System::Windows::Forms::DialogResult::OK)
				{
					Close();
					return;
				}
			}

			talk->set_ryos_kb_SDKmode(TRUE);
			talk->turn_off_all_LEDS();

			//bZone The effect zones are Ambient (0x00) and Event (0x01). Use Ambient when you have a low rate of updates. Use Event for fast paced updates. (When in doubt: use Event (0x01)).
			//bEffect Off(0x00), On(0x01), Blinking(0x02), Breathing(0x03), Heartbeat(0x04).
			//bSpeed no Change(0x00), Slow(0x01), Normal(0x02), Fast(0x03).
			//colorR simple RED value 0x00 to 0xFF.
			//colorG simple GREEN value 0x00 to 0xFF.
			//colorB simple BLUE value 0x00 to 0xFF.

			//Read colours
			if (File::Exists(Path::GetFullPath("colours.json")))
			{
				Colours ^c = JsonConvert::DeserializeObject<Colours^>(File::ReadAllText(Path::GetFullPath("colours.json")));
				for (int i = 0; i < c->items.Count; i++)
					listBox1->Items->Add(c->items[i]);
			}
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

		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			if( save )
			{
				((Item^)listBox1->SelectedItem)->str = name->Text;
				((Item^)listBox1->SelectedItem)->colour = colour;

				//Remove save mode
				save = false;
				button1->Text = "Add";
			}else{
				//Add a new item
				Item ^i = gcnew Item();
				i->str = name->Text;
				i->colour = colour;

				listBox1->Items->Add( i );
			}
			
			//Reset values
			name->Text = "";
			colour = Color::FromArgb(255,0,0,0);
			updateColour(-1,-1,-1);
		}

		System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if( !listBox1->SelectedItem )
				return;

			//Set data
			Item ^i = (Item^)listBox1->SelectedItem;
			name->Text = i->str;
			updateColour( i->colour.R, i->colour.G, i->colour.B );

			//Enable save mode
			save = true;
			button1->Text = "Save";
		}

		System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			String ^title = GetActiveWindowTitle(true);
			String ^proc = GetActiveWindowTitle(false);
			if( !title || !proc )
				return;

			label3->Text = title;
			label4->Text = proc;

			for (int i = 0; i < listBox1->Items->Count; i++)
			{
				Item ^item = (Item^)listBox1->Items[i];
				
				if (title->Contains(item->str) || proc->Contains(item->str))
				{
					if( currentIndex != i )
					{
						talk->Set_LED_RGB(0x01, 0x01, 0x02, Convert::ToByte(item->colour.R), Convert::ToByte(item->colour.G), Convert::ToByte(item->colour.B));
						currentIndex = i;
					}
				}
			}
		}

		System::Void notifyIcon1_Click(System::Object^  sender, System::EventArgs^  e) {
			if( Visible )
				Hide();
			else
				Show();
		}
	
		System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			listBox1->Items->Remove( listBox1->SelectedItem );
		}

		System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			//Reset values
			name->Text = "";
			colour = Color::FromArgb(255, 0, 0, 0);
			updateColour(-1, -1, -1);

			//Remove save mode
			save = false;
			button1->Text = "Add";
		}
	};
}
