#include <iostream>

using namespace std;

auto CreateInitList()
{
	return 1;
	//return{ 1,2,3 }; //�Ұ���, return�� auto������ ���ø� ���� ��Ģ�� ������!
}

void main()
{
	const char name[] = "asdasd";
	auto& arr = name;

	cout << typeid(arr).name() << endl << endl;

	auto x1 = 3;
	auto x2{ 3 };
	auto x3 = { 3 }; //initializer_list!, �� template���� ���� ���̴� �� ���� �ϳ��̴�.
	//auto x4{ 3,4,5 }; //initializer_list�� �ʱ�ȭ�� = �� ǥ�����־�� �Ѵ�.

	cout << typeid(x1).name() << endl;
	cout << typeid(x2).name() << endl;
	cout << typeid(x3).name() << endl;
}