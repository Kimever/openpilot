#pragma once

#include <stdbool.h>

//#define DEBUG
//#define DEBUG_UART
//#define DEBUG_USB
//#define DEBUG_SPI
//#define DEBUG_FAULTS
//#define DEBUG_COMMS
//#define DEBUG_FAN

#define CAN_INIT_TIMEOUT_MS 500U
#define USBPACKET_MAX_SIZE 0x40U
#define MAX_CAN_MSGS_PER_USB_BULK_TRANSFER 51U
#define MAX_CAN_MSGS_PER_SPI_BULK_TRANSFER 170U

// USB definitions
<<<<<<< Updated upstream
#define USB_VID 0xBBAAU
=======
#define USB_VID 0x3801U
>>>>>>> Stashed changes

#ifdef PANDA_JUNGLE
  #ifdef BOOTSTUB
    #define USB_PID 0xDDEFU
  #else
    #define USB_PID 0xDDCFU
  #endif
#else
  #ifdef BOOTSTUB
    #define USB_PID 0xDDEEU
  #else
    #define USB_PID 0xDDCCU
  #endif
#endif

// platform includes
#ifdef STM32H7
<<<<<<< Updated upstream
  #include "stm32h7/stm32h7_config.h"
#elif defined(STM32F4)
  #include "stm32f4/stm32f4_config.h"
=======
  #include "board/stm32h7/stm32h7_config.h"
#elif defined(STM32F4)
  #include "board/stm32f4/stm32f4_config.h"
>>>>>>> Stashed changes
#else
  // TODO: uncomment this, cppcheck complains
  // building for tests
  //#include "fake_stm.h"
#endif
