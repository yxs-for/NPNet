#include "NPNet/base/thread.h"
#include<functional>
#include<iostream>
#include<thread>
#include<chrono>
using std::cout;
using std::endl;
using namespace NPNet;
// namespace NPNet::test
// {

int main()
{
    auto funfact(
        [](auto &name)
        {
            return [name](auto end)
            {
                return [=]()
                {
                    for(int i=0;i<end;++i)
                    {
                        cout<<"from :"<<name<<" i:"<<i<<endl;
                    }
                };
                
            };
        }
    );
    //
    auto func1=funfact("func1")(10);
    auto func2=funfact("func2")(10);
    // auto funcm=funfact("funcm")(1000);

    Thread t1(func1);
    Thread t2(func2);
    cout<<std::boolalpha<<t1.is_running()<<'\n';
    cout<<std::boolalpha<<t2.is_running()<<'\n';
    t1.start();
    t2.start();
    cout<<std::boolalpha<<t1.is_running()<<'\n';
    cout<<std::boolalpha<<t2.is_running()<<'\n';
    std::this_thread::sleep_for(
        std::chrono::seconds(10));
    cout<<std::boolalpha<<t1.is_running()<<'\n';
    cout<<std::boolalpha<<t2.is_running()<<'\n';
    // funcm();
}
// }