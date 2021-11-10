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
	vector<int> num(10, 5);
	std::future<int> accumulate_future = std::async(std::launch::async, Accumulate, num.begin(), num.end());

	

	thread t1(threadFunc, 15);
	//t1.join();
	t1.detach();
	cout << "Ë³ÐòÖ´ÐÐ£º"<< endl;
	cout << accumulate_future.get() << endl;

	CCallbackProxy<CTest, int> CbProxy;
	CTest TestInstance(20);

	CbProxy.Set(&TestInstance, &CTest::CbPrintSum);

	int n = 100;
	CbProxy.Exec(&n);
	

	system("pause");
}