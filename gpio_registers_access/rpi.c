#include "rpi.h"

/* the g;obal gpio variable */
struct bcm2837_peripherals gpio = {GPIO_BASE};

/* Mapping peripheral memory of BCM2835 into kernel /dev/mem */
int map_peripherals(struct bcm2837_peripherals *p){
	// open /dev/mem
	if((p->mem_fd =open("/dev/mem", O_RDWR | O_SYNC)) < 0)
	{
		printf("failed to open /dev/testing, try checking permissions.\n");
		exit(EXIT_FAILURE);
	}
	p->map = mmap(NULL, BLOCK_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, p->mem_fd, p->addr_p);
	if(p->map == MAP_FAILED)
	{
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	p->addr = (volatile unsigned int *)p->map;
	return 0;
}

void unmap_peripherals(struct bcm2837_peripherals *p){
	munmap(p->map, BLOCK_SIZE);
	close(p->mem_fd);
}
