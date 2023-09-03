#include<iostream>
using namespace std;

class Singleton {
    public:
        Singleton (const Singleton&) = delete; //避免单例被复制
        static Singleton& Get() { //获得单例
            return ton;
        }
        void Function () {}
    private:
        Singleton() {} //无法调用构造函数即无法生成实例
        static Singleton ton; //静态单例对象
};

Singleton Singleton::ton; //初始化静态类成员

int main() {
    Singleton::Get().Function();
}