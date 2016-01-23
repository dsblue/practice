#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/fs.h>

#define DEVNAME "condev"
#define CLASSNAME "nathan"

MODULE_DESCRIPTION("Convert input to inverted case.");
MODULE_AUTHOR("Nathan Palmer");
MODULE_VERSION("1.0.0");
MODULE_LICENSE("GPL");

static int majorNumber;
static struct class* condevClass;
static struct device* condevDevice;

static int condev_open(struct inode *, struct file *);
static int condev_release(struct inode *, struct file *);
static ssize_t condev_read(struct file *, char *, size_t, loff_t *);
static ssize_t condev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fileOps = {
	.open = condev_open,
	.release = condev_release,
	.read = condev_read,
	.write = condev_write
};

static int condev_init(void) {
	printk(KERN_INFO "Test Entry\n");

	majorNumber = register_chrdev(0, DEVNAME, &fileOps);
	if (majorNumber < 0) {
		printk(KERN_ALERT "Error registering new device " DEVNAME "\n");
		return majorNumber;
	}

	condevClass = class_create(THIS_MODULE, DEVNAME);
	if (IS_ERR(condevClass)) {
		unregister_chrdev(majorNumber, DEVNAME);
		printk(KERN_ALERT "Error creating class " CLASSNAME "\n");
		return PTR_ERR(condevClass);
	}

	condevDevice = device_create(condevClass, NULL, MKDEV(majorNumber, 0), NULL, DEVNAME);
	if (IS_ERR(condevDevice)) {
		class_destroy(condevClass);
		unregister_chrdev(majorNumber, DEVNAME);
		return PTR_ERR(condevDevice);
	}

	return 0;
}


static void condev_exit(void) {
	printk(KERN_INFO "Test Exit\n");

	device_destroy(condevClass, MKDEV(majorNumber, 0));
	class_unregister(condevClass);
	class_destroy(condevClass);
	unregister_chrdev(majorNumber, DEVNAME);
}

static int condev_open(struct inode *i, struct file *f){
	return 0;
}
static int condev_release(struct inode *i, struct file *f){
	return 0;
}
static ssize_t condev_read(struct file *f, char *buff, size_t len, loff_t *o){
	return 0;
}
static ssize_t condev_write(struct file *f, const char *buff, size_t len, loff_t *o){
	return 0;
}


module_init(condev_init);
module_exit(condev_exit);
