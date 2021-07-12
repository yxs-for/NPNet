#ifndef __NPNET_THREAD__
#define __NPNET_THREAD__
#include <thread>
#include<functional>
#include <memory>
#include<cassert>
#include "mutex.h"
#include "NPNet/base/nocopyable.h"

using std::string;
using std::thread;

namespace NPNet
{
class Thread :nocopyable
{
public:
    using ThreadFunc =std::function<void(void)>;
private:
    std::unique_ptr<thread> m_thread_prt;
    ThreadFunc  m_func;
    string      m_name;
    bool        m_running=false;
    Mutex   mutable    m_mutex;
    
public:
    Thread(ThreadFunc func,const string &name={}): m_func{move(func)},
                                                            m_name{name}
                                                            {};
    void start()
    { 
        //  asdsad
        LockGuard guard(m_mutex);
        assert(!m_running); // TODO:  LOG ERROR
        m_running=true;
        m_thread_prt.reset(new thread(&Thread::_run,this));
        // m_thread_prt.reset(new thread(m_func));

    };
    ~Thread(){
        //
        m_thread_prt.release(); // 
    };

    bool is_running() const
    {
        LockGuard guard(m_mutex );
        return m_running;
    };
    void _run()
    {
        m_func();

        LockGuard guard(m_mutex);
        m_running=false;
    }
private:
    
};



}




#endif