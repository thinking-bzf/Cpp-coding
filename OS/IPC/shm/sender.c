#include <stdio.h>
#include <string.h>
#include "sem.h"

// sem_t *sem_send;
// sem_t *sem_receive;
// sem_t *mutex_mem;
// sem_t *send_over;

int main()
{
    // init_signal();
    char buff[256];
    char *shm_addr = NULL;

    while (1)
    {
        printf("input the message:\n");
        scanf("%s", buff);

        sem_wait(mutex_mem);
        // printf("%s", buff);
        shm_addr = shmat(shm_id, shm_addr, 0);
        if (shm_addr == (void *)-1)
        {
            printf("shmat error");
            sem_post(mutex_mem);
        }
        strcpy(shm_addr, buff);
        sem_post(sem_send);
        sem_post(mutex_mem);

        sem_wait(send_over);
        sem_wait(mutex_mem);
        strcpy(buff, shm_addr);
        printf("%s", buff);
        printf("receive over");
        sem_post(mutex_mem);
    }
}