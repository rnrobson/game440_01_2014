#ifndef WORK_ITEM_H
#define WORK_ITEM_H

/**
* A work item represents some work to be performed by one of the threads
* in a thread pool.  The work is represented by a pointer to a void function
* which accepts a single parameter of type void*.  A work item contains 
* a void* pointer to data which will be passed to the work function when
* the function is invoked by a thread.  If the function pointer is null, it
* will cause the thread which tries to execute the thread to terminate.
*/
class WorkItem
{
public:
	void (*workFunc) (void*);
	void* workData;

	WorkItem()
	{
		workFunc = NULL;
		workData = NULL;
	}

	WorkItem(void (*func) (void*), void* data )
	{
		workFunc = func;
		workData = data;
	}

	/*WorkItem(WorkItem &w)
	{
		workFunc = w.workFunc;
		workData = w.workData;
	}*/

	WorkItem operator=(WorkItem & w)
	{
		workFunc = w.workFunc;
		workData = w.workData;
		return *this;
	}
};

#endif