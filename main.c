#define PIOC_PER  *((volatile unsigned int *) 0x400E1200U)
#define PIOC_PDR  *((volatile unsigned int *) 0x400E1204U)
#define PIOC_OER  *((volatile unsigned int *) 0x400E1210U)
#define PIOC_ODR  *((volatile unsigned int *) 0x400E1214U)
#define PIOC_IDR  *((volatile unsigned int *) 0x400E1244U)
#define PIOC_IER  *((volatile unsigned int *) 0x400E1240U)
#define PIOC_ABSR *((volatile unsigned int *) 0x400E1270U)
#define PIOC_CODR *((volatile unsigned int *) 0x400E1234U)
#define PIOC_IFDR *((volatile unsigned int *) 0x400E1224U)
#define PIOC_IFER *((volatile unsigned int *) 0x400E1220U)
#define PIOC_MDDR *((volatile unsigned int *) 0x400E1254U)
#define PIOC_MDER *((volatile unsigned int *) 0x400E1250U)
#define PIOC_ODSR *((volatile unsigned int *) 0x400E1238U)
#define PIOC_PUDR *((volatile unsigned int *) 0x400E1260U)
#define PIOC_PUER *((volatile unsigned int *) 0x400E1264U)
#define PIOC_OWDR *((volatile unsigned int *) 0x400E12A4U)
#define PIOC_OWER *((volatile unsigned int *) 0x400E12A0U)
#define PIOC_SODR *((volatile unsigned int *) 0x400E1230U)

int main(void)
{
	PIOC_PER = 0x0000FFFF;
	PIOC_PDR = 0xFFFF0000;
	PIOC_OER = 0x000000FF;
	PIOC_ODR = 0xFFFFFF00;
	PIOC_IFER = 0x00000F00;
	PIOC_IFDR = 0xFFFFF0FF;
	PIOC_SODR = 0x00000000;
	PIOC_CODR = 0x0FFFFFFF;
	PIOC_IER  = 0x0F000F00;
	PIOC_IDR  = 0xF0FFF0FF;
	PIOC_MDER = 0x0000000F;
	PIOC_MDDR = 0xFFFFFFF0;
	PIOC_PUDR = 0xF0F000F0;
	PIOC_PUER = 0x0F0FFF0F;
	PIOC_ABSR = 0x00F00000;
	PIOC_OWER = 0x0000000F;
	PIOC_OWDR = 0x0FFFFFF0;

	PIOC_ODSR = 0x0000FFFF;

	return 0;
}
