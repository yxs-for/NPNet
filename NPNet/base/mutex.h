#ifndef __NPNET_MUTEX__
#define __NPNET_MUTEX__

#include <mutex>
namespace NPNet
{
using Mutex=std::mutex;
using LockGuard=std::lock_guard<Mutex>;

}


#endif