#ifndef __NPNET_NOCOPYABLE__
#define __NPNET_NOCOPYABLE__

#include <mutex>
namespace NPNet
{
class nocopyable
{
private:
    /* data */
public:
    nocopyable()=default;
    nocopyable(const nocopyable&) = delete;
    nocopyable& operator=(const nocopyable& ) = delete;
    ~nocopyable()=default;
};

}
#endif