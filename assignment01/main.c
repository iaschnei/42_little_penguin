#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init main_init(void)
{
	pr_info("Hello world\n");
	return (0);
}

static void __exit main_exit(void)
{
	pr_info("Cleaning up module.\n");
}

module_init(main_init);
module_exit(main_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("iaschnei");
MODULE_DESCRIPTION("Assignment 01");
