#!/usr/bin/env python3
"""
Run Ghidra headless analysis on the LPC1788 firmware.
Creates a Ghidra project and exports decompiled C pseudocode.

Usage: python3 /tools/ghidra_decompile.py /firmware/lpc1788.bin
"""

import os
import sys
import subprocess

GHIDRA_DIR = "/opt/ghidra"
HEADLESS = os.path.join(GHIDRA_DIR, "support", "analyzeHeadless")

def run_ghidra(firmware_path):
    project_dir = "/firmware/ghidra_project"
    project_name = "CookExpert"
    os.makedirs(project_dir, exist_ok=True)

    # Write a Ghidra script to export decompiled functions
    script_dir = "/tmp/ghidra_scripts"
    os.makedirs(script_dir, exist_ok=True)

    script_path = os.path.join(script_dir, "DecompileAll.java")
    with open(script_path, 'w') as f:
        f.write("""
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileAll extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        String outPath = "/firmware/decompiled_output.c";
        PrintWriter pw = new PrintWriter(new FileWriter(outPath));

        pw.println("// Ghidra Decompiled Output - Magimix Cook Expert LPC1788 Firmware");
        pw.println("// Auto-generated pseudocode\\n");

        FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);
        int count = 0;
        while (funcs.hasNext()) {
            Function func = funcs.next();
            DecompileResults results = decomp.decompileFunction(func, 30, getMonitor());
            if (results.decompileCompleted()) {
                pw.println("// Function: " + func.getName() + " @ " + func.getEntryPoint());
                pw.println(results.getDecompiledFunction().getC());
                pw.println("");
                count++;
            }
        }

        pw.close();
        decomp.dispose();
        println("Decompiled " + count + " functions to " + outPath);
    }
}
""")

    print(f"Running Ghidra headless analysis on {firmware_path}...")
    print(f"Project directory: {project_dir}")
    print("This may take a few minutes...\n")

    cmd = [
        HEADLESS,
        project_dir,
        project_name,
        "-import", firmware_path,
        "-processor", "ARM:LE:32:Cortex",
        "-cspec", "default",
        "-loader", "BinaryLoader",
        "-loader-baseAddr", "0x0",
        "-scriptPath", script_dir,
        "-postScript", "DecompileAll.java",
        "-overwrite",
        "-noanalysis",  # We'll run analysis explicitly
    ]

    # First import, then analyze
    cmd_import = [
        HEADLESS,
        project_dir,
        project_name,
        "-import", firmware_path,
        "-processor", "ARM:LE:32:Cortex",
        "-cspec", "default",
        "-loader", "BinaryLoader",
        "-loader-baseAddr", "0x0",
        "-overwrite",
    ]

    print("Step 1: Importing binary...")
    result = subprocess.run(cmd_import, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Import stderr:\n{result.stderr[-2000:]}")

    # Now run analysis + decompile script
    cmd_analyze = [
        HEADLESS,
        project_dir,
        project_name,
        "-process", os.path.basename(firmware_path),
        "-scriptPath", script_dir,
        "-postScript", "DecompileAll.java",
    ]

    print("Step 2: Analyzing and decompiling...")
    result = subprocess.run(cmd_analyze, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Analysis stderr:\n{result.stderr[-2000:]}")

    output_file = "/firmware/decompiled_output.c"
    if os.path.exists(output_file):
        size = os.path.getsize(output_file)
        print(f"\nDone! Decompiled output: {output_file} ({size/1024:.1f} KB)")
    else:
        print("\nDecompilation output not found. Check Ghidra logs above.")


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <firmware.bin>")
        sys.exit(1)
    run_ghidra(sys.argv[1])
