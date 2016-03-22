#include <memory>
#include <iostream>
using namespace std;

namespace oreilly
{
	// beverage
	class Beverage
	{
		string m_sdescription;
	public:
		virtual ~Beverage(){}
		virtual string getDescription() = 0;
		virtual int cost() = 0;
	};

	// decorator
	class Decorator : public Beverage
	{
		Beverage *m_beverage;		
	public:
		Decorator(Beverage *beverage) : m_beverage(beverage)
		{}
		
		int cost() 
		{ 
			return m_beverage->cost();	
		}
		
		string getDescription()	
		{ 
			return m_beverage->getDescription();	
		}

	};

	namespace coffe
	{
		//HouseBiend 
		class HouseBiend : public Beverage
		{			
			int m_cost;
			string m_description;
		public:
			HouseBiend() : m_cost(10)				
			{
				m_description = "HouseBiend";
			}

			int cost() 
			{
				return m_cost;	
			}

			string getDescription()
			{
				return m_description;
			}
		};

		//Espresso
		class Espresso : public Beverage
		{			
			string m_description;
			int m_cost;
		public:
			Espresso() : m_cost(8)		
			{
				m_description = "Espresso";
			}

			int cost() 
			{
				return m_cost;	
			}

			string getDescription()
			{
				return m_description;
			}
		};
	} // coffe

	namespace added
	{
		// added milk
		class Milk : public Decorator
		{
			int m_cost;
			string m_descriptoin;
			Beverage *m_beverage;
		public:
			Milk(Beverage *beverage) : m_beverage(beverage), m_cost(3), Decorator(beverage)
			{
				m_descriptoin = " with Milk";
			}

			int cost()
			{
				return m_beverage->cost() + m_cost;
			}

			string getDescription()
			{
				return m_beverage->getDescription() + m_descriptoin;
			}
		};

		// added Mocha
		class Mocha : public Decorator
		{
			Beverage *m_beverage;
			string m_description;
			int m_cost;
		public:
			Mocha(Beverage *beverage) : m_beverage(beverage), m_cost(8), Decorator(beverage)
			{
				m_description = " with mocha";
			}

			int cost()
			{
				return m_beverage->cost() + m_cost;
			}

			string getDescription()
			{
				return m_beverage->getDescription() + m_description;
			}
		};
		
	} // added 
}

namespace standart
{
	class IComponent
	{
	public:
		virtual int cost() = 0;
		virtual ~IComponent(){}
	};

	class Component : public IComponent
	{
		int m_sum;
	public:
		Component(int &sum) : m_sum(sum)
		{}

		virtual int cost()
		{
			return m_sum;
		}
	};

	class Decorator1 : public IComponent
	{
		std::shared_ptr<IComponent> m_component;
		int m_sum;
	public:
		Decorator1(IComponent *obj, int &sum) : m_component(obj), m_sum(sum)
		{}

		virtual int cost()
		{
			return m_sum += m_component->cost();
		}
	};


	class Decorator2 : public IComponent
	{
		std::shared_ptr<IComponent> m_component;
		int m_sum;
	public:
		Decorator2(IComponent *obj, int &sum) : m_component(obj), m_sum(sum)
		{}

		virtual int cost()
		{
			return m_sum += m_component->cost();
		}
	};
} //namespace standart