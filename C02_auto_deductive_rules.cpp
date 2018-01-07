#include <iostream>

using namespace std;

auto CreateInitList()
{
	return 1;
	//return{ 1,2,3 }; //불가능, return의 auto연역은 템플릿 연역 규칙을 따른다!
}

void main()
{
	const char name[] = "asdasd";
	auto& arr = name;

	cout << typeid(arr).name() << endl << endl;

	auto x1 = 3;
	auto x2{ 3 };
	auto x3 = { 3 }; //initializer_list!, 즉 template과의 연역 차이는 이 차이 하나이다.
	//auto x4{ 3,4,5 }; //initializer_list의 초기화는 = 를 표기해주어야 한다.

	cout << typeid(x1).name() << endl;
	cout << typeid(x2).name() << endl;
	cout << typeid(x3).name() << endl;
}