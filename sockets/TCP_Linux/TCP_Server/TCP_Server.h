#ifndef _TCP_SERVER_H
#define _TCP_SERVER_H

//==================================================================
//================= @INCLUDES ======================================
//==================================================================
#include <netinet/in.h>

//==================================================================
//================= @DEFINES =======================================
//==================================================================
#define FALSE			0
#define TRUE			1

//==================================================================
//================= @ENUMS =========================================
//==================================================================
enum
{
	TCP_CLIENT_ID_1			= 0x00,
	TCP_CLIENT_ID_2			= 0x01,
	TCP_CLIENT_ID_3			= 0x02,
	TCP_CLIENT_ID_4			= 0x03,
	TCP_CLIENT_ID_5			= 0x04,
	TCP_CLIENT_ID_6			= 0x05,
	TCP_CLIENT_ID_7			= 0x06,
	TCP_CLIENT_ID_8			= 0x07,
};

//==================================================================
//================= @DATATYPES =====================================
//==================================================================
typedef struct
{
  struct sockaddr_in servAddr;
  struct sockaddr_in cliAddr;
  
  int sockfd;
    
} TCP_SERVER;

//==================================================================
//================= @FUNCTION PROTOTYPE ============================
//==================================================================
unsigned char TCP_SERVER_Init(TCP_SERVER *pTcpServer, int portNo);

void TCP_SERVER_Recv_Packet_From_Conn(TCP_SERVER *pTcpServer, int recvBufLen);

#endif