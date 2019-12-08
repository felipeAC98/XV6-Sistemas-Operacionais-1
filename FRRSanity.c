#include "types.h"
#include "stat.h"
#include "user.h"

int glob[10];
int count=0;

int main(){

	int PID=1;
	
	printf(1, "Child %d criada \n", getpid());

	PID=fork();

	int beginTime =uptime();

	if(PID==0)
		printf(1, "Child %d criada \n", getpid());

	for(int i=0; i<10;i++){
		if(PID==0){
			PID=fork();
			if(PID==0){
				printf(1, "Child %d criada \n", getpid());
				beginTime =uptime();
			}
		}

	}

	for(int i=0;i<1000;i++){
		printf(1, "Child %d prints for the %d \n", getpid(),i+1);

	}


	int endTime=uptime();

	wait();
	sleep(30);
	printf(1, "Child %d ends at %d\n", getpid(),endTime-beginTime);

	
	exit();
}