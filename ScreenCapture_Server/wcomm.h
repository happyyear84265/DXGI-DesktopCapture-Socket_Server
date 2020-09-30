#include "winsock2.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>

using namespace std;
class WComm
{

public:
	
	WComm();

	void connectServer(char*,int);
	 int sendData(char*);
	 int recvData(char*,int);
	void fileSend(char*);
	void fileReceive(char*);
	void startServer(int);
	void waitForClient();
	void closeConnection();
};