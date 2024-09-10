#define PIOA 0x400E0E00u
#define PIOB 0x400E1000u
#define PIOC 0x400E1200u
#define PIOD 0x400E1400u

#define PORT PIOC

#define PIO_PER     *((volatile unsigned int *)(PORT + 0x0000u))
#define PIO_PDR     *((volatile unsigned int *)(PORT + 0x0004u))
#define PIO_PSR     *((volatile unsigned int *)(PORT + 0x0008u))
#define PIO_OER     *((volatile unsigned int *)(PORT + 0x0010u))
#define PIO_ODR     *((volatile unsigned int *)(PORT + 0x0014u))
#define PIO_OSR     *((volatile unsigned int *)(PORT + 0x0018u))
#define PIO_IFER    *((volatile unsigned int *)(PORT + 0x0020u))
#define PIO_IFDR    *((volatile unsigned int *)(PORT + 0x0024u))
#define PIO_IFSR    *((volatile unsigned int *)(PORT + 0x0028u))
#define PIO_SODR    *((volatile unsigned int *)(PORT + 0x0030u))
#define PIO_CODR    *((volatile unsigned int *)(PORT + 0x0034u))
#define PIO_ODSR    *((volatile unsigned int *)(PORT + 0x0038u))
#define PIO_PDSR    *((volatile unsigned int *)(PORT + 0x003Cu))
#define PIO_IER     *((volatile unsigned int *)(PORT + 0x0040u))
#define PIO_IDR     *((volatile unsigned int *)(PORT + 0x0044u))
#define PIO_IMR     *((volatile unsigned int *)(PORT + 0x0048u))
#define PIO_ISR     *((volatile unsigned int *)(PORT + 0x004Cu))
#define PIO_MDER    *((volatile unsigned int *)(PORT + 0x0050u))
#define PIO_MDDR    *((volatile unsigned int *)(PORT + 0x0054u))
#define PIO_MDSR    *((volatile unsigned int *)(PORT + 0x0058u))
#define PIO_PUDR    *((volatile unsigned int *)(PORT + 0x0060u))
#define PIO_PUER    *((volatile unsigned int *)(PORT + 0x0064u))
#define PIO_PUSR    *((volatile unsigned int *)(PORT + 0x0068u))
#define PIO_ABSR    *((volatile unsigned int *)(PORT + 0x0070u))
#define PIO_SCIFSR  *((volatile unsigned int *)(PORT + 0x0080u))
#define PIO_DIFSR   *((volatile unsigned int *)(PORT + 0x0084u))
#define PIO_IFDGSR  *((volatile unsigned int *)(PORT + 0x0088u))
#define PIO_SCDR    *((volatile unsigned int *)(PORT + 0x008Cu))
#define PIO_OWER    *((volatile unsigned int *)(PORT + 0x00A0u))
#define PIO_OWDR    *((volatile unsigned int *)(PORT + 0x00A4u))
#define PIO_OWSR    *((volatile unsigned int *)(PORT + 0x00A8u))
#define PIO_AIMER   *((volatile unsigned int *)(PORT + 0x00B0u))
#define PIO_AIMDR   *((volatile unsigned int *)(PORT + 0x00B4u))
#define PIO_AIMMR   *((volatile unsigned int *)(PORT + 0x00B8u))

#define PIO_WPMR    *((volatile unsigned int *)(PORT + 0x00E4u))
#define PIO_WPSR    *((volatile unsigned int *)(PORT + 0x00E8u))

#define PIN_NUM_MASK    (1U << 1)
#define PIO_WPEN_MASK  0x50494F00

int main(void)
{
	PIO_WPMR = PIO_WPEN_MASK & 0xFFFFFFFE;

	PIO_PER  = 0x0000FFFF;
	PIO_OER  = 0x000000FF;
	PIO_ODR  = 0xFFFFFF00;
	PIO_IFER = 0x00000F00;
	PIO_IFDR = 0xFFFFF0FF;
	PIO_SODR = 0x00000000;
	PIO_CODR = 0x0FFFFFFF;
	PIO_IER  = 0x0F000F00;
	PIO_IDR  = 0xF0FFF0FF;
	PIO_MDER = 0x0000000F;
	PIO_MDDR = 0xFFFFFFF0;
	PIO_PUDR = 0xF0F000F0;
	PIO_PUER = 0x0F0FFF0F;
	PIO_ABSR = 0x00F00000;
	PIO_OWER = 0x0000000F;
	PIO_OWDR = 0x0FFFFFF0;
	
	PIO_SODR = 0x000000F0;

	for (;;)
		;

	return 0;
}
