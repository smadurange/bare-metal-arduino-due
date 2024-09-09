#define PIOC_PER  *((volatile unsigned int *) 0x400E1200U)
#define PIOC_OER  *((volatile unsigned int *) 0x400E1210U)
#define PIOC_IDR  *((volatile unsigned int *) 0x400E1244U)
#define PIOC_CODR *((volatile unsigned int *) 0x400E1234U)
#define PIOC_IFDR *((volatile unsigned int *) 0x400E1224U)
#define PIOC_MDDR *((volatile unsigned int *) 0x400E1254U)
#define PIOC_ODSR *((volatile unsigned int *) 0x400E1238U)
#define PIOC_PUDR *((volatile unsigned int *) 0x400E1260U)
#define PIOC_OWDR *((volatile unsigned int *) 0x400E12A4U)

int main(void)
{
	PIOC_PER = 0x00000001;
	PIOC_OER = 0x00000001;
	PIOC_IDR = 0x00000001;
	PIOC_CODR = 0x00000001;
	PIOC_IFDR = 0x00000001;
	PIOC_MDDR = 0x00000001;
	PIOC_PUDR = 0x00000001;
	PIOC_OWDR = 0x00000001;

	PIOC_ODSR = 0x00000001;

	return 0;
}
