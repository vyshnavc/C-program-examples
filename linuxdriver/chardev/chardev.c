/*
 *  chardev.c: Simple read-only char device
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>  // for put_user

#define DEVICE_NAME "chardev"
#define BUF_LEN 80

static int Major;
static int Device_Open = 0;
static char msg[BUF_LEN];
static char *msg_Ptr;

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release
};

static int __init my_module_init(void)
{
    Major = register_chrdev(0, DEVICE_NAME, &fops);
    if (Major < 0) {
        printk(KERN_ALERT "Registering char device failed with %d\n", Major);
        return Major;
    }

    printk(KERN_INFO "chardev: registered with major number %d\n", Major);
    printk(KERN_INFO "Create device: mknod /dev/%s c %d 0\n", DEVICE_NAME, Major);
    return 0;
}

static void __exit my_module_exit(void)
{
    unregister_chrdev(Major, DEVICE_NAME);
    printk(KERN_INFO "chardev: unregistered device\n");
}

static int device_open(struct inode *inode, struct file *file)
{
    static int counter = 0;

    if (Device_Open)
        return -EBUSY;

    Device_Open++;
    sprintf(msg, "I already told you %d times Hello world!\n", counter++);
    msg_Ptr = msg;
    try_module_get(THIS_MODULE);

    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    Device_Open--;
    module_put(THIS_MODULE);
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
    int bytes_read = 0;

    if (*msg_Ptr == 0)
        return 0;

    while (length && *msg_Ptr) {
        put_user(*(msg_Ptr++), buffer++);
        length--;
        bytes_read++;
    }

    return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
    printk(KERN_ALERT "chardev: write operation not supported\n");
    return -EINVAL;
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Vyshnav");
MODULE_DESCRIPTION("A simple character device driver");
MODULE_VERSION("1.0");

