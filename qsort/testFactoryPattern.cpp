#include "Factory.h"

//int main()
//{
//	static const size_t numObjects = 2;
//	ConcreteCreator1 *c1 = new ConcreteCreator1;
//	ConcreteCreator2 *c2 = new ConcreteCreator2;
//
//	Creator *creators[numObjects] = { c1, c2 };
//	Product *p[numObjects];
//	for (size_t i = 0; i < numObjects; i++)
//	{
//		p[i] = creators[i]->factory();
//		string ss = p[i]->getName();
//	}
//
//	string ss = p[0]->getStr();
//	ss = p[1]->getStr();
//
//	return 0;
//}