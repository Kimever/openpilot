<<<<<<< Updated upstream
=======
#pragma once

#include "board_declarations.h"

>>>>>>> Stashed changes
// ///////////////////////////
// Tres (STM32H7) + Harness //
// ///////////////////////////

<<<<<<< Updated upstream
bool tres_ir_enabled;
bool tres_fan_enabled;
void tres_update_fan_ir_power(void) {
  red_chiplet_set_fan_or_usb_load_switch(tres_ir_enabled || tres_fan_enabled);
}

void tres_set_ir_power(uint8_t percentage){
=======
static bool tres_ir_enabled;
static bool tres_fan_enabled;
static void tres_update_fan_ir_power(void) {
  set_gpio_output(GPIOD, 3, tres_ir_enabled || tres_fan_enabled);
}

static void tres_set_ir_power(uint8_t percentage){
>>>>>>> Stashed changes
  tres_ir_enabled = (percentage > 0U);
  tres_update_fan_ir_power();
  pwm_set(TIM3, 4, percentage);
}

<<<<<<< Updated upstream
void tres_set_bootkick(BootState state) {
=======
static void tres_set_bootkick(BootState state) {
>>>>>>> Stashed changes
  set_gpio_output(GPIOA, 0, state != BOOT_BOOTKICK);
  set_gpio_output(GPIOC, 12, state != BOOT_RESET);
}

<<<<<<< Updated upstream
void tres_set_fan_enabled(bool enabled) {
=======
static void tres_set_fan_enabled(bool enabled) {
>>>>>>> Stashed changes
  // NOTE: fan controller reset doesn't work on a tres if IR is enabled
  tres_fan_enabled = enabled;
  tres_update_fan_ir_power();
}

<<<<<<< Updated upstream
bool tres_read_som_gpio (void) {
  return (get_gpio_input(GPIOC, 2) != 0);
}

void tres_init(void) {
=======
static void tres_enable_can_transceiver(uint8_t transceiver, bool enabled) {
  switch (transceiver) {
    case 1U:
      set_gpio_output(GPIOG, 11, !enabled);
      break;
    case 2U:
      set_gpio_output(GPIOB, 10, !enabled);
      break;
    case 3U:
      set_gpio_output(GPIOD, 7, !enabled);
      break;
    case 4U:
      set_gpio_output(GPIOB, 11, !enabled);
      break;
    default:
      break;
  }
}

static void tres_set_can_mode(uint8_t mode) {
  current_board->enable_can_transceiver(2U, false);
  current_board->enable_can_transceiver(4U, false);
  switch (mode) {
    case CAN_MODE_NORMAL:
    case CAN_MODE_OBD_CAN2:
      if ((bool)(mode == CAN_MODE_NORMAL) != (bool)(harness.status == HARNESS_STATUS_FLIPPED)) {
        // B12,B13: disable normal mode
        set_gpio_pullup(GPIOB, 12, PULL_NONE);
        set_gpio_mode(GPIOB, 12, MODE_ANALOG);

        set_gpio_pullup(GPIOB, 13, PULL_NONE);
        set_gpio_mode(GPIOB, 13, MODE_ANALOG);

        // B5,B6: FDCAN2 mode
        set_gpio_pullup(GPIOB, 5, PULL_NONE);
        set_gpio_alternate(GPIOB, 5, GPIO_AF9_FDCAN2);

        set_gpio_pullup(GPIOB, 6, PULL_NONE);
        set_gpio_alternate(GPIOB, 6, GPIO_AF9_FDCAN2);
        current_board->enable_can_transceiver(2U, true);
      } else {
        // B5,B6: disable normal mode
        set_gpio_pullup(GPIOB, 5, PULL_NONE);
        set_gpio_mode(GPIOB, 5, MODE_ANALOG);

        set_gpio_pullup(GPIOB, 6, PULL_NONE);
        set_gpio_mode(GPIOB, 6, MODE_ANALOG);
        // B12,B13: FDCAN2 mode
        set_gpio_pullup(GPIOB, 12, PULL_NONE);
        set_gpio_alternate(GPIOB, 12, GPIO_AF9_FDCAN2);

        set_gpio_pullup(GPIOB, 13, PULL_NONE);
        set_gpio_alternate(GPIOB, 13, GPIO_AF9_FDCAN2);
        current_board->enable_can_transceiver(4U, true);
      }
      break;
    default:
      break;
  }
}

static bool tres_read_som_gpio (void) {
  return (get_gpio_input(GPIOC, 2) != 0);
}

static void tres_init(void) {
>>>>>>> Stashed changes
  // Enable USB 3.3V LDO for USB block
  register_set_bits(&(PWR->CR3), PWR_CR3_USBREGEN);
  register_set_bits(&(PWR->CR3), PWR_CR3_USB33DEN);
  while ((PWR->CR3 & PWR_CR3_USB33RDY) == 0U);

<<<<<<< Updated upstream
  red_chiplet_init();
=======
  common_init_gpio();
>>>>>>> Stashed changes

  // C2: SOM GPIO used as input (fan control at boot)
  set_gpio_mode(GPIOC, 2, MODE_INPUT);
  set_gpio_pullup(GPIOC, 2, PULL_DOWN);

  // SOM bootkick + reset lines
<<<<<<< Updated upstream
  set_gpio_mode(GPIOC, 12, MODE_OUTPUT);
  tres_set_bootkick(BOOT_BOOTKICK);
=======
  // WARNING: make sure output state is set before configuring as output
  tres_set_bootkick(BOOT_BOOTKICK);
  set_gpio_mode(GPIOC, 12, MODE_OUTPUT);
>>>>>>> Stashed changes

  // SOM debugging UART
  gpio_uart7_init();
  uart_init(&uart_ring_som_debug, 115200);

<<<<<<< Updated upstream
  // SPI init
  gpio_spi_init();

=======
>>>>>>> Stashed changes
  // fan setup
  set_gpio_alternate(GPIOC, 8, GPIO_AF2_TIM3);

  // Initialize IR PWM and set to 0%
  set_gpio_alternate(GPIOC, 9, GPIO_AF2_TIM3);
  pwm_init(TIM3, 4);
  tres_set_ir_power(0U);

  // Fake siren
  set_gpio_alternate(GPIOC, 10, GPIO_AF4_I2C5);
  set_gpio_alternate(GPIOC, 11, GPIO_AF4_I2C5);
  register_set_bits(&(GPIOC->OTYPER), GPIO_OTYPER_OT10 | GPIO_OTYPER_OT11); // open drain
<<<<<<< Updated upstream
  fake_siren_init();

  // Clock source
  clock_source_init();
}

board board_tres = {
  .harness_config = &red_chiplet_harness_config,
  .has_obd = true,
  .has_spi = true,
  .has_canfd = true,
  .fan_max_rpm = 6600U,
=======

  // Clock source
  clock_source_init(false);
}

static harness_configuration tres_harness_config = {
  .GPIO_SBU1 = GPIOC,
  .GPIO_SBU2 = GPIOA,
  .GPIO_relay_SBU1 = GPIOA,
  .GPIO_relay_SBU2 = GPIOA,
  .pin_SBU1 = 4,
  .pin_SBU2 = 1,
  .pin_relay_SBU1 = 8,
  .pin_relay_SBU2 = 3,
  .adc_signal_SBU1 = ADC_CHANNEL_DEFAULT(ADC1, 4),
  .adc_signal_SBU2 = ADC_CHANNEL_DEFAULT(ADC1, 17)
};

board board_tres = {
  .harness_config = &tres_harness_config,
  .has_spi = true,
  .fan_max_rpm = 6600U,
  .fan_max_pwm = 100U,
>>>>>>> Stashed changes
  .avdd_mV = 1800U,
  .fan_stall_recovery = false,
  .fan_enable_cooldown_time = 3U,
  .init = tres_init,
  .init_bootloader = unused_init_bootloader,
<<<<<<< Updated upstream
  .enable_can_transceiver = red_chiplet_enable_can_transceiver,
  .enable_can_transceivers = red_chiplet_enable_can_transceivers,
  .set_led = red_set_led,
  .set_can_mode = red_chiplet_set_can_mode,
  .check_ignition = red_check_ignition,
=======
  .enable_can_transceiver = tres_enable_can_transceiver,
  .led_GPIO = {GPIOE, GPIOE, GPIOE},
  .led_pin = {4, 3, 2},
  .set_can_mode = tres_set_can_mode,
>>>>>>> Stashed changes
  .read_voltage_mV = red_read_voltage_mV,
  .read_current_mA = unused_read_current,
  .set_fan_enabled = tres_set_fan_enabled,
  .set_ir_power = tres_set_ir_power,
  .set_siren = fake_siren_set,
  .set_bootkick = tres_set_bootkick,
<<<<<<< Updated upstream
  .read_som_gpio = tres_read_som_gpio
=======
  .read_som_gpio = tres_read_som_gpio,
  .set_amp_enabled = unused_set_amp_enabled
>>>>>>> Stashed changes
};
