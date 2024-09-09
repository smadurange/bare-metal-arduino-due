#define PIOA 0x400E0E00
#define PIOB 0x400E1000
#define PIOC 0x400E1200
#define PIOD 0x400E1400

#define PORT PIOC;

#define PIO_PER     *((volatile unsigned int *)(PORT + 0x0000))
#define PIO_PDR     *((volatile unsigned int *)(PORT + 0x0004))
#define PIO_PSR     *((volatile unsigned int *)(PORT + 0x0008))
#define PIO_OER     *((volatile unsigned int *)(PORT + 0x0010))
#define PIO_ODR     *((volatile unsigned int *)(PORT + 0x0014))
#define PIO_OSR     *((volatile unsigned int *)(PORT + 0x0018))
#define PIO_IFER    *((volatile unsigned int *)(PORT + 0x0020))
#define PIO_IFDR    *((volatile unsigned int *)(PORT + 0x0024))
#define PIO_IFSR    *((volatile unsigned int *)(PORT + 0x0028))
#define PIO_SODR    *((volatile unsigned int *)(PORT + 0x0030))
#define PIO_CODR    *((volatile unsigned int *)(PORT + 0x0034))
#define PIO_ODSR    *((volatile unsigned int *)(PORT + 0x0038))
#define PIO_PDSR    *((volatile unsigned int *)(PORT + 0x003C))
#define PIO_IER     *((volatile unsigned int *)(PORT + 0x0040))
#define PIO_IDR     *((volatile unsigned int *)(PORT + 0x0044))
#define PIO_IMR     *((volatile unsigned int *)(PORT + 0x0048))
#define PIO_ISR     *((volatile unsigned int *)(PORT + 0x004C))
#define PIO_MDER    *((volatile unsigned int *)(PORT + 0x0050))
#define PIO_MDDR    *((volatile unsigned int *)(PORT + 0x0054))
#define PIO_MDSR    *((volatile unsigned int *)(PORT + 0x0058))
#define PIO_PUDR    *((volatile unsigned int *)(PORT + 0x0060))
#define PIO_PUER    *((volatile unsigned int *)(PORT + 0x0064))
#define PIO_PUSR    *((volatile unsigned int *)(PORT + 0x0068))
#define PIO_ABSR    *((volatile unsigned int *)(PORT + 0x0070))
#define PIO_SCIFSR  *((volatile unsigned int *)(PORT + 0x0080))
#define PIO_DIFSR   *((volatile unsigned int *)(PORT + 0x0084))
#define PIO_IFDGSR  *((volatile unsigned int *)(PORT + 0x0088))
#define PIO_SCDR    *((volatile unsigned int *)(PORT + 0x008C))
#define PIO_OWER    *((volatile unsigned int *)(PORT + 0x00A0))
#define PIO_OWDR    *((volatile unsigned int *)(PORT + 0x00A4))
#define PIO_OWSR    *((volatile unsigned int *)(PORT + 0x00A8))
#define PIO_AIMER   *((volatile unsigned int *)(PORT + 0x00B0))
#define PIO_AIMDR   *((volatile unsigned int *)(PORT + 0x00B4))
#define PIO_AIMMR   *((volatile unsigned int *)(PORT + 0x00B8))

#define PIO_WPMR    *((volatile unsigned int *)(PORT + 0x00E4))
#define PIO_WPSR    *((volatile unsigned int *)(PORT + 0x00E8))

#define PIN_NUM_MASK   (1U << 0)
#define PIO_WPEN_MASK 0x50494F00

int main(void)
{
	PIO_WPMR = PIO_WPEN_MASK & 0xFFFFFFFE;

	PIO_PER |= PIN_NUM_MASK;
	PIO_PDR |= ~PIN_NUM_MASK;

	PIO_OER |= PIN_NUM_MASK;
	PIO_ODR |= ~PIN_NUM_MASK;

	PIO_IER |= ~PIN_NUM_MASK;
	PIO_IDR |= PIN_NUM_MASK;

	PIO_PUDR |= PIN_NUM_MASK;
	PIO_PUER |= ~PIN_NUM_MASK;
	
	PIO_SODR = 1;
	PIO_CODR = 0;

	return 0;
}
