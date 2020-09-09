#pragma once

#include "MutexGuard.h"
#include <mutex>

GFCENGINE_NAMESPACE_BEGIN

MutexGuard::MutexGuard(std::shared_ptr<std::mutex> mutex): m_mutex(mutex){
    if(m_mutex){
        m_mutex->lock();
    }
}

MutexGuard::~MutexGuard(){
    if(m_mutex){
        m_mutex->unlock();
    }
}
GFCENGINE_NAMESPACE_END
