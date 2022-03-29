Info

* https://community.st.com/s/question/0D50X00009XkhgTSAR/stm32-disassembler 
 >You can always call the boot loader from your own code using the standard entry point (SP/PC @  0x1FFFF000/0x1FFFF004)
>The Keil tools are capable of downloading the ROM via JTAG into a HEX file, and certainly capable to debugging/disassembling code directly in the ROM. Just change the PC to point inside the ROM, or jump to the code, while in the debugger.

* Keil version of RealView
* https://www.keil.com/download/docs/314.asp
* https://reverseengineering.stackexchange.com/questions/11650/how-can-i-decompile-an-arm-cortex-m0-hex-file-to-c


Trying stuff: 
* Loaded into onload disassembler  https://onlinedisassembler.com/odaweb/Jx8hQxL4/0
* > <yourarch>-objdump -b binary -xD file.bin
