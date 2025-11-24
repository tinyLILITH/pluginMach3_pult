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
		//this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ConfigDialog::comboBox1_SelectedIndexChanged);

		this->statusStrip1->SuspendLayout();
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(235, 12);
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
		this->statusStrip1->Location = System::Drawing::Point(0, 81);
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
		this->comboBox1->Size = System::Drawing::Size(217, 21);
		this->comboBox1->TabIndex = 0;
		// 
		// ConfigDialog
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(323, 103);
		this->Controls->Add(this->comboBox1);
		this->Controls->Add(this->checkBox1);
		this->Controls->Add(this->statusStrip1);
		this->Controls->Add(this->button1);
		this->Name = L"ConfigDialog";
		this->Text = L"Настройки подключения";
		this->Load += gcnew System::EventHandler(this, &ConfigDialog::ConfigDialog_Load);
		this->statusStrip1->ResumeLayout(false);
		this->statusStrip1->PerformLayout();
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
}



		 
	 
		 

};	 
}
