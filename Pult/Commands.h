#pragma once

// Команды на отправку
#define CMD_LPT_ON      "?LPTON$\n"
#define CMD_LPT_OFF     "?LPTON$\n"
#define CMD_DRV_ON      "?DRVON$\n"
#define CMD_DRV_OFF     "?DRVOFF$\n"
#define CMD_ERLS        "?ERLS$\n"
#define CMD_JOG_STOP    "?JOGSTP$"
#define CMD_PURDY		"?PURDY$\r\n"

// Ответы от устройства
#define RESP_LPT_ON     "!LPTON$"
#define RESP_DRV_ON     "!DRVON$"
#define RESP_DRV_OFF    "!DRVOFF$"
#define RESP_ERLS       "!ERLS$"
#define RESP_ESTOP      "!ESTP$"
#define RESP_PUOK       "!PUOK$"
