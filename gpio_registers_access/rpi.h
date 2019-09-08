#ifndef	RPI_H
#define	RPI_H

/* This code is written using the fllowing website and interesing to implement
 * www.science.smith.edu/dftwiki/index.php/Tutorial:_Programming_the_GPIO
 * */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define	BCM2837_PERI_BASE	0x20000000
#define	GPIO_BASE	(BCM2837_PERI_BASE + 0x200000)	/* GPIO registers offset by 200000 */
#define	BLOCK_SIZE	(4*1024)

/* IO access */
struct bcm2837_peripherals{
	unsigned long addr_p;
	int mem_fd;
	void *map;
	volatile unsigned int *addr;
};

/* GPIO setup macros. Always use INP_GPIO(x) before using OUT_GPIO(x) */
#define	INP_GPIO(g)	*(gpio.addr + ((g)/10)) &= ~(7<<(((g)%10)*3))
#define	OUT_GPIO(g)	*(gpio.addr + ((g)/10)) |= (1<<(((g)%10)*3))
#define	SET_GPIO_ALT(g,a)	*(gpio.addr + ((g)/10)) |= (((a)<=3?(a)+4:(a)==4?3:2)<<(((g)%10)*3)
#define GPIO_SET	*(gpio.addr + 7)
#define	GPIO_CLR	*(gpio.addr + 10)
#define	GPIO_READ(g)	*(gpio.addr + 13) &= (1<<(g))

/* function prototypes */
int map_peripherals(struct bcm2837_peripherals *p);
void unmap_peripherals(struct bcm2837_peripherals *p);

#endif
