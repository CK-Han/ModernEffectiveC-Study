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
	//���� ȣ�Ⱑ�� Ŭ������ �ۼ����� �ʰ� ���ٷ� ó�� �����ϴ�.
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