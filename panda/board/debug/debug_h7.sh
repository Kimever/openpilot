<<<<<<< Updated upstream
#!/bin/bash -e
=======
#!/usr/bin/env bash
set -e
>>>>>>> Stashed changes

sudo openocd -f "interface/stlink.cfg" -c "transport select hla_swd" -f "target/stm32h7x.cfg" -c "init"
