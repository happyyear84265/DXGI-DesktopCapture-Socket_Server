// testsocket.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include "wcomm.h"

#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" ) 

void runserver();

WComm w;

int main(int argc, char* argv[])
{
	if (argc == 1) runserver();
	FILE* fp;
	if (fp = fopen("ScreenShot0.jpg", "r")) 
	{
		fclose(fp);
		ShellExecute(NULL, L"open", L"ScreenShot0.jpg", NULL, NULL, SW_SHOWDEFAULT);
	}
	return 0;
}

void runserver()
{
	// Start Server Daemon
	w.startServer(8787);
	printf("Server Started........\n");

	while (TRUE) 
	{
		// Wait until a client connects
		w.waitForClient();
		printf("Client Connected......\n");

		// Work with client
		while (TRUE)
		{
			char rec[50] = "";
			char sed[50] = "OK";
			w.recvData(rec, 32); 
			w.sendData(sed);

			if (strcmp(rec, "FileSend") == 0)
			{
				char fname[32] = "";
				w.fileReceive(fname);
				printf("File Received.........\n");
			}
			if (strcmp(rec, "EndConnection") == 0)break;
			printf("Connection Ended......\n");
			break;
		}
		// Disconnect client
		w.closeConnection();
		break;
	}
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
