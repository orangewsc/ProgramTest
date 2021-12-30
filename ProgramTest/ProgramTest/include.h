#ifndef __INCLUDE_H
#define __INCLUDE_H


#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
#include <Windows.h>
using namespace std;

int Accumulate(vector<int>::iterator first, vector<int>::iterator last)
{
	Sleep(5000);
	int sum = std::accumulate(first, last, 0);
	cout << "结果算完了：" << sum << endl;
	return sum;
}

void threadFunc(int num)
{
	for (int i = 0; i < num;i++)
	{
		Sleep(1000);
		cout << "我先运行了：" << i << endl;
	}
}


void threadFunc2()
{
	cout << "直接运行了：" << endl;
}

void threadFunc3(int num, int &g_num)
{
	Sleep(5000);
	g_num = num;
	cout << "周期调度" << num<<": "<<g_num<< endl;
}


void runnable1(int g_num)
{
	for (int i = 0; i < 5; i++)            //这里的方法是为了验证多个调用方在调用同一个回调函数时，使用多线程可以解决阻塞问题。
	{
		Sleep(1000);
		thread t3(threadFunc3, i, g_num);
		t3.detach();
	}
}

class wsc
{
public:
	wsc() :m_t(std::bind(&wsc::threadFunc2, this))
	{
	}
	thread m_t;

	void threadFunc2()
	{
		cout << "类初始化列表里的线程直接运行了：" << endl;
	}
};



template<typename Tobject,typename Tparam>
class  CCallbackProxy
{
	typedef void(Tobject::*CbFun)(Tparam*);
public:

	void Set(Tobject *pInstance, CbFun pFun);
	bool Exec(Tparam* pParam);

private:
	CbFun		pCbFun;
	Tobject*	m_pInstance;
};
template<typename Tobject,typename Tparam>
void CCallbackProxy<Tobject, Tparam>::Set(Tobject *pInstance, CbFun pFun)
{
	m_pInstance = pInstance;
	pCbFun = pFun;
}

template<typename Tobject, typename Tparam>
bool CCallbackProxy<Tobject, Tparam>::Exec(Tparam* pParam)
{
	(m_pInstance->*pCbFun)(pParam);
	return 1;
}











#endif