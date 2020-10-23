#ifndef MUTEXGUARD_H
#define MUTEXGUARD_H

#include "GfcEngine\GfcEngine.h"
#include <memory>

namespace std {
    class mutex;
}

GFCENGINE_NAMESPACE_BEGIN

class GFCENGINE_API MutexGuard {
public:
    MutexGuard(std::shared_ptr<std::mutex> mutex);
    ~MutexGuard();

private:
    std::shared_ptr<std::mutex> m_mutex;
};
GFCENGINE_NAMESPACE_END

#endif // !MUTEXGUARD_H