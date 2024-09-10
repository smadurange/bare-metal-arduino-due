#define PIOA 0x400E0E00u
#define PIOB 0x400E1000u
#define PIOC 0x400E1200u
#define PIOD 0x400E1400u

#define PORT PIOC

#define PIO_PER  *((volatile unsigned int *)(PORT + 0x0000u))
#define PIO_OER  *((volatile unsigned int *)(PORT + 0x0010u))
#define PIO_SODR *((volatile unsigned int *)(PORT + 0x0030u))
#define PIO_ODSR *((volatile unsigned int *)(PORT + 0x0038u))
#define PIO_PUDR *((volatile unsigned int *)(PORT + 0x0060u))
#define PIO_WPMR *((volatile unsigned int *)(PORT + 0x00E4u))

#define WPKEY 0x50494Fu

#define GPIO_NUM 1
#define GPIO_MASK (1u << GPIO_NUM)

int main(void)
{
	// todo: enable peripheral clock

	PIO_WPMR = WPKEY << 8;

	PIO_PER  |= GPIO_MASK;
	PIO_OER  |= GPIO_MASK;
	PIO_PUDR |= GPIO_MASK;

	PIO_WPMR = (WPKEY << 8) | 1u;

	PIO_SODR |= GPIO_MASK;
	
	for (;;)
		;

	return 0;
}
