#include <stdio.h>

typedef struct {
	int prvky[5];
} pole;

void print (pole x){
	//		volani funkce hodnotou, v pripade struktury se prenasi cela promenna
	//   	=> vytvari se kopie v zasobniku

	for (int i = 0; i < sizeof(x.prvky)/sizeof(int); i++){
		printf("%d\n", x.prvky[i]);
	}
}

int main ()
{
	int i;

	pole a = {1,2,3,4,5};
	a.prvky[1] = 20;
	print (a);
	puts ("___________________");
	for (int i = 0; i < sizeof(a.prvky)/sizeof(int); i++){
 		a.prvky[i] = i*100;
 	}
 	print (a);

	return 0;
}
