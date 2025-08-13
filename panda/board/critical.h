<<<<<<< Updated upstream
// ********************* Critical section helpers *********************
volatile bool interrupts_enabled = false;
=======
#include "critical_declarations.h"

// ********************* Critical section helpers *********************
uint8_t global_critical_depth = 0U;

static volatile bool interrupts_enabled = false;
>>>>>>> Stashed changes

void enable_interrupts(void) {
  interrupts_enabled = true;
  __enable_irq();
}

void disable_interrupts(void) {
  interrupts_enabled = false;
  __disable_irq();
}
<<<<<<< Updated upstream

uint8_t global_critical_depth = 0U;
#define ENTER_CRITICAL()                                      \
  __disable_irq();                                            \
  global_critical_depth += 1U;

#define EXIT_CRITICAL()                                       \
  global_critical_depth -= 1U;                                \
  if ((global_critical_depth == 0U) && interrupts_enabled) {  \
    __enable_irq();                                           \
  }
=======
>>>>>>> Stashed changes
