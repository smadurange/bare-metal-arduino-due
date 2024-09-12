#define PIOA 0x400E0E00u
#define PIOB 0x400E1000u
#define PIOC 0x400E1200u
#define PIOD 0x400E1400u

#define PORT PIOC

#define PIO_PER  *((volatile unsigned int *)(PORT + 0x0000u))
#define PIO_OER  *((volatile unsigned int *)(PORT + 0x0010u))
#define PIO_SODR *((volatile unsigned int *)(PORT + 0x0030u))
#define PIO_CODR *((volatile unsigned int *)(PORT + 0x0034u))
#define PIO_PUDR *((volatile unsigned int *)(PORT + 0x0060u))
#define PIO_WPMR *((volatile unsigned int *)(PORT + 0x00E4u))

#define PIO_WPKEY 0x50494Fu

#define LED_PIN 1

int main(void)
{
	volatile int i;

	PIO_WPMR = PIO_WPKEY << 8;
	PIO_PER  |= (1 << LED_PIN);
	PIO_OER  |= (1 << LED_PIN);
	PIO_PUDR |= (1 << LED_PIN);
	PIO_WPMR = (PIO_WPKEY << 8) | 1u;
	
	for (;;) {
		PIO_SODR |= (1 << LED_PIN);
		for (i = 0; i < 100000; i++)
			;		
		PIO_CODR |= (1 << LED_PIN);
		for (i = 0; i < 100000; i++)
			;		
	}		

	return 0;
}

__attribute__ ((noreturn)) void reset_handler(void)
{
	main();
	for(;;)
		;
}

extern const unsigned int sp;

__attribute__ ((section(".vtor"))) const void* tab[] = {
    &sp,
    reset_handler
};
