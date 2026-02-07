#!/bin/bash
# Build and run the firmware RE docker container
# Mounts the CLAUDE/ folder (with .bin files) into /firmware

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

IMAGE_NAME="cookexpert-re"

echo "Building Docker image..."
docker build -t "$IMAGE_NAME" "$SCRIPT_DIR"

echo ""
echo "Starting container with firmware mounted at /firmware"
echo "  Tools available:"
echo "    - arm-none-eabi-gcc/objdump  (ARM cross-toolchain)"
echo "    - r2 / radare2               (reverse engineering)"
echo "    - python3 + capstone/unicorn  (scripted analysis)"
echo "    - analyzeHeadless             (Ghidra headless)"
echo "    - binwalk                     (firmware extraction)"
echo "  Helper scripts in /tools/"
echo "    - python3 /tools/analyze_lpc.py /firmware/lpc1788.bin"
echo "    - python3 /tools/ghidra_decompile.py /firmware/lpc1788.bin"
echo ""

docker run -it --rm \
    -v "$PROJECT_ROOT/CLAUDE:/firmware" \
    -v "$SCRIPT_DIR/scripts:/tools" \
    "$IMAGE_NAME"
