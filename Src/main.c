
#include <stdint.h>


// AHBx and APBx BUS Peripheral base addresses
#define PERIPH_BASE					0x40000000U
#define APB1_PERIPH_BASE_ADDR		PERIPH_BASE
#define APB2_PERIPH_BASE_ADDR		0x40010000U
#define AHB_PERIPH_BASE_ADDR		0x40018000U

// base addresses of peripheral which are hanging on APB2 bus
#define GPIOA_BASE_ADDR		(APB2_PERIPH_BASE_ADDR + 0x0800)
#define GPIOB_BASE_ADDR		(APB2_PERIPH_BASE_ADDR + 0x0C00)
#define GPIOC_BASE_ADDR		(APB2_PERIPH_BASE_ADDR + 0x1000)
#define GPIOD_BASE_ADDR		(APB2_PERIPH_BASE_ADDR + 0x1400)


// base addresses of peripheral which are hanging on AHB bus
#define RCC_BASE_ADDR		(AHB_PERIPH_BASE_ADDR + 0x9000)


// peripheral register definition structures

typedef struct{
	volatile uint32_t CRL;			 /*!< Port configuration register low, (GPIOx_CRL) 0-7 */
	volatile uint32_t CRH;			 /* Port configuration register high (GPIOx_CRH) 8-15 */
	volatile uint32_t IDR;			 /* Port input data register (GPIOx_IDR) */
	volatile uint32_t ODR;			 /* Port output data register (GPIOx_ODR) */
	volatile uint32_t BSRR;			 /* Port bit set/reset register (GPIOx_BSRR) */
	volatile uint32_t BRR;			 /* Port bit reset register (GPIOx_BRR) */
	volatile uint32_t LCKR;			 /* Port configuration lock register (GPIOx_LCKR) */
}GPIO_RegDef_t;

typedef struct{
	volatile uint32_t CR;			/* Clock control register (RCC_CR) */
	volatile uint32_t CFGR;			/* Clock configuration register (RCC_CFGR) */
	volatile uint32_t CIR;			/* Clock interrupt register (RCC_CIR) */
 	volatile uint32_t APB2RSTR;		/* APB2 peripheral reset register (RCC_APB2RSTR) */
	volatile uint32_t APB1RSTR;		/* APB1 peripheral reset register (RCC_APB1RSTR) */
	volatile uint32_t AHBENR;		/* AHB peripheral clock enable register (RCC_AHBENR) */
	volatile uint32_t APB2ENR;		/* APB2 peripheral clock enable register (RCC_APB2ENR) */
	volatile uint32_t APB1ENR;		/* APB1 peripheral clock enable register (RCC_APB1ENR) */
	volatile uint32_t BDCR;			/* Backup domain control register (RCC_BDCR) */
	volatile uint32_t CSR;			/* Control/status register (RCC_CSR) */
}RCC_RegDef_t;

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASE_ADDR)

#define RCC ((RCC_RegDef_t*)RCC_BASE_ADDR)


int main(void)
{
	volatile uint32_t* apb2 = ((uint32_t*)0x40021018);

	*apb2 |= (1 << 2);

   //RCC -> APB2ENR |= (1 << 2);
   GPIOA ->CRL &= ~ 0xf;
   GPIOA -> CRL |= 2;
   GPIOA ->ODR |=  (1 << 0);

   while(1){
	   GPIOA ->ODR ^=  (1 << 0);
	   for(uint32_t i = 500000; i>1; i--){

	   }
   }
}
