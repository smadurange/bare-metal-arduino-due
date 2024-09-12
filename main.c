#define PIOA 0x400E0E00u
#define PIOB 0x400E1000u
#define PIOC 0x400E1200u
#define PIOD 0x400E1400u

#define PORT PIOC

#define PIO_PER  *((volatile unsigned int *)(PORT + 0x0000u))
#define PIO_OER  *((volatile unsigned int *)(PORT + 0x0010u))
#define PIO_SODR *((volatile unsigned int *)(PORT + 0x0030u))
#define PIO_CODR *((volatile unsigned int *)(PORT + 0x0034u))
#define PIO_WPMR *((volatile unsigned int *)(PORT + 0x00E4u))

#define PIO_WPKEY 0x50494Fu

#define LED_PIN 1

void wait(int t)
{
	volatile int i;

	for (i = t; i > 0; i--)
		__asm("nop");
}

int main(void)
{
	volatile int i;

	PIO_WPMR = PIO_WPKEY << 8;
	PIO_PER  |= (1 << LED_PIN);
	PIO_OER  |= (1 << LED_PIN);
	PIO_WPMR = (PIO_WPKEY << 8) | 1;
	
	for (;;) {
		PIO_SODR |= (1 << LED_PIN);
		wait(200000);
		PIO_CODR |= (1 << LED_PIN);
		wait(200000);
	}		

	return 0;
}

static inline void mem_init(void)
{
	unsigned long *dst, *src;
	extern unsigned long _sbss, _ebss, _sdata, _edata, _sidata;

	for (dst = &_sbss; dst < &_ebss; dst++)
		*dst = 0;

	for (dst = &_sdata, src = &_sidata; dst < &_edata;)
		*dst++ = *src++;
}

__attribute__((noreturn)) void reset(void) {
	mem_init();
	main();

	for (;;)
		;
}

extern const unsigned int sp;

__attribute__ ((section(".vtor"))) const void* tab[] = {
    &sp,
    reset
};
