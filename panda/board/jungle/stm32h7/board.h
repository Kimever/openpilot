<<<<<<< Updated upstream
#include "boards/board_declarations.h"

#include "stm32h7/lladc.h"
#include "boards/board_v2.h"
=======
#include "board/jungle/boards/board_declarations.h"

#include "board/stm32h7/lladc.h"
#include "board/jungle/boards/board_v2.h"
>>>>>>> Stashed changes

void detect_board_type(void) {
  hw_type = HW_TYPE_V2;
  current_board = &board_v2;
}
