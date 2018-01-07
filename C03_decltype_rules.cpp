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
	cout << typeid(c).name() << endl; //typeid.name()은 정확한 타입을 추론해주지 못한다. boost의 type_index 사용해야함
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
	decltype((x)) y = x; //(x)는 이름이 아닌 표현식이다! int&를 보고한다.

	vector<bool> v1(3);
	vector<int> v2(3);
	
	GetElement(v2, 2);
	GetElement(std::move(vector<int>(3,1)), 2); //분명 우변값인데 GetElement(Cont& ...)에 작동한다. 아 잘 모르겠다.

	cout << typeid(GetElement(v2, 2)).name() << endl;	//typeid내의 표현식은 실행되지 않는다! 그저 비교할 뿐
	cout << typeid(GetElement(vector<int>(3, 1), 2)).name() << endl;
}