#include "Factory.h"

//int main()
//{
//	// base test
//	static const size_t numObjects = 2;
//	base::ConcreteCreator1 *c1 = new base::ConcreteCreator1;
//	base::ConcreteCreator2 *c2 = new base::ConcreteCreator2;
//
//	base::Creator *creators[numObjects] = { c1, c2 };
//	base::Product *p[numObjects];
//	for (size_t i = 0; i < numObjects; i++)
//	{
//		p[i] = creators[i]->factory();
//		string ss = p[i]->getName();
//	}
//
//	string ss = p[0]->getStr();
//	ss = p[1]->getStr();
//
//
//	return 0;
//}