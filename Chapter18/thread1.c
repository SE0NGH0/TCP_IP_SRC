#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

void* thread1_main(void *arg);
void* thread2_main(void *arg);
void* thread3_main(void *arg);

static sem_t sem_one;
static sem_t sem_two;
static sem_t sem_thr;

int main(int argc, char *argv[]) 
{
	pthread_t t1_id, t2_id, t3_id;
	int thread_param=5;

	sem_init(&sem_one, 0, 1);
	sem_init(&sem_two, 0, 0);
	sem_init(&sem_thr, 0, 0);
	
	pthread_create(&t1_id, NULL, thread1_main, (void*)&thread_param);
	pthread_create(&t2_id, NULL, thread2_main, (void*)&thread_param);
	pthread_create(&t3_id, NULL, thread3_main, (void*)&thread_param);

	pthread_join(t1_id, NULL);
	pthread_join(t2_id, NULL);
	pthread_join(t3_id, NULL);

	sleep(2);  puts("end of main");

	sem_destroy(&sem_one);
	sem_destroy(&sem_two);
	sem_destroy(&sem_thr);

	return 0;
}

void* thread1_main(void *arg) 
{
	int i;
	int cnt=*((int*)arg);
	for(i=0; i<cnt; i++)
	{
		sleep(1);
		sem_wait(&sem_one);
		puts("running thread...1");
		sem_post(&sem_two);	 
	}
	return NULL;
}

void* thread2_main(void *arg) 
{
	int i;
	int cnt=*((int*)arg);
	for(i=0; i<cnt; i++)
	{
		sleep(1);
		sem_wait(&sem_two);
		puts("running thread...2");
		sem_post(&sem_thr);	 
	}
	return NULL;
}

void* thread3_main(void *arg) 
{
	int i;
	int cnt=*((int*)arg);
	for(i=0; i<cnt; i++)
	{
		sleep(1);
		sem_wait(&sem_thr);
		puts("running thread...3");	
		sem_post(&sem_one); 
	}
	return NULL;
}