#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdint.h>
#define NUM_PHILOSOPHERS 5
#define EATING 0
#define THINKING 1
#define HUNGRY 2
pthread_mutex_t forks[NUM_PHILOSOPHERS];
int philosophers[NUM_PHILOSOPHERS] ={THINKING};
void* philosopher(void* arg) {
    int id=*(int*)arg;
    int left_fork=id;
    int right_fork=(id+1)%NUM_PHILOSOPHERS;
    while(1){
        printf("Philosopher %d is thinking.\n",id);
        sleep(1);
        philosophers[id]=HUNGRY;
        printf("Philosopher %d is hungry.\n",id);
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picked up left fork.\n",id);
        if (pthread_mutex_trylock(&forks[right_fork])==0) {
            printf("Philosopher %d picked up right fork.\n",id);
            philosophers[id]=EATING;
            printf("Philosopher %d is eating.\n",id);
            sleep(2);
            pthread_mutex_unlock(&forks[right_fork]);
            pthread_mutex_unlock(&forks[left_fork]);
        } else{
            printf("Philosopher %d couldn't pick up right fork. Putting down left fork.\n",id);
            pthread_mutex_unlock(&forks[left_fork]);
        }
    }
}
int main(){
    pthread_t tid[NUM_PHILOSOPHERS];
    int ids[NUM_PHILOSOPHERS],i;
    for(i=0;i<NUM_PHILOSOPHERS;i++){
        pthread_mutex_init(&forks[i],NULL);
    }
    for(i=0;i<NUM_PHILOSOPHERS;i++){
        ids[i]=i;
        pthread_create(&tid[i],NULL,philosopher,&ids[i]);
    }
    for(i=0;i<NUM_PHILOSOPHERS;i++){
        pthread_join(tid[i], NULL);
    }
    for(i=0;i<NUM_PHILOSOPHERS;i++){
        pthread_mutex_destroy(&forks[i]);
    }
    return 0;
}
