#include <iostream>
#include <memory>
#include <unordered_map>
class Temp {};

//weak_ptr�� ��� ����
std::shared_ptr<const Temp> FastLoadTemp(unsigned int id)
{
	static std::unordered_map<int, std::weak_ptr<const Temp>> cache;

	auto ptr = cache[id].lock();
	if (ptr == nullptr)
	{
		//ĳ�ÿ� ���� ����̹Ƿ� ptr�� Temp�� �ҷ�����, cache�� ����Ѵ�.
	}
	
	//�� �Լ��� �ı��� Temp�� ���� cache�� erase�� �������� �ʾ����� ����
	return ptr;
}


void main()
{
	std::shared_ptr<Temp> sp(new Temp());
	std::weak_ptr<Temp> wp(sp);

	bool isExpired = wp.expired();

	auto newSp1 = wp.lock();
	std::shared_ptr<Temp> newSp2(wp);


}