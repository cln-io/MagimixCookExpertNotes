#!/usr/bin/env python3
"""
Disassemble and analyze the LPC1788 firmware using Capstone.
Usage: python3 /tools/analyze_lpc.py /firmware/lpc1788.bin
"""

import sys
import struct
from capstone import *

def analyze(path):
    with open(path, 'rb') as f:
        data = f.read()

    print(f"=== LPC1788 Firmware Analysis ===")
    print(f"Size: {len(data)} bytes ({len(data)/1024:.1f} KB)\n")

    # Vector table
    print("--- Vector Table ---")
    vector_names = [
        "Initial SP", "Reset", "NMI", "HardFault",
        "MemManage", "BusFault", "UsageFault", "Reserved(checksum)",
        "Reserved", "Reserved", "Reserved", "SVCall",
        "DebugMon", "Reserved", "PendSV", "SysTick"
    ]
    for i in range(16):
        val = struct.unpack_from('<I', data, i * 4)[0]
        print(f"  [{i:2d}] {vector_names[i]:>20s}: 0x{val:08X}")

    # Disassemble from Reset handler
    reset = struct.unpack_from('<I', data, 4)[0]
    reset_offset = reset & ~1  # Clear Thumb bit
    print(f"\n--- Disassembly from Reset Handler (0x{reset_offset:X}) ---")

    md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)
    md.detail = True

    # Disassemble first 200 instructions from reset
    code = data[reset_offset:reset_offset + 800]
    count = 0
    for insn in md.disasm(code, reset_offset):
        print(f"  0x{insn.address:06X}:  {insn.mnemonic:8s} {insn.op_str}")
        count += 1
        if count >= 200:
            break

    # Find all function references (BL instructions)
    print(f"\n--- Function Calls (BL targets) ---")
    targets = set()
    for insn in md.disasm(data[:0x10000], 0):
        if insn.mnemonic in ('bl', 'b.w'):
            try:
                target = int(insn.op_str.replace('#', ''), 0)
                targets.add(target)
            except ValueError:
                pass

    for t in sorted(targets):
        print(f"  sub_0x{t:06X}")

    print(f"\nTotal unique function targets: {len(targets)}")


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <firmware.bin>")
        sys.exit(1)
    analyze(sys.argv[1])
