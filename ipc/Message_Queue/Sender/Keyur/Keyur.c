//==================================================================
//================= @INCLUDES ======================================
//==================================================================
#include <stdio.h>
#include "MsgQue.h"

//==================================================================
//================= @DEFINES =======================================
//==================================================================
#define	MODULE_NAME			"Keyur"
#define	MODULE_ID			3

//==================================================================
//================= @ENUMS =========================================
//==================================================================

//==================================================================
//================= @DATATYPES =====================================
//==================================================================
static MSG_QUE msgQue;

//==================================================================
//================= @FUNCTION PROTOTYPE ============================
//==================================================================

//==================================================================
//================= @FUNCTION DEFINITION ===========================
//==================================================================
int main (void)
{
	char buffer[MSG_BUF_SIZE_MAX] = "";

	MSG_QUE_Init(&msgQue, MSG_QUE_KEY_1, MODULE_ID, MODULE_NAME);

	while (TRUE)
	{
		scanf("%s", buffer);
		MSG_QUE_Send_Data(&msgQue, buffer);
	}

	return 0;
}


