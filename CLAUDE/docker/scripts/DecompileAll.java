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
        pw.println("// Auto-generated pseudocode");
        pw.println("// Processor: ARM Cortex-M3 (NXP LPC1788)");
        pw.println("");

        FunctionIterator funcs = currentProgram.getFunctionManager().getFunctions(true);
        int count = 0;
        while (funcs.hasNext()) {
            Function func = funcs.next();
            DecompileResults results = decomp.decompileFunction(func, 30, getMonitor());
            if (results.decompileCompleted()) {
                String decompiled = results.getDecompiledFunction().getC();
                if (decompiled != null && !decompiled.isEmpty()) {
                    pw.println("// ==========================================");
                    pw.println("// Function: " + func.getName());
                    pw.println("// Address:  " + func.getEntryPoint());
                    pw.println("// Size:     " + func.getBody().getNumAddresses() + " bytes");
                    pw.println("// ==========================================");
                    pw.println(decompiled);
                    pw.println("");
                    count++;
                }
            }
        }

        pw.close();
        decomp.dispose();
        println("Decompiled " + count + " functions to " + outPath);
    }
}
