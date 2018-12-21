// Practice.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "./libevent_EvbufferStudy.h"
//#include "libeventHello.h"
#include "chronoStudy.h"
#include "WindowsFileApi.h"
#include "exceptionStudy.h"
#include "./NetBigEndStudy.h"
#include "JSONStudy.h"
#include "./Thread_condition_variable.h"
#include "./shardPtrStudy.h"
#include "./libEventProxy.h"
#include "./STLMap.h"
#include "./STLVector.h"
#include "./streamStudy.h"
#include "./logger.h"
#include "./xmlStudy.h"
#include "./Cpp11_Function_Study.h"
using namespace std;


int main()
{
	//testSystemClock();
	//testPeriodNum();
	//testSystemClock_second();
	//testSystemClock_milliSecond();
	//testSystemClock_microSeconds();
	//testElapsedtime();
	//testLibeventHello(0, nullptr); 
	//testCreateDirectory();
	//testShowExecDirectory();
	//testTryException();
	//testLibeventEvbuffer(0, nullptr);
	//testBigEnd();
	//testJsonRead();
	/*testThread_condition_variable();
	*/
	//testSharedPtr();
	//testAutoPtr();

	
	/*ServerLib server;
	server.startByNewThread();
	ClientLib client;
	client.SocketStart();*/

	/*
	cout << "choice server or client:\n1:server \n2:client)\n";
	int choice = 0;
	cin >> choice;
	cin.get();
	ServerLib server;
	ClientLib client;
	if (choice == 1) {
		
		server.startByNewThread();
		cin.get();
	}
	else {
		
		client.LibEventStart();
		cin.get();
	}
	*/


	//STLMapTest map;
	//map.baseFuctionTest();

	/*STLVectorTest vectorTest;
	vectorTest.testVectorErase(13);
	*/

	//JSONSTUDY::stringSerialized();
	//JSONSTUDY::JsonCreateMethod1();
	//JSONSTUDY::JsonCreateMethod2();

	
	//ostreamTest();

	
/*	GGWlogger mylogger("testfile");
	mylogger.SetLevel(LOGLEVEL::LOG_DEBUG);
	mylogger.WriteLog( "hhhhhhh", LOGLEVEL::LOG_INFO);
	mylogger.WriteLog("hhhhhhh");
	*/

	//xmlRead();
	//FunctionTest();
	//doubleReferenceTest();

	testThread_condition();
	cin.get();
	cout << "end" << endl;
	cin.get();
    return 0;
}

