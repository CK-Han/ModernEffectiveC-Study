#include <iostream>
#include <string>
#include <set>
#include <vector>

void f1(const std::vector<int>& v)
{
}

void f2(void*)
{
}

class Temp
{
public:
	static constexpr int STATIC_CONSTEXPR_INT = 3;
};

void f3(int)
{
}

void f4_overload(int)
{
}

void f4_overload()
{
}

template <class T>
void f4_template(T)
{
}

void f4(void(*)(int))
{
}

struct Header
{
	std::uint32_t head : 2
		, data : 14
		, extra : 16;
};

void f5(std::uint32_t sz)
{}


template<typename Func, typename... Ts>
void fwd(Func func, Ts&&... param)
{
	func(std::forward<Ts>(param)...);
}



void main()
{
	//1. �߰�ȣ �ʱ�ġ�� ���� ������ ����
	auto t = { 1,2,3 };
	//fwd(f, {1,2,3 }); //�������� ����
	fwd(f1, t);

	//2. �� �����͸� ���ϴ� 0, NULL
	//fwd(f2, NULL);
	//fwd(f2, 0);
	fwd(f2, nullptr);

	//3. ���� �� ���� static const �� constexpr ���
	//�����Ϸ����� �ٸ���. ��� ����� ���� �����Ҵ��� ���� �ʴ� ���, �̿� ����
	//��ũ ������ �߻��ϴ� ��찡 �ִ�.
	fwd(f3, Temp::STATIC_CONSTEXPR_INT);

	//4. �����ε� �Լ� �̸��� ���ø� �̸�
	f4(f4_overload); //�� ã��
	//fwd(f4, f4_overload); //�� ã��
	f4(f4_template); //�� ã��
	//fwd(f4, f4_template); //��ã��

	//5. ��Ʈ�ʵ�
	Header h;
	f5(h.extra); //�����ϵǳ� �������
	//fwd(f5, h.extra); //�����ϵ� ���� ����
}