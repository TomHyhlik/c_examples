#include <stdio.h>
int array[100];
int *pointers[100];
int result = 0;

main(){
	for(int i = 0; i < 100; i++){
		pointers[i] = &array[i];
	}
	printf("Input some nubers to count them, exit by entering 0.\n");
	for(int i = 0; i < 100; i++){
		scanf("%d",&array[i]);
		if(*pointers[i] == 0){
			printf("\nEnd of writing numbers\n\n");

			break;
		}
	}	
	for(int i = 0; i < 100; i++){
		if(*pointers[i] == 0){
			break;
		}
		result += *pointers[i];
	}
	printf("\nresult: %d\n", result);
	return 0;
}