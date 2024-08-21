#include <iostream>
#include <thread>
#include <map>

#include <windows.h>
#include <chrono>

using namespace std;



int main()
{
    
    thread t1([](){
        cout<<"Hello from thread 1\n";
    });
    thread t2([](){
        cout<<"Hello from thread 2\n";
    });
    t1.join();
    t2.join();
    
    // Sleep(5000);
    system("pause");
    return  0 ; 


}