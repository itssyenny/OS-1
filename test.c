#include<sys/syscall.h>
#include<stdio.h>
#include<stdlib.h>
#include<linux/kernel.h>
#include<unistd.h>

int main(int argc, char** argv) {
	//printf("Hello %ld, %ld\n", atol(argv[1]), atol(argv[2]));
	
	long _comp1 = atol(argv[1]);
	long _comp2 = atol(argv[2]);
	syscall(337);
	
	//printf("System call Hello returns %ld\n", test);
	long __result_of_multiplication = syscall(338, _comp1, _comp2);
	long __result_of_min = syscall(339, _comp1, _comp2);
	
	printf("The multiplication of %ld and %ld is %ld\n", _comp1, _comp2, __result_of_multiplication);
	printf("The minimum between %ld and %ld is %ld\n", _comp1, _comp2, __result_of_min);
	return 0;
}
