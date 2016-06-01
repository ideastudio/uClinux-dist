#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <asm/io.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/map.h>
#include <linux/mtd/partitions.h>
#include <linux/config.h>

#define WINDOW_ADDR 0x00010000 
#define WINDOW_SIZE 0x003F0000    
#define BUSWIDTH 2

static struct mtd_info *mymtd;

__u8 s3c44b0_read8(struct map_info *map, unsigned long ofs)
{
    return __raw_readb(map->map_priv_1 + ofs);
}

__u16 s3c44b0_read16(struct map_info *map, unsigned long ofs)
{
    return __raw_readw(map->map_priv_1 + ofs);
}

__u32 s3c44b0_read32(struct map_info *map, unsigned long ofs)
{
    return __raw_readl(map->map_priv_1 + ofs);
}

void s3c44b0_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
    memcpy(to, (void *)( map->map_priv_1 + from), len);
}

void s3c44b0_write8(struct map_info *map, __u8 d, unsigned long adr)
{
     __raw_writeb(d, map->map_priv_1 + adr);
}

void s3c44b0_write16(struct map_info *map, __u16 d, unsigned long adr)
{
    __raw_writew(d, map->map_priv_1 + adr);
}

void s3c44b0_write32(struct map_info *map, __u32 d, unsigned long adr)
{
    __raw_writel(d, map->map_priv_1 + adr);
}

void s3c44b0_copy_to(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
    memcpy((void *)( map->map_priv_1 + to), from, len);
}

struct map_info s3c44b0_map = {
    name: "s3c44b0 flash device",
    size: WINDOW_SIZE,
    buswidth: BUSWIDTH,
    read8: s3c44b0_read8,
    read16: s3c44b0_read16,
    read32: s3c44b0_read32,
    copy_from: s3c44b0_copy_from,
    write8: s3c44b0_write8,
    write16: s3c44b0_write16,
    write32: s3c44b0_write32,
    copy_to: s3c44b0_copy_to,
    map_priv_1: WINDOW_ADDR,
    map_priv_2: -1, 
};

static struct mtd_partition s3c44b0_partitions[] = {
    {
            name: "reserved for kernel",
            size: 0x0F0000,
            offset: 0x000000,
            mask_flags: MTD_WRITEABLE,
    },
    {
            name: "reserved for romdisk",
            size: 0x200000,
            offset: 0x0F0000,
            mask_flags: MTD_WRITEABLE,
    },
    {
            name: "jffs2(1M)",
            size: 0x100000,
            offset: 0x2F0000,
    }
};

int __init init_s3c44b0(void)
{
    printk(KERN_NOTICE "s3c44b0 flash device: %x at %x\n", WINDOW_SIZE, WINDOW_ADDR);
    s3c44b0_map.map_priv_1 = (unsigned long)ioremap(WINDOW_ADDR, WINDOW_SIZE);
     if (!s3c44b0_map.map_priv_1) {
         printk("Failed to ioremap\n");
         return -EIO;
     }

    mymtd = do_map_probe("cfi_probe", &s3c44b0_map);
    if (!mymtd)
    {
        mymtd = do_map_probe("jedec_probe", &s3c44b0_map);
    }
    if (mymtd) {
        mymtd->module = THIS_MODULE;
        mymtd->erasesize = 0x10000; //擦除的大小 INTEL E28F128J3A-150 是128kb
        return add_mtd_partitions(mymtd, s3c44b0_partitions, sizeof(s3c44b0_partitions) / sizeof(struct mtd_partition));
     }

    iounmap((void *)s3c44b0_map.map_priv_1);
    return -ENXIO;
}

static void __exit cleanup_s3c44b0(void)
{
     if (mymtd) {
         del_mtd_partitions(mymtd);
         map_destroy(mymtd);
     }
    if (s3c44b0_map.map_priv_1) {
        iounmap((void *)s3c44b0_map.map_priv_1);
        s3c44b0_map.map_priv_1 = 0;
     }
}

module_init(init_s3c44b0);
module_exit(cleanup_s3c44b0);
