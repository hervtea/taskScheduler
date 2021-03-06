
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tasch.h"	// Original header files
// #include "stacklib.h"
// #include "queuelib.h"

int main(int argc, char const *argv[]){
	int N;
	int time = 0;
	int queuetop = -1;
	double qtime = 0.00;
	bool available = true;	// 0: false, 1: true
	task TASKLIST[100];

	printf("## Scheduler of the order of arrival method\ninput:\n");
	scanf("%d",&N);
	for (int i = 0; i < N; ++i){
		scanf(" %s %d %d",
			TASKLIST[i].name, &TASKLIST[i].t_arrival, &TASKLIST[i].t_cost);
		TASKLIST[i].status = 1;
	}

	printf("\nOutput:\n");
	while(++queuetop < N){
		deal(TASKLIST[queuetop], &time,N, &qtime);
	}
	printf("%d %.2f\n",time,qtime);
	return 0;
}

