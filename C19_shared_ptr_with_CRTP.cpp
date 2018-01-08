#include <iostream>
#include <memory>

//Curiously Recurring Template Pattern
class Widget 
	: public std::enable_shared_from_this<Widget>
{
public:
	static std::shared_ptr<Widget> create()
	{
		//Widget �ʱ�ȭ�� �ʿ��� ���ڸ� �޾� �̸� �����ϰ�, �װ��� shared_ptr�� ��ȯ�Ѵ�.
		std::shared_ptr<Widget> ptr(new Widget());
		return ptr->GetThisSharedPtr();
	}
	
	std::shared_ptr<Widget> GetThisSharedPtr()
	{
		return shared_from_this();
		//shared_from_this�� ���� ��ü�� ���� �������� �����ϰ� �׿� ���� shared_ptr�� ��ȯ�Ѵ�.
		//�ٸ� ����, �������� �����Ǿ� �־�� �Ѵ�. �����Ǿ����� ������ ������ �ൿ�� ���´�.
		//�̸� �ذ��ϱ� ���� std::enable_shared_from_this<Widget>�� ��ӹ��� Ŭ������
		//�ڽ��� �����ڸ� private�� �����ϰ�, Ŭ���̾�Ʈ�� ��ü�� ������ �� �ֵ��� ���丮 �Լ��� �����ϴ� ��
	}

	~Widget() { std::cout << "dtor called\n"; }

private:
	Widget() { std::cout << "ctor called\n"; }
	
};

//////////////////////////////////////////////////////////////////
///////////// Curiously Recurring Template Pattern ��� ����
template <typename CountedType>
class ObjectCounter {
private:
	static size_t count;    // �����ϴ� ��ü ��

protected:
	// �⺻ ������
	ObjectCounter() {
		++ObjectCounter<CountedType>::count;
	}

	// ���� ������ 
	ObjectCounter(ObjectCounter<CountedType> const&) {
		++ObjectCounter<CountedType>::count;
	}

	// �Ҹ���
	~ObjectCounter() {
		--ObjectCounter<CountedType>::count;
	}

public:
	// �����ϴ� ��ü ���� ��ȯ 
	static size_t live() {
		return ObjectCounter<CountedType>::count;
	}
};

// ī���͸� 0���� �ʱ�ȭ
template <typename CountedType>
size_t ObjectCounter<CountedType>::count = 0;


template <typename CharT>
class MyString : public ObjectCounter<MyString<CharT> > {
	
};

int main()
{
	auto ptr = Widget::create();

	MyString<char> s1, s2;
	MyString<wchar_t> ws;
	std::cout << "number of MyString<char>: "
		<< MyString<char>::live() << std::endl;
	std::cout << "number of MyString<wchar_t>: "
		<< ws.live() << std::endl;
}