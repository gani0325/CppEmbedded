#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define BUFFER_SIZE 4096

static char buffer[BUFFER_SIZE];
static int read_ptr = 0;
static int write_ptr = 0;
static int major_number;
static struct class *buffer_class;
static struct device *buffer_device;

static int buffer_open(struct inode *inode, struct file *file)
{
    return 0;
}

static int buffer_release(struct inode *inode, struct file *file)
{
    return 0;
}

static ssize_t buffer_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
    int bytes_read = 0;
    while (count > 0)
    {
        if (read_ptr == write_ptr)
        {
            // 순환 큐가 완전히 비었을 때
            return bytes_read;
        }

        read_ptr = (read_ptr + 1) % BUFFER_SIZE;
        count--;
        bytes_read++;
    }
    return bytes_read;
}

static ssize_t buffer_write(struct file *file, const char __user *buf, size_t count, loff_t *offset)
{
    int bytes_written = 0;
    while (count > 0)
    {
        if ((write_ptr + 1) % BUFFER_SIZE == read_ptr)
        {
            // 순환 큐가 가득 찼을 때
            return bytes_written;
        }

        write_ptr = (write_ptr + 1) % BUFFER_SIZE;
        count--;
        bytes_written++;
    }
    return bytes_written;
}

static const struct file_operations buffer_fops = {
    .owner = THIS_MODULE,
    .open = buffer_open,
    .release = buffer_release,
    .read = buffer_read,
    .write = buffer_write,
};

static int __init buffer_init(void)
{
    major_number = register_chrdev(0, "buffer", &buffer_fops);
    buffer_class = class_create(THIS_MODULE, "buffer_class");

    buffer_device = device_create(buffer_class, NULL, MKDEV(major_number, 0), NULL, "buffer");

    return 0;
}

static void __exit buffer_exit(void)
{
    device_destroy(buffer_class, MKDEV(major_number, 0));
    class_unregister(buffer_class);
    class_destroy(buffer_class);
    unregister_chrdev(major_number, "buffer");
    printk(KERN_INFO "buffer device driver unloaded\n");
}

module_init(buffer_init);
module_exit(buffer_exit);