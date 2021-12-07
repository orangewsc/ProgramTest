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
	wsc t2;   //����ͨ��bind���Ͱ󶨵ĳ�Ա�̣߳��ڶ����ʼ���󼴿�ʼ����
	vector<int> num(10, 5);
	std::future<int> accumulate_future = std::async(std::launch::async, Accumulate, num.begin(), num.end());

	

	thread t1(threadFunc, 15);
	//t1.join();                             //��join()�Ļ���������ȴ�t1������Ż������������
	//t1.detach();                           //��detach()�Ļ�����������ȴ����Ὣ�������߳����룬��������
	cout << "˳��ִ�У�"<< endl;
	cout << accumulate_future.get() << endl;    //����û���ǰ������������

	cout << "������" << endl;


	CCallbackProxy<CTest, int> CbProxy;
	CTest TestInstance(20);

	CbProxy.Set(&TestInstance, &CTest::CbPrintSum);

	int n = 100;
	CbProxy.Exec(&n);
	

	system("pause");
}