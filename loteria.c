#include "types.h"
#include "stat.h"
#include "user.h"
#define loop 100
#define tickets1 5
#define tickets2 100
#define tickets3 60

void consomeCPU(){
	int i, j, k;
	for(i = 0; i < loop; i++){ for (j = 0; j < loop; ++j){ for (k = 0; k < loop; ++k) getpid();}}
	printf(1, "\n\tTerminei! PID[%d]\n", getpid());
	//Termino meu processo filho
	exit();
}

int main(void)
{
	printf(1, "\n");
	int pid;

	pid = fork(tickets1);
	if(pid > 0){
		printf(1, "Processo Pai: filho(1) = PID[%d], Bilhetes[%d]\n", pid, tickets1);
		pid = fork(tickets2);
		if(pid > 0){
			printf(1, "Processo Pai: filho(2) = PID[%d], Bilhetes[%d]\n", pid, tickets2);
			pid = fork(tickets3);
			if(pid > 0){
				printf(1, "Processo Pai: filho(3) = PID[%d], Bilhetes[%d]\n", pid, tickets3);
			}else if(pid == 0){ consomeCPU(); }
		}else if(pid == 0){ consomeCPU(); }
	}else if(pid == 0){ consomeCPU(); }
	//Espero meus tres processos filhos terminarem
	wait();
	wait();
	wait();
	printf(1, "\n\tPai terminou! PID[%d]\n\n\t################# Fim #################\n\n", getpid());
	//Termino meu processo pai
	exit();
}