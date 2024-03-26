//=====================================================================
//
//	Plugin.cpp - the optional custom part of the plugin
//
//	this source file can be filled with the actual custom code that
//	makes the plugin work. it is the choice of the developer to enable
//	which functions will be used from the available MachDevice calls.
//
//	if this is a mixed mode dll each function can be declared as either
//	an unmanaged or managed function.
//
//	please see the documentation in Plugin.h for the #define stateInputments
//	that control each functions compilation.
//
//	if this is a mixed mode dll and you need to keep global managed
//	reference please see the MG class in ManagedGlobal.h
//
//	please read the notes and comments in MachDevice.cpp for general
//	information and disclaimers.
//
//=====================================================================

#include "stdafx.h"
#include "Plugin.h"
#include "MachDevice.h"
#include "ConfigDialog.h"
#include "PlugInControlDialog.h"
#include "XMLNetProfile.h"
#include "ManagedGlobal.h"
#include <stdlib.h>
#include <windows.h>

//---------------------------------------------------------------------
//	the default namespace for managed functions and classes
//---------------------------------------------------------------------

using namespace tst;

//---------------------------------------------------------------------
//	data area
//---------------------------------------------------------------------
int menuStart = 0;



/*Read setting 
PORT - COM Port

*/

String^ readSetting(String^ node){

	XMLNetProfile ^ profile = gcnew XMLNetProfile(gcnew String(ProfileName), "Control-Pult", true);

	if (profile -> Load()) {
		return profile -> ReadString(node);
	}
return "Nothing to return";
}



//init Serial connection

void init(){

    try{
        MG::_mInst->SetUserLED(1040, 0); // turn off LED ready state

        //setup actual comport num and open
        if ( readSetting("PORT") == "" ){
            MG::PCD->listBox1->Items->Add(readSetting("PORT"));
            MG::PCD->listBox1->Items->Add("Порт не назначен. Необходимо назначить порт в Config Plugin");
        }
		else {
            MG::PCD->listBox1->Items->Add(readSetting("PORT"));

            if (!MG::CD->Serial->IsOpen){
                MG::CD->Serial->PortName = readSetting("PORT");
                MG::CD->Serial->Open();
                MG::PCD->listBox1->Items->Add("Порт назначен и успешно открыт");
            }
			
			// while not response answer by microcontroller sending ?RDY$ message
			while (true) {
				
				MG::CD->Serial->DiscardInBuffer(); // Clean Serial buffer
				
				
				Threading::Thread::Sleep(350); // Задержка перед отправкой
				
				array<unsigned char>^ command = System::Text::Encoding::ASCII->GetBytes("?RDY$" + MG::CD->Serial->NewLine);
				MG::CD->Serial->Write(command, 0, command->Length);

				MG::PCD->listBox1->Items->Add("Отправка сообщения");
				

				Threading::Thread::Sleep(50); // Задержка перед чтением

				array<unsigned char>^ buffer = gcnew array<unsigned char>(MG::CD->Serial->BytesToRead);
				MG::CD->Serial->Read(buffer, 0, MG::CD->Serial->BytesToRead);

				if( System::Text::Encoding::ASCII->GetString(buffer) -> Contains("!OK$") ) {
					MG::initComplete = true;
					MG::_mInst->SetUserLED(1040, 1); // turn on LED ready state
					MG::PCD->listBox1->Items->Add("Сообщение получено");
					break;
				}

				MG::PCD->listBox1->Items->Add("Попытка чтения");
			}

		}
    }
    
    catch (System::Exception^ e) {
        MG::PCD->listBox1->Items->Add("init" + e->Message);
        MG::_mInst->SetUserLED(1040, 0); // turn off LED ready state
    }
    
    finally{

    }
}



void mainThreadUpdateCOM(){

				


	while (true){

		try{

			if ( (!MG::initComplete) && (!MG::CD->Serial->IsOpen) ) init();

			else {

				if(MG::CD->Serial->IsOpen){
				 MG::_mInst->SetUserLED(1040, 1); // turn on LED ready state

					if (MG::CD->Serial->BytesToRead > 0){
					
						array<unsigned char>^ buffer = gcnew array<unsigned char>(MG::CD->Serial->BytesToRead);
						//reading messages from microcontroller	
						
						//MG::PCD->listBox1->Items->Add("reading");
					    MG::CD->Serial->Read(buffer, 0, MG::CD->Serial->BytesToRead);
						MG::lastRcvMessage = System::Text::Encoding::ASCII->GetString(buffer);
						
						//MG::PCD->listBox1->Items->Add("Last Recive Message: "+ MG::lastRcvMessage );
							
					}

					else{
					//if nothing to reading - sleep thread
						Threading::Thread::Sleep(1);
						//MG::PCD->listBox1->Items->Add("Sleep (1)");
					}
			}

			else{
				init();
			}
		}
	}

	catch (System::Exception^ e) {
        MG::_mInst->SetUserLED(1040, 0);
    } 

  }
}


