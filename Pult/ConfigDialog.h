#pragma once;
#include "Commands.h"
#include "XMLNetProfile.h"
#include "MachDevice.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Management;


namespace tst {

	/// <summary>
	/// Summary for ConfigDialog
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class ConfigDialog : public System::Windows::Forms::Form
	{
	public:
	static String^ selectedCOM = "";
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	public: 
		array<String^> ^availableCOMPorts;
		ConfigDialog(void)
		{
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ConfigDialog()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::ToolStripStatusLabel^  connectStatus;
	public: System::IO::Ports::SerialPort^  Serial;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel2;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel3;
	private: System::Windows::Forms::ToolStripStatusLabel^  statusCOM;

	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer supSerial - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->components = (gcnew System::ComponentModel::Container());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
		this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->connectStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->toolStripStatusLabel2 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->statusCOM = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->Serial = (gcnew System::IO::Ports::SerialPort(this->components));
		this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
		this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
		this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		this->textBox5 = (gcnew System::Windows::Forms::TextBox());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->textBox4 = (gcnew System::Windows::Forms::TextBox());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->textBox3 = (gcnew System::Windows::Forms::TextBox());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->textBox2 = (gcnew System::Windows::Forms::TextBox());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->textBox1 = (gcnew System::Windows::Forms::TextBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->statusStrip1->SuspendLayout();
		this->groupBox1->SuspendLayout();
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(216, 99);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(81, 23);
		this->button1->TabIndex = 3;
		this->button1->Text = L"Сохранить";
		this->button1->Click += gcnew System::EventHandler(this, &ConfigDialog::button1_Click);
		// 
		// statusStrip1
		// 
		this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->toolStripStatusLabel1, 
			this->connectStatus, this->toolStripStatusLabel2, this->toolStripStatusLabel3, this->statusCOM});
		this->statusStrip1->Location = System::Drawing::Point(0, 190);
		this->statusStrip1->Name = L"statusStrip1";
		this->statusStrip1->Size = System::Drawing::Size(323, 22);
		this->statusStrip1->TabIndex = 2;
		this->statusStrip1->Text = L"statusStrip1";
		// 
		// toolStripStatusLabel1
		// 
		this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
		this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 17);
		// 
		// connectStatus
		// 
		this->connectStatus->Name = L"connectStatus";
		this->connectStatus->Size = System::Drawing::Size(0, 17);
		// 
		// toolStripStatusLabel2
		// 
		this->toolStripStatusLabel2->Name = L"toolStripStatusLabel2";
		this->toolStripStatusLabel2->Size = System::Drawing::Size(0, 17);
		// 
		// toolStripStatusLabel3
		// 
		this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
		this->toolStripStatusLabel3->Size = System::Drawing::Size(144, 17);
		this->toolStripStatusLabel3->Text = L"Состояние контроллера:";
		// 
		// statusCOM
		// 
		this->statusCOM->Name = L"statusCOM";
		this->statusCOM->Size = System::Drawing::Size(101, 17);
		this->statusCOM->Text = L"НЕ ПОДКЛЮЧЕН";
		// 
		// Serial
		// 
		this->Serial->BaudRate = 115200;
		this->Serial->DiscardNull = true;
		this->Serial->DtrEnable = true;
		this->Serial->PortName = L"COM4";
		this->Serial->ReadTimeout = 1000;
		this->Serial->WriteTimeout = 1000;
		// 
		// checkBox1
		// 
		this->checkBox1->AutoSize = true;
		this->checkBox1->Location = System::Drawing::Point(215, 41);
		this->checkBox1->Name = L"checkBox1";
		this->checkBox1->Size = System::Drawing::Size(101, 17);
		this->checkBox1->TabIndex = 4;
		this->checkBox1->Text = L"Включить DTR";
		this->checkBox1->UseVisualStyleBackColor = true;
		// 
		// comboBox1
		// 
		this->comboBox1->Location = System::Drawing::Point(12, 12);
		this->comboBox1->Name = L"comboBox1";
		this->comboBox1->Size = System::Drawing::Size(298, 21);
		this->comboBox1->TabIndex = 0;
		// 
		// groupBox1
		// 
		this->groupBox1->Controls->Add(this->textBox5);
		this->groupBox1->Controls->Add(this->label5);
		this->groupBox1->Controls->Add(this->textBox4);
		this->groupBox1->Controls->Add(this->label4);
		this->groupBox1->Controls->Add(this->button1);
		this->groupBox1->Controls->Add(this->textBox3);
		this->groupBox1->Controls->Add(this->label3);
		this->groupBox1->Controls->Add(this->textBox2);
		this->groupBox1->Controls->Add(this->label2);
		this->groupBox1->Controls->Add(this->textBox1);
		this->groupBox1->Controls->Add(this->label1);
		this->groupBox1->Location = System::Drawing::Point(13, 59);
		this->groupBox1->Name = L"groupBox1";
		this->groupBox1->Size = System::Drawing::Size(303, 128);
		this->groupBox1->TabIndex = 5;
		this->groupBox1->TabStop = false;
		this->groupBox1->Text = L"OEM-коды";
		// 
		// textBox5
		// 
		this->textBox5->Location = System::Drawing::Point(222, 17);
		this->textBox5->Name = L"textBox5";
		this->textBox5->Size = System::Drawing::Size(76, 20);
		this->textBox5->TabIndex = 9;
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Location = System::Drawing::Point(157, 20);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(53, 13);
		this->label5->TabIndex = 8;
		this->label5->Text = L"Кнопка 5";
		// 
		// textBox4
		// 
		this->textBox4->Location = System::Drawing::Point(78, 95);
		this->textBox4->Name = L"textBox4";
		this->textBox4->Size = System::Drawing::Size(70, 20);
		this->textBox4->TabIndex = 7;
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Location = System::Drawing::Point(7, 98);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(53, 13);
		this->label4->TabIndex = 6;
		this->label4->Text = L"Кнопка 4";
		// 
		// textBox3
		// 
		this->textBox3->Location = System::Drawing::Point(78, 69);
		this->textBox3->Name = L"textBox3";
		this->textBox3->Size = System::Drawing::Size(70, 20);
		this->textBox3->TabIndex = 5;
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(7, 72);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(53, 13);
		this->label3->TabIndex = 4;
		this->label3->Text = L"Кнопка 3";
		// 
		// textBox2
		// 
		this->textBox2->Location = System::Drawing::Point(78, 43);
		this->textBox2->Name = L"textBox2";
		this->textBox2->Size = System::Drawing::Size(70, 20);
		this->textBox2->TabIndex = 3;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(7, 46);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(53, 13);
		this->label2->TabIndex = 2;
		this->label2->Text = L"Кнопка 2";
		// 
		// textBox1
		// 
		this->textBox1->Location = System::Drawing::Point(78, 17);
		this->textBox1->Name = L"textBox1";
		this->textBox1->Size = System::Drawing::Size(73, 20);
		this->textBox1->TabIndex = 1;
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(7, 20);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(53, 13);
		this->label1->TabIndex = 0;
		this->label1->Text = L"Кнопка 1";
		// 
		// ConfigDialog
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(323, 212);
		this->Controls->Add(this->groupBox1);
		this->Controls->Add(this->comboBox1);
		this->Controls->Add(this->checkBox1);
		this->Controls->Add(this->statusStrip1);
		this->Name = L"ConfigDialog";
		this->Text = L"Настройки подключения";
		this->Load += gcnew System::EventHandler(this, &ConfigDialog::ConfigDialog_Load);
		this->statusStrip1->ResumeLayout(false);
		this->statusStrip1->PerformLayout();
		this->groupBox1->ResumeLayout(false);
		this->groupBox1->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

			}
