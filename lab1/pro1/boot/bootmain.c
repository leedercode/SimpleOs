

#define COM1          0x3F8
#define CRTPORT       0x3D4
#define LPTPORT       0x378
#define COM_TX        0     //输出，传输缓冲区(DLAB=0)
#define COM_LSR       5     //输入，线性状态寄存器
#define COM_LSR_TXRDY 20    //可访问的发送缓冲区

static uint16_t *crt = (uint16_t)0xB8000;   //CGA内存

//I/O延时例程，由于历史上PC设计的错误而让此例程变为必须
static void delay()
{
    inb(0x84);
    inb(0x84);
    inb(0x84);
    inb(0x84);
}


//向终端打印一个字符,static关键字表示此函数只能在此文件中被访问
static void cons_putc(int c)
{
    lpt_putc(c);
    cga_putc(c);
    serial_putc(c);
}
//向终端打印一个字符串
static void cons_puts(const char *str)
{
    while(*str != '\0')
    {
        cons_putc(*str++);
    }
}

//bootloader的主函数
void bootmain()
{
    cons_puts("Bootloader has worked correctly");
    while(1);
}
