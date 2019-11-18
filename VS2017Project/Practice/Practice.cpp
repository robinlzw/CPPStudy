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
#include "./ThreadPoolsStudy.h"
#include "./ThreadsWaitNotifyManager.h"
#include "./coutStudy.h"
#include "./ComputerInformation.h"
#include "./libeventTimerStudy.h"
#include "./CircleVector.h"
#include "./pointerToMember.h"
#include "./mathTest.h"
#include "./asyncFutureStudy.h"
#include "./future_promise_test.h"
#include "./packagedTaskStudy.h"
#include "glogStudy.h"
#include "stringStudy.h"
#include "./constStudy.h"
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
	//JSONSTUDY::TestObjectToSerial();
	//JSONSTUDY::TestObjectToSerial2();
	JSONSTUDY::TestObjectToSeria3();
	//JSONSTUDY::JsonCreateMethod1();
	//JSONSTUDY::JsonCreateMethod2();
	//JSONSTUDY::iteratorRead();
	
	//ostreamTest();

	
/*	GGWlogger mylogger("testfile");
	mylogger.SetLevel(LOGLEVEL::LOG_DEBUG);
	mylogger.WriteLog( "hhhhhhh", LOGLEVEL::LOG_INFO);
	mylogger.WriteLog("hhhhhhh");
	*/

	/*
	//xml的操作
	xmlRead();
	*/
	/*
	//函数指针
	FunctionTest();
	*/
	//测试左值引用和右值引用 
	//doubleReferenceTest();

	//testThread_condition();



/*
	// create thread pool with 4 worker threads
	ThreadPool pool(4);
	// enqueue and store future
	auto result = pool.enqueue([](int answer) { return answer; }, 42);
	// get result from future
	std::cout << result.get() << std::endl;
*/

	//messengerTest();

	//ostreamTest();

	/*测试浮点数的精度
	int BidVolumn = 1;
	int AskVolumn = 1;
	double AskPrice = 286.15;  
	double BidPrice = 286.05;
	int marketSpread = 6;
	double tickPrice = 0.05;
	if (BidVolumn>0 && AskVolumn>0 )
	{
		cout << "1 true";
	}
	if ((AskPrice - BidPrice >= (2-0.1) * tickPrice))     //0.099999999999965894 >= 0.10000000000000001
		cout << "2 true";
	if ((AskPrice - BidPrice <= (marketSpread+0.1) * tickPrice))
		cout << " 3 true";
	if ((AskPrice - BidPrice - 2 * tickPrice)>=-0.001*tickPrice)
		cout << "4 true";
	if (fabs(AskPrice - BidPrice - 2 * tickPrice) < 0.1*tickPrice)
		cout << "5 true";
	
	if ((AskPrice - BidPrice-2*tickPrice) >= -0.1 * tickPrice)     //0.099999999999965894 >= 0.10000000000000001
		cout << "2 true";

	BidPrice = 0.0;
	if (BidPrice == 0)
		cout << "6 true";
		*/
   
		
	//测试线程之间互相通信
//messengerTest();

  // testElapsedmilliTime();
	//testCout();
/*
测试获取本地电脑信息的功能
	getNetworkInfo();
	getSysInfo();
	getIP();
	getCpuInfo();

	getMemoryInfo();
	getHardDiskInfo();
	getHardDiskInfo2();
	*/

//测试定时器的功能
//TimerTest();

//测试面向对象编程，接口编程。
/*
*/

/*
CicleVector cc;
cc.display();
for (int i = 2; i < 16; i++)
{
	cc.add(i);
}
cc.display();
cc.remove();
cc.remove();
cc.add(12);
cc.add(13);
cc.display();
cc.display2();
for (int i = 2; i < 16; i++)
{
	cc.remove();
}
for (int i = 2; i < 8; i++)
{
	cc.add(i);
}
cc.display();

cc.display2();
*/

/*testDataMember();

testPointToDataFunction();
*/

//testTryThrowException();
//testMyErrorException();

//MathTest::Test1(30.33);
//MathTest::ShowLimits();

//FunctionTest2();
//stdAsynct_test();
//future_promise_test();
//packagedTask_test();
//packagedTask_testBind();
//packagedTask_testClassBindholder();

//MathTest::testDBL_MIN();
//testGlog();

/*STLUnorderedMapTest test;
test.test();*/
/*
eventsTest();*/

/*STLVectorTest ss;
ss.testVectorTime1(10000000);
ss.testVectorTime2(10000000);
ss.testArrayTime1(10000000);*/
/*
std::cout<<gugw::string_to<int>("10000",1)<<std::endl;
std::cout << gugw::to_string<int>(10000) << std::endl;
vector<string>::const_iterator element;
vector<string> arrays = gugw::split("acb,dfd,asdf,ggg",',');
for (element = arrays.cbegin(); element < arrays.cend(); element++)
{
	std::cout << *element << "," << std::endl;
}

*/
//ConstTestF();
/*
STLPriorityQueueTest *test = new STLPriorityQueueTest();
test->test();
*/
/*
STLPriorityQueueTest2 test;
test.test();
*/
/*STLPriorityQueueTest3 test;
test.test();*/

	cin.get();
    return 0;
}
