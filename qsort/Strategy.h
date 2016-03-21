#pragma once

class Strategy
{
public:
	virtual ~Strategy(){}
	virtual void someFunc() = 0;
};

class Strat1 : public Strategy
{
public:
	void someFunc(){}
};

class Strat2 : public Strategy
{
public:
	void someFunc(){}
};

class Strat3 : public Strategy
{
public:
	void someFunc(){}
};


//////////

class Context
{
protected:
	Strategy *m_strat;
public:
	virtual ~Context() {}
	virtual void useStrategy() = 0;
	virtual void setStrategy(Strategy *obj) = 0;
	
};

class Client : public Context
{
public:
	void useStrategy()
	{
		m_strat->someFunc();
	}

	void setStrategy(Strategy* obj)
	{
		m_strat = obj;
	}
};


