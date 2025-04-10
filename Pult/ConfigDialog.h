#pragma once;
#include "XMLNetProfile.h"
#include "MachDevice.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

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
		static String^ selectedCOM; // Храним выбранный COM port
	private: System::Windows::Forms::CheckBox^  checkBox1;
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
		/// Required method for Designer support - do not modify
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
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
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
			this->checkBox1->Location = System::Drawing::Point(210, 16);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(101, 17);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"Включить DTR";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// ConfigDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(323, 103);
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
 
 
void getCOMPorts(){
    array<String^> ^AvailableSerialPorts;
    array<unsigned char> ^aTemp;
    String ^sTemp;

    try
    {
//        comList->Items->Clear();
        AvailableSerialPorts = this->Serial->GetPortNames();
        availableCOMPorts = AvailableSerialPorts;  // Сохраняем порты в глобальную переменную

        for(int Count = 0; Count < AvailableSerialPorts->Length; Count++)
        {
            sTemp = AvailableSerialPorts[Count];

            // Убираем любые нецифровые символы в конце порта (например, добавленные драйверами Bluetooth)
            aTemp = System::Text::Encoding::UTF8->GetBytes(sTemp);
            while ((aTemp->Length > 1) && ((aTemp[(aTemp->Length - 1)] < '0') || (aTemp[(aTemp->Length - 1)] > '9')))
            {
                Array::Resize(aTemp, (aTemp->Length - 1));
            }
            sTemp = System::Text::Encoding::UTF8->GetString(aTemp);

//            comList->Items->Add(sTemp);
        }
//        comList->SelectedIndex = 0;
    }
    catch(System::Exception^ e)
    {
        e->Message;
    }
}

 

String^ sendMessageAndWaitForResponse(String^ message)
{
    String^ response = "";
    bool success = false;
    String^ selectedCOM = "";  // Переменная для хранения имени порта

    try
    {
        // Перебираем все доступные порты
        for (int i = 0; i < availableCOMPorts->Length; i++)
        {
            String^ portName = availableCOMPorts[i];

            try
            {
                // Проверка, открыт ли порт
                if (this->Serial->IsOpen)
                {
                    this->Serial->Close();  // Закрываем порт, если он открыт
                }

                // Устанавливаем имя порта
                this->Serial->PortName = portName;

                try
                {
                    // Попытка открыть порт
                    this->Serial->Open();
                }
                catch (UnauthorizedAccessException^ ex)
                {
                    // Ошибка доступа (порт уже занят другим процессом)
                    this->statusCOM->Text = "Порт " + portName + " занят другим процессом.";
                    continue;  // Переход к следующему порту
                }
                catch (System::Exception^ ex)
                {
                    // Другие ошибки при попытке открыть порт
                    this->statusCOM->Text = "Ошибка при открытии порта " + portName + ": " + ex->Message;
                    continue;  // Переход к следующему порту
                }

                // Установим таймаут для чтения данных
                this->Serial->ReadTimeout = 1000;  // Таймаут чтения 5 секунд

                // Отправка сообщения
                array<unsigned char>^ command = System::Text::Encoding::ASCII->GetBytes(message + this->Serial->NewLine);
                this->Serial->Write(command, 0, command->Length);

                // Ожидание ответа
                try
                {
                    response = this->Serial->ReadLine();  // Чтение ответа от устройства
                    this->statusCOM->Text = "Ответ: " + response;  // Логируем ответ

                    // Если ответ соответствует ожидаемому
                    if (response->Contains("!PUOK$"))
                    {
                        selectedCOM = portName;
                        this->statusCOM->Text = "Ответ получен с порта " + selectedCOM + ": " + response;
                        success = true;
                        break;  // Выход из цикла при успешном ответе
                    }
                    else
                    {
                        // Если ответ не соответствует ожидаемому
                        this->statusCOM->Text = "Ответ не соответствует ожидаемому на порте " + portName + ": " + response;
                        //this->Serial->Close();  // Закрываем порт
                    }
                }
                catch (TimeoutException^ ex)
                {
                    // Таймаут при ожидании ответа
                    this->statusCOM->Text = "Таймаут при ожидании ответа от устройства на порте " + portName;
                    this->Serial->Close();  // Закрываем порт
                }
                catch (System::Exception^ ex)
                {
                    // Ошибка при чтении данных с порта
                    this->statusCOM->Text = "Ошибка при чтении данных с порта " + portName + ": " + ex->Message;
                    this->Serial->Close();  // Закрываем порт
                }
            }
            catch (Exception^ ex)
            {
                // Обработка ошибок при работе с портом
                this->statusCOM->Text = "Ошибка на порте " + portName + ": " + ex->Message;
            }
        }

        if (!success)
        {
            this->statusCOM->Text = "Ответ не получен на всех портах.";
            MessageBox::Show("Ответ не получен на всех портах.");
        }
    }
    catch (Exception^ ex)
    {
        this->statusCOM->Text = "Ошибка: " + ex->Message;
        MessageBox::Show("Ошибка: " + ex->Message);
    }

    // Здесь можно использовать selectedCOM, например, для дальнейших операций
    if (selectedCOM != "")
    {
     return selectedCOM;
    }
}

private: System::Void ConfigDialog_Load(System::Object^  sender, System::EventArgs^  e) {

getCOMPorts();
}



private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	   
	   writeSetting("PORT", sendMessageAndWaitForResponse("?PURDY$"));
	   
 }
		 
		 
		 
		 
	};	 
}
