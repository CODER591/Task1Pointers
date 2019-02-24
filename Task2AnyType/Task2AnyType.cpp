// Task1 Pointers Cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <typeinfo>

using namespace std;



union Holding
{
	int intgr;
	double dbl;
	bool bl;
	char chr;
	unsigned int uint;
	//else can be done analogically
};
class Anytype
{
	private:
		bool booled;
		bool integ;
		bool doubler;
		bool chard;
		bool usint;
		Holding store;
	public:
		Anytype()
		{
			booled=false;
			integ = false;
			doubler = false;
			chard = false;
			usint = false;
		}
		template<typename T>
	    Anytype(T val )
		{
			if(typeid(int)==typeid(T))
			{
				store.intgr = val;
				integ = true;
				booled = false;
				doubler = false;
				chard = false;
				usint = false;
			}
			if(typeid(double)==typeid(T))
			{
				store.dbl=val;
				integ = false;
				booled = false;
				doubler = true;
				chard = false;
				usint = false;
			}
			if(typeid(bool)==typeid(T))
			{
				store.bl = val;
				integ = false;
				booled = true;
				doubler = false;
				chard = false;
				usint = false;
			}
			if(typeid(char)==typeid(T))
			{
				store.chr = val;
				integ = false;
				booled = false;
				chard = true;
				doubler = false;
				usint = false;
			}
			if(typeid(unsigned int)==typeid(T))
			{
				store.uint = val;
				integ = false;
				booled = false;
				chard = false;
				doubler = false;
				usint = true;
			}
		}
		int ToInt()
		{
			if(integ==true)
			{
				return store.intgr;
			}
			else
			{
				throw "Here is int exeption";
			}
		}
		void getType()
		{
			if(booled == true)   cout << "bool" << endl;
			if(integ == true)    cout << "int" << endl;
			if(chard == true)    cout << "char" << endl;
			if(doubler == true) cout << "double" << endl;
			if (usint == true)    cout << "unsigned int" << endl;
		}
		~Anytype(){}
		void operator =(const Anytype& any)
		{
			this->booled = any.booled;
			this-> integ = any.integ;
			this->doubler = any.doubler;
			this->chard = any.chard;
			this->store = any.store;
			this->usint = any.usint;
		}

};
void Swap(Anytype &a, Anytype &b)
{
	//make all sorts of buffers vars
	//or overload = operator
	Anytype ggg = a;
	a = b;
	b = ggg;
}

int main()
{
	//
	//AnyType any = false;
	//AnyType fff(1.6);
	//AnyType iii(7);
	//any = 7;
	//any = 'a';
	//any = 1.5;
	//try
	//{
	//	int bbb = any.ToInt();
	//	cout << "bbb " << bbb << endl;
	//	char kkk = any.ToChar();
	//	cout << "kkk " << kkk << endl;
	//	double lll = any.ToDouble();
	//	cout << "lll " << lll << endl;
	//	fff.ToChar();
	//	Swap(fff, any);
	//	any.TypeOfContainedVal();
	//	any = true; //get exeption
	//	any.ToDouble();
	//}
	//catch (const char* msg)
	//{
	//	cout << msg << endl;
	//}
	//cout << sizeof(AnyType);
	Anytype any = 10;
	Anytype bbb = true;
	//Swap(any, bbb);
	any.getType();
	bbb.getType();
	unsigned int ccc = 6;
	any = ccc;
	any.getType();
	cout << sizeof(Anytype) << endl;
	//better make alot constructors
	try
	{
		int b=any.ToInt();
		cout << b;
	}
	catch(const char* msg)
	{
		cout << msg << endl;
	}
	system("pause");
	return 0;
}
