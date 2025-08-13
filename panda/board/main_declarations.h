<<<<<<< Updated upstream
// ******************** Prototypes ********************
void print(const char *a);
void puth(unsigned int i);
void puth2(unsigned int i);
void puth4(unsigned int i);
void hexdump(const void *a, int l);
=======
#pragma once

// ******************** Prototypes ********************
void print(const char *a);
void puth(unsigned int i);
>>>>>>> Stashed changes
typedef struct board board;
typedef struct harness_configuration harness_configuration;
void pwm_init(TIM_TypeDef *TIM, uint8_t channel);
void pwm_set(TIM_TypeDef *TIM, uint8_t channel, uint8_t percentage);

// ********************* Globals **********************
<<<<<<< Updated upstream
uint8_t hw_type = 0;
board *current_board;
uint32_t uptime_cnt = 0;
bool green_led_enabled = false;

// heartbeat state
uint32_t heartbeat_counter = 0;
bool heartbeat_lost = false;
bool heartbeat_disabled = false;            // set over USB

// siren state
bool siren_enabled = false;
uint32_t siren_countdown = 0; // siren plays while countdown > 0
uint32_t controls_allowed_countdown = 0;

=======
extern uint8_t hw_type;
extern board *current_board;
extern uint32_t uptime_cnt;
extern bool green_led_enabled;

// heartbeat state
extern uint32_t heartbeat_counter;
extern bool heartbeat_lost;
extern bool heartbeat_disabled;            // set over USB

// siren state
extern bool siren_enabled;
>>>>>>> Stashed changes
