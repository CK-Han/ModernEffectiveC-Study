#include <iostream>
#include <memory>
using namespace std;

class Base {};
class A : public Base {};
class B : public Base {};

class Uptr_Deleter
{
public:
	void operator()(Base* base) { cout << "called Uptr_Deleter\n"; delete base; }
};


unique_ptr<Base, Uptr_Deleter> GetUniquePtr()
{
	int choiceDerived = rand() % 2;
	//굳이 호출가능 클래스를 작성하지 않고 람다로 처리 가능하다.
	Uptr_Deleter deleter;
	auto ptr = unique_ptr<Base, Uptr_Deleter>(nullptr, deleter);

	if (choiceDerived == 0)
		ptr.reset(new A());
	else
		ptr.reset(new B());

	return ptr;
}


void main()
{
	GetUniquePtr();
}