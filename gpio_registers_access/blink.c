#include "rpi.h"

extern struct bcm2837_peripherals gpio;

int main(int argc, char *argv[])
{
	if(map_peripherals(&gpio) == -1)
	{
		printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
		exit(EXIT_FAILURE);
	}

	/* define pin 7 or GPIO-4 as output */
	INP_GPIO(4);
	OUT_GPIO(4);

	while(1)
	{
		/* Toggle pin or blink led */
		GPIO_SET = 1 << 4;
		sleep(1);

		GPIO_CLR = 1 << 4;
		sleep(1);
	}

	return 0;
}
