#define PIOA 0x400E0E00u
#define PIOB 0x400E1000u
#define PIOC 0x400E1200u
#define PIOD 0x400E1400u

#define PORT PIOC

#define PIO_PER  *((volatile unsigned int *)(PORT + 0x0000u))
#define PIO_OER  *((volatile unsigned int *)(PORT + 0x0010u))
#define PIO_SODR *((volatile unsigned int *)(PORT + 0x0030u))
#define PIO_PUDR *((volatile unsigned int *)(PORT + 0x0060u))
#define PIO_WPMR *((volatile unsigned int *)(PORT + 0x00E4u))

#define PIO_WPKEY 0x50494Fu

#define PMC_PID          13
#define PMC_WPKEY 0x504D43u

#define PMC_WPMR  *((volatile unsigned int *)(PORT + 0x400E06E4u))
#define PMC_PCER0 *((volatile unsigned int *)(PORT + 0x400E0610u))

#define GPIO_NUM                 1
#define GPIO_MASK (1u << GPIO_NUM)

int main(void)
{
	volatile int i;

	PIO_WPMR = PIO_WPKEY << 8;
	PIO_PER  |= GPIO_MASK;
	PIO_OER  |= GPIO_MASK;
	PIO_PUDR |= GPIO_MASK;
	PIO_WPMR = (PIO_WPKEY << 8) | 1u;
	
	for (;;) {
		PIO_SODR ^= GPIO_MASK;
		
		for (i = 0; 0x100000; i++)
			;		
	}		

	return 0;
}

extern const unsigned int sp;

__attribute__ ((section(".vtor")))
const void* VectorTable[] = {
    &sp,
    main
};
