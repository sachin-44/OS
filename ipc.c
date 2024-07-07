Receiver
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
	void *shared_memory;
	char buffer[100];
	int shmid;
	shmid=shmget((key_t)1222,1024,0666);
	printf("Key of the shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("Process attached at %p\n",shared_memory);
	printf("Data read from shared memory is: %s\n",(char*)shared_memory);
}
Sender
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	void *shared_memory;
	char buffer[100];
	int shmid;
	shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
	printf("Key of the shared Memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("Process attached at %p\n",shared_memory);
	printf("Enter some data to write into the shared memory:\n");
	read(0,buffer,100);
	strcpy(shared_memory,buffer);
	printf("You have Enterd: %s",(char*)shared_memory);
}
