// StudyBase.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "./InterfaceDefineAndRealize.h"
#include <iostream>
#include "a.h"
#include "./b.h"
#pragma comment(lib, "../Debug/GUGWAPI.lib")
#pragma comment(lib, "../Debug/OTHERAPI.lib")
int main()
{

	CNaiveApproach obj(10);
	obj.Test();
	obj.Func();

	IExport* pExport = CreateExportObj();
	pExport->Hi();
	pExport->Test();
	DestroyExportObj(pExport);
	system("pause");
    return 0;
}