/*
void initCOM() {

    try {

        if (MG::CD->Serial->IsOpen) {
            return;
        }

        MG::CD->Serial->Open();
        if (!MG::CD->Serial->IsOpen) {
            return;
        }
				Sleep(2500);

        MG::PCD->listBox1->Items->Add("COM порт открыт");
        MG::CD->Serial->WriteLine("?RDY$"); //Отправка тестового сообщения на контроллер

        MG::initRequestCOM = MG::CD->Serial->ReadLine();
        MG::PCD->listBox1->Items->Add(MG::initRequestCOM);

        //Читаем ответ если ответ совпадает - значит контроллер нужный
		if (MG::initRequestCOM->Contains("!OK$")){

			//Отправка запроса на включение реле
			MG::CD->Serial->WriteLine("?RLYON$");
			MG::initLPTPower = MG::CD->Serial->ReadLine();

			if(MG::initLPTPower->Contains("!RLYOK$")){
			 MG::PCD->listBox1->Items->Add("Питание подано на плату");
			}
			else{
				MG::PCD->listBox1->Items->Add("Отсутствует питание платы. Выполните перезагрузку Mach3");
			}

			
			MG::PCD->listBox1->Items->Add("Получен корректный ответ");
		    MG::_mInst->SetUserLED(1040, 1);//Зажигаем светодиод

            //Читаем пользовательское значение jog
//            MG::userJogOverride = MG::_mInst->GetOEMDRO(3);
        } 
		
		else {
            MG::PCD->listBox1->Items->Add("Ответ от контроллера не получен");
            MG::CD->Serial->Close();
            MG::PCD->listBox1->Items->Add("Порт закрыт");
            MG::_mInst->SetUserLED(1040, 0);
        }

    } 
	
	catch (System::Exception^ e) {
        MG::PCD->listBox1->Items->Add("Ошибкаinit:" + e->Message);
        MG::_mInst->SetUserLED(1040, 0);
    } 

	finally {

    }
}
*/



//Посыл сигнала каждую милисекунду для наиболее быстрой остановки при jog

/*
// Объявление обработчика таймера
VOID CALLBACK TimerStopJog(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {

	if (MG::axisSelected->Contains("!aZ$")) MG::_mInst->DoOEMButton(336);
	if (MG::axisSelected->Contains("!aX$")) MG::_mInst->DoOEMButton(334);
    
    KillTimer(NULL, idEvent);
}
*/



void mainUpdateCycle() {
    if (MG::CD->Serial->BytesToRead <= 0) {
        return;
    }

    array<Byte>^ buffer = gcnew array<Byte>(10);
    MG::CD->Serial->Read(buffer, 0, 10);
    String^ str = System::Text::Encoding::ASCII->GetString(buffer);


/*
    //Выбор оси для перемещения
    if (str->Contains("!aX$") || str->Contains("!aZ$")) {
        MG::axisSelected = str;
    }
*/

    //Эмуляция нажатий кнопок cycle start и stop
	if (str->Contains("!START$")) {
        MG::PCD->listBox1->Items->Add("Цикл старт");
        MG::_mInst->DoOEMButton(1000);
        MG::_mInst->SetVar(100, MG::_mInst->GetOEMDRO(1516) + 1);
        MG::_mInst->SetOEMDRO(1516, MG::_mInst->GetVar(100));
    }

    if (str->Contains("!ESTP$")) {
        MG::_mInst->DoOEMButton(1021);
    }

	
	if (str->Contains("!STOP$")) {
        MG::_mInst->DoOEMButton(1003);
    }
/*
    if (str->Contains("!SlwM$")) {
        MG::_mInst->SetOEMDRO(3, MG::userJogOverride);
    }

    if (str->Contains("!FstM$")) {
        MG::_mInst->SetOEMDRO(3, 100.0);
    }

    // Jog с выбором осей
    if (str->Contains("!J+$") || str->Contains("!J-$")) {
        MG::PCD->listBox1->Items->Add("J++");

        if (MG::axisSelected->Contains("!aZ$")) {
            MG::_mInst->DoOEMButton(str->Contains("!J+$") ? 311 : 312);
        }

        if (MG::axisSelected->Contains("!aX$")) {
            MG::_mInst->DoOEMButton(str->Contains("!J+$") ? 307 : 308);
        }

        // Запуск таймера на 1 миллисекунд
        UINT_PTR timerId = SetTimer(NULL, 0, 1, (TIMERPROC)&TimerStopJog);
    }
	*/
}





