#ifndef __RW_LOCK_T__
#define __RW_LOCK_T__

#include <pthread.h>

//! ReadWriteLock is an implementation of a read/write lock.
class ReadWriteLock
{
    int NoOfReaders, NoOfWriters, NoOfWritersWaiting;
    pthread_mutex_t class_mutex;
    pthread_cond_t  reader_gate;
    pthread_cond_t  writer_gate;

public:
    ReadWriteLock();
    virtual ~ReadWriteLock();
    void r_lock();      //!< Get read lock
    void w_lock();      //!< Get write lock
    void r_unlock();    //!< Release read lock
    void w_unlock();    //!< Release write lock
};

#endif
