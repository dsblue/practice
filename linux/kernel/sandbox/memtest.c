#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */
#include <linux/types.h>
#include <linux/slab.h>

static char *buffer1;

#define BUFFER1_SIZE	0x100
#define MEMORY_START	0x20000000

struct register_map {
	u32	reg1;
	u32	reg2;
	u32	reg3;
	u16	half1;
	u16	half2; 
};

static int __init memtest_init(void)
{
	printk(KERN_INFO "Starting memtest\n");

	buffer1 = (char *)kmalloc(BUFFER1_SIZE, GFP_KERNEL);

	struct register_map *map = ((struct register_map *)MEMORY_START);
	u32 *mem = (u32 *)MEMORY_START;	

	int i;
	for (i=0;i<8;i++) {
		printk(KERN_INFO "%d\n", mem[i]);
	}

	return 0;
}

static void __exit memtest_exit(void)
{
	printk(KERN_INFO "Goodbye, world 2\n");
}

module_init(memtest_init);
module_exit(memtest_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nathan Palmer");
MODULE_DESCRIPTION("Refresher on kernel module memory accesses");
