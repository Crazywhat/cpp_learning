///
/// @file    main.c


#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

using std::cout;
using std::endl;

class MutexLock
{
	public:
		MutexLock();
		~MutexLock();
		void lock();
		void unlock();
		pthread_mutex_t* get_lock();
	private:
		pthread_mutex_t _mutex;
};

MutexLock::MutexLock()
{
	int ret = pthread_mutex_init(&_mutex,NULL);
	if(0!=ret)
	{
		cout << "lock_init : " << ret << endl;
	}
}
MutexLock::~MutexLock()
{	
	int ret = pthread_mutex_destroy(&_mutex);
	if(0!=ret)
	{
		cout << "destroy error : " << ret << endl;
	}
}
void MutexLock::lock()
{	
	int ret=pthread_mutex_lock(&_mutex);
	if(0!=ret)
	{
		cout << "lock error : " << ret << endl;
	}

}
void MutexLock::unlock()
{
	int ret=pthread_mutex_unlock(&_mutex);
	if(0!=ret)
	{
		cout << "unlock error : " << ret << endl;
	}
}
pthread_mutex_t* MutexLock::get_lock()
{
	return &_mutex;
}



class Condition
{
	public:
		Condition();
		~Condition();
		void wait(pthread_mutex_t* pmutex);
		void notify();
		void notifyall();
	private:
			pthread_cond_t _cond;
};



Condition::Condition()
{
	 int ret = pthread_cond_init(&_cond,NULL);
	 if(0!=ret)
	 {
		cout << "cond_init error : " << ret << endl;
	 }
}
Condition::~Condition()
{
	int ret=pthread_cond_destroy(&_cond);
	if(0!=ret)
	{
		cout << "destroy error : " << ret << endl;
	}
}
void Condition::wait(pthread_mutex_t* pmutex)
{
	int ret=pthread_cond_wait(&_cond,pmutex);
	if(0!=ret)
	{
		cout << "wait error : " << ret << endl;
	}
}

void Condition::notify()
{
	int ret = pthread_cond_signal(&_cond);
	if(0!=ret)
	{
		cout << "notify error : " << ret << endl;
	}
}
void Condition:: notifyall()
{
	int ret = pthread_cond_broadcast(&_cond);
	if(0!=ret)
	{
		cout << "notifyall" << ret << endl;
	}
}




typedef struct
{
	MutexLock &lock;
	Condition &cond;
}trans_info;

void *start_routine(void *p){
	trans_info* pinfo = static_cast<trans_info*>(p);
	pinfo->lock.lock();
	pinfo->cond.wait(pinfo->lock.get_lock());
	cout << "child thread : I am running..." << endl;
	pinfo->lock.unlock();
	pthread_exit(NULL);
}


int main()
{

	MutexLock lock;
	Condition cond;

	trans_info info={lock,cond};

	pthread_t thread;
	int ret = pthread_create(&thread, NULL,start_routine,&info);
	if(0!=ret)
	{
		cout << "pthread_create error : " << ret << endl;
	}

	cout << "main thread will sleep 5 s , then wake up child thread ." << endl;
	sleep(5);
	cond.notify();
	
	pthread_join(thread,NULL);

	return 0;
}
