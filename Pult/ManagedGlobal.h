//=====================================================================
//
//	Plugin::MG - Plugin's ManagedGlobal (MG) class
//
//	place static members here to hold our global handles and managed
//	data which need to persist. they will need to be 'copied' to working
//	variables in the functions that use them so that the 'static' will
//	not interfere with operations.
//
//	see xyzdemo for examples of usage
//
//=====================================================================

#ifdef _MANAGED
#pragma managed

using namespace tst;
using namespace System;

namespace tst
{

	public ref class MG
	{
	public:
		//--- sample of a global modeless dialog -----
		//static	MonitorDialog^ monitorDialog;
		//--------------------------------------------
		static	 PlugInControlDialog^ PCD = gcnew PlugInControlDialog();
		static	 ConfigDialog^ CD = gcnew ConfigDialog();
		static   IMach4^ _mach = (IMach4^) Marshal::GetActiveObject("Mach4.Document");
		static	 IMyScriptObject^ _mInst = (IMyScriptObject^) _mach->GetScriptDispatch();
		static bool initComplete = false;  //flag init
		static String^ currentCOM = "";
		static String^ lastRcvMessage = "";	 //recive message from microcontroller
		static String^ initLPTPower = ""; //Подтверждение на включение реле
		/*
		literal System::String^ CMD_LPT_ON		 = "?LPTON$\n";
		literal System::String^ CMD_DRV_ON		 = "?DRVON$\n";
		literal System::String^ CMD_DRV_OFF		 = "?DRVOFF$\n";
		literal System::String^ CMD_ERLS		 = "?ERLS$\n";
		literal System::String^ CMD_JOG_STOP     = "?JOGSTP$";

		literal System::String^ RESP_LPT_ON		 = "!LPTON$";
		literal System::String^ RESP_DRV_ON		 = "!DRVON$";
		literal System::String^ RESP_DRV_OFF	 = "!DRVOFF$";
		literal System::String^ RESP_ERLS		 = "!ERLS$";
		literal System::String^ RESP_ESTOP		 = "!ESTP$";
		literal System::String^ RESP_PUOK		 = "!PUOK$";
		  */
		
		};
}
#endif

		
/*		
#ifdef _MANAGED
#pragma managed

using namespace System;

namespace tst
{
	public ref class MG
	{
	public:
		// Объявляем переменные, но НЕ инициализируем
		static PlugInControlDialog^ PCD;
		static ConfigDialog^ CD;
		static IMach4^ _mach;
		static IMyScriptObject^ _mInst;
		static bool initComplete;
		static String^ currentCOM;
		static String^ lastRcvMessage;
		static String^ initLPTPower;

		literal System::String^ CMD_LPT_ON = "?LPTON$\n";
		literal System::String^ CMD_DRV_ON = "?DRVON$\n";
		literal System::String^ CMD_DRV_OFF = "?DRVOFF$\n";
		literal System::String^ CMD_ERLS = "?ERLS$\n";
		literal System::String^ CMD_JOG_STOP = "?JOGSTP$";

		literal System::String^ RESP_LPT_ON = "!LPTON$";
		literal System::String^ RESP_DRV_ON = "!DRVON$";
		literal System::String^ RESP_DRV_OFF = "!DRVOFF$";
		literal System::String^ RESP_ERLS = "!ERLS$";
		literal System::String^ RESP_ESTOP = "!ESTP$";
		literal System::String^ RESP_PUOK = "!PUOK$";
	};
}
#endif
	   */