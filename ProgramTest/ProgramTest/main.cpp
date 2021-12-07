#include "include.h"

class CTest
{
public:
	CTest(int num) :m_num(num)
	{
	};


	void CbPrintSum(int *pnAddNum)
	{
		cout << "The sum is :" << m_num + *pnAddNum << endl;
	}

private:
	int m_num;
};



void main()
{
	wsc t2;   //类里通过bind类型绑定的成员线程，在对象初始化后即开始运行
	vector<int> num(10, 5);
	std::future<int> accumulate_future = std::async(std::launch::async, Accumulate, num.begin(), num.end());

	

	thread t1(threadFunc, 15);
	//t1.join();                             //用join()的话会在这里等待t1结束后才会继续向下运行
	//t1.detach();                           //用detach()的话不会在这里等待，会将其与主线程脱离，继续向下
	cout << "顺序执行："<< endl;
	cout << accumulate_future.get() << endl;    //这里没完成前会阻塞在这里

	cout << "会阻塞" << endl;


	CCallbackProxy<CTest, int> CbProxy;
	CTest TestInstance(20);

	CbProxy.Set(&TestInstance, &CTest::CbPrintSum);

	int n = 100;
	CbProxy.Exec(&n);
	

	system("pause");
}