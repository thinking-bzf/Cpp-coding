#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>

sem_t *sem_send;
sem_t *sem_receive;
sem_t *mutex_mem;
sem_t *send_over;
int shm_id;
// sem_t *sem_receive;

void main()
{
    sem_send = sem_open("open", O_CREAT, 0744, 0);
    sem_receive = sem_open("receive", O_CREAT, 0744, 0);
    mutex_mem = sem_open("mutex", O_CREAT, 0744, 1);
    send_over = sem_open("over", O_CREAT, 0744, 0);
    shm_id = shmget(0, 1024, IPC_CREAT);

    char buff[256];
    char *shm_addr = NULL;

    pid = fork(); //创建子进程
    if (pid < 0)
    { //创建失败
        perror("fork error");
        exit(1);
    }
    else if (pid == 0)
    {
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
    else
    {
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
    sem_send = sem_unlink("open");
    sem_receive = sem_unlink("receive");
    mutex_mem = sem_unlink("mutex");
    send_over = sem_unlink("over");
}
