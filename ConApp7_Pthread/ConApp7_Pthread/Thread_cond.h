#pragma once
#include<pthread.h>
#include<iostream>

using namespace std;
class ThreadCond {
public:
	pthread_cond_t CondVar;
	pthread_mutex_t MutexVar;
	static int count;
	const int ciCountDone = 10;
	const int COUNT_HALT1 = 3;
	const int COUNT_HALT2 = 6;
	ThreadCond():CondVar(PTHREAD_COND_INITIALIZER),MutexVar(PTHREAD_MUTEX_INITIALIZER)
	{}
	~ThreadCond(){
	
	}
	void* func1(void* args) {
		while(1)
		{
			pthread_mutex_lock(&MutexVar);
			//wait cond:
			pthread_cond_wait(&CondVar, &MutexVar);
				count++;
				cout << "Counter val_f1:" << count << endl;
			pthread_mutex_unlock(&MutexVar);

			if (count > ciCountDone) return (NULL);

		}

	}
	void* func2(void* args) {
		while (1)
		{
			pthread_mutex_lock(&MutexVar);
			if (count<COUNT_HALT1 || count>COUNT_HALT2)
			{
				pthread_cond_signal(&CondVar);
			}
			else
			{
				count++;
				cout << "counter val_f2:" << count<<endl;
			}

			pthread_mutex_unlock(&MutexVar);


		}
		if (count > ciCountDone) return(NULL);
		
	}
	

	
	
};
