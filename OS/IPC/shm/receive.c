#include"sem.h"
#include <stdio.h>
#include <string.h>

int main()
{
    // init_signal();
    char buff[256];
    char *shm_addr = NULL;

    while (1)
    {
        sem_wait(mutex_mem);
        // printf("%s", buff);
        shm_addr = shmat(shm_id, shm_addr, 0);
        if (shm_addr == (void *)-1)
        {
            printf("shmat error");
            sem_post(mutex_mem);
        }
        strcpy(buff, shm_addr);
        strcpy(shm_addr, "over");
        sem_post(sem_over);
        sem_post(mutex_mem);

    }
}