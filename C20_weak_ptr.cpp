#include <iostream>
#include <memory>
#include <unordered_map>
class Temp {};

//weak_ptr의 사용 예시
std::shared_ptr<const Temp> FastLoadTemp(unsigned int id)
{
	static std::unordered_map<int, std::weak_ptr<const Temp>> cache;

	auto ptr = cache[id].lock();
	if (ptr == nullptr)
	{
		//캐시에 없는 경우이므로 ptr에 Temp를 불러오고, cache에 등록한다.
	}
	
	//이 함수는 파괴된 Temp에 대해 cache의 erase는 구현되지 않았음을 주의
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