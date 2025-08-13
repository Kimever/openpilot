#pragma once

#define CLOCK_SOURCE_PERIOD_MS           50U
#define CLOCK_SOURCE_PULSE_LEN_MS        2U

<<<<<<< Updated upstream
void clock_source_set_period(uint8_t period);
void clock_source_init(void);
=======
void clock_source_set_timer_params(uint16_t param1, uint16_t param2);
void clock_source_init(bool enable_channel1);
>>>>>>> Stashed changes
