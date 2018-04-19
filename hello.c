#include<linux/kernel.h>
#include<linux/linkage.h>

asmlinkage int sys_hello(void) {
	printk("HELLO SYSTEM CALL B05902101 B05902102");
	return 0;
}
