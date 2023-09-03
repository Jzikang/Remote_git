#include<iostream>
#include<map>
using namespace std;
class Base {
	public:
		//static int a;
		void PrintName() {
			cout << "I am in Base!" << endl;
		}
		Base() {cout << "Create Base" << endl;}
		virtual ~Base() {cout << "Destory Base" << endl;}
};

class Child : public Base {
	public:
		Child() {cout << "Create Child" << endl;}
		~Child() {cout << "Destory Child" << endl;}
};

class Girl : public Base {
	public:
		void PrintName() {
			cout << "I am in Girl!" << endl;
		}
		Girl() {cout << "Create Child_" << endl;}
		~Girl() {cout << "Destory Child_" << endl;}
};
static char a;
int main()
{
	//Base* b = new Base();
	Child* c = new Child();
	//Child* c = b;
	Base* b = c;
	delete b;
}
