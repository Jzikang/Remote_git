#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int g_num = 10;
mutex g_mutex;

void thread1()
{   
    while(1) {
        g_mutex.lock();
        if (g_num > 0) {
            cout << g_num << endl;
            g_num--;
        } else {
            g_mutex.unlock();
            break;
        }
        g_mutex.unlock();
    }
    
   
}


int main(int argc, char* argv[])
{
    thread t(thread1);
    t.join();
    thread t1(thread1);
    t1.join();
    return 0;
}