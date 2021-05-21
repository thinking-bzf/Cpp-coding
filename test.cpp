SYSCALL_DEFINE3(my_file, const char __user *, filename, int, len, struct file_info_struct __user *, file_info)
{
    struct file *fp; // 文件指针^Z
    long copied;
    char *k_filename;
    printk("cp enter/n");
    struct file_info_struct *buf; //定义存放信息的内核缓冲
    printk("Definition complete");
    buf = kcalloc(1, sizeof(struct file_info_struct), GFP_KERNEL);
    copied = copy_from_user(buf, file_info, sizeof(struct file_info_struct)); //复制用户空间缓冲信息
    printk("copy complete1");
    if (copied != 0)
        return -EFAULT;
    k_filename = (char *)kcalloc(sizeof(char) * len, GFP_KERNEL);
    printk("kmalloc k_filename");
    copied = copy_from_user(&k_filename, filename, len); //复制用>户空间缓冲长度
    if (copied != 0)
        return -EFAULT;
    printk("copy comlete2");
    printk(k_filename);
    fp = filp_open(k_filename, O_RDWR | O_CREAT, 0644); // 打开src文件
    if (IS_ERR(fp))
    {
        printk("create file error/n");
        return -1;
    }
}