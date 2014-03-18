#include "ThreadPool.h"
#include <iostream>
#include <sstream>
#include <SDL_timer.h>



int pool_worker_function(void *data)
{
	WorkerData *wd = (WorkerData*)data;
	ThreadPool *pool = wd->pool;
	int index = wd->threadIndex;
	pool->incActiveThreads();
	ServerCommand* item = pool->workQue.pop();
	//std::cout << "thread " << index << " gets work item " << item.workFunc << std::endl;
	while (item)
	{
		item->Execute();
		item = pool->workQue.pop();
		//std::cout << "thread gets work item " << item.workFunc << std::endl;
	}
	std::cout << "worker decrementing thread count\n";
	pool->decActiveThreads(index);
	std::cout << "worker terminating\n";
	return 0;
}

ThreadPool::ThreadPool(int nthreads)
{
	numThreads = nthreads;
	activeThreads = 0;
	threadLock = SDL_CreateMutex();
	threadList = new SDL_Thread*[numThreads];
	workerDataList = new WorkerData*[numThreads];

	for (int i = 0; i < numThreads; i++)
	{
		std::stringstream ss;
		ss << i;
		workerDataList[i] = new WorkerData(this, i);
		threadList[i] = SDL_CreateThread(pool_worker_function, (std::string("thread") + ss.str()).c_str(), workerDataList[i]);
	}
}

ThreadPool::~ThreadPool()
{
	shutdown();

	SDL_DestroyMutex(threadLock);
	delete[] threadList;
	delete[] workerDataList;
}

void ThreadPool::incActiveThreads()
{
	SDL_mutexP(threadLock);
	activeThreads++;
	SDL_mutexV(threadLock);
}

void ThreadPool::decActiveThreads(int index)
{
	SDL_mutexP(threadLock);
	activeThreads--;
	threadList[index] = NULL;
	//std::cout << "dec: threadCount = " << activeThreads << std::endl;
	SDL_mutexV(threadLock);
}

int ThreadPool::activeThreadCount()
{
	int result = 0;
	SDL_mutexP(threadLock);
	result = activeThreads;
	SDL_mutexV(threadLock);
	return result;
}

void ThreadPool::addWork(ServerCommand* w)
{
	workQue.push(w);
}

void ThreadPool::shutdown()
{
	int n = activeThreadCount();
	ServerCommand* item;

	if (n <= 0) return;

	//std::cout << "shutdown pushes " << n << " work items" << std::endl;
	for (int i = 0; i < n; i++)
	{
		workQue.push(item);
	}

	SDL_Delay(2000);

}