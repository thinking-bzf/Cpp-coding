SYSCALL_DEFINE3(alterhostname, char __user *, name, int, len, int, mode)
{
    int errno;

    char tmp[__NEW_UTS_LEN];

    if (len < 0 || len > __NEW_UTS_LEN)
    {
        printf("Invalid length of usename!");
        return -EINVAL; 
    }

    errno = -EFAULT; /* Bad address */
    if (!copy_from_user(tmp, name, len))
    {
        if (mode == 0)
        {
            struct file *utsname;
            mm_segment_t old_fs;
            loff_t pos;
            old_fs = get_fs();
            set_fs(KERNEL_DS);
            utsname = kmalloc(sizeof(struct file), GFP_KERNEL);
            utsname = filp_open("/etc/hostname", O_RDWR | O_TRUNC, 0744);

            pos = utsname->f_pos;
            // file open error
            if (IS_ERR(utsname))
            {
                printf("open error");
                return errno;
            }
            vfs_write(utsname, tmp, strlen(tmp), &pos);
            set_fs(old_fs);
            filp_close(filp, NULL);
            errno = 0;
        }
        else
        {
            struct new_utsname *u;
            down_write(&uts_sem);
            u = utsname();
            memcpy(u->nodename, tmp, len);
            memset(u->nodename + len, 0, sizeof(u->nodename) - len);
            errno = 0;
            uts_proc_notify(UTS_PROC_HOSTNAME);
            up_write(&uts_sem);
        }
    }
    return errno;
}

SYSCALL_DEFINE3(open, const char __user *, filename, int, flags, umode_t, mode)
{
    long ret;

    if (force_o_largefile())
        flags |= O_LARGEFILE;
    ret = do_sys_open(AT_FDCWD, filename, flags, mode);
    /* avoid REGPARM breakage on x86: */
    asmlinkage_protect(3, ret, filename, flags, mode);
    return ret;
}

{

    struct file *file = NULL;
            mm_segment_t old_fs;
    char buf[128] = "123233fdafa23fdaga";

            file = filp_open("/data/test.txt", O_RDWR | O_APPEND | O_CREAT, 0644);
            if (IS_ERR(file))
    {
                        return 0;
               
    }

            old_fs = get_fs();
            set_fs(KERNEL_DS);
            vfs_write(file, buf, sizeof(buf),  0);
            set_fs(old_fs);
            filp_close(file, NULL);
      

        return 0;
}

struct file *filp_open(const char *filename, int flags, umode_t mode)
{
    struct open_flags op;
    int lookup = build_open_flags(flags, mode, &op);
    return do_filp_open(AT_FDCWD, filename, &op, lookup);
}

static int __init changename_init(void) //初始化函数
{
    struct file *filp;
    loff_t pos;
    mm_segment_t fs;
    printk("succeed!");
    //GFP_KERNEL是linux内存分配器的标志，标识着内存分配器将要采取的行为。分配器标志分为行为修饰符，区修饰符及类型。行为修饰符表示内核应当如何分配所需的内存。区修饰符表示内存区应当从何处分配。类型就是行为修饰符和区修饰符的合体。
    filp = kmalloc(sizeof(struct file), GFP_KERNEL);
    filp = filp_open("/etc/hostname", O_RDWR, 0644);
    //filp_open()在kernel中可以打开文件，其原形如下：
    //strcut file* filp_open(const char* filename, int open_mode, int mode);
    //该函数返回strcut file*结构指针，供后继函数操作使用，该返回值用IS＿ERR（）来检>验其有效性。
    if (IS_ERR(filp))
    {
        printk("open error");
        return 0;
    }
    //kernel中文件的读写操作可以使用vfs_read()和vfs_write，在使用这两个函数前需要说>明一下get_fs()和 set_fs()这两个函数。
    //vfs_read() vfs_write()两函数的原形如下：
    //ssize_t vfs_read(struct file* filp, char __user* buffer, size_t len, loff_t* pos);
    //ssize_t vfs_write(struct file* filp, const char __user* buffer, size_t len, loff_t* pos);
    fs = get_fs();     //取得当前的地址访问限制值
    set_fs(KERNEL_DS); //改变kernel对内存地址检查的处理方式
    pos = filp->f_pos;
    vfs_write(filp, newname, strlen(newname), &pos);
    set_fs(fs);             //设置当前的地址访问限制值
    filp_close(filp, NULL); //关闭读写文件
    return 0;
}