#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

class String {
    public:
        String() = delete;
        String(const char* Buff) {
            cout << "Create!" << endl;
            this->size = strlen(Buff);
            this->Buff = new char[this->size];
            strcpy(this->Buff, Buff);
        }
        String(const String& other) {
            cout << "Copy!" << endl;
            size = other.size;
            Buff = new char[size];
            strcpy(Buff, other.Buff);
        }
        String(String&& other) {
            cout << "Move!" << endl;
            size = other.size;
            Buff = other.Buff;
            other.size = 0;
            other.Buff = nullptr;
        }
        String& operator= (String&& other) {
            delete[] this->Buff;
            size = other.size;
            Buff = other.Buff;
            other.size = 0;
            other.Buff = nullptr;
            return *this;
        }
        ~String() {
            cout << "Destory!" << endl;
            delete[] Buff;
        }
    private:
        char* Buff;
        int size;
};

class Enity {
    public:
        Enity(const String& string) : s(string) {}
        Enity(String&& string) : s(move(string)) {}//右值引用

    private:
        String s;
};

int main() {
    //Enity e("Jinzikang");
    String s1 = "jinzikang";
    String s2 = s1;
}