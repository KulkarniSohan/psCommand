#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/sched.h>

static int ps_init(void)
{
	printk(KERN_ALERT "In my module\n");
	struct task_struct *my;
	for_each_process(my)
	{
		printk("Name : %s[pid : %d]\n",my->comm,my->pid);
	}
	return 0;
}

static void ps_exit(void)
{
	printk(KERN_ALERT "Module unloading\n");
}

module_init(ps_init);
module_exit(ps_exit);
