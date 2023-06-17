
#ifndef MEMMAP_H_
#define MEMMAP_H_

// Port A
#define PINA_REG  (*(volatile uint8_t*)0x20)
#define DDRA_REG  (*(volatile uint8_t*)0x21)
#define PORTA_REG (*(volatile uint8_t*)0x22)


// Port B
#define PINB_REG  (*(volatile uint8_t*)0x23)
#define DDRB_REG  (*(volatile uint8_t*)0x24)
#define PORTB_REG (*(volatile uint8_t*)0x25)


// Port C
#define PINC_REG  (*(volatile uint8_t*)0x26)
#define DDRC_REG  (*(volatile uint8_t*)0x27)
#define PORTC_REG (*(volatile uint8_t*)0x28)


// Port D
#define PIND_REG  (*(volatile uint8_t*)0x29)
#define DDRD_REG  (*(volatile uint8_t*)0x2A)
#define PORTD_REG (*(volatile uint8_t*)0x2B)


// Port E
#define PINE_REG  (*(volatile uint8_t*)0x2C)
#define DDRE_REG  (*(volatile uint8_t*)0x2D)
#define PORTE_REG (*(volatile uint8_t*)0x2E)


// Port F
#define PINF_REG  (*(volatile uint8_t*)0x2F)
#define DDRF_REG  (*(volatile uint8_t*)0x30)
#define PORTF_REG (*(volatile uint8_t*)0x31)


// Port G
#define PING_REG  (*(volatile uint8_t*)0x32)
#define DDRG_REG  (*(volatile uint8_t*)0x33)
#define PORTG_REG (*(volatile uint8_t*)0x34)


// Port H
#define PINH_REG  (*(volatile uint8_t*)0x100)
#define DDRH_REG  (*(volatile uint8_t*)0x101)
#define PORTH_REG (*(volatile uint8_t*)0x102)


// Port J
#define PINJ_REG  (*(volatile uint8_t*)0x103)
#define DDRJ_REG  (*(volatile uint8_t*)0x104)
#define PORTJ_REG (*(volatile uint8_t*)0x105)


// Port K
#define PINK_REG  (*(volatile uint8_t*)0x106)
#define DDRK_REG  (*(volatile uint8_t*)0x107)
#define PORTK_REG (*(volatile uint8_t*)0x108)


// Port L
#define PINL_REG  (*(volatile uint8_t*)0x109)
#define DDRL_REG  (*(volatile uint8_t*)0x10A)
#define PORTL_REG (*(volatile uint8_t*)0x10B)


#endif /* MEMMAP_H_ */