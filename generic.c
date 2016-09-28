#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
	printf(1, "Oi, eu sou um novo processo! Meu PID eh %d\n\n\n", getpid());
	exit();
}
