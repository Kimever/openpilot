<<<<<<< Updated upstream
=======
#pragma once

#include "board_declarations.h"

>>>>>>> Stashed changes
// ////////////////////////// //
// Cuatro (STM32H7) + Harness //
// ////////////////////////// //

<<<<<<< Updated upstream
void cuatro_set_led(uint8_t color, bool enabled) {
  switch (color) {
    case LED_RED:
      set_gpio_output(GPIOD, 15, !enabled);
      break;
     case LED_GREEN:
      set_gpio_output(GPIOD, 14, !enabled);
      break;
    case LED_BLUE:
      set_gpio_output(GPIOE, 2, !enabled);
      break;
    default:
      break;
  }
}

void cuatro_enable_can_transceiver(uint8_t transceiver, bool enabled) {
=======
static void cuatro_enable_can_transceiver(uint8_t transceiver, bool enabled) {
>>>>>>> Stashed changes
  switch (transceiver) {
    case 1U:
      set_gpio_output(GPIOB, 7, !enabled);
      break;
    case 2U:
      set_gpio_output(GPIOB, 10, !enabled);
      break;
    case 3U:
      set_gpio_output(GPIOD, 8, !enabled);
      break;
    case 4U:
      set_gpio_output(GPIOB, 11, !enabled);
      break;
    default:
      break;
  }
}

<<<<<<< Updated upstream
void cuatro_enable_can_transceivers(bool enabled) {
  uint8_t main_bus = (harness.status == HARNESS_STATUS_FLIPPED) ? 3U : 1U;
  for (uint8_t i=1U; i<=4U; i++) {
    // Leave main CAN always on for CAN-based ignition detection
    if (i == main_bus) {
      cuatro_enable_can_transceiver(i, true);
    } else {
      cuatro_enable_can_transceiver(i, enabled);
    }
  }
}

uint32_t cuatro_read_voltage_mV(void) {
  return adc_get_mV(8) * 11U;
}

uint32_t cuatro_read_current_mA(void) {
  return adc_get_mV(3) * 2U;
}

void cuatro_init(void) {
  red_chiplet_init();
=======
static uint32_t cuatro_read_voltage_mV(void) {
  return adc_get_mV(&(const adc_signal_t) ADC_CHANNEL_DEFAULT(ADC1, 8)) * 11U;
}

static uint32_t cuatro_read_current_mA(void) {
  return adc_get_mV(&(const adc_signal_t) ADC_CHANNEL_DEFAULT(ADC1, 3)) * 2U;
}

static void cuatro_set_fan_enabled(bool enabled) {
  set_gpio_output(GPIOD, 3, !enabled);
}

static void cuatro_set_bootkick(BootState state) {
  set_gpio_output(GPIOA, 0, state != BOOT_BOOTKICK);
}

static void cuatro_set_amp_enabled(bool enabled) {
  // *** tmp, remove soon ***
  static const uint8_t olds[][12] = {
    {0x44, 0x00, 0x10, 0x00, 0x19, 0x51, 0x32, 0x34, 0x39, 0x37, 0x37, 0x30},
    {0x14, 0x00, 0x13, 0x00, 0x18, 0x51, 0x32, 0x34, 0x39, 0x37, 0x37, 0x30},
    {0x04, 0x00, 0x30, 0x00, 0x18, 0x51, 0x32, 0x34, 0x39, 0x37, 0x37, 0x30},
    {0x2f, 0x00, 0x14, 0x00, 0x18, 0x51, 0x32, 0x34, 0x39, 0x37, 0x37, 0x30},
    {0x1e, 0x00, 0x2f, 0x00, 0x18, 0x51, 0x32, 0x34, 0x39, 0x37, 0x37, 0x30},
    {0x26, 0x00, 0x15, 0x00, 0x19, 0x51, 0x32, 0x34, 0x39, 0x37, 0x37, 0x30},
    {0x35, 0x00, 0x32, 0x00, 0x18, 0x51, 0x32, 0x34, 0x39, 0x37, 0x37, 0x30},
    {0x37, 0x00, 0x2f, 0x00, 0x18, 0x51, 0x32, 0x34, 0x39, 0x37, 0x37, 0x30},
  };
  bool is_old = false;
  for (uint8_t i = 0U; i < (sizeof(olds) / sizeof(olds[0])); i++) {
    is_old |= (memcmp(olds[i], ((uint8_t *)UID_BASE), 12) == 0);
  }
  if (is_old) set_gpio_output(GPIOA, 5, enabled);
  // *** tmp end ***

  set_gpio_output(GPIOB, 0, enabled);
}

static void cuatro_init(void) {
  common_init_gpio();

  // open drain
  set_gpio_output_type(GPIOD, 3, OUTPUT_TYPE_OPEN_DRAIN); // FAN_EN
  set_gpio_output_type(GPIOC, 12, OUTPUT_TYPE_OPEN_DRAIN); // VBAT_EN
>>>>>>> Stashed changes

  // Power readout
  set_gpio_mode(GPIOC, 5, MODE_ANALOG);
  set_gpio_mode(GPIOA, 6, MODE_ANALOG);

  // CAN transceiver enables
  set_gpio_pullup(GPIOB, 7, PULL_NONE);
  set_gpio_mode(GPIOB, 7, MODE_OUTPUT);
  set_gpio_pullup(GPIOD, 8, PULL_NONE);
  set_gpio_mode(GPIOD, 8, MODE_OUTPUT);

  // FDCAN3, different pins on this package than the rest of the reds
  set_gpio_pullup(GPIOD, 12, PULL_NONE);
  set_gpio_alternate(GPIOD, 12, GPIO_AF5_FDCAN3);
  set_gpio_pullup(GPIOD, 13, PULL_NONE);
  set_gpio_alternate(GPIOD, 13, GPIO_AF5_FDCAN3);

  // C2: SOM GPIO used as input (fan control at boot)
  set_gpio_mode(GPIOC, 2, MODE_INPUT);
  set_gpio_pullup(GPIOC, 2, PULL_DOWN);

  // SOM bootkick + reset lines
<<<<<<< Updated upstream
  set_gpio_mode(GPIOC, 12, MODE_OUTPUT);
  tres_set_bootkick(BOOT_BOOTKICK);
=======
  cuatro_set_bootkick(BOOT_BOOTKICK);
>>>>>>> Stashed changes

  // SOM debugging UART
  gpio_uart7_init();
  uart_init(&uart_ring_som_debug, 115200);

<<<<<<< Updated upstream
  // SPI init
  gpio_spi_init();

  // fan setup
  set_gpio_alternate(GPIOC, 8, GPIO_AF2_TIM3);

  // Initialize IR PWM and set to 0%
  set_gpio_alternate(GPIOC, 9, GPIO_AF2_TIM3);
  pwm_init(TIM3, 4);
  tres_set_ir_power(0U);

  // Clock source
  clock_source_init();
}

board board_cuatro = {
  .harness_config = &red_chiplet_harness_config,
  .has_obd = true,
  .has_spi = true,
  .has_canfd = true,
  .fan_max_rpm = 6600U,
=======
  // fan setup
  set_gpio_alternate(GPIOC, 8, GPIO_AF2_TIM3);
  register_set_bits(&(GPIOC->OTYPER), GPIO_OTYPER_OT8); // open drain

  // Clock source
  clock_source_init(true);

  // Sound codec
  cuatro_set_amp_enabled(false);
  set_gpio_alternate(GPIOA, 2, GPIO_AF8_SAI4);    // SAI4_SCK_B
  set_gpio_alternate(GPIOC, 0, GPIO_AF8_SAI4);    // SAI4_FS_B
  set_gpio_alternate(GPIOD, 11, GPIO_AF10_SAI4);  // SAI4_SD_A
  set_gpio_alternate(GPIOE, 3, GPIO_AF8_SAI4);    // SAI4_SD_B
  set_gpio_alternate(GPIOE, 4, GPIO_AF3_DFSDM1);  // DFSDM1_DATIN3
  set_gpio_alternate(GPIOE, 9, GPIO_AF3_DFSDM1);  // DFSDM1_CKOUT
  set_gpio_alternate(GPIOE, 6, GPIO_AF10_SAI4);   // SAI4_MCLK_B
  sound_init();
}

static harness_configuration cuatro_harness_config = {
  .GPIO_SBU1 = GPIOC,
  .GPIO_SBU2 = GPIOA,
  .GPIO_relay_SBU1 = GPIOA,
  .GPIO_relay_SBU2 = GPIOA,
  .pin_SBU1 = 4,
  .pin_SBU2 = 1,
  .pin_relay_SBU1 = 9,
  .pin_relay_SBU2 = 3,
  .adc_signal_SBU1 = ADC_CHANNEL_DEFAULT(ADC1, 4),
  .adc_signal_SBU2 = ADC_CHANNEL_DEFAULT(ADC1, 17)
};

board board_cuatro = {
  .harness_config = &cuatro_harness_config,
  .has_spi = true,
  .fan_max_rpm = 12500U,
  .fan_max_pwm = 99U, // it can go up to 14k RPM, but 99% -> 100% is very non-linear
>>>>>>> Stashed changes
  .avdd_mV = 1800U,
  .fan_stall_recovery = false,
  .fan_enable_cooldown_time = 3U,
  .init = cuatro_init,
  .init_bootloader = unused_init_bootloader,
  .enable_can_transceiver = cuatro_enable_can_transceiver,
<<<<<<< Updated upstream
  .enable_can_transceivers = cuatro_enable_can_transceivers,
  .set_led = cuatro_set_led,
  .set_can_mode = red_chiplet_set_can_mode,
  .check_ignition = red_check_ignition,
  .read_voltage_mV = cuatro_read_voltage_mV,
  .read_current_mA = cuatro_read_current_mA,
  .set_fan_enabled = tres_set_fan_enabled,
  .set_ir_power = tres_set_ir_power,
  .set_siren = unused_set_siren,
  .set_bootkick = tres_set_bootkick,
  .read_som_gpio = tres_read_som_gpio
=======
  .led_GPIO = {GPIOC, GPIOC, GPIOC},
  .led_pin = {6, 7, 9},
  .led_pwm_channels = {1, 2, 4},
  .set_can_mode = tres_set_can_mode,
  .read_voltage_mV = cuatro_read_voltage_mV,
  .read_current_mA = cuatro_read_current_mA,
  .set_fan_enabled = cuatro_set_fan_enabled,
  .set_ir_power = unused_set_ir_power,
  .set_siren = unused_set_siren,
  .set_bootkick = cuatro_set_bootkick,
  .read_som_gpio = tres_read_som_gpio,
  .set_amp_enabled = cuatro_set_amp_enabled
>>>>>>> Stashed changes
};
