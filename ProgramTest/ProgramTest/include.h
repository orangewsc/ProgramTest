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