//---------------------------------------------------------------------
//
//	piInitControl() - Plugin extension of InitControl()
//
//		XML file can NOT be accessed since SetProName hasn't
//		been called yet
//
//		called EVEN if plugin is disabled
//
//---------------------------------------------------------------------

#ifdef PI_INITCONTROL
#ifdef _MANAGED
#pragma PI_MIX_INITCONTROL
#endif
bool piInitControl() {
  menuStart = GetMenuRange(MENU_COUNT);


  return true;
}
#endif

//---------------------------------------------------------------------
//
//	piSetProName() - Plugin extension of SetProName()
//
//		XML file CAN be accessed
//
//		called EVEN if plugin is disabled
//
//---------------------------------------------------------------------

#ifdef PI_SETPRONAME
#ifdef _MANAGED
#pragma PI_MIX_SETPRONAME
#endif
char * piSetProName(LPCSTR name) {
  XMLNetProfile ^ profile = gcnew XMLNetProfile(gcnew String(ProfileName), "Control-Pult", true);

  profile -> Load();

  MG::_mInst->SetUserLED(1040, 0); // Выключаем светодиод для индикации о том, что устройство не подключено

  return "Control Pult";
}
#endif

//---------------------------------------------------------------------
//
//	piPostInitControl() - Plugin extension of PostInitControl()
//
//		XML file can NOT be accessed
//
//		called ONLY if plugin is enabled
//
//---------------------------------------------------------------------

#ifdef PI_POSTINITCONTROL
#ifdef _MANAGED
#pragma PI_MIX_POSTINITCONTROL
#endif
void piPostInitControl() {


  // Store a reference to the form in the ManagedGlobal class for later use

  HMENU hMachMenu = GetMenu(MachView -> MachFrame -> m_hWnd);
  HMENU hPluginMenu = 0;
  int machMenuCnt = GetMenuItemCount(hMachMenu);
  MENUITEMINFO mii;
  LPTSTR txt;

  for (int i = 0; i < machMenuCnt; i++) {
    mii.cbSize = sizeof(MENUITEMINFO);
    mii.fMask = MIIM_FTYPE | MIIM_ID | MIIM_SUBMENU | MIIM_STRING;
    mii.dwTypeData = NULL;

    if (GetMenuItemInfo(hMachMenu, i, true, & mii)) {
      txt = (LPTSTR) malloc(++mii.cch);
      mii.dwTypeData = txt;

      if (GetMenuItemInfo(hMachMenu, i, true, & mii)) {
        if (strcmp(txt, "PlugIn Control") == 0) {
          hPluginMenu = mii.hSubMenu;
          i = machMenuCnt;
        }
      }

      free(txt);
    }

    if (hPluginMenu) {
       InsertMenu(hPluginMenu, -1, MF_BYPOSITION, menuStart, "Control Pult"); // Вставить плагин в выпадающее меню mach3
    }
  }



//Показ окна
  MG::PCD -> Show();
 init();

  //Start threat for updateCOM Port
System::Threading::ThreadStart^ threadDelegate = gcnew System::Threading::ThreadStart(mainThreadUpdateCOM);
System::Threading::Thread^ threadUpdateCOM = gcnew System::Threading::Thread(threadDelegate);
threadUpdateCOM->Start();


}
#endif

//---------------------------------------------------------------------
//
//	piConfig() - Plugin extension of Config()
//
//		called if user presses CONFIG in Config|Config Plugins
//		even if plugin is disabled
//
//		XML file CAN be accessed
//
//---------------------------------------------------------------------

#ifdef PI_CONFIG
#ifdef _MANAGED
#pragma PI_MIX_CONFIG
#endif
void piConfig() {
	MG::CD -> ShowDialog();
	
}
#endif

//---------------------------------------------------------------------
//
//	piStopPlug() - Plugin extension of StopPlug()
//
//---------------------------------------------------------------------

