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
	//std::future<int> accumulate_future = std::async(std::launch::async, Accumulate, num.begin(), num.end());

	

	//thread t1(threadFunc, 15);
	//t1.join();                             //用join()的话会在这里等待t1结束后才会继续向下运行
	//t1.detach();                           //用detach()的话不会在这里等待，会将其与主线程脱离，继续向下
	cout << "顺序执行："<< endl;
	//cout << accumulate_future.get() << endl;    //这里没完成前会阻塞在这里

	cout << "会阻塞" << endl;


// 	CCallbackProxy<CTest, int> CbProxy;
// 	CTest TestInstance(20);
// 
// 	CbProxy.Set(&TestInstance, &CTest::CbPrintSum);
// 
// 	int n = 100;
// 	CbProxy.Exec(&n);

// 	int a = 10; 
// 	printf("%d %d %d %d\n", a++, ++a, a, a++);//1. 在将参数入栈前，编译器会先把参数的的表达式都处理掉，哪怕这些运算会改变其中某些参数的值，
											 //2.对于a++操作，编译器会开辟一个缓冲区来保存当前a的值，然后再对a操作，取值时是从缓冲区取，而不是直接从a的内存地址里取。
	int g_num = 0;

	runnable1(g_num);        //这里的方法是为了验证多个调用方在调用同一个回调函数时，使用多线程可以解决阻塞问题。



	system("pause");
}