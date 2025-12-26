#pragma once

// Команды на отправку
#define CMD_LPT_ON      "?LPTON$\r\n"
#define CMD_LPT_OFF     "?LPTOFF$\r\n"
#define CMD_DRV_ON      "?DRVON$\r\n"
#define CMD_DRV_OFF     "?DRVOFF$\r\n"
#define CMD_ERLS        "?ERLS$\r\n"
#define CMD_PURDY		"?PURDY$\r\n"

// Пользовательские команды для кнопок
#define UCB1      "!UCB1$\r\n"
#define UCB2	  "!UCB2$\r\n"
#define UCB3      "!UCB3$\r\n"
#define UCB4	  "!UCB4$\r\n"
#define UCB5      "!UCB5$\r\n"


// Сигналы аварии ШД
#define ALMX      "!ALMX$\r\n"
#define ALMZ	  "!ALMZ$\r\n"
#define ALMX_RLS      "!ALMX_RLS$\r\n"
#define ALMZ_RLS	  "!ALMZ_RLS$\r\n"


// Ответы от устройства
#define RESP_LPT_ON            "!LPTON$"
#define RESP_LPT_OFF           "!LPTOFF$"
#define RESP_DRV_ON            "!DRVON$"
#define RESP_DRV_OFF           "!DRVOFF$"
#define RESP_ERLS			   "!ERLS$"
#define RESP_ESTOP			   "!ESTP$"
#define RESP_PUOK			   "!PUOK$"
#define RESP_CYCLE_START       "!CS$"
#define RESP_CYCLE_SOFT_STOP   "!CSS$"

//Пользовательские индикаторы
#define LED_ALM_X			  1001
#define LED_ALM_Z             1002
#define LED_PURDY			  1003
#define LED_DRVCHECK		  1004
#define LED_LPTCHECK		  1005


//Переменные mach3 для сохранения состояния работы
#define DRV_VAR				  100
#define LPT_VAR				  101