#ifdef PI_STOPPLUG
#ifdef _MANAGED
#pragma PI_MIX_STOPPLUG
#endif
void piStopPlug() {

  XMLNetProfile ^ profile = gcnew XMLNetProfile(gcnew String(ProfileName), "Control-Pult", true);

	  //before close save custom settings
  if (profile -> Load()) {
	
	  if( (!profile->ReadString("PORT")->Contains("COM")) ){
		profile->WriteString("PORT",MG::CD->selectedCOM);
	  }

    profile -> Save();


  }
//Записываем пользовательское значение jog
//MG::_mInst->SetOEMDRO(3,MG::userJogOverride);

try{
	

	if (MG::CD->Serial->IsOpen){
		MG::CD->Serial->WriteLine("?RLYOFF$");
		
	}

	else{
		MG::_mInst->Message("Serial Port was not open");
	}

}
	catch (System::Exception^ e) {
        MG::PCD->listBox1->Items->Add("Ошибка STOPPLUG:" + e->Message);
        MG::_mInst->SetUserLED(1040, 0);
    } 

}
#endif

//---------------------------------------------------------------------
//
//	piUpdate() - Plugin extension of Update()
//
//		XML file can NOT be accessed
//
//		called ONLY if plugin is enabled
//
//		WARNING - when you enable a plugin it immediately is added
//		to the update loop. if you haven't initialized some items
//		because PostInitControl() hasn't been called you can get
//		some problems!!!
//
//---------------------------------------------------------------------

#ifdef PI_UPDATE
#ifdef _MANAGED
#pragma PI_MIX_UPDATE
#endif
  
void piUpdate() {



}

#endif




//---------------------------------------------------------------------
//
//	piNotify() - Plugin extension of Notify()
//
//		among other notices this is where we are notified when the
//		user clicks on our 'PlugIn Control' menu item.
//
//		XML file CAN be accessed on a menu item notify
//
//---------------------------------------------------------------------

#ifdef PI_NOTIFY
#ifdef _MANAGED
#pragma PI_MIX_NOTIFY
#endif
void piNotify(int id) {
	
  if (id == menuStart) {
    //	xyzDemoConfig->enableDlg = MG::xyzDemoDialog->Visible;

    //вызов немодального окна
	  try{
		if (MG::PCD == nullptr || MG::PCD->IsDisposed)
			{
				MG::PCD = gcnew PlugInControlDialog();
			}

			MG::PCD->Show();
	  }
		
	  catch(System::Exception^ e) {
		  System::Windows::Forms::MessageBox::Show(e->Message);
	}
	     
	
  }
}
#endif

//---------------------------------------------------------------------
//
//	piDoDwell() - Plugin extension of DoDwell()
//
//---------------------------------------------------------------------

#ifdef PI_DODWELL
#ifdef _MANAGED
#pragma PI_MIX_DODWELL
#endif
void piDoDwell(double time) {

}
#endif

//---------------------------------------------------------------------
//
//	piReset() - Plugin extension of Reset()
//
//---------------------------------------------------------------------

#ifdef PI_RESET
#ifdef _MANAGED
#pragma PI_MIX_RESET
#endif

// Ф-я исполняется когда нажимаешь reset
void piReset() {



}
#endif

//---------------------------------------------------------------------
//
//	piJogOn() - Plugin extension of JogOn()
//
//---------------------------------------------------------------------

#ifdef PI_JOGON
#ifdef _MANAGED
#pragma PI_MIX_JOGON
#endif
void piJogOn(short axis, short dir, double speed) {

}

#endif

//---------------------------------------------------------------------
//
//	piJogOff() - Plugin extension of JogOff()
//
//---------------------------------------------------------------------

#ifdef PI_JOGOFF
#ifdef _MANAGED
#pragma PI_MIX_JOGOFF
#endif
void piJogOff(short axis) {}
#endif

//---------------------------------------------------------------------
//
//	piPurge() - Plugin extension of Purge()
//
//---------------------------------------------------------------------

#ifdef PI_PURGE
#ifdef _MANAGED
#pragma PI_MIX_PURGE
#endif
void piPurge(short flags) {

}
#endif

//---------------------------------------------------------------------
//
//	piProbe() - Plugin extension of Probe()
//
//---------------------------------------------------------------------

#ifdef PI_PROBE
#ifdef _MANAGED
#pragma PI_MIX_PROBE
#endif
void piProbe() {}
#endif

//---------------------------------------------------------------------
//
//	piHome() - Plugin extension of Home()
//
//---------------------------------------------------------------------

#ifdef PI_HOME
#ifdef _MANAGED
#pragma PI_MIX_HOME
#endif
void piHome(short axis) {}
#endif

