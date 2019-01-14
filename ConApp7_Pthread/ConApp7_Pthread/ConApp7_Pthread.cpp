//// ConApp7_Pthread.cpp : Defines the entry point for the console application.
////
#include "stdafx.h"
//#include<iostream>
//#define HAVE_STRUCT_TIMESPEC
//#include<pthread.h>
//#include<windows.h>
//#include<assert.h>
//#include<semaphore.h>
//#include"Thread_cond.h"
//
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//const short NO_OF_THREAD = 2;
//using namespace std;
//void* mythreadfunc(void* varg)
//{
//	static int valueCheck = 0;
//	
//	int *arg = (int*)varg;
//	pthread_mutex_lock(&mutex);
//	if (*arg == 0)
//	{
//		Sleep(10000);
//		++valueCheck;
//	}
//	else
//	{
//		++valueCheck;
//	}
//	pthread_mutex_unlock(&mutex);
//	cout <<"Inside Thread"<< *arg << valueCheck<< endl;
//	return NULL;
//}
//
//typedef void*(*THREADFUNC1)(void*);
//
//int main()
//{
//
//	//pthread_t threads[NO_OF_THREAD];
//	//int args[NO_OF_THREAD];
//	//int ResultVal;
//	//cout << "Before creating thread" << endl;
//	//for (int i = 0; i < NO_OF_THREAD; i++)
//	//{
//	//	args[i] = i;
//	//	ResultVal = pthread_create(&threads[i], NULL, mythreadfunc, &args[i]);
//	//	assert(ResultVal == 0);
//	//}
//
//	//for (int i = 0; i < NO_OF_THREAD; i++)
//	//{
//	//	ResultVal = pthread_join(threads[i], NULL);
//	//	if (ResultVal == 0)
//	//	{
//	//		cout << "completed thread" << i<<endl;
//	//	}
//	//	
//	//}
//	//cout << "All threads completed" << endl;
//
//	///////////////////////////////////////////////
//	//condition variable
//	///////////////////////////////////////////////
//	//CreateThreadObj()
//		
//
//		ThreadCond *objThc = new ThreadCond();
//		pthread_t thread1, thread2;
//		int a = 19;
//		pthread_create(&thread1, NULL, (THREADFUNC1)&ThreadCond::func1, &a);
//		pthread_create(&thread2, NULL, (THREADFUNC1)&ThreadCond::func2, &a);
//
//		cout << "THread created" << endl;
//		pthread_join(thread1, NULL);
//		pthread_join(thread2, NULL);
//
//}
#include <stdio.h>
#include <stdlib.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include<semaphore.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  condition_var = PTHREAD_COND_INITIALIZER;

void *functionCount1(void *args);
void *functionCount2(void *args);
int  count = 0;
#define COUNT_DONE  10
#define COUNT_HALT1  3
#define COUNT_HALT2  6
sem_t mutex;
int main()
{
	pthread_t thread1, thread2;
	
	sem_init(&mutex, 0, 1);

	pthread_create(&thread1, NULL, &functionCount1, NULL);
	pthread_create(&thread2, NULL, &functionCount2, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Final count: %d\n", count);

	exit(EXIT_SUCCESS);
}

// Write numbers 1-3 and 8-10 as permitted by functionCount2()

void *functionCount1(void *args)
{
	for (;;)
	{
		// Lock mutex and then wait for signal to relase mutex
		//pthread_mutex_lock(&count_mutex);
		sem_wait(&mutex);
		// Wait while functionCount2() operates on count
		// mutex unlocked if condition varialbe in functionCount2() signaled.
		pthread_cond_wait(&condition_var, &mutex/*&count_mutex*/);
		
		count++;
		printf("Counter value functionCount1: %d\n", count);

		sem_post(&mutex);
		//pthread_mutex_unlock(&count_mutex);

		if (count >= COUNT_DONE) return(NULL);
	}
}

// Write numbers 4-7

void *functionCount2(void *args)
{
	for (;;)
	{
		//pthread_mutex_lock(&count_mutex);
		sem_wait(&mutex);
		if (count < COUNT_HALT1 || count > COUNT_HALT2)
		{
			// Condition of if statement has been met. 
			// Signal to free waiting thread by freeing the mutex.
			// Note: functionCount1() is now permitted to modify "count".
			pthread_cond_signal(&condition_var);
			printf( "set sig\n");
		}
		else
		{
			count++;
			printf("Counter value functionCount2: %d\n", count);
		}

		sem_post(&mutex);
		//pthread_mutex_unlock(&count_mutex);

		if (count >= COUNT_DONE) return(NULL);
	}

}