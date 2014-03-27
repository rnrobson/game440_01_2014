#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "BlockingQueue.h"
#include "WorkItem.h"
#include "PacketFactory.h"
class ThreadPool;

class WorkerData
{
public:
	ThreadPool	*pool;
	int			threadIndex;

	WorkerData(ThreadPool *p, int idx)
		:pool(p), threadIndex(idx)
	{}

};

class ThreadPool
{
private:
	BlockingQueue<CommandPacket*>		workQue;
	SDL_Thread					**threadList;
	int							numThreads;
	int							activeThreads;
	SDL_mutex					*threadLock;
	WorkerData					**workerDataList;

	void incActiveThreads();
	void decActiveThreads(int index);
public:
	ThreadPool(int nthreads);

	~ThreadPool();

	void addWork(CommandPacket* w);

	void shutdown();

	int activeThreadCount();

	friend int pool_worker_function(void *data);

};

#endif