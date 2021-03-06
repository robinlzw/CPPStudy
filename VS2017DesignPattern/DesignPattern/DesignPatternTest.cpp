// DesignPattern.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//构造
#include "Singleton.h"
#include "SimpleFactory.h"
#include "MethodFactory.h"
#include "AbstractFactory.h"
#include "Builder.h"
//结构
#include "Decpratpr.h"
#include "Composite.h"
#include "Facade.h"
#include "flyweight.h"
#include "Proxy.h"
#include "Bridge.h"
//行为
#include "TemplateMethod.h"
#include "command.h"
#include "Observer.h"
#include "mediator.h"
#include "memento.h"
#include "strategy.h"
#include "ChainofResponsibility.h"

//AOP
#include "Aspect.h"

#include <map>
#include <ctime>
using namespace std;
Singleton_lazy *Singleton_lazy::m_p = NULL;
mutex Singleton_lazy::m_mutex;
Singleton_lazy::GC Singleton_lazy::GC::gc;


void testSingleton()
{
	Singleton::GetInstance().doSomething();
	Singleton_lazy::GetInstance()->doSomething();
	Singleton_lazy *m = Singleton_lazy::GetInstance();
	m->doSomething();
}

void testSimpleFactory()
{
	SimpleFactory *SF = new SimpleFactory();
	ICar *pCar = NULL;
	pCar = SF->CreateCar(SimpleFactory::CAR_TYPE::AUDI_CAR);
	cout << pCar->name() << endl;
	delete pCar;

	pCar = SF->CreateCar(SimpleFactory::CAR_TYPE::BENZ_CAR);
	cout << pCar->name() << endl;
	delete pCar;

	pCar = SF->CreateCar(SimpleFactory::CAR_TYPE::BMW_CAR);
	cout << pCar->name() << endl;
	delete pCar;

	pCar = SF->CreateAudi();
	cout << pCar->name() << endl;
	delete pCar;

}

void testMethodFactory()
{
	MethodFactory *pFactory = new BenzFactory();
	ICar *pCar = pFactory->CreateCar();
	cout<<pCar->name() << endl;
	pFactory = new BmwFactory();
	pCar = pFactory->CreateCar();
	cout << pCar->name() << endl;
}

void testAbstractFactory()
{
	AF::AbstractFactory *pFactory = new AF::BenzFactory();
	ICar *pCar = pFactory->CreateCar();
	cout << pCar->name() << endl;
	pFactory = new AF::BmwFactory();
	AF::IBike *pBike = pFactory->CreateBike();
	cout << pBike->name() << endl;
}

void testBuilder()
{
	Director * pDirector = new Director();
	IBuilder * pBuilder = new MacBuilder();
	IBuilder * pBuilder2 = new MacProBuilder();
	pDirector->Create(pBuilder);
	pDirector->Create(pBuilder2);
	Computer *c = pBuilder->GetResult();
	Computer *c1 = pBuilder2->GetResult();
	cout << c->GetCpu() << endl;;
	cout << c1->GetCpu() << endl;
}


void testDecorator()
{
	IBeverage *pHouseBlend = new HouseBlend();
	cout << pHouseBlend->Name() << ":" << pHouseBlend->Cost() << endl;

	CondimentDecorator *pCream = new Cream(pHouseBlend);
	cout << pCream->Name() << ":" << pCream->Cost() << endl;

	CondimentDecorator *pMocha = new Mocha(pHouseBlend);
	cout << pMocha->Name() << ":" << pMocha->Cost() << endl;


	IBeverage *pDarkRost = new DarkRoast();
	cout << pDarkRost->Name() << ":" << pDarkRost->Cost() << endl;

	CondimentDecorator *pCreamDR = new Cream(pDarkRost);
	cout << pCreamDR->Name() << ":" << pCreamDR->Cost() << endl;
	;

	SAFE_DELETE(pHouseBlend);
	SAFE_DELETE(pCream);
	SAFE_DELETE(pMocha);
	SAFE_DELETE(pDarkRost);
	SAFE_DELETE(pCreamDR);

}

void testComposite()
{
	// 创建一个树形结构
	// 创建根节点
	Component *pRoot = new Composite("江湖公司（任我行）");

	// 创建分支
	Component *pDepart1 = new Composite("日月神教（东方不败）");
	pDepart1->Add(new Leaf("光明左使（向问天）"));
	pDepart1->Add(new Leaf("光明右使（曲洋）"));
	pRoot->Add(pDepart1);

	Component *pDepart2 = new Composite("五岳剑派（左冷蝉）");
	pDepart2->Add(new Leaf("嵩山（左冷蝉）"));
	pDepart2->Add(new Leaf("衡山（莫大）"));
	pDepart2->Add(new Leaf("华山（岳不群）"));
	pDepart2->Add(new Leaf("泰山（天门道长）"));
	pDepart2->Add(new Leaf("恒山（定闲师太）"));
	pRoot->Add(pDepart2);

	// 添加和删除叶子
	pRoot->Add(new Leaf("少林（方证大师）"));
	pRoot->Add(new Leaf("武当（冲虚道长）"));
	Component *pLeaf = new Leaf("青城（余沧海）");
	pRoot->Add(pLeaf);

	// 小丑，直接裁掉
	pRoot->Remove(pLeaf);

	// 递归地显示组织架构
	pRoot->Operation(1);

	// 删除分配的内存
	SAFE_DELETE(pRoot);
}

