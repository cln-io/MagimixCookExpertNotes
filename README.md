# Magimix Cook Expert 18900
## Harware
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

## Software 

Based on the PIC16LF1826-I/SS it looks like there are 2 compilers
![image](https://user-images.githubusercontent.com/7887972/160502582-8c6a9c86-fc36-409c-aeee-a20574130154.png)

![image](https://user-images.githubusercontent.com/7887972/160502609-92e75526-267f-4406-82d5-682c80d9111a.png)

* XC8 compiler
* HI-TECH PICC
