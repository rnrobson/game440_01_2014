#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <SDL_mutex.h>
#include <SDL_thread.h>
#include <queue>

template<class T>
class BlockingQueue
{
private:
	std::queue<T>	que;
	SDL_mutex *threadLock;
	SDL_cond	*condVar;
public:
	BlockingQueue()
	{
		threadLock = SDL_CreateMutex();
		condVar = SDL_CreateCond();
	}

	~BlockingQueue()
	{
		SDL_DestroyMutex(threadLock);
		SDL_DestroyCond(condVar);
	}

	void push(T &data)
	{
		SDL_mutexP(threadLock);
		que.push(data);
		SDL_CondSignal(condVar);
		SDL_mutexV(threadLock);
	}

	T pop()
	{
		T result;
		SDL_mutexP(threadLock);
		while(que.empty())
		{
			SDL_CondWait(condVar, threadLock);
		}
		result = que.front();
		que.pop();
		SDL_mutexV(threadLock);
		return result;
	}

	bool empty()
	{
		bool result = true;
		SDL_mutexP(threadLock);
		result = que.empty();
		SDL_mutexV(threadLock);
		return result;
	}

};


#endif