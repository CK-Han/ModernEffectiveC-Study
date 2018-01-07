#include <iostream>
#include <vector>

using namespace std;

template <class T>
T foo(T&& t)
{
	cout << typeid(decltype(t)).name() << endl;
	return t;
}

template <class Container, class Index>
decltype(auto) GetElement(Container& c, Index i)
{
	cout << typeid(c).name() << endl; //typeid.name()�� ��Ȯ�� Ÿ���� �߷������� ���Ѵ�. boost�� type_index ����ؾ���
	//return c[i];
	return std::forward<Container>(c)[i];
}

class Temp
{
public:
	Temp() : arr{3,4,5,6,7} {}
	int& operator[](int idx) { return arr[idx]; }

private:
	int arr[5];
};

void main()
{
	int x = 3;
	decltype((x)) y = x; //(x)�� �̸��� �ƴ� ǥ�����̴�! int&�� �����Ѵ�.

	vector<bool> v1(3);
	vector<int> v2(3);
	
	GetElement(v2, 2);
	GetElement(std::move(vector<int>(3,1)), 2); //�и� �캯���ε� GetElement(Cont& ...)�� �۵��Ѵ�. �� �� �𸣰ڴ�.

	cout << typeid(GetElement(v2, 2)).name() << endl;	//typeid���� ǥ������ ������� �ʴ´�! ���� ���� ��
	cout << typeid(GetElement(vector<int>(3, 1), 2)).name() << endl;
}