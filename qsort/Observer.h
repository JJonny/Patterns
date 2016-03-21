#pragma once
#include <list>
using namespace std;

namespace observer
{
	class WetherData;
	class IObserver
	{
	public:
		virtual void update(const WetherData &data) = 0;
	};


	class ISubject
	{
	public:
		virtual void addObserver(IObserver &o) = 0;
		virtual void removeObserver(IObserver &o) = 0;
		virtual void notify() = 0;
	};

	//////////////////
	class WetherData : public ISubject
	{
		string m_str;

		list<IObserver* const> m_observers;

	public:
		void addObserver(IObserver &o)
		{
			m_observers.push_back(&o);
		}

		void removeObserver(IObserver &o)
		{
			m_observers.remove(&o);
		}

		void notify()
		{
			for (auto it : m_observers)
			{
				it->update(*this);
			}
		}

		const string get() const
		{
			return m_str;
		}

		void set(string str)
		{
			m_str = str;
			notify();
		}
	};

	//
	class CurrentConditionDisplay : public IObserver
	{
		string mStr;
	public:
		void update(const WetherData &data)
		{
			mStr = data.get();
		}
	};

	//
	class StatisticDisplay : public IObserver
	{
		string mStr;

	public:
		void update(const WetherData &data)
		{
			mStr = data.get();
		}
	};

	//
	class ForecastDisplay : public IObserver
	{
		string mStr;
	public:
		void update(const WetherData &data)
		{
			mStr = data.get();
		}
	};
} // namespace





