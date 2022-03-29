# Magimix Cook Expert 18900

These are my notes in trying to understand how the Magimix Cook Expert works software / hardware wise.
Would love to understand how to control the hardware, the french version has a USB bluetooth dongle that you can insert in the USB port, I want to see if I can "upgrade" my non french version to the same bluetooth connectivity.

the firmware for the non bluetooth version, and bluetooth version are identical, so in theory, its possible?


## Hardware
### Strings on the control unit
* BL1175_MAIN
* 2014-11-14
* V:02
* 1638 
* E301544
* 94V-0
* HM-02
* IC500
* RU ( [Recognized Component Mark](https://en.wikipedia.org/wiki/UL_(safety_organization)) )
> The "Recognized Component Mark" is a type of quality mark issued by Underwriters Laboratories. It is placed on components which are intended to be part of a UL listed product, but which cannot bear the full UL logo themselves.[6] The general public does not ordinarily come across it, as it is borne on components which make up finished products.

![mainboard_right_up_corner](img/mainboard_right_up.jpeg)

### Strings on IC's

![image](https://user-images.githubusercontent.com/7887972/160485835-4447e43d-bca3-4e2a-b2e7-c30aa354c974.png)

#### IC (1) XLSEMI XL6001E1 62837 [( Identified as 400KHz 32V 2A Switching Current Boost LED Constant Current Driver )](datasheet/XLSEMI-XL6001E1.pdf) 
<img src="img/ic_1.jpeg" width="250px">

#### IC (2) PIC16F82 -1/SS 327 HW

<img src="img/ic_2_diffangle.jpeg" width="250px">

due marking, these are the options left which it can be

* PIC16F1826
* PIC16F1826T-I/SS
* [PIC16F1826-I/SS](datasheet/PIC16F1826.pdf)
* PIC16LF1826-I/SS (I don't think its the T, since that would show on the ic)


I'm fairly certain its this one

![image](https://user-images.githubusercontent.com/7887972/160498890-8954de9e-390c-4721-9eb0-8caa65523c12.png)



#### IC (3) 6757 3S26 M-L ( does this say 3526 M-L? this could be a [LM3526 Dual Port USB Power Switch and Over-Current Protection](datasheet/lm3526.pdf )
<img src="img/ic_3.jpeg" width="250px">

## To investigate:
What controls that giant display then?
Is this something I overlooked?
When I google the firmware filename lpc1788.bin, I come across NXP - LPC1788 microcontroller with LCD Graphics Controller, is this hidden under the display plate? (its on a big raiser)

## Software 

Based on the PIC16LF1826-I/SS it looks like there are 2 compilers

![image](https://user-images.githubusercontent.com/7887972/160502582-8c6a9c86-fc36-409c-aeee-a20574130154.png)

![image](https://user-images.githubusercontent.com/7887972/160502609-92e75526-267f-4406-82d5-682c80d9111a.png)

* XC8 compiler
* HI-TECH PICC
### Version 2.01S
#### [flash.bin](https://web.archive.org/web/20220328234253/https://www.magimix.be/files/ope_smart/flash.bin) ( IPFS QmQbvSE9QcdJZjWrYR1725nyrUUioMi51nixRzzSp277M5 )
* MD5	ea4f67872a67aaf16435360c8c5d7a75
* SHA-1	213d984924dadfbf8a704f33e7749b171ad203fc
* SHA-256	b931c9b3506dd288e03453c1e5e66b5eb94df6b90dd15e566deaa02ea3038e43
* SSDEEP	6144:Rqz6Jn/syKVgEf4lrT5KTf5Z8PVYw2+Z+x1:RLblrl9Vc1

#### [lpc1788.bin](https://web.archive.org/web/20220328234107/https://www.magimix.be/files/ope_smart/lpc1788.bin) ( IPFS QmVY3NxQ3sMiL98QBqFQ9tcbwcr75BWPdHw7cBWAz1rLP1 )
* MD5	9f6df216e6452656ce91be420473119b
* SHA-1	14eb7f05b237c4e2133d4dd51078e01f4a4cb8df
* SHA-256	4db01a4c95e2a51debb7a7ec143a58106a5863352442fa717c908cf9331aa4ea
* SSDEEP	1536:Z4ZV6CLFrXtgbhhEJQ2o/Nj2GVSysAvbDOM1XcAI:2V1pXtghGK2Mj7Y6/OMWD


### Version 4.00F
#### [flash.bin](https://web.archive.org/web/20220327122823/https://fr.dev-magimix.com/upload/maj40/flash.bin) ( IPFS QmfRuQrCgV6RjxYAPxqccaw6TaBenk3bwcGBkaFFoFpVdE )
* MD5	a5576c9f1ebde4ecaf42ae0d9cad723a
* SHA-1	caf8e7ac6a9ad957d497efedb1505747fe729acc
* SHA-256	b38fad98a4576a901df541d39ed758e32134734fca32c4d15c1f5042bb80fb4e
* SSDEEP	12288:JEOnJEhgmzaZDO06eJgVVSYm4wbSZZrok:tG7z5GgVVSYm4CWb
* TLSH	T18725D614FE42E811C47552B5CCAA8FC8012AAD058E37584770FBF36E67B560BF91AF98

#### [lpc1788.bin](https://web.archive.org/web/20220327122830/https://fr.dev-magimix.com/upload/maj40/lpc1788.bin) ( IPFS QmNsNzDbr6DtL8szfBft1goSNK2KWmq4HrkHurSsibsx7d )
* MD5	92a4b7c42ec2d8890a6c5e162dba1f48
* SHA-1	fcc721d214b6c4e379f630801109b20817b8fa07
* SHA-256	450543f9740f31126fa2caf3f2a1d4affb62cdf038c817eab9c9a75e53dfc151
* SSDEEP	3072:r6m9WLKWCJNV1CM8lmqW7QRfkj6Tcx7+/OMYfoLuU/IQBHsZHPf:mmJ1TV1CMEvW7Qci4oOMEunBkPf
* TLSH	T1B924858F7749728FC818873484A6C3B0B9723C747A61C9927F916B1F9DB5280EF12679