#pragma endregion

//Функции самописные
 
void writeSetting(String^ node, String^ parametr){
 try{
	XMLNetProfile ^ profile = gcnew XMLNetProfile(gcnew String(ProfileName), "Pult-Control", true);
	if (profile -> Load()) {
		profile->WriteString(node,parametr);
		profile->Save();
	}
	profile->Save();
}
    catch (Exception^ ex)
    {
        MessageBox::Show("Ошибка: " + ex->Message);
    }

} 
 
String^ readSetting(String^ node){

	XMLNetProfile ^ profile = gcnew XMLNetProfile(gcnew String(ProfileName), "Pult-Control", true);

	if (profile -> Load()) {
		return profile -> ReadString(node);
	}
return "Nothing to return";
}

void getCOMPorts() {
    comboBox1->Items->Clear();  // Очистка списка

    try {
        // Поиск всех устройств с COM в названии
        ManagementObjectSearcher^ searcher = gcnew ManagementObjectSearcher(
            "SELECT * FROM Win32_PnPEntity WHERE Name LIKE '%(COM%'");

        for each (ManagementObject^ obj in searcher->Get()) {
            String^ name = obj["Name"]->ToString();             // "USB Serial Device (COM3)"
            String^ deviceID = obj["PNPDeviceID"]->ToString();  // "USB\\VID_2E8A&PID_000A\\PULT01"

            // Извлечение COM-порта
            int comIndex = name->LastIndexOf("COM");
            if (comIndex < 0) continue;
            String^ comPort = name->Substring(comIndex)->TrimEnd(')');

            // Поиск по VID/PID для RP2040 (или твоего устройства)
            if (deviceID->Contains("VID_2E8A") && deviceID->Contains("PID_0003")) {
                String^ friendlyName = "RP2040";

                // Извлечение серийного номера
                int serialIndex = deviceID->LastIndexOf("\\");
                if (serialIndex >= 0 && serialIndex + 1 < deviceID->Length) {
                    String^ serial = deviceID->Substring(serialIndex + 1);

                    // Назначаем имя по сериалу
                    if (serial == "PULT01") {
                        friendlyName = "Mach3 Control Pult";
                    }
                    else if (serial == "SENSOR01") {
                        friendlyName = "Sensor Board";
                    }
                    else {
                        friendlyName = "RP2040 Unknown (" + serial + ")";
                    }
                }

                comboBox1->Items->Add(friendlyName + " (" + comPort + ")");
            }
            else {
                // Добавляем прочие COM-порты с оригинальным именем
                comboBox1->Items->Add(name);
            }
        }

        if (comboBox1->Items->Count > 0)
            comboBox1->SelectedIndex = 0;
        else
            comboBox1->Items->Add("Нет доступных устройств");

    } catch (Exception^ ex) {
        MessageBox::Show("Ошибка при получении COM-портов: " + ex->Message);
    }
}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (this->comboBox1->SelectedItem == nullptr)
    {
        MessageBox::Show("COM порт не выбран.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Извлекаем COMx из строки, например: "Mach3 Control Pult (COM4)"
    String^ selectedText = this->comboBox1->SelectedItem->ToString();
    int start = selectedText->LastIndexOf("COM");
    if (start < 0) return;

    int end = selectedText->IndexOf(")", start);
    if (end < 0) end = selectedText->Length;

    selectedCOM = selectedText->Substring(start, end - start);

    // Отправляем команду и сохраняем, если всё ок
    String^ response = sendMessageAndWaitForResponse(selectedCOM, CMD_PURDY);

    if (!String::IsNullOrEmpty(response) && response->Trim()->Length > 0)
    {
        writeSetting("PORT", selectedCOM); // сохраняем правильный COM
    }
    else															
    {
        MessageBox::Show("Не удалось получить ответ от микроконтроллера.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}




 

String^ sendMessageAndWaitForResponse(String^ SerialName, String^ message)
{
    String^ response = "";
    

    try
    {
        Serial->PortName = SerialName;
        Serial->BaudRate = 115200; // Замените на вашу
        Serial->ReadTimeout = 2000;
        Serial->NewLine = "\r\n"; // Проверьте нужный символ

        Serial->Open();

        Serial->DiscardInBuffer();
        Serial->DiscardOutBuffer();

        array<unsigned char>^ command = System::Text::Encoding::ASCII->GetBytes(message + Serial->NewLine);
        Serial->Write(command, 0, command->Length);

        response = Serial->ReadLine();

        this->statusCOM->Text = "Ответ: " + response;

        if (response->Contains(RESP_PUOK))
        {
            return SerialName;
        }
        else
        {
            return "";
        }
    }
    catch (Exception^ ex)
    {
        this->statusCOM->Text = "Ошибка: " + ex->Message;
        return "";
    }
    finally
    {
        if (Serial->IsOpen)
            Serial->Close();
    }
}


private: System::Void ConfigDialog_Load(System::Object^  sender, System::EventArgs^  e) {

getCOMPorts();

    try
    {
	 this->textBox1->Text = readSetting("B1");
	 this->textBox2->Text = readSetting("B2");
	 this->textBox3->Text = readSetting("B3");
	 this->textBox4->Text = readSetting("B4");
	 this->textBox5->Text = readSetting("B5");
    }
    
    catch (Exception^ ex)
    {
		 MessageBox::Show("При чтении значений OEM кодов кнопок произошла ошибка", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }

}



private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    if (comboBox1->SelectedItem == nullptr)
    {
        MessageBox::Show("COM порт не выбран.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    // Извлекаем COMx из строки
    String^ selectedText = comboBox1->SelectedItem->ToString();
    int start = selectedText->LastIndexOf("COM");
    if (start < 0) return;

    int end = selectedText->IndexOf(")", start);
    if (end < 0) end = selectedText->Length;

    selectedCOM = selectedText->Substring(start, end - start);

    String^ response = sendMessageAndWaitForResponse(selectedCOM, CMD_PURDY);

    if (!String::IsNullOrEmpty(response))
    {
        writeSetting("PORT", selectedCOM);
    }
    else
    {
        MessageBox::Show("Нет ответа от устройства.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    

    //Сохраняем ОЕМ коды кнопок
    try
    {
	 writeSetting("B1", this->textBox1->Text);
	 writeSetting("B2", this->textBox2->Text);
	 writeSetting("B3", this->textBox3->Text);
	 writeSetting("B4", this->textBox4->Text);
	 writeSetting("B5", this->textBox5->Text);
    }
    
    catch (Exception^ ex)
    {
	  MessageBox::Show("При записи значений OEM кодов кнопок произошла ошибка", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    
}



		 
	 
		 



};	 
}
