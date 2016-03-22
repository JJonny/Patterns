#include <string>
#include <iostream>
using namespace std;

namespace base
{
	class Product
	{
	public:
		virtual string getName() = 0;
		virtual string getStr() = 0;
	};

	class ConcreteProduct1 : public Product
	{
		string m_str;
	public:
		string getName() {
			m_str = "product1";
			return m_str;
		}
		string getStr()	{ return m_str; }
	};

	class ConcreteProduct2 : public Product
	{
		string m_str;
	public:
		string getName() {
			m_str = "product2";
			return m_str;
		}

		string getStr()	{ return m_str; }
	};

	class Creator
	{
	public:
		virtual Product *factory() = 0;
	};

	class ConcreteCreator1 : public Creator
	{
	public:
		Product *factory() {
			return new ConcreteProduct1;
		}
	};

	class ConcreteCreator2 : public Creator
	{
	public:
		Product *factory() {
			return new ConcreteProduct2;
		}
	};
} // base namspce

