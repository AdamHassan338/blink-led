#include <stdint.h>

#define RCC_BASE 0x40021000
#define GPIOC_BASE 0x40011000

uint32_t *RCC_APB2ENR = (uint32_t *)(RCC_BASE + 0x18);
uint32_t *GPIOC_CFGR = (uint32_t *)(GPIOC_BASE + 0x04);
uint32_t *GPIOC_ODR = (uint32_t *)(GPIOC_BASE + 0x0C);

uint32_t GPIOC_MODE_2MHZ_BIT = (2 << 20);
uint32_t GPIOC_PUSH_PULL_OUTPUT_BIT = (0 << 22);

int main(void) {

  /* SET GPIO-C ENBALBE CLOCK BIT */
  *RCC_APB2ENR |= (1 << 4);
  // RESET
  *GPIOC_CFGR &= ~((0 << 20) | (0 < 22));
  *GPIOC_CFGR |= GPIOC_MODE_2MHZ_BIT | GPIOC_PUSH_PULL_OUTPUT_BIT;

  while (1) {
    /* set GPIOC13 to 0 */
    *GPIOC_ODR &= ~(1 << 13)
    ;
    for (int i = 0; i < 1000000; i++)
      __asm__("nop");

    /* set GPIOC13 to 1 */
    *GPIOC_ODR |= (1 << 13);

    for (int i = 0; i < 1000000; i++)
      __asm__("nop");
  }
}