void testFacade()
{
	OnlineShoppingFacade facade;

	// 提交订单
	facade.submitRequest();

	// 跟踪订单，直到订单完成
	while (!facade.checkStatus());

	std::cout << "********** 订单完成，跟踪次数：" << facade.followupNum() << " **********" << std::endl;

}
std::map<std::string, IPlayer*> PlayerFactory::m_map = std::map<std::string, IPlayer*>();
// 玩家类型和武器
static std::string s_playerType[2] = { "T", "CT" };
static std::string s_weapons[4] = { "AK-47", "Maverick", "Gut Knife", "Desert Eagle" };
#define GET_ARRAY_LEN(array, len) {len = (sizeof(array) / sizeof(array[0]));}

void testFlyweight()
{
	srand((unsigned)time(NULL));
	int playerLen;
	int weaponsLen;
	GET_ARRAY_LEN(s_playerType, playerLen);
	GET_ARRAY_LEN(s_weapons, weaponsLen);
	// 假设，游戏中有十位玩家
	for (int i = 0; i < 10; i++) {
		// 获取随机玩家和武器
		int typeIndex = rand() % playerLen;
		int weaponIndex = rand() % weaponsLen;
		std::string type = s_playerType[typeIndex];
		std::string weapon = s_weapons[weaponIndex];

		// 获取玩家
		IPlayer *p = PlayerFactory::getPlayer(type);

		// 从武器库中随机分配武器
		p->assignWeapon(weapon);

		// 派玩家去执行任务
		p->mission();
	}


}


void testProxy()
{
	Proxy* proxy = new Proxy();
	proxy->Recharge(20);
	proxy->Recharge(100);

	SAFE_DELETE(proxy);
}


void testBridge()
{
	IElectricalEquipment *light = new Light();
	IElectricalEquipment *fan = new Fan();

	ISwitch *pullChain = new PullChainSwitch(light);
	ISwitch *twoPosition = new TwoPositionSwitch(fan);

	pullChain->On();
	pullChain->Off();

	twoPosition->On();
	twoPosition->Off();
	SAFE_DELETE(twoPosition);
	SAFE_DELETE(pullChain);
	SAFE_DELETE(fan);
	SAFE_DELETE(light);
}


void testTemplate()
{
	// 阿里校招
	Company *alibaba = new Alibaba();
	alibaba->Recruit();

	// 腾讯校招
	Company *tencent = new Tencent();
	tencent->Recruit();

	SAFE_DELETE(tencent);
	SAFE_DELETE(alibaba);

	getchar();
}

void testCommand()
{
	Receiver *rev = new Receiver();
	Command *cmd1 = new TakeCommand(rev);
	PayCommand *cmd2 = new PayCommand(rev);
	Invoker inv;

	inv.addCmd(cmd1);
	inv.addCmd(cmd2);
	inv.notify();

	delete cmd1;
	delete cmd2;
	delete rev;
}

void testObserver()
{
	// 创建主题、观察者
	ConcreteSubject *pSubject = new ConcreteSubject();
	IObserver *pObserver1 = new ConcreteObserver("trader1");
	IObserver *pObserver2 = new ConcreteObserver("trader2");

	// 注册观察者
	pSubject->Attach(pObserver1);
	pSubject->Attach(pObserver2);

	// 更改价格，并通知观察者
	pSubject->SetPrice(12.5);
	pSubject->Notify();

	// 注销观察者
	pSubject->Detach(pObserver2);
	// 再次更改状态，并通知观察者
	pSubject->SetPrice(15.0);
	pSubject->Notify();

	SAFE_DELETE(pObserver1);
	SAFE_DELETE(pObserver2);
	SAFE_DELETE(pSubject);

}

void testMediator()
{
	UnitedNationsSecurityCouncil UNSC;
	USA usa(&UNSC);
	Iraq iraq(&UNSC);
	UNSC.AddColleague(&usa);
	UNSC.AddColleague(&iraq);
	
	usa.Declare("usa say hi");
	iraq.Declare("iraq say hi");
}

void testmemento()
{
	GameRole *pLiXY = new GameRole(); // 创建李逍遥这个角色
	pLiXY->ShowState(); // 显示初始的状态

						// 存档
	RoleStateCaretaker *pRoleStateCaretaker = new RoleStateCaretaker();
	pRoleStateCaretaker->SetRoleStateMemento(pLiXY->SaveState());

	// 开始打大BOSS
	pLiXY->Fight();
	pLiXY->ShowState();

	// 读档，从新开始
	pLiXY->RecoveryState(pRoleStateCaretaker->GetRoleStateMemento());
	pLiXY->ShowState();

}

void testStrategy()
{
	IStrategy *bike = new BikeStrategy();
	Context *bikeC = new Context(bike);

	bikeC->Travel();
	delete bike;
	bike = new CarStrategy();
	delete bikeC;
	bikeC = new Context(bike);
	bikeC->Travel();

	delete bike;
	delete bikeC;
}

void testChain()
{
	IHandler *manager = new Manager();
	IHandler *director = new DirectorW();
	IHandler *ceo = new CEO();

	// 职责链：经理 -> 总监 -> 总裁
	manager->SetNext(director);
	director->SetNext(ceo);

	manager->HandleRequest(1);
	manager->HandleRequest(2);
	manager->HandleRequest(5);
	manager->HandleRequest(10);

	SAFE_DELETE(manager);
	SAFE_DELETE(director);
	SAFE_DELETE(ceo);
}

int main()
{
	//testSingleton();
	//testSimpleFactory();
	//testMethodFactory();
	//testAbstractFactory();
	//testBuilder();
	//testDecorator();
	//testComposite();
	//testFacade();
	//testFlyweight();
	//testProxy();
	//testBridge();
	//testTemplate();
	//testCommand();
	//testObserver();
	//testMediator();
	//testmemento();
	//testStrategy();
	//testChain();
	TestAOP();
	system("pause");
	return 0;
}

