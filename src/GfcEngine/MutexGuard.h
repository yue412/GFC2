#pragma once

#include "GfcEngine\GfcEngine.h"
#include <memory>

namespace std{
    class mutex;
}

GFCENGINE_NAMESPACE_BEGIN

class MutexGuard{
public:
    MutexGuard(std::shared_ptr<std::mutex> mutex);
    ~MutexGuard();

private:
    std::shared_ptr<std::mutex> m_mutex;
};
GFCENGINE_NAMESPACE_END
