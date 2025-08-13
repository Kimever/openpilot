#!/usr/bin/env python3
import os
import time
from collections import defaultdict
import binascii

from panda import PandaJungle

# fake
def sec_since_boot():
  return time.time()

def can_printer():
  p = PandaJungle()
<<<<<<< Updated upstream

  start = sec_since_boot()
  lp = sec_since_boot()
  msgs = defaultdict(list)
  canbus = int(os.getenv("CAN", "0"))
  while True:
    can_recv = p.can_recv()
    for address, _, dat, src  in can_recv:
      if src == canbus:
        msgs[address].append(dat)
=======
  print(f"Connected to: {p._serial}: {p.get_version()}")
  time.sleep(1)

  p.can_clear(0xFFFF)

  start = sec_since_boot()
  lp = sec_since_boot()
  all_msgs = defaultdict(list)

  canbus = os.getenv("CAN")
  if canbus == "3":
    p.set_obd(True)
    canbus = "1"

  while True:
    can_recv = p.can_recv()
    for addr, dat, bus in can_recv:
      if canbus is None or str(bus) == canbus:
        all_msgs[(addr, bus)].append((dat))
>>>>>>> Stashed changes

    if sec_since_boot() - lp > 0.1:
      dd = chr(27) + "[2J"
      dd += "%5.2f\n" % (sec_since_boot() - start)
<<<<<<< Updated upstream
      for k,v in sorted(zip(list(msgs.keys()), [binascii.hexlify(x[-1]) for x in list(msgs.values())], strict=True)):
        dd += "%s(%6d) %s\n" % ("%04X(%4d)" % (k,k),len(msgs[k]), v)
=======
      for (addr, bus), dat_log in sorted(all_msgs.items()):
        dd += "%d: %s(%6d): %s\n" % (bus, "%04X(%4d)" % (addr, addr), len(dat_log), binascii.hexlify(dat_log[-1]).decode())
>>>>>>> Stashed changes
      print(dd)
      lp = sec_since_boot()

if __name__ == "__main__":
  can_printer()
