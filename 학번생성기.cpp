#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

int main(void){
	//년도-월일분초 
	//yy-mmdd mmss 
	int i;
	
    time_t now;
 	now = time(NULL);
	srand(time(NULL));
	
 	for(i=0; i<100; i++){
		int random = rand();
 		printf("%ld\n", now+random+300000000);
	}
 	
	return 0;
}
