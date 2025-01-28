#pragma once
#include <iostream>
#include <string>

namespace AirportCLRProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FlightsForm
	/// </summary>
	public ref class FlightsForm : public System::Windows::Forms::Form
	{
	private:
		DataGridView^ dataGridView;

	public:
		FlightsForm(void)
		{
			InitializeComponent();
			LoadFlightsData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FlightsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Arrival_Place;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Departure_Place;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Arrival_Time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Departure_Time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Plane_Id;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Arrival_Place = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Departure_Place = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Arrival_Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Departure_Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Plane_Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Id, this->Arrival_Place,
					this->Departure_Place, this->Arrival_Time, this->Departure_Time, this->Plane_Id
			});
			this->dataGridView1->Location = System::Drawing::Point(45, 67);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(644, 354);
			this->dataGridView1->TabIndex = 0;
			// 
			// Id
			// 
			this->Id->HeaderText = L"Id";
			this->Id->Name = L"Id";
			// 
			// Arrival_Place
			// 
			this->Arrival_Place->HeaderText = L"Arrival_Place";
			this->Arrival_Place->Name = L"Arrival_Place";
			// 
			// Departure_Place
			// 
			this->Departure_Place->HeaderText = L"Departure_Place";
			this->Departure_Place->Name = L"Departure_Place";
			// 
			// Arrival_Time
			// 
			this->Arrival_Time->HeaderText = L"Arrival_Time";
			this->Arrival_Time->Name = L"Arrival_Time";
			// 
			// Departure_Time
			// 
			this->Departure_Time->HeaderText = L"Departure_Time";
			this->Departure_Time->Name = L"Departure_Time";
			// 
			// Plane_Id
			// 
			this->Plane_Id->HeaderText = L"Plane_Id";
			this->Plane_Id->Name = L"Plane_Id";
			// 
			// FlightsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(718, 497);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"FlightsForm";
			this->Text = L"FlightsForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
		}

		void LoadFlightsData() {
			
		}
#pragma endregion
	};
}
