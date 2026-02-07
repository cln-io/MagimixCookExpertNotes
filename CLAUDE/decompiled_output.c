// Ghidra Decompiled Output - Magimix Cook Expert LPC1788 Firmware
// Auto-generated pseudocode
// Processor: ARM Cortex-M3 (NXP LPC1788)

// ==========================================
// Function: FUN_00000198
// Address:  00000198
// Size:     154 bytes
// ==========================================

undefined4 FUN_00000198(int *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  if ((param_2 != 100) && (param_2 != 0x75)) {
    if (param_2 == 0x73) {
      if (param_1[5] == 0) {
        FUN_0000c646(param_1,*param_3,0xffffffff);
      }
      return 1;
    }
    return 0;
  }
  uVar3 = 0;
  uVar1 = *param_3;
  puVar4 = (undefined *)0xc700;
  if (param_2 != 0x75) {
    if ((int)uVar1 < 0) {
      uVar1 = -uVar1;
      puVar4 = &DAT_0000c704;
    }
    else if (*param_1 << 0x1e < 0) {
      puVar4 = (undefined *)0xc708;
    }
    else {
      if (-1 < *param_1 << 0x1d) goto LAB_0000c6d0;
      puVar4 = (undefined *)0xc70c;
    }
    uVar3 = 1;
  }
LAB_0000c6d0:
  iVar2 = 0;
  for (; uVar1 != 0; uVar1 = uVar1 / 10) {
    *(char *)((int)param_1 + iVar2 + 0x24) = (char)uVar1 + (char)(uVar1 / 10) * -10 + '0';
    iVar2 = iVar2 + 1;
  }
  uVar3 = FUN_0000c9d4(param_1,iVar2,puVar4,uVar3);
  return uVar3;
}



// ==========================================
// Function: FUN_000001b2
// Address:  000001b2
// Size:     4 bytes
// ==========================================

void FUN_000001b2(void)

{
  return;
}



// ==========================================
// Function: FUN_00000200
// Address:  00000200
// Size:     18 bytes
// ==========================================

void FUN_00000200(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & ~(1 << (param_2 & 0xff));
  return;
}



// ==========================================
// Function: FUN_00000212
// Address:  00000212
// Size:     76 bytes
// ==========================================

void FUN_00000212(void)

{
  FUN_00009832(DAT_00000618,0,DAT_00000614,3);
  FUN_00009832(DAT_00000620,0,DAT_0000061c,7);
  FUN_00009832(DAT_00000628,0,DAT_00000624,5);
  FUN_00009832(DAT_00000630,0,DAT_0000062c,4);
  FUN_00009832(DAT_00000638,0,DAT_00000634,8);
  return;
}



// ==========================================
// Function: FUN_0000025e
// Address:  0000025e
// Size:     86 bytes
// ==========================================

void FUN_0000025e(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined local_24;
  undefined auStack_23 [22];
  undefined local_d;
  undefined local_c;
  undefined local_b;
  
  FUN_00007080(0);
  local_24 = 0x30;
  for (uVar2 = 0; uVar2 < 0x16; uVar2 = uVar2 + 1 & 0xffff) {
    auStack_23[uVar2] = *(undefined *)(DAT_0000063c + uVar2);
  }
  local_d = 0x4f;
  uVar1 = FUN_00007118(&local_24,0xe,1);
  local_c = (undefined)((ushort)uVar1 >> 8);
  local_b = (undefined)uVar1;
  FUN_00006e9c(0,0,&local_24,0,0x1a);
  return;
}



// ==========================================
// Function: FUN_000002b4
// Address:  000002b4
// Size:     52 bytes
// ==========================================

void FUN_000002b4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00007080(2);
  uVar2 = FUN_00007118(DAT_00000640,0x34,4);
  iVar1 = DAT_00000640;
  *(undefined4 *)(DAT_00000640 + 0xd0) = DAT_00000644;
  *(undefined4 *)(iVar1 + 0xd4) = uVar2;
  FUN_00006e9c(0,4,iVar1,0,0xd8);
  return;
}



// ==========================================
// Function: FUN_000002e8
// Address:  000002e8
// Size:     656 bytes
// ==========================================

void FUN_000002e8(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined auStack_104 [8];
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  char local_2c;
  undefined auStack_2b [22];
  char local_15;
  undefined local_14;
  undefined local_13;
  
  FUN_00007080(0);
  FUN_00006f72(0,0,&local_2c,0,0x1a);
  sVar1 = FUN_00007118(&local_2c,0xe,1);
  iVar2 = DAT_0000063c;
  if (((local_2c == '0') && (local_15 == 'O')) && (CONCAT11(local_14,local_13) == sVar1)) {
    for (uVar3 = 0; uVar3 < 0x16; uVar3 = uVar3 + 1 & 0xff) {
      *(undefined *)(DAT_0000063c + uVar3) = auStack_2b[uVar3];
    }
  }
  else {
    *(undefined *)(DAT_0000063c + 0xe) = 0;
    *(undefined *)(iVar2 + 10) = 0;
    *(undefined *)(iVar2 + 0xb) = 0;
    *(undefined *)(iVar2 + 1) = 0;
    *(undefined *)(iVar2 + 2) = 6;
    *(undefined *)(iVar2 + 3) = 0x70;
    *(undefined *)(iVar2 + 4) = 0;
    *(undefined *)(iVar2 + 5) = 0;
    *(undefined *)(iVar2 + 0xc) = 0;
    *(undefined *)(iVar2 + 9) = 4;
    *(undefined *)(iVar2 + 0xd) = 0;
    *(undefined *)(iVar2 + 6) = 0;
    *(undefined *)(iVar2 + 7) = 0;
    *(undefined *)(iVar2 + 0xf) = 0xff;
    *(undefined *)(iVar2 + 0x10) = 0;
    *(undefined *)(iVar2 + 0x11) = 0;
    *(undefined *)(iVar2 + 0x12) = 0;
    *(undefined *)(iVar2 + 0x13) = 0;
    *(undefined *)(iVar2 + 0x14) = 0;
    *(undefined *)(iVar2 + 0x15) = 0;
    FUN_0000025e();
    *DAT_00000648 = 0x1df;
    iVar2 = DAT_0000064c;
    *(undefined *)(DAT_0000064c + 4) = 0x1f;
    *(undefined *)(iVar2 + 7) = 0x77;
  }
  FUN_000070c8();
  FUN_00007080(2);
  FUN_0000c980(DAT_00000640,0xd8);
  FUN_00006f72(0,4,DAT_00000640,0,0xd8);
  iVar2 = FUN_00007118(DAT_00000640,0x34,4);
  if ((*(int *)(DAT_00000640 + 0xd0) != DAT_00000644) || (*(int *)(DAT_00000640 + 0xd4) != iVar2)) {
    FUN_000070c8();
    iVar2 = FUN_00007118(DAT_00000640,0x24,4);
    if ((*(int *)(DAT_00000640 + 0x90) == DAT_00000644) && (*(int *)(DAT_00000640 + 0x94) == iVar2))
    {
      FUN_0000c91c(auStack_104,DAT_00000640,0xd8);
      *(undefined4 *)(DAT_00000640 + 200) = local_7c;
      *(undefined4 *)(DAT_00000640 + 0xcc) = 0;
      *(undefined4 *)(DAT_00000640 + 0xc0) = local_84;
      *(undefined4 *)(DAT_00000640 + 0xc4) = local_80;
      *(undefined4 *)(DAT_00000640 + 0xb8) = local_8c;
      *(undefined4 *)(DAT_00000640 + 0xbc) = local_88;
      *(undefined4 *)(DAT_00000640 + 0xb0) = 0;
      *(undefined4 *)(DAT_00000640 + 0xb4) = 0;
      *(undefined4 *)(DAT_00000640 + 0xa8) = 0;
      *(undefined4 *)(DAT_00000640 + 0xac) = 0;
      *(undefined4 *)(DAT_00000640 + 0xa0) = 0;
      *(undefined4 *)(DAT_00000640 + 0xa4) = 0;
      *(undefined4 *)(DAT_00000640 + 0x98) = local_94;
      *(undefined4 *)(DAT_00000640 + 0x9c) = local_90;
      *(undefined4 *)(DAT_00000640 + 0x90) = local_9c;
      *(undefined4 *)(DAT_00000640 + 0x94) = local_98;
      *(undefined4 *)(DAT_00000640 + 0x88) = local_a4;
      *(undefined4 *)(DAT_00000640 + 0x8c) = local_a0;
      *(undefined4 *)(DAT_00000640 + 0x80) = local_ac;
      *(undefined4 *)(DAT_00000640 + 0x84) = local_a8;
      *(undefined4 *)(DAT_00000640 + 0x78) = local_b4;
      *(undefined4 *)(DAT_00000640 + 0x7c) = local_b0;
      *(undefined4 *)(DAT_00000640 + 0x70) = local_bc;
      *(undefined4 *)(DAT_00000640 + 0x74) = local_b8;
      *(undefined4 *)(DAT_00000640 + 0x68) = local_c4;
      *(undefined4 *)(DAT_00000640 + 0x6c) = local_c0;
      *(undefined4 *)(DAT_00000640 + 0x60) = 0;
      *(undefined4 *)(DAT_00000640 + 100) = 0;
      *(undefined4 *)(DAT_00000640 + 0x58) = 0;
      *(undefined4 *)(DAT_00000640 + 0x5c) = 0;
      *(undefined4 *)(DAT_00000640 + 0x50) = 0;
      *(undefined4 *)(DAT_00000640 + 0x54) = 0;
      *(undefined4 *)(DAT_00000640 + 0x48) = local_cc;
      *(undefined4 *)(DAT_00000640 + 0x4c) = local_c8;
      *(undefined4 *)(DAT_00000640 + 0x40) = local_d4;
      *(undefined4 *)(DAT_00000640 + 0x44) = local_d0;
      *(undefined4 *)(DAT_00000640 + 0x38) = local_dc;
      *(undefined4 *)(DAT_00000640 + 0x3c) = local_d8;
      *(undefined4 *)(DAT_00000640 + 0x30) = local_e4;
      *(undefined4 *)(DAT_00000640 + 0x34) = local_e0;
      *(undefined4 *)(DAT_00000640 + 0x28) = local_ec;
      *(undefined4 *)(DAT_00000640 + 0x2c) = local_e8;
      *(undefined4 *)(DAT_00000640 + 0x20) = local_f4;
      *(undefined4 *)(DAT_00000640 + 0x24) = local_f0;
      *(undefined4 *)(DAT_00000640 + 0x18) = local_fc;
      *(undefined4 *)(DAT_00000640 + 0x1c) = local_f8;
      *(undefined4 *)(DAT_00000640 + 0x10) = 0;
      *(undefined4 *)(DAT_00000640 + 0x14) = 0;
      *(undefined4 *)(DAT_00000640 + 8) = 0;
      *(undefined4 *)(DAT_00000640 + 0xc) = 0;
    }
    else {
      FUN_0000c980(DAT_00000640,0xd8);
    }
    FUN_000002b4();
  }
  return;
}



// ==========================================
// Function: FUN_00000578
// Address:  00000578
// Size:     164 bytes
// ==========================================

void FUN_00000578(void)

{
  undefined4 uVar1;
  
  FUN_00006582();
  FUN_000067c4();
  FUN_00006910(1);
  FUN_000066b8(0);
  FUN_0000a2b6(DAT_00000650);
  FUN_000069a0();
  FUN_00007168();
  FUN_000063c2();
  *(uint *)(DAT_00000654 + 0x7c) = *(uint *)(DAT_00000654 + 0x7c) & 0xfffffff8;
  FUN_00000200(DAT_00000658,0x1f);
  FUN_000062a6();
  FUN_00006e1c();
  FUN_000002e8();
  FUN_00001028();
  *DAT_00000660 = (uint)*(ushort *)(DAT_0000065c + (uint)*(byte *)(DAT_0000063c + 1) * 2) * 0x3c;
  FUN_00006206();
  uVar1 = FUN_00009432(0);
  *DAT_00000664 = uVar1;
  FUN_0000735a(DAT_00000668,&DAT_0001c200);
  FUN_000060ce();
  if (*(char *)(DAT_0000063c + 0xd) != '\0') {
    FUN_0000bb0c();
    FUN_00006418(1);
    FUN_00009cc0(500);
  }
  FUN_00000212();
  FUN_000098c6(0xff);
  return;
}



// ==========================================
// Function: FUN_00000674
// Address:  00000674
// Size:     72 bytes
// ==========================================

void FUN_00000674(void)

{
  if (((*DAT_00000a70 == '\b') && ((*(ushort *)(DAT_00000a74 + 0x10) & 0x200) != 0)) ||
     ((*DAT_00000a70 != '\b' &&
      ((*DAT_00000a70 != '\x05' && ((*(ushort *)(DAT_00000a74 + 0x10) & 0x200) == 0)))))) {
    *DAT_00000a78 = *DAT_00000a78 | 8;
  }
  else {
    *DAT_00000a78 = *DAT_00000a78 & 0xf7;
  }
  return;
}



// ==========================================
// Function: FUN_000006bc
// Address:  000006bc
// Size:     136 bytes
// ==========================================

void FUN_000006bc(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if ((*(byte *)(DAT_00000a7c + 5) & 0x40) == 0) {
    if ((*(ushort *)(DAT_00000a74 + 0x10) & 0x200) == 0) {
      if (*DAT_00000a70 == '\b') {
        return;
      }
      *DAT_00000a80 = 0x17;
      *DAT_00000a70 = '\b';
      *DAT_00000a84 = 3;
    }
    else {
      if (*DAT_00000a70 != '\b') {
        return;
      }
      *DAT_00000a70 = '\x03';
      *DAT_00000a80 = 3;
      *DAT_00000a84 = 1;
    }
    FUN_0000223e();
    uVar2 = FUN_0000cb64();
    puVar1 = DAT_00000a8c;
    puVar3 = (undefined4 *)(DAT_00000a88 + (uint)*DAT_00000a80 * 10);
    *DAT_00000a8c = *puVar3;
    puVar1[1] = puVar3[1];
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(puVar3 + 2);
    FUN_0000cb6c(uVar2);
    FUN_0000bf64(1);
  }
  return;
}



// ==========================================
// Function: FUN_00000744
// Address:  00000744
// Size:     64 bytes
// ==========================================

void FUN_00000744(void)

{
  *DAT_00000a78 = *DAT_00000a78 & 0xe6;
  FUN_00000674();
  if ((*(ushort *)(DAT_00000a74 + 0x20) & 0xc00) != 0) {
    *DAT_00000a78 = *DAT_00000a78 | 0x10;
  }
  if ((*(ushort *)(DAT_00000a74 + 0x30) & 0x1000) == 0) {
    *DAT_00000a78 = *DAT_00000a78 | 1;
  }
  return;
}



// ==========================================
// Function: FUN_00000784
// Address:  00000784
// Size:     20 bytes
// ==========================================

void FUN_00000784(undefined4 param_1)

{
  (**(code **)(DAT_00000a90 + (uint)*DAT_00000a94 * 4))(param_1);
  return;
}



// ==========================================
// Function: FUN_00000798
// Address:  00000798
// Size:     20 bytes
// ==========================================

void FUN_00000798(undefined4 param_1)

{
  (**(code **)(DAT_00000a98 + (uint)*DAT_00000a94 * 4))(param_1);
  return;
}



// ==========================================
// Function: FUN_000007ac
// Address:  000007ac
// Size:     134 bytes
// ==========================================

undefined4 FUN_000007ac(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    param_1[3] = 0;
    if (*param_1 != 0) {
      *(undefined *)(param_1 + 2) = 1;
    }
  }
  else if (cVar1 == '\x01') {
    if (param_1[1] == *param_1) {
      *(undefined *)(param_1 + 2) = 2;
    }
    else {
      *(undefined *)(param_1 + 2) = 0;
    }
  }
  else if (cVar1 == '\x02') {
    if (*param_1 == param_1[1]) {
      *(undefined *)(param_1 + 2) = 3;
      iVar2 = FUN_00000798(param_1);
      if (iVar2 != 0) {
        *(undefined *)(param_1 + 2) = 2;
        param_1[3] = param_1[3] + 1;
        return 1;
      }
    }
    else {
      *(undefined *)(param_1 + 2) = 0;
    }
  }
  else if (((cVar1 == '\x03') && (*param_1 != param_1[1])) && (*param_1 == 0)) {
    *(undefined *)(param_1 + 2) = 0;
    FUN_00000784(param_1);
    return 1;
  }
  if (*(char *)(param_1 + 2) != '\x03') {
    param_1[1] = *param_1;
  }
  return 0;
}



// ==========================================
// Function: FUN_0000083a
// Address:  0000083a
// Size:     478 bytes
// ==========================================

undefined FUN_0000083a(int *param_1)

{
  char cVar1;
  undefined uVar2;
  int iVar3;
  
  if (param_1[3] == 6) {
    switch(*DAT_00000a84) {
    default:
      uVar2 = 1;
      break;
    case '\x01':
    case '\x02':
    case '\x06':
      *DAT_00000aa0 = (uint)*(ushort *)(DAT_00000a9c + (uint)*(byte *)(DAT_00000a7c + 1) * 2) * 0x3c
      ;
      *DAT_00000aa4 = *param_1 + 0x800;
      FUN_000096c6(*DAT_00000aa8);
      iVar3 = *param_1;
      if (((iVar3 == 4) || (iVar3 == 8)) || (iVar3 == 0x40)) {
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
      break;
    case '\x03':
    case '\x04':
    case '\x05':
    case '\a':
      *DAT_00000aa0 = (uint)*(ushort *)(DAT_00000a9c + (uint)*(byte *)(DAT_00000a7c + 1) * 2) * 0x3c
      ;
      if ((*DAT_00000a78 & 0x10) == 0) {
        *DAT_00000aa4 = *param_1 + 0x800;
        FUN_000096c6(*DAT_00000aa8);
      }
      else {
        *DAT_00000a78 = *DAT_00000a78 & 0xef;
        FUN_0000149e();
      }
      iVar3 = *param_1;
      if (iVar3 != 8) {
        if (iVar3 < 9) {
          if (iVar3 == 1) {
LAB_00000910:
            if ((*(char *)(DAT_00000a7c + 7) != '\0') && (*DAT_00000aac == '\x01')) {
              return 1;
            }
            return 0;
          }
          if (iVar3 != 4) {
            return 0;
          }
        }
        else if (iVar3 != 0x40) {
          if (iVar3 != 0x80) {
            return 0;
          }
          goto LAB_00000910;
        }
      }
      uVar2 = 1;
    }
    return uVar2;
  }
  cVar1 = *DAT_00000a84;
  if (cVar1 == '\0') {
    if ((param_1[3] == 100) && (*param_1 == 1)) {
      *DAT_00000a84 = '\x01';
      FUN_00001028();
      FUN_000062f6(*DAT_00000ab0);
      *DAT_00000aa0 = (uint)*(ushort *)(DAT_00000a9c + (uint)*(byte *)(DAT_00000a7c + 1) * 2) * 0x3c
      ;
      FUN_0000bf64(1);
    }
  }
  else if ((((cVar1 == '\x03') || (cVar1 == '\x04')) || (cVar1 == '\x05')) && (param_1[3] == 100)) {
    iVar3 = *param_1;
    if (iVar3 != 1) {
      if ((iVar3 == 4) || (iVar3 == 8)) {
        cVar1 = *DAT_00000ab4;
        if ((cVar1 == '\x01') || ((cVar1 == '\x02' || (cVar1 == '\x04')))) {
          param_1[3] = 0x60;
          *DAT_00000aa4 = *param_1 + 0x800;
          *DAT_00000aa0 =
               (uint)*(ushort *)(DAT_00000a9c + (uint)*(byte *)(DAT_00000a7c + 1) * 2) * 0x3c;
          *DAT_00000ab8 = (*DAT_00000ab8 & 0xfffb) + 4;
          FUN_000096c6(*DAT_00000aa8,DAT_00000aa4);
        }
        goto code_r0x00000a26;
      }
      if (iVar3 != 0x80) goto code_r0x00000a26;
    }
    if ((*(char *)(DAT_00000a7c + 7) != '\0') && (*DAT_00000aac == '\x01')) {
      *DAT_00000aac = '\x02';
      FUN_00001316();
    }
  }
code_r0x00000a26:
  if ((param_1[3] == 0x96) && (*param_1 == 0x40)) {
    *DAT_00000aa4 = 0x8fe;
    FUN_000096c6(*DAT_00000aa8);
  }
  return 1;
}



// ==========================================
// Function: FUN_00000a46
// Address:  00000a46
// Size:     80 bytes
// ==========================================

undefined4 FUN_00000a46(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*DAT_00000a70 == '\x05') {
    if (*DAT_00000a84 != '\x05') {
      if (*DAT_00000a84 != '\a') {
        return 0;
      }
      if (*DAT_00000a78 == '\b') {
        *DAT_00000a78 = '\0';
        FUN_0000149e();
      }
    }
    *DAT_00000e20 = (uint)*(ushort *)(DAT_00000e1c + (uint)*(byte *)(DAT_00000e18 + 1) * 2) * 0x3c;
    uVar1 = 1;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00000ae2
// Address:  00000ae2
// Size:     42 bytes
// ==========================================

undefined4 FUN_00000ae2(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0xc) == 6) && (2 < *DAT_00000e24)) {
    *DAT_00000e28 = *DAT_00000e28 | 0x10;
    FUN_0000149e();
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00000b0c
// Address:  00000b0c
// Size:     276 bytes
// ==========================================

undefined4 FUN_00000b0c(int param_1)

{
  if (*(int *)(param_1 + 0xc) != 6) {
    return 1;
  }
  *DAT_00000e20 = (uint)*(ushort *)(DAT_00000e1c + (uint)*(byte *)(DAT_00000e18 + 1) * 2) * 0x3c;
  switch(*DAT_00000e24) {
  case 0:
    if ((1 < *DAT_00000e2c) && ((*(byte *)(DAT_00000e18 + 5) & 0x40) == 0)) {
      if ((*(ushort *)(DAT_00000e30 + 0x10) & 0x200) == 0) {
        if (*DAT_00000e2c != 8) {
          *DAT_00000e2c = 8;
        }
      }
      else if (*DAT_00000e2c == 8) {
        *DAT_00000e2c = 4;
      }
    }
    break;
  case 2:
    if (*DAT_00000e2c < 2) {
      return 0;
    }
    if ((*(byte *)(DAT_00000e18 + 5) & 0x40) != 0) {
      return 0;
    }
    if ((*(ushort *)(DAT_00000e30 + 0x10) & 0x200) == 0) {
      *DAT_00000e24 = 1;
    }
  case 1:
    if ((*(byte *)(DAT_00000e18 + 5) & 0x40) == 0) {
      if ((*(ushort *)(DAT_00000e30 + 0x10) & 0x200) == 0) {
        if (*DAT_00000e2c != 8) {
          *DAT_00000e2c = 8;
          FUN_0000bf64(1);
        }
      }
      else if (*DAT_00000e2c == 8) {
        *DAT_00000e2c = 4;
        FUN_0000bf64(1);
      }
    }
    break;
  case 5:
  case 6:
    goto switchD_00000b32_caseD_6;
  case 7:
    *DAT_00000e28 = *DAT_00000e28 & 0xf6;
    FUN_0000149e();
    if (*DAT_00000e28 != 0) {
      return 0;
    }
  case 3:
    if ((1 < *DAT_00000e2c) && ((*(byte *)(DAT_00000e18 + 5) & 0x40) == 0)) {
switchD_00000b32_caseD_6:
      FUN_000006bc();
    }
  }
  return 0;
}



// ==========================================
// Function: FUN_00000c2a
// Address:  00000c2a
// Size:     158 bytes
// ==========================================

void FUN_00000c2a(byte *param_1)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = *DAT_00000e24;
  if (cVar1 == '\x03') {
    if ((((*DAT_00000e2c == '\0') && (*(char *)(DAT_00000e34 + 5) == '\f')) &&
        (*(int *)(param_1 + 4) == 0x18)) && ((*param_1 & 0x18) != 0x18)) {
      *DAT_00000e38 = 0x8fb;
      FUN_000096c6(*DAT_00000e3c);
      return;
    }
  }
  else if (((cVar1 != '\x04') && (cVar1 != '\x05')) && (cVar1 != '\a')) {
    return;
  }
  if (*(int *)(param_1 + 4) == 0x100) {
    if ((int)((uint)*DAT_00000e40 << 0x1a) < 0) {
      bVar2 = *(byte *)(DAT_00000e44 + 1);
    }
    else {
      bVar2 = FUN_00001142();
    }
    if ((bVar2 & 8) != 0) {
      *DAT_00000e20 = (uint)*(ushort *)(DAT_00000e1c + (uint)*(byte *)(DAT_00000e18 + 1) * 2) * 0x3c
      ;
      *DAT_00000e38 = 0x8ff;
      FUN_000096c6(*DAT_00000e3c);
    }
  }
  return;
}



// ==========================================
// Function: FUN_00000cc8
// Address:  00000cc8
// Size:     58 bytes
// ==========================================

void FUN_00000cc8(void)

{
  if ((*DAT_00000e2c == '\x05') && (*DAT_00000e24 == '\x04')) {
    *DAT_00000e20 = (uint)*(ushort *)(DAT_00000e1c + (uint)*(byte *)(DAT_00000e18 + 1) * 2) * 0x3c;
    *DAT_00000e38 = 0x840;
    FUN_000096c6(*DAT_00000e3c);
  }
  return;
}



// ==========================================
// Function: FUN_00000d02
// Address:  00000d02
// Size:     44 bytes
// ==========================================

void FUN_00000d02(void)

{
  if ((*DAT_00000e24 == '\a') && ((*DAT_00000e28 & 0x10) != 0)) {
    *DAT_00000e28 = *DAT_00000e28 & 0xef;
    FUN_0000149e();
    FUN_0000120c();
  }
  return;
}



// ==========================================
// Function: FUN_00000d2e
// Address:  00000d2e
// Size:     30 bytes
// ==========================================

void FUN_00000d2e(void)

{
  if (*DAT_00000e24 == '\x04') {
    *DAT_00000e28 = *DAT_00000e28 | 1;
    FUN_0000149e();
  }
  return;
}



// ==========================================
// Function: FUN_00000d4c
// Address:  00000d4c
// Size:     72 bytes
// ==========================================

void FUN_00000d4c(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = DAT_00000e30;
  uVar3 = 0;
  for (uVar2 = 0; uVar2 < 0xd; uVar2 = uVar2 + 1 & 0xff) {
    if ((*(uint *)(*(int *)(DAT_00000e4c + uVar2 * 8) + 0x14) &
        *(uint *)(DAT_00000e4c + uVar2 * 8 + 4)) == 0) {
      uVar3 = uVar3 | 1 << uVar2;
    }
  }
  *DAT_00000e30 = uVar3 & 0x1ff;
  puVar1[4] = uVar3 & 0x200;
  puVar1[8] = uVar3 & 0xc00;
  puVar1[0xc] = uVar3 & 0x1000;
  return;
}



// ==========================================
// Function: FUN_00000e58
// Address:  00000e58
// Size:     24 bytes
// ==========================================

char FUN_00000e58(uint param_1)

{
  return *(char *)(DAT_00001240 + ((int)param_1 >> 4)) + *(char *)(DAT_00001240 + (param_1 & 0xf));
}



// ==========================================
// Function: FUN_00000e70
// Address:  00000e70
// Size:     16 bytes
// ==========================================

undefined4 FUN_00000e70(void)

{
  undefined4 uVar1;
  
  if (*(char *)(DAT_00001244 + 4) == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffff;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00000e80
// Address:  00000e80
// Size:     16 bytes
// ==========================================

uint FUN_00000e80(uint param_1)

{
  if (*(char *)(DAT_00001244 + 4) == '\x01') {
    param_1 = param_1 ^ 0xffffff;
  }
  return param_1;
}



// ==========================================
// Function: FUN_00000e90
// Address:  00000e90
// Size:     86 bytes
// ==========================================

void FUN_00000e90(void)

{
  int *piVar1;
  
  *DAT_0000124c = DAT_00001248;
  FUN_0000c91c(*DAT_0000124c + 8,DAT_00001250,0x28);
  *(undefined2 *)(*DAT_0000124c + 4) = 0xbe;
  *(undefined4 *)(*DAT_0000124c + 0x10) = 0xff0000;
  piVar1 = DAT_00001258;
  *DAT_00001258 = DAT_00001254;
  *(undefined *)(*piVar1 + 1) = 0;
  FUN_0000c91c(*DAT_00001258 + 8,DAT_0000125c,0x28);
  *(undefined2 *)(*DAT_00001258 + 4) = 0xf2;
  *(undefined4 *)(*DAT_00001258 + 0x10) = 0xffffff;
  return;
}



// ==========================================
// Function: FUN_00000ee6
// Address:  00000ee6
// Size:     12 bytes
// ==========================================

void FUN_00000ee6(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_00001260;
  *DAT_00001260 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  return;
}



// ==========================================
// Function: FUN_00000ef2
// Address:  00000ef2
// Size:     40 bytes
// ==========================================

void FUN_00000ef2(void)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_00001264;
  *DAT_00001264 = 0x8c;
  puVar1[1] = 0x52;
  *(undefined *)(puVar1 + 3) = 0xe;
  *(undefined *)((int)puVar1 + 5) = 0;
  *(undefined *)(puVar1 + 2) = 0;
  *(uint *)(DAT_00001264 + 4) = DAT_0000126c + (uint)*DAT_00001268 * 0x3c;
  return;
}



// ==========================================
// Function: FUN_00000f1a
// Address:  00000f1a
// Size:     18 bytes
// ==========================================

void FUN_00000f1a(void)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_00001270;
  *DAT_00001270 = 0x8c;
  puVar1[1] = 0x50;
  *(undefined *)((int)puVar1 + 5) = 0;
  *(undefined *)(puVar1 + 2) = 0;
  return;
}



// ==========================================
// Function: FUN_00000f2c
// Address:  00000f2c
// Size:     26 bytes
// ==========================================

void FUN_00000f2c(void)

{
  if ((*(byte *)(DAT_00001244 + 5) & 0x10) == 0) {
    *(undefined *)(DAT_00001274 + 4) = 0x1f;
  }
  else {
    *(undefined *)(DAT_00001274 + 4) = 0x3f;
  }
  return;
}



// ==========================================
// Function: FUN_00000f46
// Address:  00000f46
// Size:     38 bytes
// ==========================================

void FUN_00000f46(void)

{
  if ((*(byte *)(DAT_00001244 + 5) & 0x20) == 0) {
    *(byte *)(DAT_00001274 + 7) = *(byte *)(DAT_00001274 + 7) & 0xf7;
  }
  else {
    *(byte *)(DAT_00001274 + 7) = *(byte *)(DAT_00001274 + 7) | 8;
  }
  return;
}



// ==========================================
// Function: FUN_00000f6c
// Address:  00000f6c
// Size:     34 bytes
// ==========================================

void FUN_00000f6c(void)

{
  if ((*(byte *)(DAT_00001244 + 5) & 0x40) == 0) {
    *DAT_00001278 = 0x1df;
  }
  else {
    *DAT_00001278 = 0x1ff;
  }
  return;
}



// ==========================================
// Function: FUN_00000f8e
// Address:  00000f8e
// Size:     26 bytes
// ==========================================

void FUN_00000f8e(void)

{
  *(byte *)(DAT_00001274 + 7) =
       *(byte *)(DAT_00001244 + 3) & 0x70 | *(byte *)(DAT_00001274 + 7) & 0xf;
  return;
}



// ==========================================
// Function: FUN_00000fa8
// Address:  00000fa8
// Size:     52 bytes
// ==========================================

undefined FUN_00000fa8(int param_1,char param_2)

{
  undefined uVar1;
  uint uVar2;
  char cVar3;
  
  cVar3 = '\0';
  uVar1 = 0x18;
  if (0 < param_1) {
    for (uVar2 = 2; (int)uVar2 < param_1; uVar2 = uVar2 + 1 & 0xff) {
      cVar3 = *(char *)(DAT_0000127c + uVar2) + cVar3;
    }
    uVar1 = *(undefined *)(DAT_00001280 + (uint)(byte)(cVar3 + param_2) * 10 + 9);
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00000fdc
// Address:  00000fdc
// Size:     76 bytes
// ==========================================

void FUN_00000fdc(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar2 = FUN_00000fa8(*DAT_00001288,*DAT_00001284);
  if (iVar2 < 0x18) {
    *DAT_0000128c = (byte)iVar2;
    uVar3 = FUN_0000cb64();
    puVar1 = DAT_00001290;
    puVar4 = (undefined4 *)(DAT_00001280 + (uint)*DAT_0000128c * 10);
    *DAT_00001290 = *puVar4;
    puVar1[1] = puVar4[1];
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(puVar4 + 2);
    FUN_0000cb6c(uVar3);
    *DAT_00001294 = *(undefined *)((int)DAT_00001290 + 5);
  }
  return;
}



// ==========================================
// Function: FUN_00001028
// Address:  00001028
// Size:     282 bytes
// ==========================================

void FUN_00001028(void)

{
  byte bVar1;
  int iVar2;
  
  *DAT_00001298 = 0;
  *DAT_00001268 = *(byte *)(DAT_00001244 + 10) & 0xf;
  if ((*(char *)(DAT_00001244 + 6) == '\0') || (*DAT_0000129c == '\x01')) {
    if ((*(char *)(DAT_00001244 + 0xf) == -1) || (*(char *)(DAT_00001244 + 0xf) == '\0')) {
      *DAT_0000129c = '\x01';
      *DAT_00001288 = *(byte *)(DAT_00001244 + 9) & 0xf;
      *DAT_000012a0 = 0;
      *DAT_000012a4 = 0;
      FUN_0000223e();
    }
    else {
      *DAT_0000129c = *(char *)(DAT_00001244 + 0xf);
      *DAT_00001288 = *(byte *)(DAT_00001244 + 0x10);
      *DAT_00001284 = *(undefined *)(DAT_00001244 + 0x11);
      if ((*DAT_0000129c == '\x03') || (*DAT_0000129c == '\x06')) {
        FUN_00000fdc();
        iVar2 = DAT_00001290;
        *(ushort *)(DAT_00001290 + 6) =
             CONCAT11(*(undefined *)(DAT_00001244 + 0x12),*(undefined *)(DAT_00001244 + 0x13));
        *(undefined *)(iVar2 + 5) = *(undefined *)(DAT_00001244 + 0x14);
        *DAT_000012a8 = *(undefined *)(DAT_00001244 + 0xe);
        *(undefined *)(DAT_00001290 + 8) = *(undefined *)(DAT_00001244 + 0x15);
        bVar1 = *(byte *)(DAT_00001244 + 0xc);
        *DAT_00001298 = *DAT_00001298 & 0xffdf | (ushort)(bVar1 >> 7) << 5;
        *DAT_000012ac = (byte)(((uint)bVar1 << 0x1b) >> 0x1d);
        *DAT_000012b0 = bVar1 & 3;
      }
      *(undefined *)(DAT_00001244 + 0xf) = 0xff;
      FUN_0000025e();
    }
  }
  else {
    *DAT_0000129c = '\0';
  }
  *DAT_000012b4 = 0xff;
  *DAT_0000124c = DAT_00001248;
  *DAT_00001258 = DAT_00001254;
  *DAT_000012b8 = 1;
  *DAT_000012bc = 0;
  FUN_00000f2c();
  FUN_00000f46();
  FUN_00000f6c();
  FUN_00000f8e();
  FUN_00000ef2();
  FUN_00000f1a();
  FUN_00000e90();
  FUN_0000a39a();
  return;
}



// ==========================================
// Function: FUN_00001142
// Address:  00001142
// Size:     88 bytes
// ==========================================

byte FUN_00001142(void)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = *DAT_00001290;
  cVar1 = *DAT_0000128c;
  if (cVar1 == '\x05') {
    if (*(ushort *)(DAT_00001290 + 6) < 0x5a) {
      bVar2 = bVar2 & 0xfd;
    }
  }
  else if (cVar1 == '\x06') {
    if (*(ushort *)(DAT_00001290 + 6) < 0x3c) {
      bVar2 = bVar2 & 0xfd;
    }
  }
  else if ((((cVar1 == '\x11') && (*DAT_0000129c == '\x04')) &&
           (-1 < (int)((uint)*DAT_00001298 << 0x1a))) && (DAT_00001290[5] == 0xd)) {
    bVar2 = bVar2 & 0xf9;
  }
  return bVar2;
}



// ==========================================
// Function: FUN_0000119a
// Address:  0000119a
// Size:     58 bytes
// ==========================================

void FUN_0000119a(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  
  pbVar1 = DAT_00001294;
  if ((*DAT_000012c0 & 4) == 0) {
    *DAT_00001294 = 0;
    if (*DAT_00001288 == '\b') {
      uVar2 = *(undefined2 *)(DAT_000012c4 + (uint)*pbVar1 * 2);
    }
    else {
      uVar2 = *(undefined2 *)(DAT_000012c8 + (uint)*DAT_00001294 * 2);
    }
    *DAT_000012cc = uVar2;
    FUN_00004484(0xd5);
  }
  return;
}



// ==========================================
// Function: FUN_000011d4
// Address:  000011d4
// Size:     56 bytes
// ==========================================

void FUN_000011d4(void)

{
  undefined2 uVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_00001294;
  if ((*DAT_000012c0 & 4) == 0) {
    *DAT_00001294 = 0;
    if (*DAT_00001288 == '\b') {
      uVar1 = *(undefined2 *)(DAT_000012c4 + (uint)*pbVar2 * 2);
    }
    else {
      uVar1 = *(undefined2 *)(DAT_000012c8 + (uint)*DAT_00001294 * 2);
    }
    *DAT_000012cc = uVar1;
    FUN_00004450();
  }
  return;
}



// ==========================================
// Function: FUN_0000120c
// Address:  0000120c
// Size:     24 bytes
// ==========================================

void FUN_0000120c(void)

{
  FUN_0000638c(0);
  FUN_0000638c(4);
  FUN_0000119a();
  return;
}



// ==========================================
// Function: FUN_00001224
// Address:  00001224
// Size:     98 bytes
// ==========================================

bool FUN_00001224(void)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(char *)(DAT_00001244 + 7) != '\0') {
    cVar1 = *DAT_0000128c;
    if (cVar1 == '\x03') {
      if ((0xc < *(byte *)(DAT_000016cc + 5)) &&
         (((0x3c < *DAT_000016d0 || ((int)((uint)*DAT_000016d4 << 0x15) < 0)) ||
          (0x3c < *(byte *)(DAT_000016cc + 8))))) {
        bVar2 = true;
      }
    }
    else if (cVar1 == '\x05') {
      bVar2 = *(ushort *)(DAT_000016cc + 6) < 0x4c;
    }
    else if (cVar1 == '\x06') {
      bVar2 = *(ushort *)(DAT_000016cc + 6) < 0x1f;
    }
  }
  return bVar2;
}



// ==========================================
// Function: FUN_00001316
// Address:  00001316
// Size:     296 bytes
// ==========================================

undefined4 FUN_00001316(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  cVar1 = *DAT_000016d8;
  if (((cVar1 == '\x03') || (cVar1 == '\x05')) || (cVar1 == '\x06')) {
    cVar1 = *DAT_000016dc;
    if (cVar1 == '\0') {
      iVar2 = FUN_00001224();
      if (iVar2 != 0) {
        if ((*DAT_000016dc == '\0') && (*DAT_000016dc = '\x01', *DAT_000016e0 == '\x04')) {
          *DAT_000016e4 = 0x8f8;
          FUN_000096c6(*DAT_000016e8);
          uVar4 = 1;
        }
        uVar3 = FUN_00000e70();
        FUN_000066ee(0x1b2,0xc,0x2e,0x2e,uVar3);
        FUN_000062f6(*DAT_000016ec);
        FUN_0000c34e(DAT_000016f0,0x1ba,0x20,1,1);
        FUN_0000aea4(*DAT_000016fc,*(undefined4 *)(DAT_000016f4 + (uint)*DAT_000016f8 * 4));
      }
    }
    else if (cVar1 == '\x01') {
      iVar2 = FUN_00001224();
      if (iVar2 == 0) {
        uVar3 = FUN_00000e70();
        FUN_000066ee(0x1b2,0xc,0x2e,0x2e,uVar3);
        FUN_000062f6(*DAT_000016ec);
        FUN_0000ae5a(*DAT_000016fc);
        *DAT_000016dc = '\0';
      }
    }
    else if (cVar1 == '\x02') {
      uVar3 = FUN_00000e70();
      FUN_000066ee(0x1b2,0xc,0x2e,0x2e,uVar3);
      FUN_0000c34e(DAT_00001700,0x1ba,0x20,1,1);
      FUN_000062f6(*DAT_000016ec);
      FUN_0000ae5a(*DAT_000016fc);
      *DAT_000016dc = '\x03';
    }
  }
  return uVar4;
}



// ==========================================
// Function: FUN_0000144e
// Address:  0000144e
// Size:     80 bytes
// ==========================================

bool FUN_0000144e(void)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = false;
  if ((0xc < *DAT_00001708) && ((0x3c < *DAT_000016d0 || ((int)((uint)*DAT_000016d4 << 0x15) < 0))))
  {
    if (*(char *)(DAT_00001704 + 7) == '\0') {
      bVar2 = true;
    }
    else {
      cVar1 = *DAT_000016d8;
      if (((cVar1 == '\x03') || (cVar1 == '\x05')) || (cVar1 == '\x06')) {
        bVar2 = 1 < *DAT_000016dc;
      }
      else {
        bVar2 = true;
      }
    }
  }
  return bVar2;
}



// ==========================================
// Function: FUN_0000149e
// Address:  0000149e
// Size:     30 bytes
// ==========================================

/* WARNING: Switch with 1 destination removed at 0x000014b2 */

void FUN_0000149e(void)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  
  pcVar1 = pcRam00001718;
  if ((1 < *DAT_0000170c) && (*DAT_000016e0 - 3 < 5)) {
    if (*pbRam00001710 == 0) {
      cVar2 = -1;
    }
    else {
      cVar2 = *(char *)(iRam00001714 + (uint)*pbRam00001710);
    }
    *pcRam00001718 = cVar2;
    if (*pcVar1 == -1) {
      *(uint *)(iRam00001728 + 0x4c) = *(uint *)(iRam00001728 + 0x4c) & 0xffffefff;
      if (*pbRam0000171c == 4) {
        bVar3 = 5;
      }
      else {
        bVar3 = 3;
      }
      *DAT_000016e0 = bVar3;
      *(undefined *)(*piRam0000172c + 2) = 0;
      *DAT_000016e4 = 0x8fc;
      FUN_000096c6(*DAT_000016e8);
    }
    else {
      if ((*DAT_000016e0 != 7) && (*pbRam0000171c = *DAT_000016e0, (*DAT_000016d4 & 1) == 0)) {
        *puRam00001720 = *DAT_00001708;
      }
      if (*pbRam00001710 == 0x10) {
        FUN_0000119a();
      }
      else {
        FUN_0000120c();
      }
      if ((*pbRam00001710 & 1) == 0) {
        if ((*pbRam00001710 & 8) == 0) {
          *puRam00001724 = 0x78;
        }
        else {
          *puRam00001724 = 3;
        }
      }
      else {
        *puRam00001724 = 0;
      }
      *DAT_000016e4 = 0x8fd;
      FUN_000096c6(*DAT_000016e8);
    }
  }
  return;
}



// ==========================================
// Function: FUN_00001594
// Address:  00001594
// Size:     28 bytes
// ==========================================

void FUN_00001594(uint param_1,uint param_2)

{
  for (; ((int)param_1 < 0x10 && ((1 << (param_1 & 0xff) & param_2) == 0));
      param_1 = param_1 + 1 & 0xff) {
  }
  return;
}



// ==========================================
// Function: FUN_000015b0
// Address:  000015b0
// Size:     28 bytes
// ==========================================

void FUN_000015b0(uint param_1,uint param_2)

{
  for (; (0 < (int)param_1 && ((1 << (param_1 & 0xff) & param_2) == 0));
      param_1 = param_1 - 1 & 0xff) {
  }
  return;
}



// ==========================================
// Function: FUN_000015cc
// Address:  000015cc
// Size:     28 bytes
// ==========================================

uint FUN_000015cc(uint param_1)

{
  uint uVar1;
  
  for (uVar1 = 0xf; (uVar1 != 0 && ((1 << (uVar1 & 0xff) & param_1) == 0)); uVar1 = uVar1 - 1) {
  }
  return uVar1 & 0xff;
}



// ==========================================
// Function: FUN_000015e8
// Address:  000015e8
// Size:     50 bytes
// ==========================================

undefined4 FUN_000015e8(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar2 = FUN_000015cc(param_1);
  if (param_2 <= iVar2) {
    if (iVar2 == param_2) {
      cVar1 = '\0';
    }
    else {
      cVar1 = (char)param_2 + '\x01';
    }
    uVar3 = FUN_00001594(cVar1,param_1);
  }
  return uVar3;
}



// ==========================================
// Function: FUN_0000161a
// Address:  0000161a
// Size:     56 bytes
// ==========================================

undefined4 FUN_0000161a(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_00001594(0,param_1);
  if (iVar1 <= param_2) {
    if (iVar1 == param_2) {
      uVar2 = FUN_000015cc(param_1);
    }
    else {
      uVar2 = FUN_000015b0(param_2 - 1U & 0xff,param_1 & 0xff);
    }
  }
  return uVar2;
}



// ==========================================
// Function: FUN_00001670
// Address:  00001670
// Size:     142 bytes
// ==========================================

void FUN_00001670(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar3 = FUN_00000fa8(*DAT_0000170c,*DAT_00001730);
  if (iVar3 < 0x18) {
    *DAT_000016d8 = (byte)iVar3;
    uVar4 = FUN_0000cb64();
    puVar2 = DAT_000016cc;
    puVar5 = (undefined4 *)(DAT_00001734 + (uint)*DAT_000016d8 * 10);
    *DAT_000016cc = *puVar5;
    puVar2[1] = puVar5[1];
    *(undefined2 *)(puVar2 + 2) = *(undefined2 *)(puVar5 + 2);
    FUN_0000cb6c(uVar4);
    if (param_1 < 3) {
      if (*(char *)(DAT_00001738 + 5) != -1) {
        *(undefined *)((int)DAT_000016cc + 5) = *(undefined *)(DAT_00001738 + 5);
      }
      sVar1 = CONCAT11(*(undefined *)(DAT_000017f8 + 3),*(undefined *)(DAT_00001738 + 4));
      if (sVar1 != -1) {
        *(short *)(DAT_000017fc + 6) = sVar1;
      }
      if (*(char *)(DAT_000017f8 + 6) != -1) {
        *(undefined *)(DAT_000017fc + 8) = *(undefined *)(DAT_000017f8 + 6);
      }
    }
    *DAT_00001800 = *(undefined *)(DAT_000017fc + 5);
  }
  return;
}



// ==========================================
// Function: FUN_0000176e
// Address:  0000176e
// Size:     138 bytes
// ==========================================

uint FUN_0000176e(void)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = *DAT_00001804;
  if (bVar1 == 8) {
    return (uint)(*(char *)(DAT_000017fc + 5) == '\x04');
  }
  if (bVar1 < 9) {
    if ((bVar1 == 0) || (bVar1 == 1)) {
      if (*(char *)(DAT_000017fc + 5) != '\x0f') {
        return 0;
      }
      if ((int)((uint)*DAT_00001808 << 0x1a) < 0) {
        return 0;
      }
      return 1;
    }
  }
  else {
    if (bVar1 == 0x11) {
      if (*(char *)(DAT_000017fc + 5) != '\r') {
        return 0;
      }
      if ((int)((uint)*DAT_00001808 << 0x1a) < 0) {
        return 0;
      }
      return 1;
    }
    if (bVar1 == 0x17) {
      return (uint)(*(char *)(DAT_000017fc + 5) == '\r');
    }
  }
  if ((int)((uint)*DAT_00001808 << 0x1a) < 0) {
    bVar1 = *(byte *)(DAT_000017fc + 1);
  }
  else {
    bVar1 = FUN_00001142();
  }
  if ((bVar1 & 4) == 0) {
    uVar2 = 1;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_00001814
// Address:  00001814
// Size:     28 bytes
// ==========================================

void FUN_00001814(void)

{
  disableIRQinterrupts();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==========================================
// Function: FUN_00001830
// Address:  00001830
// Size:     278 bytes
// ==========================================

/* WARNING: Removing unreachable block (ram,0x00001850) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00001830(void)

{
  uint *puVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  int local_8;
  
  FUN_000063ac();
  *(undefined4 *)(DAT_00001bec + 8) = DAT_00001be8;
  *(undefined *)(DAT_00001bf0 + 0x26) = 8;
  _DAT_e000e104 = 0x40;
  *(undefined4 *)(DAT_00001bf4 + -8) = 4;
  *DAT_00001bf8 = 8;
  *(uint *)(DAT_00001bfc + 0x1cc) = *(uint *)(DAT_00001bfc + 0x1cc) & 0xfffffff8;
  puVar1 = DAT_00001c00;
  DAT_00001c00[0x18] = DAT_00001c00[0x18] | 0x80000;
  puVar1[0x1f] = 0x80000;
  FUN_00006418(3);
  *(uint *)(DAT_00001bfc + 8) = *(uint *)(DAT_00001bfc + 8) & 0xfffffff8;
  puVar1 = DAT_00001c00;
  *DAT_00001c00 = *DAT_00001c00 | 4;
  puVar1[7] = 4;
  *(uint *)(DAT_00001bfc + 0xc) = *(uint *)(DAT_00001bfc + 0xc) & 0xfffffff8;
  puVar1 = DAT_00001c00;
  *DAT_00001c00 = *DAT_00001c00 | 8;
  puVar1[7] = 8;
  *(uint *)(DAT_00001c04 + 0x20) = *(uint *)(DAT_00001c04 + 0x20) | 0x2000;
  for (local_8 = 6000; local_8 != 0; local_8 = local_8 + -1) {
  }
  WaitForInterrupt();
  UNRECOVERED_JUMPTABLE = (code *)0x1910;
  FUN_00001814();
  switch(*DAT_00001c08) {
  case 0:
  case 1:
  case 2:
  case 4:
  case 7:
  case 9:
    uVar2 = 0x28;
    break;
  case 3:
  case 0x10:
    uVar2 = 0x1d;
    break;
  case 5:
  case 6:
  case 8:
  case 10:
  case 0xb:
  case 0xc:
    uVar2 = 0x32;
    break;
  default:
    uVar2 = 0x14;
  }
                    /* WARNING: Could not recover jumptable at 0x00001956. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}



// ==========================================
// Function: FUN_00001958
// Address:  00001958
// Size:     72 bytes
// ==========================================

undefined4 FUN_00001958(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
  case 1:
  case 2:
    uVar1 = 0x3c;
    break;
  case 3:
  case 7:
    if (param_2 == 0) {
      uVar1 = 0x78;
    }
    else if (param_3 < 0x1c20) {
      uVar1 = 0x8c;
    }
    else {
      uVar1 = 0x78;
    }
    break;
  default:
    uVar1 = 0x8c;
    break;
  case 5:
  case 6:
  case 0xb:
    uVar1 = 0x78;
    break;
  case 8:
  case 10:
    uVar1 = 0xa0;
    break;
  case 0xc:
    uVar1 = 100;
    break;
  case 0x10:
    uVar1 = 0x6e;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_000019b2
// Address:  000019b2
// Size:     48 bytes
// ==========================================

void FUN_000019b2(void)

{
  if ((((*DAT_00001c08 == '\x03') || (*DAT_00001c08 == '\a')) &&
      (*(char *)(DAT_00001c0c + 5) == '\0')) && (0x78 < *(byte *)(DAT_00001c0c + 8))) {
    *(undefined *)(DAT_00001c0c + 8) = 0x78;
    FUN_00004912();
    FUN_0000ac28();
  }
  return;
}



// ==========================================
// Function: FUN_000019e2
// Address:  000019e2
// Size:     86 bytes
// ==========================================

void FUN_000019e2(void)

{
  undefined2 uVar1;
  
  if (*DAT_00001c10 == '\x04') {
    *DAT_00001c14 = 0;
    *DAT_00001c18 = (*DAT_00001c18 & 0xfffd) + 2;
    *DAT_00001c1c = *(byte *)(DAT_00001c0c + 5);
    FUN_00004912();
    if (*DAT_00001c20 == '\b') {
      uVar1 = *(undefined2 *)(DAT_00001c24 + (uint)*DAT_00001c1c * 2);
    }
    else {
      uVar1 = *(undefined2 *)(DAT_00001c28 + (uint)*DAT_00001c1c * 2);
    }
    *DAT_00001c2c = uVar1;
    FUN_00004450();
  }
  return;
}



// ==========================================
// Function: FUN_00001a38
// Address:  00001a38
// Size:     102 bytes
// ==========================================

void FUN_00001a38(void)

{
  ushort uVar1;
  byte bVar2;
  
  uVar1 = *(ushort *)(DAT_00001c0c + 6);
  bVar2 = *(byte *)(DAT_00001c0c + 5);
  if (uVar1 < 0x1c21) {
    if (uVar1 < 0x259) {
      if ((0xb4 < uVar1) && (0xd < bVar2)) {
        bVar2 = 0xd;
      }
    }
    else if (4 < bVar2) {
      bVar2 = 4;
    }
  }
  else if (1 < bVar2) {
    bVar2 = 1;
  }
  if (((*DAT_00001c08 == '\x11') && (*(char *)(DAT_00001c0c + 5) == '\r')) &&
     (-1 < (int)((uint)*DAT_00001c18 << 0x1a))) {
    bVar2 = 0xc;
  }
  if (*(byte *)(DAT_00001c0c + 5) != bVar2) {
    *(byte *)(DAT_00001c0c + 5) = bVar2;
    FUN_0000ada4();
    FUN_000019e2();
    if (bVar2 == 0) {
      FUN_000019b2();
    }
  }
  return;
}



// ==========================================
// Function: FUN_00001a9e
// Address:  00001a9e
// Size:     98 bytes
// ==========================================

void FUN_00001a9e(void)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = *(ushort *)(DAT_00001c0c + 6);
  bVar1 = *(byte *)(DAT_00001c0c + 5);
  if (bVar1 < 0xe) {
    if (bVar1 < 5) {
      if ((1 < bVar1) && (0x1c20 < uVar2)) {
        uVar2 = 0x1c20;
      }
    }
    else if (600 < uVar2) {
      uVar2 = 600;
    }
  }
  else if (0xb4 < uVar2) {
    uVar2 = 0xb4;
  }
  if (((*DAT_00001c08 == '\x11') && (*(char *)(DAT_00001c0c + 5) == '\r')) &&
     (-1 < (int)((uint)*DAT_00001c18 << 0x1a))) {
    uVar2 = 0x78;
  }
  if (*(ushort *)(DAT_00001c0c + 6) != uVar2) {
    *(ushort *)(DAT_00001c0c + 6) = uVar2;
    FUN_0000ab24(1);
  }
  return;
}



// ==========================================
// Function: FUN_00001b00
// Address:  00001b00
// Size:     42 bytes
// ==========================================

void FUN_00001b00(void)

{
  if ((0x1c1f < *(ushort *)(DAT_00001c0c + 6)) && (0x77 < *(byte *)(DAT_00001c0c + 8))) {
    *(undefined *)(DAT_00001c0c + 8) = 0x78;
    FUN_0000ac28();
    if (*DAT_00001c10 == '\x04') {
      FUN_00004912();
    }
  }
  return;
}



// ==========================================
// Function: FUN_00001b2a
// Address:  00001b2a
// Size:     42 bytes
// ==========================================

void FUN_00001b2a(int param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(DAT_00001c0c + 6) -
          param_1 * ((int)(uint)*(ushort *)(DAT_00001c0c + 6) / param_1);
  if ((uVar1 & 0xffff) == 0) {
    *(short *)(DAT_00001c0c + 6) = *(short *)(DAT_00001c0c + 6) + (short)param_1;
  }
  else {
    *(short *)(DAT_00001c0c + 6) = *(short *)(DAT_00001c0c + 6) + ((short)param_1 - (short)uVar1);
  }
  return;
}



// ==========================================
// Function: FUN_00001b54
// Address:  00001b54
// Size:     158 bytes
// ==========================================

undefined ** FUN_00001b54(int param_1,uint param_2)

{
  undefined **ppuVar1;
  
  if (param_2 == 0xff) {
    param_2 = ((uint)*DAT_00001c18 << 0x1a) >> 0x1f;
  }
  if (param_2 == 0) {
    switch(param_1) {
    case 0:
    case 1:
      ppuVar1 = (undefined **)0x3c;
      break;
    default:
      ppuVar1 = (undefined **)&DAT_00001c20;
      break;
    case 3:
    case 7:
    case 0xb:
      ppuVar1 = (undefined **)&DAT_00003840;
      break;
    case 8:
    case 10:
      ppuVar1 = (undefined **)0x384;
      break;
    case 0x10:
    case 0x13:
    case 0x14:
      ppuVar1 = (undefined **)0x258;
      break;
    case 0x11:
      ppuVar1 = (undefined **)0x258;
    }
  }
  else if (param_1 == 3) {
    ppuVar1 = (undefined **)&DAT_00003840;
  }
  else {
    if (param_1 < 4) {
      if (((param_1 == 0) || (param_1 == 1)) || (param_1 == 2)) {
        return &SysTick;
      }
    }
    else {
      if ((param_1 == 8) || (param_1 == 10)) {
        return (undefined **)0x384;
      }
      if (param_1 == 0x13) {
        return (undefined **)0x258;
      }
    }
    ppuVar1 = (undefined **)&DAT_00001c20;
  }
  return ppuVar1;
}



// ==========================================
// Function: FUN_00001c52
// Address:  00001c52
// Size:     58 bytes
// ==========================================

uint FUN_00001c52(void)

{
  byte bVar1;
  
  bVar1 = *DAT_00002038;
  if (bVar1 != 0xf) {
    if (bVar1 < 0x10) {
      if ((bVar1 != 0xd) && (bVar1 != 0xe)) {
        return 1;
      }
    }
    else if (bVar1 != 0x12) {
      if (bVar1 != 0x17) {
        return 1;
      }
      return 0;
    }
  }
  return ((uint)*DAT_0000203c << 0x1a) >> 0x1f;
}



// ==========================================
// Function: FUN_00001c8c
// Address:  00001c8c
// Size:     74 bytes
// ==========================================

undefined4 FUN_00001c8c(undefined4 param_1)

{
  if ((int)((uint)*DAT_0000203c << 0x1a) < 0) {
    param_1 = 0;
  }
  else {
    switch(*DAT_00002038) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 8:
    case 10:
    case 0xb:
    case 0xc:
    case 0x10:
    case 0x11:
    case 0x13:
    case 0x14:
    case 0x15:
      param_1 = 0;
      break;
    case 4:
    case 6:
    case 7:
    case 9:
      param_1 = 0x3c;
      break;
    case 5:
      param_1 = 0x5a;
    }
  }
  return param_1;
}



// ==========================================
// Function: FUN_00001cec
// Address:  00001cec
// Size:     18 bytes
// ==========================================

void FUN_00001cec(void)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = *(ushort *)(DAT_00002040 + 6);
  uVar3 = FUN_00001b54(*DAT_00002038,((uint)*DAT_0000203c << 0x1a) >> 0x1f);
  if (*(ushort *)(DAT_00002040 + 6) == uVar3) {
    if ((int)((uint)*DAT_0000203c << 0x1d) < 0) {
      *DAT_00002044 = 1;
    }
    else {
      iVar4 = FUN_00001c52();
      if (iVar4 == 0) {
        *(short *)(DAT_00002040 + 6) = (short)uVar3;
      }
      else {
        uVar2 = FUN_00001c8c();
        *(undefined2 *)(DAT_00002040 + 6) = uVar2;
      }
    }
  }
  else if (uVar1 < 0x3c) {
    FUN_00001b2a(5);
  }
  else if (uVar1 < 600) {
    FUN_00001b2a(0x1e);
  }
  else {
    FUN_00001b2a(0x3c);
  }
  return;
}



// ==========================================
// Function: FUN_0000223e
// Address:  0000223e
// Size:     138 bytes
// ==========================================

void FUN_0000223e(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  
  if ((int)((uint)*DAT_00002478 << 0x1a) < 0) {
    bVar3 = *(byte *)(DAT_0000247c + 1);
  }
  else {
    bVar3 = FUN_00001142();
  }
  if (-1 < (int)((uint)*DAT_00002478 << 0x1a)) {
    *DAT_00002474 = bVar3 & 2;
  }
  pbVar1 = DAT_00002474;
  if ((*DAT_00002488 == '\x06') && (*DAT_00002474 != 0)) {
    *DAT_00002470 = 2;
  }
  else {
    *DAT_00002474 = bVar3 & 2;
    pbVar2 = DAT_00002474;
    if (*pbVar1 == 0) {
      *DAT_00002474 = bVar3 & 4;
      pbVar1 = DAT_00002474;
      if (*pbVar2 == 0) {
        *DAT_00002474 = bVar3 & 1;
        if (*pbVar1 == 0) {
          *DAT_00002470 = 0;
        }
        else {
          *DAT_00002470 = 1;
        }
      }
      else {
        *DAT_00002470 = 3;
      }
    }
    else {
      *DAT_00002470 = 2;
    }
  }
  return;
}



// ==========================================
// Function: FUN_000022c8
// Address:  000022c8
// Size:     130 bytes
// ==========================================

void FUN_000022c8(void)

{
  char cVar1;
  
  cVar1 = *DAT_00002470;
  FUN_0000223e();
  if ((cVar1 != *DAT_00002470) && (*DAT_00002470 != '\0')) {
    if (cVar1 == '\x01') {
      FUN_0000ac28();
      FUN_0000b094();
    }
    else if (cVar1 == '\x02') {
      FUN_0000ab24(1);
      FUN_0000b210();
    }
    else if (cVar1 == '\x03') {
      FUN_0000ada4();
      FUN_0000b024();
    }
    cVar1 = *DAT_00002470;
    if (cVar1 == '\x01') {
      FUN_0000ac28();
      FUN_0000b094();
    }
    else if (cVar1 == '\x02') {
      FUN_0000ab24(1);
      FUN_0000b210();
    }
    else if (cVar1 == '\x03') {
      FUN_0000ada4();
      FUN_0000b024();
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000234a
// Address:  0000234a
// Size:     42 bytes
// ==========================================

void FUN_0000234a(void)

{
  if (*(char *)(DAT_00002498 + 0xd) == '\0') {
    *(undefined *)(DAT_00002498 + 1) = 0;
  }
  else {
    *(undefined *)(DAT_00002498 + 1) = 3;
  }
  *DAT_000024a0 = (uint)*(ushort *)(DAT_0000249c + (uint)*(byte *)(DAT_00002498 + 1) * 2) * 0x3c;
  return;
}



// ==========================================
// Function: FUN_00002374
// Address:  00002374
// Size:     24 bytes
// ==========================================

void FUN_00002374(void)

{
  FUN_0000ab24(*DAT_000024a4);
  *DAT_000024a4 = *DAT_000024a4 ^ 1;
  return;
}



// ==========================================
// Function: FUN_0000238c
// Address:  0000238c
// Size:     386 bytes
// ==========================================

void FUN_0000238c(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  
  piVar4 = DAT_000024a0;
  if (*DAT_000024a0 != 0) {
    *DAT_000024a0 = *DAT_000024a0 + -1;
    if (*piVar4 == 0) {
      FUN_00001830();
    }
    else if (*piVar4 != 1) {
      if (*(char *)(DAT_000028bc + 0xd) == '\0') {
        return;
      }
      uVar8 = (uint)*(ushort *)(DAT_000028c0 + (uint)*(byte *)(DAT_000028bc + 1) * 2) * 0x3c -
              *DAT_000028c4;
      if (uVar8 < 0x7e) {
        return;
      }
      if (uVar8 != (uVar8 / 5) * 5) {
        return;
      }
      *DAT_000028d0 = (1 << *(sbyte *)(DAT_000028c8 + *DAT_000028cc)) + 0x800;
      FUN_000096c6(*DAT_000028d4);
      puVar5 = DAT_000028cc;
      *DAT_000028cc = *DAT_000028cc + 1;
      if (*puVar5 < 0x14) {
        return;
      }
      *puVar5 = 0;
      return;
    }
    FUN_000073ea();
    FUN_00009b10(4);
    FUN_00004484(0xd6);
    bVar1 = *DAT_00002488;
    if (bVar1 == 5) {
      *DAT_00002488 = 3;
    }
    else if (bVar1 == 6) {
      uVar6 = FUN_0000cb64();
      puVar2 = DAT_0000247c;
      puVar7 = (undefined4 *)(DAT_000024a8 + (uint)*DAT_00002484 * 10);
      *DAT_0000247c = *puVar7;
      puVar2[1] = puVar7[1];
      *(undefined2 *)(puVar2 + 2) = *(undefined2 *)(puVar7 + 2);
      FUN_0000cb6c(uVar6);
      *DAT_00002478 = *DAT_00002478 & 0xffdf;
      *DAT_00002488 = 3;
    }
    else if (bVar1 == 7) {
      *DAT_00002488 = 1;
    }
    if ((*DAT_000024ac == '\0') && (2 < *DAT_00002488)) {
      *DAT_00002488 = 2;
    }
    else {
      *(undefined *)(DAT_00002498 + 0xe) = *DAT_00002494;
    }
    iVar3 = DAT_00002498;
    *(byte *)(DAT_00002498 + 0xf) = *DAT_00002488;
    *(char *)(iVar3 + 0x10) = *DAT_000024ac;
    *(undefined *)(iVar3 + 0x11) = *DAT_000024b0;
    *(char *)(iVar3 + 0x12) = (char)((ushort)*(undefined2 *)((int)DAT_0000247c + 6) >> 8);
    *(undefined *)(iVar3 + 0x13) = *(undefined *)((int)DAT_0000247c + 6);
    *(undefined *)(iVar3 + 0x14) = *(undefined *)((int)DAT_0000247c + 5);
    *(undefined *)(iVar3 + 0x15) = *(undefined *)(DAT_000028ac + 8);
    *(byte *)(DAT_000028bc + 0xc) =
         (*(byte *)DAT_000028b0 >> 5) << 7 | *DAT_000028b4 << 2 | *DAT_000028b8;
    FUN_0000025e();
    FUN_000002b4();
    *DAT_000028b0 = (*DAT_000028b0 & 0xff7f) + 0x80;
  }
  return;
}



// ==========================================
// Function: FUN_00002552
// Address:  00002552
// Size:     34 bytes
// ==========================================

void FUN_00002552(void)

{
  if (*DAT_000028d8 != *DAT_000028dc) {
    *DAT_000028dc = *DAT_000028d8;
    *DAT_000028e0 = 0;
    FUN_0000b094();
  }
  return;
}



// ==========================================
// Function: FUN_00002574
// Address:  00002574
// Size:     156 bytes
// ==========================================

void FUN_00002574(void)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = DAT_000028e8;
  if (((*(char *)(DAT_000028ac + 5) == '\x01') || (*(char *)(DAT_000028ac + 5) == '\x02')) ||
     ((*DAT_000028e4 == '\b' && (*(char *)(DAT_000028ac + 5) == '\x04')))) {
    uVar2 = (uint)*(byte *)(DAT_000028ac + 5);
    if ((*DAT_000028e4 == '\b') && (*(char *)(DAT_000028ac + 5) == '\x04')) {
      uVar2 = 3;
    }
    *DAT_000028e8 = *DAT_000028e8 + 1;
    if ((int)((uint)*(byte *)DAT_000028b0 << 0x1e) < 0) {
      if (*(byte *)(DAT_000028ec + uVar2 * 2) <= *pbVar1) {
        *DAT_000028e8 = 0;
        *DAT_000028f0 = 0;
        *DAT_000028b0 = *DAT_000028b0 & 0xfffd;
      }
    }
    else if (*(byte *)(DAT_000028ec + uVar2 * 2 + 1) <= *DAT_000028e8) {
      *DAT_000028e8 = 0;
      *DAT_000028f0 = 3;
      *DAT_000028b0 = (*DAT_000028b0 & 0xfffd) + 2;
    }
  }
  return;
}



// ==========================================
// Function: FUN_00002610
// Address:  00002610
// Size:     170 bytes
// ==========================================

void FUN_00002610(void)

{
  undefined2 uVar1;
  uint uVar2;
  
  if ((*DAT_000028f4 != 0) &&
     (((0xc < *(byte *)(DAT_000028ac + 5) &&
       ((0x3c < *DAT_000028f8 || ((int)((uint)*DAT_000028b0 << 0x15) < 0)))) ||
      ((*(byte *)DAT_000028b0 & 1) != 0)))) {
    *DAT_000028f4 = *DAT_000028f4 - 1;
    if ((*(byte *)DAT_000028b0 & 1) == 0) {
      uVar2 = (uint)*(byte *)(DAT_000028ac + 5);
    }
    else if (*DAT_000028e4 == '\x17') {
      uVar2 = 0xd;
    }
    else {
      uVar2 = 0x12;
    }
    if (*DAT_000028f4 == 0) {
      *DAT_000028f0 = (byte)uVar2;
    }
    else {
      *DAT_000028f0 = *(byte *)(DAT_000028fc + (uVar2 - 0xd) * 3 + (*DAT_000028f4 - 1));
    }
  }
  if (*DAT_00002900 == '\b') {
    uVar1 = *(undefined2 *)(DAT_00002904 + (uint)*DAT_000028f0 * 2);
  }
  else {
    uVar1 = *(undefined2 *)(DAT_00002908 + (uint)*DAT_000028f0 * 2);
  }
  *DAT_0000290c = uVar1;
  FUN_00004450();
  return;
}



// ==========================================
// Function: FUN_000026ba
// Address:  000026ba
// Size:     32 bytes
// ==========================================

void FUN_000026ba(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00002918;
  *DAT_00002918 =
       *(undefined4 *)(*(int *)(DAT_00002910 + (uint)*DAT_000028e4 * 4) + (uint)*DAT_00002914 * 4);
  *DAT_000028f0 = *(undefined *)puVar1;
  return;
}



// ==========================================
// Function: FUN_000026da
// Address:  000026da
// Size:     584 bytes
// ==========================================

void FUN_000026da(void)

{
  short sVar1;
  ushort uVar2;
  char cVar3;
  
  FUN_0000ab24(1);
  FUN_00002552();
  if ((int)((uint)*DAT_000028b0 << 0x1a) < 0) {
    FUN_00002574();
    goto LAB_000029b0;
  }
  switch(*DAT_000028e4) {
  case 2:
  case 0xd:
  case 0x14:
  case 0x15:
switchD_00002700_caseD_15:
    cVar3 = *DAT_0000291c;
    if (cVar3 == '\0') {
      *DAT_00002914 = 0;
      FUN_000026ba();
      *DAT_0000291c = '\x01';
    }
    else if (cVar3 == '\x01') {
      sVar1 = *(short *)(DAT_00002918 + 2) + -1;
      *(short *)(DAT_00002918 + 2) = sVar1;
      if (sVar1 == 0) {
        *DAT_00002914 = *DAT_00002914 + 1;
        if (*DAT_00002914 < *(byte *)(DAT_00002920 + (uint)*DAT_000028e4)) {
          FUN_000026ba();
        }
        else {
          *DAT_0000291c = '\x03';
        }
        if ((*DAT_000028e4 == 0x15) && (*DAT_00002914 == 3)) {
          FUN_00004484(0xd5);
          *DAT_00002924 = *DAT_000028f0;
          *DAT_0000291c = '\x02';
          return;
        }
      }
    }
    else if (cVar3 == '\x02') {
      uVar2 = *(short *)(DAT_00002918 + 2) - 1;
      *(ushort *)(DAT_00002918 + 2) = uVar2;
      if (1 < uVar2) {
        return;
      }
      *DAT_0000291c = '\x01';
      return;
    }
    break;
  case 3:
    goto LAB_0000298e;
  case 5:
    if (*(ushort *)(DAT_000028ac + 6) < 0x5b) {
      if (*(ushort *)(DAT_000028ac + 6) < 0x45) {
        *DAT_000028f0 = '\x12';
      }
      else {
        if (*(short *)(DAT_000028ac + 6) == 0x5a) {
          FUN_000022c8();
        }
        *DAT_000028f0 =
             *(char *)(DAT_00002928 + (0x5a - (uint)*(ushort *)(DAT_000028ac + 6))) + '\x02';
      }
    }
    else if (*DAT_000028f4 == '\0') {
      *DAT_000028f0 = '\0';
    }
    else {
      *DAT_000028f0 = '\f';
      *DAT_000028f4 = *DAT_000028f4 + -1;
    }
    break;
  case 6:
    if (*(ushort *)(DAT_000028ac + 6) < 0x1f) {
      if (*(ushort *)(DAT_000028ac + 6) < 0x12) {
        *DAT_00002d0c = 0xd;
      }
      else {
        if (*(short *)(DAT_000028ac + 6) == 0x1d) {
          FUN_000022c8();
        }
        *DAT_000028f0 =
             *(char *)(DAT_00002928 + (0x1e - (uint)*(ushort *)(DAT_000028ac + 6))) + '\x02';
      }
    }
    else if (*DAT_00002d10 == '\0') {
      *DAT_00002d0c = 0;
    }
    else {
      *DAT_00002d0c = 0xc;
      *DAT_00002d10 = *DAT_00002d10 + -1;
    }
    break;
  case 7:
    goto LAB_0000298e;
  case 8:
    goto LAB_0000298e;
  case 0xe:
    if ((uint)*(ushort *)(DAT_000028ac + 6) == ((int)(uint)*(ushort *)(DAT_000028ac + 6) >> 1) * 2)
    {
      cVar3 = '\x10';
    }
    else {
      cVar3 = '\t';
    }
    *DAT_000028f0 = cVar3;
    break;
  case 0xf:
    if (*(ushort *)(DAT_000028ac + 6) < 0x78) {
      *DAT_000028f0 = '\r';
    }
    else if (*(ushort *)(DAT_000028ac + 6) < 0xb4) {
      *DAT_000028f0 = '\b';
    }
    else {
      *DAT_000028f0 = '\x04';
    }
    break;
  case 0x10:
LAB_0000298e:
    FUN_00002574();
    break;
  case 0x11:
    if (*(char *)(DAT_000028ac + 5) == '\r') goto switchD_00002700_caseD_15;
    FUN_00002574();
    break;
  case 0x12:
    if (*(short *)(DAT_00002d14 + 6) == 0x3c) {
      *DAT_00002d0c = 0;
      *(undefined *)(DAT_00002d14 + 5) = 9;
      *DAT_00002d18 = 9;
      *DAT_00002d1c = 5;
      *DAT_00002d20 = 0;
      FUN_000062f6(*DAT_00002d24);
      FUN_0000ada4();
    }
  }
  if ((*(short *)(DAT_00002d14 + 6) != 0x3c) || (*DAT_00002d28 != '\x12')) {
    *DAT_00002d18 = *DAT_00002d0c;
  }
LAB_000029b0:
  FUN_00002610();
  return;
}



// ==========================================
// Function: FUN_000029b8
// Address:  000029b8
// Size:     184 bytes
// ==========================================

void FUN_000029b8(void)

{
  char cVar1;
  ushort *puVar2;
  
  if (*(short *)(DAT_00002d14 + 6) == 0) {
    if (-1 < (int)((uint)*(byte *)DAT_00002d2c << 0x1a)) {
      if (*(char *)(DAT_00002d14 + 4) != '\0') {
        *(undefined *)(DAT_00002d14 + 5) = *(undefined *)(DAT_00002d14 + 4);
      }
      cVar1 = *DAT_00002d28;
      if ((cVar1 == '\0') || (cVar1 == '\x01')) {
        *(undefined *)(DAT_00002d14 + 8) = 0x28;
      }
      else if (cVar1 == '\x02') {
        *(undefined *)(DAT_00002d14 + 8) = 0x3c;
      }
      else if (cVar1 == '\f') {
        *(undefined *)(DAT_00002d14 + 8) = 0x4b;
      }
    }
    FUN_0000120c();
    *DAT_00002d38 = (uint)*(ushort *)(DAT_00002d34 + (uint)*(byte *)(DAT_00002d30 + 1) * 2) * 0x3c;
    puVar2 = DAT_00002d2c;
    *DAT_00002d2c = (*DAT_00002d2c & 0xffef) + 0x10;
    *puVar2 = (*puVar2 & 0xffdf) + 0x20;
    *DAT_00002d3c = 0;
    *DAT_00002d40 = 2;
    *DAT_00002d1c = 6;
    *DAT_00002d20 = 0;
    FUN_000002b4();
    FUN_000022c8();
    FUN_0000a066(*DAT_00002d48,DAT_00002d44);
    FUN_0000bf64(0);
  }
  return;
}



// ==========================================
// Function: FUN_00002a70
// Address:  00002a70
// Size:     30 bytes
// ==========================================

void FUN_00002a70(void)

{
  *(byte *)(DAT_00002d30 + (uint)*(byte *)(DAT_00002d4c + 5)) =
       *(byte *)(DAT_00002d30 + (uint)*(byte *)(DAT_00002d4c + 5)) & 0xf0 | *DAT_00002d50 & 0xf;
  return;
}



// ==========================================
// Function: FUN_00002a8e
// Address:  00002a8e
// Size:     708 bytes
// ==========================================

void FUN_00002a8e(void)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_00002d3c;
  switch(*DAT_00002d1c) {
  case '\0':
  case '\x01':
  case '\x02':
    FUN_0000238c();
    break;
  case '\x03':
    if (*DAT_00002d54 < 2) {
      if ((((*DAT_00002d54 == 0) && (*DAT_00002d1c == '\x03')) &&
          (*(char *)(DAT_00002d4c + 5) == '\r')) &&
         (bVar1 = *DAT_00002d60, *DAT_00002d60 = bVar1 + 1, 5 < (byte)(bVar1 + 1))) {
        FUN_00002a70();
        FUN_0000234a();
        FUN_0000025e();
        *DAT_00002d1c = '\x01';
        if (*(char *)(DAT_00002d30 + 0xd) == '\0') {
          *DAT_00002d54 = *(byte *)(DAT_00002d30 + 9) & 0xf;
          FUN_0000bf64(1);
        }
        else {
          *DAT_00002d38 = 0x78;
        }
      }
    }
    else {
      if ((*(byte *)DAT_00002d2c & 1) != 0) {
        FUN_00002610();
      }
      if (*DAT_00002d58 != 0) {
        *DAT_00002d38 =
             (uint)*(ushort *)(DAT_00002d34 + (uint)*(byte *)(DAT_00002d30 + 1) * 2) * 0x3c;
        *(int *)(DAT_00002d5c + 0xc0) = *(int *)(DAT_00002d5c + 0xc0) + 1;
      }
      *(int *)(DAT_00002d5c + 0xc4) = *(int *)(DAT_00002d5c + 0xc4) + 1;
      FUN_00002552();
    }
    FUN_0000238c();
    FUN_0000af94(*DAT_00002d64);
    break;
  case '\x04':
    if (*DAT_00002d58 != 0) {
      *(int *)(DAT_00002d5c + 0xc0) = *(int *)(DAT_00002d5c + 0xc0) + 1;
    }
    *(int *)(DAT_00002d5c + 0xc4) = *(int *)(DAT_00002d5c + 0xc4) + 1;
    if ((*(byte *)DAT_00002d2c & 1) == 0) {
      if (*DAT_00002d28 == 0x17) {
        *(short *)(DAT_00002d14 + 6) = *(short *)(DAT_00002d14 + 6) + 1;
        FUN_000026da();
      }
      else if (*(short *)(DAT_00002d14 + 6) == 0) {
        FUN_000029b8();
      }
      else {
        if ((-1 < (int)((uint)*(byte *)DAT_00002d2c << 0x19)) && (*DAT_00002d1c != '\x05')) {
          *(short *)(DAT_00002d14 + 6) = *(short *)(DAT_00002d14 + 6) + -1;
        }
        FUN_000029b8();
        if (*(short *)(DAT_00002d14 + 6) != 0) {
          FUN_000026da();
          FUN_00004734();
        }
        *(int *)(DAT_00002d5c + (uint)*DAT_00002d28 * 8 + 4) =
             *(int *)(DAT_00002d5c + (uint)*DAT_00002d28 * 8 + 4) + 1;
      }
    }
    else {
      FUN_00002610();
    }
    FUN_0000af94(*DAT_00002d64);
    break;
  case '\x05':
    if ((*(short *)(DAT_00002d14 + 6) == 0x3c) && (*DAT_00002d28 == 0x12)) {
      FUN_00002374();
    }
    FUN_00002552();
    FUN_0000238c();
    if ((*(byte *)DAT_00002d2c & 1) != 0) {
      FUN_00002610();
    }
    FUN_0000af94(*DAT_00002d64);
    break;
  case '\x06':
    if ((int)((uint)*(byte *)DAT_00002d2c << 0x1b) < 0) {
      if ((*DAT_00002d28 == 5) || (*DAT_00002d28 == 0xd)) {
        *DAT_00002d3c = *DAT_00002d3c + 1;
        bVar1 = *pbVar2;
        if ((bVar1 == 1) || (bVar1 == 3)) {
          FUN_000062f6(*DAT_00002d24);
        }
        else if (bVar1 == 4) {
          *DAT_00002d2c = *DAT_00002d2c & 0xffef;
          *DAT_00002d3c = 0;
        }
      }
      else {
        *DAT_00002d2c = *DAT_00002d2c & 0xffef;
        FUN_000062f6(*DAT_00002d68);
      }
    }
    FUN_00002374();
    FUN_00002552();
    FUN_0000238c();
    FUN_0000af94(*DAT_00002d64);
    break;
  case '\a':
    if (*DAT_00002d3c != 0) {
      *DAT_00002d3c = *DAT_00002d3c - 1;
      if ((uint)*pbVar2 % 3 == 2) {
        *(uint *)(DAT_00002d6c + 0x4c) = *(uint *)(DAT_00002d6c + 0x4c) | 0x1000;
      }
      else {
        *(uint *)(DAT_00003150 + 0x4c) = *(uint *)(DAT_00003150 + 0x4c) & 0xffffefff;
      }
    }
    FUN_000047ca();
    FUN_0000af94(*DAT_00003154);
    FUN_0000af94(*DAT_00003158);
    *(int *)(DAT_0000315c + 0xc4) = *(int *)(DAT_0000315c + 0xc4) + 1;
    FUN_00002552();
    FUN_0000238c();
  }
  *(int *)(DAT_0000315c + 200) = *(int *)(DAT_0000315c + 200) + 1;
  return;
}



// ==========================================
// Function: FUN_00002dd4
// Address:  00002dd4
// Size:     36 bytes
// ==========================================

void FUN_00002dd4(int param_1)

{
  if (*(char *)(param_1 + 5) != '\0') {
    *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + -1;
    if (*(byte *)(param_1 + 5) < *(byte *)(param_1 + 4)) {
      *(undefined *)(param_1 + 4) = *(undefined *)(param_1 + 5);
    }
    FUN_0000b596(param_1);
  }
  return;
}



// ==========================================
// Function: FUN_00002df8
// Address:  00002df8
// Size:     44 bytes
// ==========================================

void FUN_00002df8(int param_1)

{
  if ((int)(uint)*(byte *)(param_1 + 5) < (int)(*(byte *)(param_1 + 6) - 1)) {
    *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + '\x01';
    if (5 < (int)((uint)*(byte *)(param_1 + 5) - (uint)*(byte *)(param_1 + 4))) {
      *(char *)(param_1 + 4) = *(char *)(param_1 + 5) + -5;
    }
    FUN_0000b596(param_1);
  }
  return;
}



// ==========================================
// Function: FUN_00002e24
// Address:  00002e24
// Size:     276 bytes
// ==========================================

undefined4 FUN_00002e24(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if ((int)((uint)*(byte *)DAT_0000316c << 0x1a) < 0) {
    bVar4 = *(byte *)(DAT_00003170 + 1);
  }
  else {
    bVar4 = FUN_00001142();
  }
  if ((bVar4 & 1) != 0) {
    cVar1 = *(char *)(DAT_00003174 + 6);
    if (((*(char *)(DAT_00003170 + 8) != cVar1) && (*(char *)(DAT_00003170 + 8) != '\0')) &&
       (cVar1 != -1)) {
      uVar5 = 1;
      *(char *)(DAT_00003170 + 8) = cVar1;
      *DAT_00003178 = 1;
      *DAT_0000317c = 1;
    }
  }
  if ((int)((uint)*(byte *)DAT_0000316c << 0x1a) < 0) {
    bVar4 = *(byte *)(DAT_00003170 + 1);
  }
  else {
    bVar4 = FUN_00001142();
  }
  if ((bVar4 & 2) != 0) {
    sVar2 = CONCAT11(*(undefined *)(DAT_00003174 + 3),*(undefined *)(DAT_00003174 + 4));
    if (((*(short *)(DAT_00003170 + 6) != sVar2) && (*(short *)(DAT_00003170 + 6) != -1)) &&
       (sVar2 != -1)) {
      uVar5 = 1;
      *(short *)(DAT_00003170 + 6) = sVar2;
      FUN_00001a38();
      *DAT_00003178 = 2;
      *DAT_0000317c = 2;
    }
  }
  if ((int)((uint)*(byte *)DAT_0000316c << 0x1a) < 0) {
    bVar4 = *(byte *)(DAT_00003170 + 1);
  }
  else {
    bVar4 = FUN_00001142();
  }
  iVar3 = DAT_00003170;
  if ((bVar4 & 4) != 0) {
    cVar1 = *(char *)(DAT_00003174 + 5);
    if (((*(char *)(DAT_00003170 + 5) != cVar1) && (*DAT_00003180 != '\x04')) &&
       ((*DAT_00003180 != '\t' && (cVar1 != -1)))) {
      uVar5 = 1;
      *(char *)(DAT_00003170 + 5) = cVar1;
      *DAT_00003184 = *(undefined *)(iVar3 + 5);
      FUN_00001a9e();
      FUN_000019b2();
      *DAT_00003188 = *DAT_00003184;
      *DAT_00003178 = 3;
      *DAT_0000317c = 4;
    }
  }
  if (*(byte *)(DAT_00003174 + 7) != 0xff) {
    *DAT_0000316c = *DAT_0000316c & 0xffdf | (ushort)((*(byte *)(DAT_00003174 + 7) & 1) << 5);
  }
  return uVar5;
}



// ==========================================
// Function: FUN_00002f38
// Address:  00002f38
// Size:     16 bytes
// ==========================================

void FUN_00002f38(void)

{
  FUN_0000ae5a(*DAT_00003154);
  return;
}



// ==========================================
// Function: FUN_00004450
// Address:  00004450
// Size:     52 bytes
// ==========================================

void FUN_00004450(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_000046f8;
  *DAT_000046f8 = *(undefined *)DAT_000046f4;
  puVar1[1] = (char)((ushort)*DAT_000046f4 >> 8);
  *DAT_000046fc = 0xd1;
  *DAT_00004700 = 2;
  *DAT_00004704 = DAT_000046f8;
  if (*(char *)(DAT_00004708 + 0xd) == '\0') {
    FUN_000097da(*DAT_0000470c);
  }
  return;
}



// ==========================================
// Function: FUN_00004484
// Address:  00004484
// Size:     36 bytes
// ==========================================

void FUN_00004484(undefined param_1)

{
  *DAT_000046f8 = 0;
  *DAT_000046fc = param_1;
  *DAT_00004700 = 0;
  *DAT_00004704 = DAT_000046f8;
  FUN_000097da(*DAT_0000470c);
  return;
}



// ==========================================
// Function: FUN_000044a8
// Address:  000044a8
// Size:     14 bytes
// ==========================================

void FUN_000044a8(void)

{
  FUN_00004484(0xd2);
  return;
}



// ==========================================
// Function: FUN_000044b6
// Address:  000044b6
// Size:     24 bytes
// ==========================================

void FUN_000044b6(void)

{
  *DAT_00004710 = *DAT_00004710 | 4;
  FUN_000002b4();
  FUN_0000149e();
  return;
}



// ==========================================
// Function: FUN_000044ce
// Address:  000044ce
// Size:     16 bytes
// ==========================================

void FUN_000044ce(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 3) != '\0') {
    FUN_000044b6();
  }
  return;
}



// ==========================================
// Function: FUN_000044e0
// Address:  000044e0
// Size:     18 bytes
// ==========================================

void FUN_000044e0(void)

{
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < 3000; uVar1 = uVar1 + 1) {
  }
  return;
}



// ==========================================
// Function: FUN_000044f2
// Address:  000044f2
// Size:     114 bytes
// ==========================================

void FUN_000044f2(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 < 0xc) {
    FUN_0000721a(0xcc);
    FUN_000044e0();
    FUN_0000721a(param_1);
    FUN_000044e0();
    FUN_0000721a(param_2);
    uVar1 = (param_1 + 0xccU & 0xff) + param_2;
    FUN_000044e0();
    for (uVar2 = 0; (int)uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
      FUN_0000721a(*(undefined *)(param_3 + uVar2));
      uVar1 = (uint)*(byte *)(param_3 + uVar2) + (uVar1 & 0xff);
      FUN_000044e0();
    }
    FUN_0000721a(uVar1 & 0xff);
    FUN_000044e0();
    FUN_0000721a(0x18);
  }
  return;
}



// ==========================================
// Function: FUN_00004564
// Address:  00004564
// Size:     186 bytes
// ==========================================

bool FUN_00004564(void)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  bVar2 = 0;
  bVar7 = false;
  do {
    iVar5 = 0;
    iVar3 = FUN_0000721a(0);
    FUN_000044e0();
    if (iVar3 == 0xee) {
      iVar5 = 0xee;
      break;
    }
    bVar2 = bVar2 + 1;
  } while (bVar2 < 100);
  if (bVar2 < 100) {
    bVar2 = FUN_0000721a(0);
    pbVar1 = DAT_00004714;
    *DAT_00004714 = bVar2;
    bVar2 = *pbVar1;
    FUN_000044e0();
    iVar3 = FUN_0000721a(0);
    DAT_00004714[1] = (byte)iVar3;
    uVar4 = ((uint)bVar2 + iVar5 & 0xff) + iVar3;
    if (iVar3 < 0x12) {
      FUN_000044e0();
      for (uVar6 = 0; (int)uVar6 < iVar3; uVar6 = uVar6 + 1 & 0xff) {
        bVar2 = FUN_0000721a(0);
        pbVar1 = DAT_00004714;
        DAT_00004714[uVar6 + 2] = bVar2;
        uVar4 = (uint)pbVar1[uVar6 + 2] + (uVar4 & 0xff);
        FUN_000044e0();
      }
      uVar6 = FUN_0000721a(0);
      FUN_000044e0();
      FUN_0000721a(0);
      FUN_000044e0();
      bVar7 = (uVar4 & 0xff) == uVar6;
    }
  }
  else {
    bVar7 = false;
  }
  return bVar7;
}



// ==========================================
// Function: FUN_00004734
// Address:  00004734
// Size:     150 bytes
// ==========================================

void FUN_00004734(void)

{
  char cVar1;
  byte *pbVar2;
  
  pbVar2 = DAT_00004b14;
  if (*DAT_00004b18 == '\x05') {
    cVar1 = *DAT_00004b10;
    if (cVar1 == '\0') {
      if (*DAT_00004b1c < 0x28) {
        *DAT_00004b14 = *DAT_00004b14 + 1;
        if (0x59 < *pbVar2) {
          *DAT_00004b10 = '\x02';
          *DAT_00004b14 = 0;
        }
      }
      else {
        *DAT_00004b10 = '\x01';
        *DAT_00004b14 = 0;
      }
    }
    else if (cVar1 == '\x01') {
      if (*DAT_00004b1c < 0x28) {
        *DAT_00004b14 = *DAT_00004b14 + 1;
        if (0x59 < *pbVar2) {
          *DAT_00004b10 = '\x02';
        }
      }
      else {
        *DAT_00004b14 = 0;
      }
    }
    else if (cVar1 == '\x02') {
      *DAT_00004b20 = *DAT_00004b20 | 0x10;
      FUN_0000149e();
    }
  }
  return;
}



// ==========================================
// Function: FUN_000047ca
// Address:  000047ca
// Size:     42 bytes
// ==========================================

void FUN_000047ca(void)

{
  if ((*DAT_00004b18 == '\x05') && (0x27 < *DAT_00004b1c)) {
    *DAT_00004b20 = *DAT_00004b20 & 0xef;
    FUN_0000149e();
    FUN_0000120c();
  }
  return;
}



// ==========================================
// Function: FUN_000047f4
// Address:  000047f4
// Size:     74 bytes
// ==========================================

uint FUN_000047f4(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0xd8;
  uVar2 = 0;
  if ((int)param_1 < (int)(uint)*DAT_00004b24) {
    if ((int)param_1 < (int)(uint)DAT_00004b24[0xd8]) {
      uVar2 = 0xd8;
    }
    else {
      do {
        iVar1 = (int)(uVar3 + uVar2) >> 1;
        if ((int)(uint)DAT_00004b24[iVar1] < (int)param_1) {
          uVar3 = iVar1 - 1U & 0xffff;
        }
        else {
          uVar2 = iVar1 + 1U & 0xffff;
        }
      } while ((uVar2 <= uVar3) && (DAT_00004b24[iVar1] != param_1));
      uVar2 = uVar2 - 1 & 0xffff;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_0000483e
// Address:  0000483e
// Size:     212 bytes
// ==========================================

void FUN_0000483e(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  
  if ((*DAT_00004b28 == '\x04') || (*DAT_00004b28 == '\x05')) {
    if (*DAT_00004b1c < (short)(ushort)*(byte *)(DAT_00004b2c + 8)) {
      uVar1 = FUN_0000d338((uint)*(byte *)(DAT_00004b2c + 8) - (int)*DAT_00004b30);
      uVar2 = FUN_0000d338(((int)*DAT_00004b1c - (int)*DAT_00004b30) * 5);
      FUN_0000d174(uVar2,uVar1);
      uVar4 = FUN_0000d040();
      FUN_0000cc14((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,DAT_00004b34);
      iVar3 = FUN_0000cd64();
    }
    else {
      iVar3 = 5;
    }
  }
  else {
    iVar3 = (int)*DAT_00004b1c / 0x14;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (5 < iVar3) {
    iVar3 = 5;
  }
  *DAT_00004b38 = (char)iVar3;
  if (((uint)*DAT_00004b3c << 0x16) >> 0x1f != (uint)(0x3c < *DAT_00004b1c)) {
    *DAT_00004b40 = 0;
    *DAT_00004b3c = *DAT_00004b3c & 0xfdff | (ushort)(0x3c < *DAT_00004b1c) << 9;
  }
  return;
}



// ==========================================
// Function: FUN_00004912
// Address:  00004912
// Size:     158 bytes
// ==========================================

void FUN_00004912(void)

{
  *DAT_00004b44 = (ushort)*(byte *)(DAT_00004b2c + 8);
  *DAT_00004b48 = 0;
  *DAT_00004b4c = 100;
  *DAT_00004b50 = 0;
  *DAT_00004b54 = 0;
  *DAT_00004b58 = *DAT_00004b1c;
  *DAT_00004b5c = 0;
  *DAT_00004b60 = 0;
  *DAT_00004b64 = 0;
  *DAT_00004b68 = 0;
  *DAT_00004b6c = 0;
  *DAT_00004b70 = 0;
  *DAT_00004b74 = 0;
  *DAT_00004b78 = 0;
  if ((int)(short)*DAT_00004b44 - (int)*DAT_00004b1c < 0x1f) {
    if ((int)(short)*DAT_00004b44 - (int)*DAT_00004b1c < 0x15) {
      if ((int)(short)*DAT_00004b44 - (int)*DAT_00004b1c < 0xb) {
        *DAT_00004b78 = 1;
      }
      else {
        *DAT_00004b74 = 1;
      }
    }
    else {
      *DAT_00004b70 = 1;
    }
  }
  else {
    *DAT_00004b6c = 1;
  }
  return;
}



// ==========================================
// Function: FUN_000049b0
// Address:  000049b0
// Size:     316 bytes
// ==========================================

void FUN_000049b0(void)

{
  char cVar1;
  ushort uVar2;
  short *psVar3;
  byte *pbVar4;
  undefined2 uVar5;
  short sVar6;
  
  do {
  } while ((int)DAT_00004b7c[7] < 0);
  uVar5 = FUN_00006ddc(3);
  FUN_00005778(uVar5);
  *DAT_00004b7c = *DAT_00004b7c | DAT_00004b80;
  if (*(char *)(*DAT_00004b84 + 1) != '\0') {
    uVar2 = *(ushort *)(*DAT_00004b84 + 2);
    cVar1 = *DAT_00004b28;
    if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
      if (uVar2 < 0xf70) {
        if (uVar2 < 0x6c) {
          *DAT_00004b20 = *DAT_00004b20 | 0x20;
          FUN_0000149e();
        }
        else if ((uVar2 < 0x217) && ((*DAT_00004b88 == '\x04' || (*DAT_00004b88 == '\t')))) {
          *DAT_00004b20 = *DAT_00004b20 | 2;
          FUN_0000149e();
        }
      }
      else {
        *DAT_00004b20 = *DAT_00004b20 | 0x40;
        FUN_0000149e();
      }
    }
    else if ((cVar1 == '\a') && ((*DAT_00004b20 & 2) != 0)) {
      if (0x5c8 < uVar2) {
        *DAT_00004b20 = *DAT_00004b20 & 0xfd;
        FUN_0000149e();
      }
      pbVar4 = DAT_00004b20;
      if (uVar2 < *(ushort *)(DAT_00004b24 + 0x1b0)) {
        *DAT_00004b20 = 0;
        *pbVar4 = *pbVar4 | 0x20;
        FUN_0000149e();
      }
    }
    if ((*DAT_00004b20 & 0xe0) == 0) {
      sVar6 = FUN_000047f4(uVar2);
      psVar3 = DAT_00004b1c;
      *DAT_00004b1c = sVar6 + -0x1c;
      if (*psVar3 < 0) {
        *psVar3 = 0;
      }
      cVar1 = *DAT_00004b28;
      if ((((cVar1 == '\x03') || (cVar1 == '\x04')) || (cVar1 == '\x05')) || (cVar1 == '\x06')) {
        FUN_0000483e();
        FUN_00001316();
      }
    }
  }
  return;
}



// ==========================================
// Function: FUN_00004aec
// Address:  00004aec
// Size:     2424 bytes
// ==========================================

void FUN_00004aec(int param_1,undefined4 param_2,int param_3)

{
  if (*DAT_00004b64 == 0) {
    if (*DAT_0000537c != 0) {
      if (param_1 < 0x5a) {
        if (param_1 < 0x50) {
          if (param_1 < 0x46) {
            if (param_1 < 0x3c) {
              if (param_1 < 0x32) {
                if (param_3 < 300) {
                  if (param_3 < 0xb4) {
                    if (param_3 < 0x3c) {
                      *DAT_00005378 = 3;
                    }
                    else {
                      *DAT_00005378 = 3;
                    }
                  }
                  else {
                    *DAT_00005378 = 2;
                  }
                }
                else {
                  *DAT_00005378 = 1;
                }
              }
              else if (param_3 < 300) {
                if (param_3 < 0xb4) {
                  if (param_3 < 0x3c) {
                    *DAT_00005378 = 6;
                  }
                  else {
                    *DAT_00005378 = 5;
                  }
                }
                else {
                  *DAT_00005378 = 4;
                }
              }
              else {
                *DAT_00005378 = 2;
              }
            }
            else if (param_3 < 300) {
              if (param_3 < 0xb4) {
                if (param_3 < 0x3c) {
                  *DAT_00005378 = 7;
                }
                else {
                  *DAT_00005378 = 6;
                }
              }
              else {
                *DAT_00005378 = 4;
              }
            }
            else {
              *DAT_00005378 = 3;
            }
          }
          else if (param_3 < 300) {
            if (param_3 < 0xb4) {
              if (param_3 < 0x3c) {
                *DAT_00005378 = 8;
              }
              else {
                *DAT_00005378 = 7;
              }
            }
            else {
              *DAT_00005378 = 5;
            }
          }
          else {
            *DAT_00005378 = 3;
          }
        }
        else if (param_3 < 300) {
          if (param_3 < 0xb4) {
            if (param_3 < 0x3c) {
              *DAT_00005378 = 8;
            }
            else {
              *DAT_00005378 = 7;
            }
          }
          else {
            *DAT_00005378 = 5;
          }
        }
        else {
          *DAT_00005378 = 3;
        }
      }
      else if (param_3 < 300) {
        if (param_3 < 0xb4) {
          if (param_3 < 0x3c) {
            *DAT_00005378 = 8;
          }
          else {
            *DAT_00005378 = 6;
          }
        }
        else {
          *DAT_00005378 = 4;
        }
      }
      else {
        *DAT_00005378 = 2;
      }
    }
    if (*DAT_00005380 != 0) {
      if (param_1 < 0x5a) {
        if (param_1 < 0x50) {
          if (param_1 < 0x46) {
            if (param_1 < 0x3c) {
              if (param_1 < 0x32) {
                if (param_3 < 300) {
                  if (param_3 < 0xb4) {
                    if (param_3 < 0x3c) {
                      *DAT_00005378 = 4;
                    }
                    else {
                      *DAT_00005378 = 3;
                    }
                  }
                  else {
                    *DAT_00005378 = 3;
                  }
                }
                else {
                  *DAT_00005378 = 2;
                }
              }
              else if (param_3 < 300) {
                if (param_3 < 0xb4) {
                  if (param_3 < 0x3c) {
                    *DAT_00005378 = 5;
                  }
                  else {
                    *DAT_00005378 = 4;
                  }
                }
                else {
                  *DAT_00005378 = 3;
                }
              }
              else {
                *DAT_00005378 = 2;
              }
            }
            else if (param_3 < 300) {
              if (param_3 < 0xb4) {
                if (param_3 < 0x3c) {
                  *DAT_00005378 = 6;
                }
                else {
                  *DAT_00005378 = 5;
                }
              }
              else {
                *DAT_00005378 = 4;
              }
            }
            else {
              *DAT_00005378 = 3;
            }
          }
          else if (param_3 < 300) {
            if (param_3 < 0xb4) {
              if (param_3 < 0x3c) {
                *DAT_00005378 = 7;
              }
              else {
                *DAT_00005378 = 6;
              }
            }
            else {
              *DAT_00005378 = 5;
            }
          }
          else {
            *DAT_00005378 = 3;
          }
        }
        else if (param_3 < 300) {
          if (param_3 < 0xb4) {
            if (param_3 < 0x3c) {
              *DAT_00005378 = 8;
            }
            else {
              *DAT_00005378 = 7;
            }
          }
          else {
            *DAT_00005378 = 5;
          }
        }
        else {
          *DAT_00005378 = 3;
        }
      }
      else if (param_3 < 300) {
        if (param_3 < 0xb4) {
          if (param_3 < 0x3c) {
            *DAT_00005378 = 8;
          }
          else {
            *DAT_00005378 = 7;
          }
        }
        else {
          *DAT_00005378 = 5;
        }
      }
      else {
        *DAT_00005378 = 3;
      }
    }
    if (*DAT_00005384 != 0) {
      if (param_1 < 0x5a) {
        if (param_1 < 0x50) {
          if (param_1 < 0x46) {
            if (param_1 < 0x3c) {
              if (param_1 < 0x32) {
                if (param_3 < 300) {
                  if (param_3 < 0xb4) {
                    if (param_3 < 0x3c) {
                      *DAT_00005718 = 4;
                    }
                    else {
                      *DAT_00005718 = 3;
                    }
                  }
                  else {
                    *DAT_00005718 = 2;
                  }
                }
                else {
                  *DAT_00005718 = 2;
                }
              }
              else if (param_3 < 300) {
                if (param_3 < 0xb4) {
                  if (param_3 < 0x3c) {
                    *DAT_00005718 = 5;
                  }
                  else {
                    *DAT_00005718 = 4;
                  }
                }
                else {
                  *DAT_00005718 = 3;
                }
              }
              else {
                *DAT_00005378 = 2;
              }
            }
            else if (param_3 < 300) {
              if (param_3 < 0xb4) {
                if (param_3 < 0x3c) {
                  *DAT_00005378 = 5;
                }
                else {
                  *DAT_00005378 = 4;
                }
              }
              else {
                *DAT_00005378 = 3;
              }
            }
            else {
              *DAT_00005378 = 2;
            }
          }
          else if (param_3 < 300) {
            if (param_3 < 0xb4) {
              if (param_3 < 0x3c) {
                *DAT_00005378 = 6;
              }
              else {
                *DAT_00005378 = 5;
              }
            }
            else {
              *DAT_00005378 = 4;
            }
          }
          else {
            *DAT_00005378 = 3;
          }
        }
        else if (param_3 < 300) {
          if (param_3 < 0xb4) {
            if (param_3 < 0x3c) {
              *DAT_00005378 = 7;
            }
            else {
              *DAT_00005378 = 6;
            }
          }
          else {
            *DAT_00005378 = 5;
          }
        }
        else {
          *DAT_00005378 = 3;
        }
      }
      else if (param_3 < 300) {
        if (param_3 < 0xb4) {
          if (param_3 < 0x3c) {
            *DAT_00005378 = 7;
          }
          else {
            *DAT_00005378 = 6;
          }
        }
        else {
          *DAT_00005378 = 5;
        }
      }
      else {
        *DAT_00005378 = 3;
      }
    }
    if (*DAT_0000571c != 0) {
      if (param_1 < 0x5a) {
        if (param_1 < 0x50) {
          if (param_1 < 0x46) {
            if (param_1 < 0x3c) {
              if (param_1 < 0x32) {
                if (param_3 < 300) {
                  if (param_3 < 0xb4) {
                    if (param_3 < 0x3c) {
                      *DAT_00005718 = 3;
                    }
                    else {
                      *DAT_00005718 = 3;
                    }
                  }
                  else {
                    *DAT_00005718 = 2;
                  }
                }
                else {
                  *DAT_00005718 = 2;
                }
              }
              else if (param_3 < 300) {
                if (param_3 < 0xb4) {
                  if (param_3 < 0x3c) {
                    *DAT_00005718 = 4;
                  }
                  else {
                    *DAT_00005718 = 4;
                  }
                }
                else {
                  *DAT_00005718 = 3;
                }
              }
              else {
                *DAT_00005718 = 2;
              }
            }
            else if (param_3 < 300) {
              if (param_3 < 0xb4) {
                if (param_3 < 0x3c) {
                  *DAT_00005718 = 5;
                }
                else {
                  *DAT_00005718 = 4;
                }
              }
              else {
                *DAT_00005718 = 3;
              }
            }
            else {
              *DAT_00005718 = 2;
            }
          }
          else if (param_3 < 300) {
            if (param_3 < 0xb4) {
              if (param_3 < 0x3c) {
                *DAT_00005718 = 5;
              }
              else {
                *DAT_00005718 = 4;
              }
            }
            else {
              *DAT_00005718 = 3;
            }
          }
          else {
            *DAT_00005718 = 2;
          }
        }
        else if (param_3 < 300) {
          if (param_3 < 0xb4) {
            if (param_3 < 0x3c) {
              *DAT_00005718 = 5;
            }
            else {
              *DAT_00005718 = 4;
            }
          }
          else {
            *DAT_00005718 = 4;
          }
        }
        else {
          *DAT_00005718 = 3;
        }
      }
      else if (param_3 < 300) {
        if (param_3 < 0xb4) {
          if (param_3 < 0x3c) {
            *DAT_00005718 = 5;
          }
          else {
            *DAT_00005718 = 4;
          }
        }
        else {
          *DAT_00005718 = 4;
        }
      }
      else {
        *DAT_00005718 = 3;
      }
    }
  }
  else {
    if (*DAT_00004b6c != 0) {
      if (param_1 < 0x5a) {
        if (param_1 < 0x50) {
          if (param_1 < 0x46) {
            if (param_1 < 0x3c) {
              if (param_1 < 0x32) {
                if (param_3 < 300) {
                  if (param_3 < 0xb4) {
                    if (param_3 < 0x3c) {
                      *DAT_00004f7c = 3;
                    }
                    else {
                      *DAT_00004f7c = 2;
                    }
                  }
                  else {
                    *DAT_00004f7c = 1;
                  }
                }
                else {
                  *DAT_00004f7c = 0;
                }
              }
              else if (param_3 < 300) {
                if (param_3 < 0xb4) {
                  if (param_3 < 0x3c) {
                    *DAT_00004f7c = 5;
                  }
                  else {
                    *DAT_00004f7c = 4;
                  }
                }
                else {
                  *DAT_00004f7c = 2;
                }
              }
              else {
                *DAT_00004f7c = 0;
              }
            }
            else if (param_3 < 300) {
              if (param_3 < 0xb4) {
                if (param_3 < 0x3c) {
                  *DAT_00004f7c = 5;
                }
                else {
                  *DAT_00004f7c = 4;
                }
              }
              else {
                *DAT_00004f7c = 2;
              }
            }
            else {
              *DAT_00004f7c = 0;
            }
          }
          else if (param_3 < 300) {
            if (param_3 < 0xb4) {
              if (param_3 < 0x3c) {
                *DAT_00004f7c = 5;
              }
              else {
                *DAT_00004f7c = 4;
              }
            }
            else {
              *DAT_00004f7c = 2;
            }
          }
          else {
            *DAT_00004f7c = 0;
          }
        }
        else if (param_3 < 300) {
          if (param_3 < 0xb4) {
            if (param_3 < 0x3c) {
              *DAT_00004f7c = 6;
            }
            else {
              *DAT_00004f7c = 4;
            }
          }
          else {
            *DAT_00004f7c = 2;
          }
        }
        else {
          *DAT_00004f7c = 0;
        }
      }
      else if (param_3 < 300) {
        if (param_3 < 0xb4) {
          if (param_3 < 0x3c) {
            *DAT_00004f7c = 6;
          }
          else {
            *DAT_00004f7c = 4;
          }
        }
        else {
          *DAT_00004f7c = 2;
        }
      }
      else {
        *DAT_00004b54 = 0;
      }
    }
    if (*DAT_00004f80 != 0) {
      if (param_1 < 0x5a) {
        if (param_1 < 0x50) {
          if (param_1 < 0x46) {
            if (param_1 < 0x3c) {
              if (param_1 < 0x32) {
                if (param_3 < 300) {
                  if (param_3 < 0xb4) {
                    if (param_3 < 0x3c) {
                      *DAT_00004f7c = 2;
                    }
                    else {
                      *DAT_00004f7c = 2;
                    }
                  }
                  else {
                    *DAT_00004f7c = 1;
                  }
                }
                else {
                  *DAT_00004f7c = 0;
                }
              }
              else if (param_3 < 300) {
                if (param_3 < 0xb4) {
                  if (param_3 < 0x3c) {
                    *DAT_00004f7c = 3;
                  }
                  else {
                    *DAT_00004f7c = 2;
                  }
                }
                else {
                  *DAT_00004f7c = 1;
                }
              }
              else {
                *DAT_00004f7c = 0;
              }
            }
            else if (param_3 < 300) {
              if (param_3 < 0xb4) {
                if (param_3 < 0x3c) {
                  *DAT_00004f7c = 5;
                }
                else {
                  *DAT_00004f7c = 4;
                }
              }
              else {
                *DAT_00004f7c = 2;
              }
            }
            else {
              *DAT_00004f7c = 0;
            }
          }
          else if (param_3 < 300) {
            if (param_3 < 0xb4) {
              if (param_3 < 0x3c) {
                *DAT_00004f7c = 5;
              }
              else {
                *DAT_00004f7c = 4;
              }
            }
            else {
              *DAT_00004f7c = 2;
            }
          }
          else {
            *DAT_00004f7c = 0;
          }
        }
        else if (param_3 < 300) {
          if (param_3 < 0xb4) {
            if (param_3 < 0x3c) {
              *DAT_00004f7c = 6;
            }
            else {
              *DAT_00004f7c = 4;
            }
          }
          else {
            *DAT_00004f7c = 2;
          }
        }
        else {
          *DAT_00004f7c = 0;
        }
      }
      else if (param_3 < 300) {
        if (param_3 < 0xb4) {
          if (param_3 < 0x3c) {
            *DAT_00004f7c = 6;
          }
          else {
            *DAT_00004f7c = 4;
          }
        }
        else {
          *DAT_00004f7c = 2;
        }
      }
      else {
        *DAT_00004f7c = 0;
      }
    }
    if (*DAT_00004f84 != 0) {
      if (param_1 < 0x5a) {
        if (param_1 < 0x50) {
          if (param_1 < 0x46) {
            if (param_1 < 0x3c) {
              if (param_1 < 0x32) {
                if (param_3 < 300) {
                  if (param_3 < 0xb4) {
                    if (param_3 < 0x3c) {
                      *DAT_00004f7c = 2;
                    }
                    else {
                      *DAT_00004f7c = 2;
                    }
                  }
                  else {
                    *DAT_00004f7c = 1;
                  }
                }
                else {
                  *DAT_00004f7c = 0;
                }
              }
              else if (param_3 < 300) {
                if (param_3 < 0xb4) {
                  if (param_3 < 0x3c) {
                    *DAT_00004f7c = 2;
                  }
                  else {
                    *DAT_00004f7c = 2;
                  }
                }
                else {
                  *DAT_00004f7c = 1;
                }
              }
              else {
                *DAT_00004f7c = 0;
              }
            }
            else if (param_3 < 300) {
              if (param_3 < 0xb4) {
                if (param_3 < 0x3c) {
                  *DAT_00004f7c = 3;
                }
                else {
                  *DAT_00004f7c = 3;
                }
              }
              else {
                *DAT_00004f7c = 1;
              }
            }
            else {
              *DAT_00004f7c = 0;
            }
          }
          else if (param_3 < 300) {
            if (param_3 < 0xb4) {
              if (param_3 < 0x3c) {
                *DAT_00004f7c = 4;
              }
              else {
                *DAT_00004f7c = 3;
              }
            }
            else {
              *DAT_00004f7c = 2;
            }
          }
          else {
            *DAT_00004f7c = 0;
          }
        }
        else if (param_3 < 300) {
          if (param_3 < 0xb4) {
            if (param_3 < 0x3c) {
              *DAT_00004f7c = 5;
            }
            else {
              *DAT_00004f7c = 4;
            }
          }
          else {
            *DAT_00004f7c = 2;
          }
        }
        else {
          *DAT_00004f7c = 0;
        }
      }
      else if (param_3 < 300) {
        if (param_3 < 0xb4) {
          if (param_3 < 0x3c) {
            *DAT_00004f7c = 5;
          }
          else {
            *DAT_00004f7c = 4;
          }
        }
        else {
          *DAT_00004f7c = 2;
        }
      }
      else {
        *DAT_00004f7c = 0;
      }
    }
    if (*DAT_00004f88 != 0) {
      if (param_1 < 0x5a) {
        if (param_1 < 0x50) {
          if (param_1 < 0x46) {
            if (param_1 < 0x3c) {
              if (param_1 < 0x32) {
                if (param_3 < 300) {
                  if (param_3 < 0xb4) {
                    if (param_3 < 0x3c) {
                      *DAT_00005378 = 2;
                    }
                    else {
                      *DAT_00005378 = 2;
                    }
                  }
                  else {
                    *DAT_00005378 = 1;
                  }
                }
                else {
                  *DAT_00005378 = 0;
                }
              }
              else if (param_3 < 300) {
                if (param_3 < 0xb4) {
                  if (param_3 < 0x3c) {
                    *DAT_00005378 = 3;
                  }
                  else {
                    *DAT_00005378 = 2;
                  }
                }
                else {
                  *DAT_00005378 = 1;
                }
              }
              else {
                *DAT_00005378 = 0;
              }
            }
            else if (param_3 < 300) {
              if (param_3 < 0xb4) {
                if (param_3 < 0x3c) {
                  *DAT_00005378 = 4;
                }
                else {
                  *DAT_00005378 = 3;
                }
              }
              else {
                *DAT_00005378 = 1;
              }
            }
            else {
              *DAT_00005378 = 0;
            }
          }
          else if (param_3 < 300) {
            if (param_3 < 0xb4) {
              if (param_3 < 0x3c) {
                *DAT_00005378 = 4;
              }
              else {
                *DAT_00005378 = 3;
              }
            }
            else {
              *DAT_00005378 = 1;
            }
          }
          else {
            *DAT_00004f7c = 0;
          }
        }
        else if (param_3 < 300) {
          if (param_3 < 0xb4) {
            if (param_3 < 0x3c) {
              *DAT_00004f7c = 4;
            }
            else {
              *DAT_00004f7c = 3;
            }
          }
          else {
            *DAT_00004f7c = 2;
          }
        }
        else {
          *DAT_00004f7c = 0;
        }
      }
      else if (param_3 < 300) {
        if (param_3 < 0xb4) {
          if (param_3 < 0x3c) {
            *DAT_00004f7c = 4;
          }
          else {
            *DAT_00004f7c = 3;
          }
        }
        else {
          *DAT_00004f7c = 1;
        }
      }
      else {
        *DAT_00004f7c = 0;
      }
    }
  }
  return;
}



// ==========================================
// Function: FUN_00005778
// Address:  00005778
// Size:     160 bytes
// ==========================================

void FUN_00005778(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0000cb64();
  *(uint *)(*DAT_00005860 + 4) =
       *(int *)(*DAT_00005860 + 4) - (uint)*(ushort *)(*DAT_00005860 + (uint)**DAT_00005860 * 2 + 8)
  ;
  *(short *)(*DAT_00005860 + (uint)**DAT_00005860 * 2 + 8) = (short)param_1;
  *(int *)(*DAT_00005860 + 4) = *(int *)(*DAT_00005860 + 4) + param_1;
  **DAT_00005860 = **DAT_00005860 + 1;
  if (((*DAT_00005860)[1] == 0) && (0x1f < **DAT_00005860)) {
    (*DAT_00005860)[1] = 1;
  }
  **DAT_00005860 = **DAT_00005860 & 0x1f;
  if ((*DAT_00005860)[1] != 0) {
    *(short *)(*DAT_00005860 + 2) = (short)((uint)(*(int *)(*DAT_00005860 + 4) << 0xb) >> 0x10);
  }
  FUN_0000cb6c(uVar1);
  return;
}



// ==========================================
// Function: FUN_00005818
// Address:  00005818
// Size:     72 bytes
// ==========================================

void FUN_00005818(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = FUN_0000cb64();
  piVar1 = DAT_00005860;
  *DAT_00005860 = DAT_00005864;
  *(undefined *)*piVar1 = 0;
  *(undefined *)(*DAT_00005860 + 1) = 0;
  *(undefined2 *)(*DAT_00005860 + 2) = 0;
  *(undefined4 *)(*DAT_00005860 + 4) = 0;
  for (uVar3 = 0; uVar3 < 0x20; uVar3 = uVar3 + 1 & 0xff) {
    *(undefined2 *)(*DAT_00005860 + 8 + uVar3 * 2) = 0;
  }
  FUN_0000cb6c(uVar2);
  return;
}



// ==========================================
// Function: FUN_000059d4
// Address:  000059d4
// Size:     60 bytes
// ==========================================

void FUN_000059d4(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
  }
  return;
}



// ==========================================
// Function: FUN_00005a10
// Address:  00005a10
// Size:     18 bytes
// ==========================================

void FUN_00005a10(void)

{
  thunk_FUN_000086a4(DAT_00005dec,0x40);
  *DAT_00005df0 = 0;
  return;
}



// ==========================================
// Function: FUN_00005a22
// Address:  00005a22
// Size:     20 bytes
// ==========================================

void FUN_00005a22(int param_1)

{
  uint uVar1;
  
  for (uVar1 = 5; uVar1 < 0x10; uVar1 = uVar1 + 1 & 0xff) {
    *(undefined *)(param_1 + uVar1) = 0xff;
  }
  return;
}



// ==========================================
// Function: FUN_00005a36
// Address:  00005a36
// Size:     34 bytes
// ==========================================

uint FUN_00005a36(void)

{
  uint uVar1;
  
  uVar1 = ((uint)*DAT_00005df4 << 0x1a) >> 0x1f;
  if (*(char *)(*DAT_00005df8 + 1) != '\0') {
    uVar1 = uVar1 | 2;
  }
  if (*DAT_00005dfc == '\x01') {
    uVar1 = uVar1 | 4;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00005a58
// Address:  00005a58
// Size:     1544 bytes
// ==========================================

void FUN_00005a58(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint local_12c;
  uint local_128;
  undefined local_124;
  undefined local_123;
  char local_122;
  byte local_121 [4];
  byte local_11d;
  byte local_11c;
  undefined local_11b;
  undefined local_11a;
  undefined local_119;
  undefined local_118;
  undefined local_117;
  undefined local_116;
  undefined local_115;
  undefined local_114;
  undefined local_113;
  undefined uStack_61;
  
  if ((*(char *)(DAT_00005dec + 1) == '\x10') || (*(char *)(DAT_00005dec + 1) == '\x12')) {
    bVar1 = *(byte *)(DAT_00005dec + (*(byte *)(DAT_00005dec + 2) - 1));
    local_12c = FUN_000059d4(DAT_00005dec,*(byte *)(DAT_00005dec + 2) - 1 & 0xff);
  }
  else {
    bVar1 = *(byte *)(DAT_00005dec + 2);
    local_12c = FUN_000059d4(DAT_00005dec,2);
  }
  iVar10 = DAT_00006190;
  local_128 = (uint)bVar1;
  if (local_128 != local_12c) {
    return;
  }
  local_124 = 0x5a;
  local_123 = *(undefined *)(DAT_00005dec + 1);
  switch(*(undefined *)(DAT_00005dec + 1)) {
  case 0xd:
    if (*DAT_00005e00 < 4) {
      local_122 = FUN_000059d4(&local_124,2);
      FUN_00007480(&local_124,3);
      *DAT_00005e04 = 0x8f9;
      FUN_000096c6(*DAT_00005e08);
    }
    break;
  case 0xe:
    local_122 = 0x12;
    local_121[0] = *(byte *)(DAT_00005e0c + 2);
    local_121[1] = *(undefined *)(DAT_00005e10 + 1);
    local_121[2] = *(undefined *)(DAT_00005e10 + 2);
    local_121[3] = *(undefined *)(DAT_00005e10 + 3);
    local_11d = *(undefined *)(DAT_00005e10 + 4);
    local_11c = *(undefined *)(DAT_00005e10 + 5);
    local_11b = *(undefined *)(DAT_00005e10 + 6);
    local_11a = *(undefined *)(DAT_00005e10 + 7);
    local_117 = *(undefined *)(DAT_00005e10 + 10);
    local_116 = *(undefined *)(DAT_00005e10 + 0xb);
    local_118 = *(undefined *)(DAT_00005e10 + 9);
    local_115 = 0xff;
    local_114 = *(undefined *)(DAT_00005e10 + 0xd);
    local_113 = FUN_000059d4(&local_124,0x11);
    FUN_00007480(&local_124,0x12);
    break;
  case 0xf:
    local_122 = 0x10;
    local_121[0] = *DAT_00005e00;
    local_121[1] = *(undefined *)(DAT_00005e14 + (uint)*DAT_00005e18);
    FUN_00005a22(&local_124);
    if (*DAT_00005e18 == 0) {
      if (*DAT_00005e00 == 2) {
        local_121[2] = *(undefined *)(DAT_00005e1c + 5);
      }
      else if (*DAT_00005e00 == 3) {
        local_121[2] = *(undefined *)(DAT_00005e1c + 5);
        bVar1 = *(byte *)(DAT_00005e1c + 5);
        if (bVar1 == 9) {
LAB_00005bee:
          local_121[3] = *(byte *)(DAT_00005e20 + 5) | *(char *)(DAT_00005e20 + 4) << 4;
        }
        else if (bVar1 < 10) {
          if ((bVar1 != 0) && (bVar1 != 8)) {
LAB_00005c02:
            local_121[3] = *DAT_00005e24;
          }
        }
        else {
          if (bVar1 == 10) goto LAB_00005bee;
          if (bVar1 != 0xc) goto LAB_00005c02;
        }
      }
    }
    else if (*DAT_00005e18 == 1) {
      if ((*DAT_00005e00 == 2) || (*DAT_00005e00 == 3)) {
        local_121[2] = *DAT_00005e28;
      }
    }
    else {
      switch(*DAT_00005e00) {
      case 2:
        if ((*DAT_00005e18 != 3) && (*DAT_00005e18 != 8)) {
          local_121[2] = *DAT_00005e28;
        }
        break;
      case 3:
      case 4:
      case 5:
      case 6:
        local_121[2] = *DAT_00005e28;
        local_121[3] = (byte)((ushort)*(undefined2 *)(DAT_00005e2c + 6) >> 8);
        local_11d = *(undefined *)(DAT_00005e2c + 6);
        local_11c = *(undefined *)(DAT_00005e2c + 5);
        local_11b = *(undefined *)(DAT_00005e2c + 8);
        local_11a = *DAT_00005e30;
        if ((*DAT_00005e18 < 2) || (*DAT_00005e00 < 3)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          local_119 = 0;
          local_118 = 0;
        }
        else {
          local_119 = *DAT_00005e34;
          local_118 = *DAT_00005e38;
        }
        local_117 = *DAT_00005e3c;
        local_116 = FUN_00005a36();
        break;
      case 7:
        local_121[2] = *DAT_00005e28;
        local_117 = *DAT_00005e3c;
        local_116 = FUN_00005a36();
      }
    }
    local_115 = FUN_000059d4(&local_124,0xf);
    FUN_00007480(&local_124,0x10);
    break;
  case 0x10:
    cVar5 = '\0';
    if ((*(byte *)(DAT_00006190 + 10) < 2) || (*(byte *)(DAT_00006190 + 10) == 0xff)) {
      bVar1 = *(byte *)(DAT_00006190 + 3);
      if ((bVar1 < 8) || (bVar1 == 0xff)) {
        bVar7 = *(byte *)(DAT_00006194 + (uint)*(byte *)(DAT_00006190 + 4));
        uVar6 = (uint)bVar7;
        if ((uVar6 < 9) || (uVar6 == 0xff)) {
          *(byte *)(DAT_00006190 + 4) = bVar7;
          uVar8 = (uint)*(byte *)(iVar10 + 5);
          iVar10 = FUN_00000e58(*(undefined *)(DAT_00006198 + uVar6));
          if ((iVar10 < (int)uVar8) && (uVar8 != 0xff)) {
            cVar5 = '\x04';
          }
          else {
            uVar9 = (uint)CONCAT11(*(undefined *)(DAT_00006190 + 6),*(undefined *)(DAT_00006190 + 7)
                                  );
            iVar10 = FUN_00000fa8(uVar6,uVar8);
            iVar3 = FUN_00001b54(iVar10,*(undefined *)(DAT_00006190 + 10));
            if ((iVar3 < (int)uVar9) && (uVar9 != 0xffff)) {
              cVar5 = '\b';
            }
            else {
              bVar7 = *(byte *)(DAT_00006190 + 8);
              if ((*(byte *)(DAT_0000619c + iVar10 * 10 + 3) < bVar7) && (bVar7 != 0xff)) {
                cVar5 = '\x10';
              }
              else {
                uVar6 = (uint)*(byte *)(DAT_00006190 + 9);
                if (uVar6 != 0xff) {
                  if (bVar7 == 0xff) {
                    bVar7 = *(byte *)(DAT_000061a0 + 5);
                  }
                  iVar10 = FUN_00001958(iVar10,bVar7,uVar6);
                  if (iVar10 < (int)uVar6) {
                    cVar5 = ' ';
                    goto code_r0x00005fec;
                  }
                }
                if (((*DAT_000061a4 < 3) && (bVar1 == 0xff)) &&
                   ((uVar9 != 0xffff || ((bVar7 != 0xff || (uVar6 != 0xff)))))) {
                  cVar5 = '\x01';
                }
              }
            }
          }
        }
        else {
          cVar5 = '\x02';
        }
      }
      else {
        cVar5 = '\x01';
      }
    }
    else {
      cVar5 = '@';
    }
code_r0x00005fec:
    if (cVar5 == '\0') {
      for (uVar6 = 0; uVar6 < 8; uVar6 = uVar6 + 1 & 0xff) {
        *(undefined *)(DAT_000061a8 + uVar6) = *(undefined *)(DAT_00006190 + uVar6 + 3);
      }
      *DAT_000061ac = 0x8fa;
      FUN_000096c6(*DAT_000061b0);
    }
    local_123 = *(undefined *)(DAT_00006190 + 1);
    local_122 = cVar5;
    local_121[0] = FUN_000059d4(&local_124,3);
    FUN_00007480(&local_124,4);
    break;
  case 0x11:
    local_122 = 0x10;
    uVar4 = *(undefined4 *)(DAT_00005e40 + 0xc0);
    local_121[0] = (byte)((uint)uVar4 >> 0x18);
    local_121[1] = (byte)((uint)uVar4 >> 0x10);
    local_121[2] = (byte)((uint)uVar4 >> 8);
    local_121[3] = (byte)uVar4;
    uVar4 = *(undefined4 *)(DAT_00005e40 + 0xc4);
    local_11d = (byte)((uint)uVar4 >> 0x18);
    local_11c = (byte)((uint)uVar4 >> 0x10);
    local_11b = (undefined)((uint)uVar4 >> 8);
    local_11a = (undefined)uVar4;
    uVar4 = *(undefined4 *)(DAT_00005e40 + 200);
    local_119 = (undefined)((uint)uVar4 >> 0x18);
    local_118 = (undefined)((uint)uVar4 >> 0x10);
    local_117 = (undefined)((uint)uVar4 >> 8);
    local_116 = (undefined)uVar4;
    local_115 = FUN_000059d4(&local_124,0xf);
    FUN_00007480(&local_124,0x10);
    break;
  case 0x12:
    if (*(byte *)(DAT_00006190 + 2) < 0x1e) {
      thunk_FUN_00008b3a(DAT_000061b4,DAT_00006190 + 3,*(byte *)(DAT_00006190 + 2) - 4);
      local_122 = FUN_000059d4(&local_124,2);
      FUN_00007480(&local_124,3);
      FUN_0000bac2();
    }
    break;
  case 0x13:
    local_122 = 0xc;
    local_121[0] = *DAT_00006184;
    local_121[1] = DAT_00006184[1];
    local_121[2] = DAT_00006184[2];
    local_121[3] = DAT_00006184[3];
    local_11d = DAT_00006184[4];
    local_11c = DAT_00006184[5];
    local_11b = *DAT_00006188;
    local_11a = *DAT_0000618c;
    local_119 = FUN_000059d4(&local_124,0xb);
    FUN_00007480(&local_124,0xc);
    break;
  case 0x14:
    local_122 = 0xc4;
    for (uVar6 = 0; uVar6 < 0x18; uVar6 = uVar6 + 1) {
      for (uVar8 = 0; uVar8 < 2; uVar8 = uVar8 + 1) {
        iVar10 = *(int *)(DAT_00005e40 + (uint)*(byte *)(DAT_00005e44 + uVar6) * 8 + uVar8 * 4);
        for (uVar9 = 0; uVar9 < 4; uVar9 = uVar9 + 1) {
          local_121[(uVar8 + uVar6 * 2) * 4 + uVar9] = (byte)((uint)iVar10 >> 0x18);
          iVar10 = iVar10 << 8;
        }
      }
    }
    uStack_61 = FUN_000059d4(&local_124,0xc3);
    FUN_00007480(&local_124,0xc4);
    break;
  default:
    bVar1 = *(byte *)(DAT_00006190 + 1);
    local_122 = FUN_000059d4(&local_124,2);
    FUN_00007480(&local_124,3);
    *DAT_000061ac = (1 << (bVar1 - 1 & 0xff)) + 0x800;
    FUN_000096c6(*DAT_000061b0);
  }
  *DAT_000061c0 = (uint)*(ushort *)(DAT_000061bc + (uint)*(byte *)(DAT_000061b8 + 1) * 2) * 0x3c;
  *(undefined *)(DAT_000061b4 + -0x27) = 0;
  return;
}



// ==========================================
// Function: FUN_000060ce
// Address:  000060ce
// Size:     22 bytes
// ==========================================

void FUN_000060ce(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00008654(0);
  *DAT_000061c4 = uVar1;
  FUN_00000ee6();
  FUN_00005a10();
  return;
}



// ==========================================
// Function: FUN_000061f4
// Address:  000061f4
// Size:     18 bytes
// ==========================================

void FUN_000061f4(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00006438;
  *(uint *)(DAT_00006438 + 0x40) = (uint)*(byte *)(DAT_00006440 + param_1);
  *(undefined4 *)(iVar1 + 0x50) = 0x11;
  *(undefined4 *)(iVar1 + 4) = 9;
  return;
}



// ==========================================
// Function: FUN_00006206
// Address:  00006206
// Size:     160 bytes
// ==========================================

undefined8 FUN_00006206(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 uStack_c;
  
  *DAT_00006444 = *DAT_00006444 | 0x20;
  iVar1 = DAT_00006448;
  *(uint *)(DAT_00006448 + 0x1cc) = *(uint *)(DAT_00006448 + 0x1cc) & 0xfffffff8;
  *DAT_0000644c = *(uint *)(iVar1 + 0x1cc) | 2;
  iVar1 = DAT_00006438;
  *(undefined4 *)(DAT_00006438 + 4) = 2;
  *(undefined4 *)(iVar1 + 0xc) = 0x95;
  *(undefined4 *)(iVar1 + 0x14) = 2;
  *(undefined4 *)(iVar1 + 0x18) = 100;
  uStack_c = in_r3;
  FUN_000061f4(*(undefined *)(DAT_00006450 + 2));
  uVar2 = FUN_00009e60(2,0,1,DAT_00006460,0,s_tmr_beep_00006454,&uStack_c);
  *DAT_00006464 = uVar2;
  uVar2 = FUN_00009e60(4,0,1,DAT_00006460,0,s_tmr_beep_00006454,&uStack_c);
  *DAT_00006468 = uVar2;
  uVar3 = 0;
  pcVar4 = s_tmr_TimeSet_0000646c;
  uVar2 = FUN_00009e60(2,0,1,DAT_00006478,0,s_tmr_TimeSet_0000646c,&uStack_c);
  *DAT_0000647c = uVar2;
  return CONCAT44(pcVar4,uVar3);
}



// ==========================================
// Function: FUN_000062a6
// Address:  000062a6
// Size:     80 bytes
// ==========================================

void FUN_000062a6(void)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  for (uVar1 = 0; uVar1 < 6; uVar1 = uVar1 + 1 & 0xff) {
    puVar2 = *(uint **)(DAT_00006480 + uVar1 * 0xc);
    for (uVar3 = 0; uVar3 < *(byte *)(DAT_00006480 + uVar1 * 0xc + 8); uVar3 = uVar3 + 1 & 0xff) {
      uVar4 = 1 << *(sbyte *)(*(int *)(DAT_00006480 + uVar1 * 0xc + 4) + uVar3);
      *puVar2 = *puVar2 | uVar4;
      puVar2[7] = uVar4;
    }
  }
  return;
}



// ==========================================
// Function: FUN_000062f6
// Address:  000062f6
// Size:     26 bytes
// ==========================================

void FUN_000062f6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_10;
  
  *(uint *)(DAT_00006438 + 0x4c) = *(uint *)(DAT_00006438 + 0x4c) | 0x1000;
  uStack_10 = param_4;
  FUN_0000a066(param_1,&uStack_10);
  return;
}



// ==========================================
// Function: FUN_00006310
// Address:  00006310
// Size:     28 bytes
// ==========================================

void FUN_00006310(void)

{
  undefined4 in_r3;
  undefined4 auStack_8 [2];
  
  *DAT_0000643c = (*DAT_0000643c & 0xffbf) + 0x40;
  auStack_8[0] = in_r3;
  FUN_0000a066(*DAT_0000647c,auStack_8);
  return;
}



// ==========================================
// Function: FUN_0000632c
// Address:  0000632c
// Size:     96 bytes
// ==========================================

void FUN_0000632c(int param_1)

{
  byte *local_8;
  
  if (param_1 == 0) {
    *(uint *)(DAT_00006484 + 0x18) = *(uint *)(DAT_00006484 + 0x18) & 0xfffff7ff;
    for (local_8 = &BYTE_00002710; local_8 != (byte *)0x0; local_8 = local_8 + -1) {
    }
    *(uint *)(DAT_00006484 + 0x18) = *(uint *)(DAT_00006484 + 0x18) & 0xfffffffe;
  }
  else {
    *(uint *)(DAT_00006484 + 0x18) = *(uint *)(DAT_00006484 + 0x18) | 1;
    for (local_8 = &BYTE_00002710; local_8 != (byte *)0x0; local_8 = local_8 + -1) {
    }
    *(uint *)(DAT_00006484 + 0x18) = *(uint *)(DAT_00006484 + 0x18) | 0x800;
  }
  return;
}



// ==========================================
// Function: FUN_0000638c
// Address:  0000638c
// Size:     32 bytes
// ==========================================

void FUN_0000638c(int param_1)

{
  if (param_1 < 5) {
    *(undefined4 *)(*(int *)(DAT_00006488 + param_1 * 0xc) + 0x1c) =
         *(undefined4 *)(DAT_00006488 + param_1 * 0xc + 4);
  }
  return;
}



// ==========================================
// Function: FUN_000063ac
// Address:  000063ac
// Size:     22 bytes
// ==========================================

void FUN_000063ac(void)

{
  FUN_0000632c(0);
  FUN_0000638c(1);
  FUN_0000638c(2);
  return;
}



// ==========================================
// Function: FUN_000063c2
// Address:  000063c2
// Size:     86 bytes
// ==========================================

void FUN_000063c2(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  for (uVar2 = 0; iVar1 = DAT_00006488, uVar2 < 5; uVar2 = uVar2 + 1) {
    puVar3 = *(uint **)(DAT_00006488 + uVar2 * 0xc);
    *puVar3 = *puVar3 | *(uint *)(DAT_00006488 + uVar2 * 0xc + 4);
    if (*(char *)(iVar1 + uVar2 * 0xc + 8) == '\x01') {
      puVar3[6] = *(uint *)(iVar1 + uVar2 * 0xc + 4);
    }
    else {
      puVar3[7] = *(uint *)(DAT_00006488 + uVar2 * 0xc + 4);
    }
  }
  return;
}



// ==========================================
// Function: FUN_00006418
// Address:  00006418
// Size:     32 bytes
// ==========================================

void FUN_00006418(int param_1)

{
  if (param_1 < 5) {
    *(undefined4 *)(*(int *)(DAT_00006488 + param_1 * 0xc) + 0x18) =
         *(undefined4 *)(DAT_00006488 + param_1 * 0xc + 4);
  }
  return;
}



// ==========================================
// Function: FUN_000064d4
// Address:  000064d4
// Size:     174 bytes
// ==========================================

void FUN_000064d4(void)

{
  undefined4 *puVar1;
  
  *DAT_00006694 = 0x21;
  *(undefined4 *)(DAT_00006698 + 0x144) = 0x21;
  DAT_00006694[2] = 0x21;
  DAT_00006694[4] = 0x21;
  DAT_00006694[8] = 0x21;
  puVar1 = DAT_00006694;
  DAT_00006694[0xc] = 0x21;
  puVar1[0xd] = 0x21;
  puVar1 = DAT_00006694;
  DAT_00006694[0x10] = 0x21;
  puVar1[0x11] = 0x21;
  puVar1[0x12] = 0x21;
  puVar1[0x13] = 0x21;
  puVar1[0x14] = 0x21;
  puVar1[0x15] = 0x21;
  puVar1[0x16] = 0x21;
  puVar1[0x17] = 0x21;
  puVar1[0x18] = 0x21;
  puVar1[0x19] = 0x21;
  puVar1[0x1a] = 0x21;
  puVar1[0x1b] = 0x21;
  puVar1[0x1c] = 0x21;
  puVar1[0x1d] = 0x21;
  puVar1[0x1e] = 0x21;
  puVar1[0x1f] = 0x21;
  puVar1 = DAT_00006694;
  DAT_00006694[0x30] = 0x21;
  puVar1[0x31] = 0x21;
  puVar1[0x32] = 0x21;
  puVar1[0x33] = 0x21;
  puVar1[0x34] = 0x21;
  puVar1[0x35] = 0x21;
  puVar1[0x36] = 0x21;
  puVar1[0x37] = 0x21;
  puVar1[0x38] = 0x21;
  puVar1[0x39] = 0x21;
  puVar1[0x3a] = 0x21;
  puVar1[0x3b] = 0x21;
  puVar1[0x3c] = 0x21;
  puVar1[0x3d] = 0x21;
  puVar1[0x3e] = 0x21;
  *DAT_0000669c = 0x21;
  return;
}



// ==========================================
// Function: FUN_00006582
// Address:  00006582
// Size:     274 bytes
// ==========================================

void FUN_00006582(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined *local_8;
  
  FUN_000064d4();
  puVar1 = DAT_000066a0;
  *DAT_000066a0 = *DAT_000066a0 | 0x800;
  puVar1[0x46] = puVar1[0x46] | 8;
  puVar1[0x46] = puVar1[0x46] | 0x800;
  *DAT_000066a4 = puVar1[0x46] | 0x80000;
  puVar2 = DAT_000066a8;
  *DAT_000066a8 = 1;
  puVar2[10] = 1;
  puVar2[0x41] = 0;
  puVar2[0x41] = puVar2[0x41] | 0x300;
  *DAT_000066ac = puVar2[0x41] | 3;
  puVar2 = DAT_000066a8;
  DAT_000066a8[0xc] = 3;
  puVar2[0xd] = 6;
  puVar2[0xe] = 10;
  puVar2[0xf] = 1;
  puVar2[0x10] = 6;
  puVar2[0x11] = 3;
  puVar2[0x12] = 8;
  puVar2[0x13] = 8;
  puVar2[0x14] = 10;
  puVar2[0x15] = 2;
  puVar2[0x16] = 3;
  DAT_000066ac[-1] = 0x280;
  DAT_000066a8[8] = 0x183;
  puVar2 = DAT_000066a8;
  for (local_8 = &DAT_00004650; local_8 != (undefined *)0x0; local_8 = local_8 + -1) {
  }
  DAT_000066a8[8] = 0x103;
  puVar2[9] = 2;
  puVar2 = DAT_000066a8;
  for (local_8 = (undefined *)0x300; local_8 != (undefined *)0x0;
      local_8 = (undefined *)((int)local_8 + -1)) {
  }
  DAT_000066a8[9] = 0x3a;
  puVar2[8] = 0x83;
  puVar2[8] = 0;
  puVar2[0x40] = DAT_000066ac[-1] | 0x80000;
  for (local_8 = (undefined *)DAT_000066b4; local_8 != (undefined *)0x0;
      local_8 = (undefined *)((int)local_8 + -1)) {
  }
  return;
}



// ==========================================
// Function: FUN_000066b8
// Address:  000066b8
// Size:     18 bytes
// ==========================================

void FUN_000066b8(undefined4 param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_00006970;
  for (uVar1 = 0; uVar1 < 0x1fe00; uVar1 = uVar1 + 1) {
    *puVar2 = param_1;
    puVar2 = puVar2 + 1;
  }
  return;
}



// ==========================================
// Function: FUN_000066ca
// Address:  000066ca
// Size:     36 bytes
// ==========================================

void FUN_000066ca(uint param_1,uint param_2,undefined4 param_3)

{
  if ((param_1 < 0x1e0) && (param_2 < 0x110)) {
    *(undefined4 *)(DAT_00006970 + param_2 * 0x780 + param_1 * 4) = param_3;
  }
  return;
}



// ==========================================
// Function: FUN_000066ee
// Address:  000066ee
// Size:     58 bytes
// ==========================================

void FUN_000066ee(uint param_1,uint param_2,int param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  
  for (uVar2 = param_2; uVar1 = param_1, uVar2 < param_2 + param_4; uVar2 = uVar2 + 1) {
    for (; uVar1 < param_1 + param_3; uVar1 = uVar1 + 1) {
      FUN_000066ca(uVar1,uVar2,param_5);
    }
  }
  return;
}



// ==========================================
// Function: FUN_00006728
// Address:  00006728
// Size:     156 bytes
// ==========================================

void FUN_00006728(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_00006974;
  *(undefined4 *)(DAT_00006974 + 0x10) = 0x27;
  *(undefined4 *)(iVar1 + 0x14) = 0x27;
  *DAT_00006978 = 0x27;
  *(undefined4 *)(DAT_00006974 + 0x274) = 0x27;
  puVar2 = DAT_0000697c;
  *DAT_0000697c = 0x27;
  puVar2[1] = 0x27;
  puVar2[2] = 0x27;
  puVar2[3] = 0x27;
  iVar1 = DAT_00006974;
  *(undefined4 *)(DAT_00006974 + 0x18) = 0x27;
  *(undefined4 *)(iVar1 + 0x1c) = 0x27;
  puVar2 = DAT_0000697c;
  DAT_0000697c[-0x12] = 0x27;
  puVar2[-0x11] = 0x27;
  puVar2[-0x10] = 0x27;
  puVar2[-0xf] = 0x27;
  puVar2[-0xe] = 0x27;
  puVar2[-0xd] = 0x27;
  iVar1 = DAT_00006974;
  *(undefined4 *)(DAT_00006974 + 0x20) = 0x27;
  *(undefined4 *)(iVar1 + 0x24) = 0x27;
  puVar2 = DAT_0000697c;
  DAT_0000697c[6] = 0x27;
  puVar2[7] = 0x27;
  puVar2 = DAT_0000697c;
  DAT_0000697c[-0xc] = 0x27;
  puVar2[-0xb] = 0x27;
  puVar2[-10] = 0x27;
  puVar2[-9] = 0x27;
  puVar2 = DAT_0000697c;
  DAT_0000697c[-5] = 0x20;
  puVar2[-4] = 0x27;
  puVar2[-3] = 0x27;
  puVar2[-2] = 0x27;
  puVar2[-1] = 0x27;
  DAT_0000697c[-6] = 7;
  puVar2 = DAT_0000697c;
  DAT_0000697c[-4] = 7;
  puVar2[-3] = 7;
  puVar2[-2] = 7;
  *(undefined4 *)(DAT_00006974 + 0x114) = 7;
  return;
}



// ==========================================
// Function: FUN_000067c4
// Address:  000067c4
// Size:     332 bytes
// ==========================================

void FUN_000067c4(void)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int local_8;
  
  FUN_00006728();
  *DAT_00006980 = *DAT_00006980 | 1;
  *DAT_00006984 = *DAT_00006984 & 0xfffffffe;
  puVar2 = DAT_00006988;
  DAT_00006988[6] = 0;
  puVar2[6] = puVar2[6] | 10;
  puVar2[6] = puVar2[6] | 0x20;
  puVar2[6] = puVar2[6] & 0xffffff7f;
  puVar2[6] = puVar2[6] | 0x100;
  puVar2[6] = puVar2[6] & 0xfffffdff;
  puVar2[6] = puVar2[6] & 0xfffffbff;
  puVar2[6] = puVar2[6] & 0xfffff7ff;
  DAT_00006980[0x3d] = *DAT_0000698c / DAT_00006990;
  puVar2 = DAT_00006988;
  DAT_00006988[2] = DAT_00006988[2] | 0x4000000;
  puVar2[2] = puVar2[2] & 0xffffffdf;
  puVar2[2] = puVar2[2] | 0x800;
  puVar2[2] = puVar2[2] | 0x1000;
  puVar2[2] = puVar2[2] & 0xffffdfff;
  puVar2[2] = puVar2[2] & 0xffffbfff;
  puVar3 = DAT_00006988;
  DAT_00006988[2] = puVar2[2] & DAT_00006994;
  puVar2 = DAT_00006988;
  DAT_00006988[2] = puVar3[2] | DAT_00006998;
  *puVar2 = 0;
  *puVar2 = *puVar2 | 0x13000000;
  *puVar2 = *puVar2 | 0x70000;
  *puVar2 = *puVar2 | 0x300;
  *puVar2 = *puVar2 | 0x74;
  puVar2[1] = 0;
  puVar2[1] = puVar2[1] | 0xa000000;
  puVar2[1] = puVar2[1] | 0x80000;
  puVar2[1] = puVar2[1] | 0xc00;
  puVar3 = DAT_00006988;
  DAT_00006988[1] = puVar2[1] | 0x10f;
  uVar1 = DAT_00006970;
  puVar3[4] = DAT_00006970;
  puVar3[5] = uVar1;
  for (local_8 = DAT_0000699c; local_8 != 0; local_8 = local_8 + -1) {
  }
  return;
}



// ==========================================
// Function: FUN_00006910
// Address:  00006910
// Size:     96 bytes
// ==========================================

void FUN_00006910(int param_1)

{
  byte *local_8;
  
  if (param_1 == 0) {
    *(uint *)(DAT_00006988 + 0x18) = *(uint *)(DAT_00006988 + 0x18) & 0xfffff7ff;
    for (local_8 = &BYTE_00002710; local_8 != (byte *)0x0; local_8 = local_8 + -1) {
    }
    *(uint *)(DAT_00006988 + 0x18) = *(uint *)(DAT_00006988 + 0x18) & 0xfffffffe;
  }
  else {
    *(uint *)(DAT_00006988 + 0x18) = *(uint *)(DAT_00006988 + 0x18) | 1;
    for (local_8 = &BYTE_00002710; local_8 != (byte *)0x0; local_8 = local_8 + -1) {
    }
    *(uint *)(DAT_00006988 + 0x18) = *(uint *)(DAT_00006988 + 0x18) | 0x800;
  }
  return;
}



// ==========================================
// Function: FUN_000069a0
// Address:  000069a0
// Size:     322 bytes
// ==========================================

void FUN_000069a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  *DAT_00006d88 = *DAT_00006d88 | 0x200000;
  iVar1 = DAT_00006d8c;
  *(uint *)(DAT_00006d8c + 0x250) = *(uint *)(DAT_00006d8c + 0x250) & 0xfffffff8;
  *(uint *)(iVar1 + 0x250) = *(uint *)(iVar1 + 0x250) | 3;
  *(uint *)(iVar1 + 600) = *(uint *)(iVar1 + 600) & 0xfffffff8;
  *(uint *)(iVar1 + 600) = *(uint *)(iVar1 + 600) | 3;
  *(uint *)(iVar1 + 0x25c) = *(uint *)(iVar1 + 0x25c) & 0xfffffff8;
  *(uint *)(iVar1 + 0x25c) = *(uint *)(iVar1 + 0x25c) | 3;
  *(uint *)(iVar1 + 0x254) = *(uint *)(iVar1 + 0x254) & 0xfffffff8;
  *(undefined4 *)(iVar1 + 0x254) = *DAT_00006d90;
  iVar1 = DAT_00006d94;
  *(uint *)(DAT_00006d94 + 0x98) = *(uint *)(DAT_00006d94 + 0x98) | 0x200000;
  *(uint *)(iVar1 + 0x80) = *(uint *)(iVar1 + 0x80) | 0x200000;
  iVar1 = DAT_00006d8c;
  *(uint *)(DAT_00006d8c + 0x244) = *(uint *)(DAT_00006d8c + 0x244) & 0xfffffff8;
  *(undefined4 *)(iVar1 + 0x244) = DAT_00006d90[-4];
  iVar1 = DAT_00006d94;
  *(uint *)(DAT_00006d94 + 0x80) = *(uint *)(DAT_00006d94 + 0x80) | 0x20000;
  *(uint *)(iVar1 + 0x98) = *(uint *)(iVar1 + 0x98) | 0x20000;
  iVar1 = DAT_00006d8c;
  *(uint *)(DAT_00006d8c + 0x248) = *(uint *)(DAT_00006d8c + 0x248) & 0xfffffff8;
  *(undefined4 *)(iVar1 + 0x248) = DAT_00006d90[-3];
  iVar1 = DAT_00006d94;
  *(uint *)(DAT_00006d94 + 0x80) = *(uint *)(DAT_00006d94 + 0x80) | 0x40000;
  *(uint *)(DAT_00006d94 + 0x98) = *(uint *)(iVar1 + 0x98) | 0x40000;
  puVar2 = DAT_00006d98;
  *DAT_00006d98 = 7;
  puVar2[1] = 2;
  puVar2[4] = 2;
  do {
  } while ((DAT_00006d98[3] & 0x10) != 0);
  do {
  } while ((DAT_00006d98[3] & 4) != 0);
  return;
}



// ==========================================
// Function: FUN_00006ae2
// Address:  00006ae2
// Size:     56 bytes
// ==========================================

uint FUN_00006ae2(undefined4 param_1)

{
  do {
  } while ((*(uint *)(DAT_00006d98 + 0xc) & 0x10) != 0);
  *(undefined4 *)(DAT_00006d98 + 8) = param_1;
  do {
  } while ((*(uint *)(DAT_00006d98 + 0xc) & 0x10) != 0);
  do {
  } while ((*(uint *)(DAT_00006d98 + 0xc) & 4) == 0);
  return *(uint *)(DAT_00006d98 + 8) & 0xff;
}



// ==========================================
// Function: FUN_00006b1a
// Address:  00006b1a
// Size:     52 bytes
// ==========================================

undefined4 FUN_00006b1a(void)

{
  undefined4 uVar1;
  
  *(uint *)(DAT_00006d94 + 0x9c) = *(uint *)(DAT_00006d94 + 0x9c) | 0x200000;
  FUN_00006ae2(5);
  uVar1 = FUN_00006ae2(0xff);
  *(uint *)(DAT_00006d94 + 0x98) = *(uint *)(DAT_00006d94 + 0x98) | 0x200000;
  return uVar1;
}



// ==========================================
// Function: FUN_00006b4e
// Address:  00006b4e
// Size:     70 bytes
// ==========================================

void FUN_00006b4e(void)

{
  uint uVar1;
  
  do {
    uVar1 = FUN_00006b1a();
  } while ((uVar1 & 1) != 0);
  *(uint *)(DAT_00006d94 + 0x9c) = *(uint *)(DAT_00006d94 + 0x9c) | 0x200000;
  FUN_00006ae2(6);
  *(uint *)(DAT_00006d94 + 0x98) = *(uint *)(DAT_00006d94 + 0x98) | 0x200000;
  do {
    uVar1 = FUN_00006b1a();
  } while ((uVar1 & 3) != 2);
  return;
}



// ==========================================
// Function: FUN_00006b94
// Address:  00006b94
// Size:     144 bytes
// ==========================================

uint FUN_00006b94(uint param_1,int param_2,uint param_3)

{
  undefined uVar1;
  uint uVar2;
  
  if (((param_3 == 0) || (0x48ab < param_3)) || (param_2 == 0)) {
    uVar2 = 0;
  }
  else {
    while (uVar2 = FUN_00006b1a(), (uVar2 & 1) != 0) {
      for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1) {
      }
    }
    *(uint *)(DAT_00006d94 + 0x9c) = *(uint *)(DAT_00006d94 + 0x9c) | 0x200000;
    FUN_00006ae2(3);
    FUN_00006ae2((param_1 << 8) >> 0x18);
    FUN_00006ae2((param_1 << 0x10) >> 0x18);
    FUN_00006ae2(param_1 & 0xff);
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
      uVar1 = FUN_00006ae2(0xff);
      *(undefined *)(param_2 + uVar2) = uVar1;
    }
    *(uint *)(DAT_00006d94 + 0x98) = *(uint *)(DAT_00006d94 + 0x98) | 0x200000;
    uVar2 = uVar2 & 0xff;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_00006c24
// Address:  00006c24
// Size:     118 bytes
// ==========================================

undefined4 FUN_00006c24(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((param_3 == 0) || (param_2 == 0)) {
    uVar1 = 0;
  }
  else {
    FUN_00006b4e();
    *(uint *)(DAT_00006d94 + 0x9c) = *(uint *)(DAT_00006d94 + 0x9c) | 0x200000;
    FUN_00006ae2(2);
    FUN_00006ae2((param_1 << 8) >> 0x18);
    FUN_00006ae2((param_1 << 0x10) >> 0x18);
    FUN_00006ae2(param_1 & 0xff);
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
      FUN_00006ae2(*(undefined *)(param_2 + uVar2));
    }
    *(uint *)(DAT_00006d94 + 0x98) = *(uint *)(DAT_00006d94 + 0x98) | 0x200000;
    do {
      uVar2 = FUN_00006b1a();
    } while ((uVar2 & 1) != 0);
    uVar1 = 1;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00006c9a
// Address:  00006c9a
// Size:     124 bytes
// ==========================================

undefined4 FUN_00006c9a(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = 0;
  if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    if ((param_1 & 0xff) != 0) {
      uVar3 = 0x100 - (param_1 & 0xff);
      if (param_3 <= uVar3) {
        FUN_00006c24(param_1,param_2,param_3);
        return 1;
      }
      FUN_00006c24(param_1,param_2,uVar3);
    }
    uVar4 = param_3 - uVar3 & 0xff;
    for (uVar2 = 0; uVar2 < param_3 - uVar3 >> 8; uVar2 = uVar2 + 1) {
      iVar5 = uVar3 + uVar2 * 0x100;
      FUN_00006c24(param_1 + iVar5,param_2 + iVar5,0x100);
    }
    if (uVar4 != 0) {
      iVar5 = uVar3 + uVar2 * 0x100;
      FUN_00006c24(param_1 + iVar5,param_2 + iVar5,uVar4);
    }
    uVar1 = 1;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00006d16
// Address:  00006d16
// Size:     86 bytes
// ==========================================

undefined4 FUN_00006d16(uint param_1)

{
  uint uVar1;
  
  FUN_00006b4e();
  *(uint *)(DAT_00006d94 + 0x9c) = *(uint *)(DAT_00006d94 + 0x9c) | 0x200000;
  FUN_00006ae2(0x20);
  FUN_00006ae2((param_1 << 8) >> 0x18);
  FUN_00006ae2((param_1 << 0x10) >> 0x18);
  FUN_00006ae2(param_1 & 0xff);
  *(uint *)(DAT_00006d94 + 0x98) = *(uint *)(DAT_00006d94 + 0x98) | 0x200000;
  do {
    uVar1 = FUN_00006b1a();
  } while ((uVar1 & 1) != 0);
  return 1;
}



// ==========================================
// Function: FUN_00006d6c
// Address:  00006d6c
// Size:     26 bytes
// ==========================================

undefined4 FUN_00006d6c(uint param_1,uint param_2)

{
  for (; param_1 <= param_2; param_1 = param_1 + 1) {
    FUN_00006d16(param_1 << 0xc);
  }
  return 1;
}



// ==========================================
// Function: FUN_00006ddc
// Address:  00006ddc
// Size:     46 bytes
// ==========================================

uint FUN_00006ddc(int param_1)

{
  uint uVar1;
  
  *DAT_00006e18 = *DAT_00006e18 & 0xf8ffffff;
  if ((DAT_00006e18[param_1 + 4] & 0x40000000) == 0) {
    uVar1 = (DAT_00006e18[param_1 + 4] << 0x10) >> 0x14;
  }
  else {
    uVar1 = 0xffffff;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00006e1c
// Address:  00006e1c
// Size:     128 bytes
// ==========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00006e1c(void)

{
  *DAT_0000706c = 0;
  _DAT_00200094 = *DAT_00007070 / DAT_00007074 - 1;
  _DAT_00200090 =
       ((*DAT_00007070 / DAT_00007078) * 0xf) / 1000 + 1 |
       (((*DAT_00007070 / DAT_00007078) * 0x37) / 1000 + 1) * 0x100 |
       (((*DAT_00007070 / DAT_00007078) * 0x23) / 1000 + 1) * 0x10000;
  return;
}



// ==========================================
// Function: FUN_00006e9c
// Address:  00006e9c
// Size:     214 bytes
// ==========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00006e9c(uint param_1,uint param_2,byte *param_3,int param_4,uint param_5)

{
  uint uVar1;
  
  *DAT_0000707c = 0x14000000;
  if (param_4 == 1) {
    if ((param_1 & 1) != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else if ((param_4 == 2) && ((param_1 & 3) != 0)) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  _DAT_00200084 = param_1 & 0x3f;
  *DAT_0000707c = 0x4000000;
  for (uVar1 = 0; uVar1 < param_5; uVar1 = uVar1 + 1) {
    if (param_4 == 0) {
      _DAT_00200080 = 3;
      _DAT_00200088 = (uint)*param_3;
      param_3 = param_3 + 1;
      param_1 = param_1 + 1 & 0xffff;
    }
    if (0x3f < (int)param_1 || param_5 - 1 == uVar1) {
      *DAT_0000707c = 0x10000000;
      _DAT_00200084 = (param_2 << 0x1a) >> 0x14;
      _DAT_00200080 = 6;
      do {
      } while (-1 < (int)(DAT_0000707c[-2] << 3));
    }
    if (0x3f < (int)param_1) {
      param_1 = 0;
      param_2 = param_2 + 1 & 0xffff;
      _DAT_00200084 = 0;
      if (0x3f < param_2) {
        param_2 = 0;
      }
    }
  }
  return;
}



// ==========================================
// Function: FUN_00006f72
// Address:  00006f72
// Size:     250 bytes
// ==========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00006f72(uint param_1,uint param_2,undefined *param_3,int param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  
  *DAT_0000707c = 0x14000000;
  _DAT_00200084 = param_1 & 0x3f | (param_2 & 0x3f) << 6;
  if (param_4 == 0) {
    _DAT_00200080 = 8;
  }
  else if (param_4 == 1) {
    _DAT_00200080 = 9;
    if ((param_1 & 1) != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  else {
    _DAT_00200080 = 10;
    if ((param_1 & 3) != 0) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
  }
  for (uVar1 = 0; uVar1 < param_5; uVar1 = uVar1 + 1) {
    *DAT_0000707c = 0x4000000;
    if (param_4 == 0) {
      *param_3 = (char)*(undefined4 *)(DAT_0000706c + -0xc);
      param_1 = param_1 + 1 & 0xffff;
    }
    else if (param_4 == 1) {
      *param_3 = (char)*(undefined4 *)(DAT_0000706c + -0xc);
      param_1 = param_1 + 2 & 0xffff;
    }
    else {
      *param_3 = (char)*(undefined4 *)(DAT_0000706c + -0xc);
      param_1 = param_1 + 4 & 0xffff;
    }
    do {
    } while (-1 < (int)(DAT_0000707c[-2] << 5));
    if (0x3f < param_1) {
      param_1 = 0;
      uVar2 = param_2 + 1;
      param_2 = uVar2 & 0xffff;
      _DAT_00200084 = (uVar2 & 0x3f) << 6;
      if (param_4 == 0) {
        _DAT_00200080 = 8;
      }
      else if (param_4 == 1) {
        _DAT_00200080 = 9;
      }
      else {
        _DAT_00200080 = 10;
      }
    }
    param_3 = param_3 + 1;
  }
  return;
}



// ==========================================
// Function: FUN_00007080
// Address:  00007080
// Size:     72 bytes
// ==========================================

void FUN_00007080(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00007160;
  if (param_1 == 0) {
    *DAT_00007160 = 0;
    puVar1[1] = 0xffff;
    *DAT_00007164 = 0;
  }
  else if (param_1 == 1) {
    *DAT_00007160 = 0x15;
    puVar1[1] = 0;
    *DAT_00007164 = 1;
  }
  else {
    if (param_1 != 2) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    *DAT_00007160 = 0x36;
    puVar1[1] = 0xffffffff;
    *DAT_00007164 = 2;
  }
  return;
}



// ==========================================
// Function: FUN_000070c8
// Address:  000070c8
// Size:     48 bytes
// ==========================================

void FUN_000070c8(void)

{
  if (*DAT_00007164 == '\0') {
    *(undefined4 *)(DAT_00007160 + 4) = 0xffff;
  }
  else if (*DAT_00007164 == '\x01') {
    *(undefined4 *)(DAT_00007160 + 4) = 0;
  }
  else if (*DAT_00007164 == '\x02') {
    *(undefined4 *)(DAT_00007160 + 4) = 0xffffffff;
  }
  return;
}



// ==========================================
// Function: FUN_00007118
// Address:  00007118
// Size:     70 bytes
// ==========================================

undefined4 FUN_00007118(undefined4 *param_1,int param_2,int param_3)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if (param_3 == 1) {
      *(undefined *)(DAT_00007160 + 8) = *(undefined *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 1);
    }
    else if (param_3 == 2) {
      *(undefined2 *)(DAT_00007160 + 8) = *(undefined2 *)param_1;
      param_1 = (undefined4 *)((int)param_1 + 2);
    }
    else {
      *(undefined4 *)(DAT_00007160 + 8) = *param_1;
      param_1 = param_1 + 1;
    }
  }
  return *(undefined4 *)(DAT_00007160 + 8);
}



// ==========================================
// Function: FUN_00007168
// Address:  00007168
// Size:     178 bytes
// ==========================================

void FUN_00007168(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  *DAT_0000726c = *DAT_0000726c | 0x200000;
  iVar1 = DAT_00007270;
  *(uint *)(DAT_00007270 + 0x3c) = *(uint *)(DAT_00007270 + 0x3c) & 0xfffffff8;
  *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) | 2;
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffff8;
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) | 2;
  iVar1 = DAT_00007274;
  *(uint *)(DAT_00007274 + 0x38) = *(uint *)(DAT_00007274 + 0x38) | 0x10000;
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | 0x10000;
  iVar1 = DAT_00007270;
  *(uint *)(DAT_00007270 + 0x44) = *(uint *)(DAT_00007270 + 0x44) & 0xfffffff8;
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) | 2;
  *(uint *)(iVar1 + 0x48) = *(uint *)(iVar1 + 0x48) & 0xfffffff8;
  *(uint *)(iVar1 + 0x48) = *(uint *)(iVar1 + 0x48) | 2;
  puVar2 = DAT_00007278;
  *DAT_00007278 = 0x87;
  puVar2[1] = 2;
  puVar2[4] = 0xe6;
  do {
  } while ((DAT_00007278[3] & 0x10) != 0);
  do {
  } while ((DAT_00007278[3] & 4) != 0);
  return;
}



// ==========================================
// Function: FUN_0000721a
// Address:  0000721a
// Size:     80 bytes
// ==========================================

uint FUN_0000721a(undefined4 param_1)

{
  *(uint *)(DAT_00007274 + 0x1c) = *(uint *)(DAT_00007274 + 0x1c) | 0x10000;
  do {
  } while ((*(uint *)(DAT_00007278 + 0xc) & 0x10) != 0);
  *(undefined4 *)(DAT_00007278 + 8) = param_1;
  do {
  } while ((*(uint *)(DAT_00007278 + 0xc) & 0x10) != 0);
  do {
  } while ((*(uint *)(DAT_00007278 + 0xc) & 4) == 0);
  *(uint *)(DAT_00007274 + 0x18) = *(uint *)(DAT_00007274 + 0x18) | 0x10000;
  return *(uint *)(DAT_00007278 + 8) & 0xff;
}



// ==========================================
// Function: FUN_0000727c
// Address:  0000727c
// Size:     50 bytes
// ==========================================

void FUN_0000727c(int param_1)

{
  undefined uVar1;
  byte bVar2;
  
  while ((DAT_000074d0[0x14] & 1) != 0) {
    uVar1 = *DAT_000074d0;
    bVar2 = *DAT_000074d4;
    *DAT_000074d4 = *DAT_000074d4 + 1;
    *(undefined *)(DAT_000074d8 + (uint)bVar2) = uVar1;
  }
  if (param_1 != 0) {
    FUN_000097da(*DAT_000074dc);
  }
  return;
}



// ==========================================
// Function: FUN_000072ae
// Address:  000072ae
// Size:     38 bytes
// ==========================================

void FUN_000072ae(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 in_r3;
  undefined4 local_10;
  
  uVar1 = 0;
  local_10 = in_r3;
  while ((uVar1 < 0x10 && (iVar2 = FUN_00007c7a(DAT_000074e0,&local_10), iVar2 == 0))) {
    *DAT_000074d0 = (undefined)local_10;
    uVar1 = uVar1 + 1;
  }
  return;
}



// ==========================================
// Function: FUN_000072d4
// Address:  000072d4
// Size:     134 bytes
// ==========================================

uint FUN_000072d4(undefined4 param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  
  uVar3 = FUN_0000d368(param_2 << 4);
  uVar4 = FUN_0000d368(param_1);
  uVar3 = FUN_0000d174(uVar4,uVar3);
  FUN_0000d174(uVar3,0x43800000);
  uVar2 = FUN_0000d2f8();
  uVar6 = (uint)uVar2;
  cVar7 = '\0';
  uVar4 = FUN_0000d338(uVar6 << 8);
  uVar3 = FUN_0000d4f0(uVar4,uVar3);
  FUN_0000d2f8(uVar3);
  uVar4 = FUN_0000d368();
  uVar4 = FUN_0000d4f0(uVar4,uVar3);
  FUN_0000d48e(uVar4,0x3f000000);
  if (cVar7 == '\0') {
    bVar1 = FUN_0000d2f8(uVar3);
    uVar6 = bVar1 + 1 | (uVar6 & 0xff) << 8;
  }
  else {
    uVar5 = FUN_0000d2f8(uVar3);
    uVar6 = uVar5 & 0xff | (uVar6 & 0xff) << 8;
  }
  return uVar6;
}



// ==========================================
// Function: FUN_0000735a
// Address:  0000735a
// Size:     144 bytes
// ==========================================

void FUN_0000735a(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined2 uVar3;
  
  *DAT_000074e4 = *DAT_000074e4 | 4;
  iVar2 = DAT_000074e8;
  *(uint *)(DAT_000074e8 + 8) = *(uint *)(DAT_000074e8 + 8) & 0xfffffff8;
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 1;
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffff8;
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 1;
  DAT_000074d0[0xc] = 0x83;
  uVar3 = FUN_000072d4(param_1,param_2);
  puVar1 = DAT_000074d0;
  DAT_000074d0[4] = (char)((ushort)uVar3 >> 8);
  *puVar1 = (char)uVar3;
  puVar1[0xc] = 3;
  puVar1[8] = 199;
  FUN_00007c5c(DAT_000074e0,DAT_000074ec,0x40);
  *DAT_000074d4 = 0;
  uRame000e100 = 0x20;
  *(undefined4 *)(DAT_000074d0 + 4) = 7;
  return;
}



// ==========================================
// Function: FUN_000073ea
// Address:  000073ea
// Size:     74 bytes
// ==========================================

void FUN_000073ea(void)

{
  *DAT_000074f0 = *DAT_000074f0 & 0xfffffff7;
  *DAT_000074f4 = 0x20;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}



// ==========================================
// Function: FUN_00007434
// Address:  00007434
// Size:     76 bytes
// ==========================================

uint FUN_00007434(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(DAT_000074d0 + 8);
  uVar2 = (int)(uVar1 & 0xff) >> 1 & 7;
  if (uVar2 == 1) {
    uVar1 = FUN_000072ae();
  }
  else if (uVar2 == 2) {
    uVar1 = FUN_0000727c(0);
  }
  else if (uVar2 == 3) {
    uVar1 = DAT_000074d0[0x14] & 0x9e;
    if ((DAT_000074d0[0x14] & 0x9e) != 0) {
      uVar1 = (uint)*DAT_000074d0;
    }
  }
  else if (uVar2 == 6) {
    uVar1 = FUN_0000727c(1);
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00007480
// Address:  00007480
// Size:     78 bytes
// ==========================================

uint FUN_00007480(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    *(uint *)(DAT_000074d0 + 4) = *(uint *)(DAT_000074d0 + 4) & 0xfffffffd;
    uVar1 = 0;
    while ((uVar1 < param_2 &&
           (iVar2 = FUN_00007ca8(DAT_000074e0,*(undefined *)(param_1 + uVar1)), iVar2 == 0))) {
      uVar1 = uVar1 + 1;
    }
    iVar2 = DAT_000074d0;
    *(uint *)(DAT_000074d0 + 4) = *(uint *)(DAT_000074d0 + 4) | 2;
    if ((*(byte *)(iVar2 + 0x14) & 0x20) != 0) {
      FUN_000072ae();
    }
  }
  return uVar1;
}



// ==========================================
// Function: FUN_000074f8
// Address:  000074f8
// Size:     84 bytes
// ==========================================

void FUN_000074f8(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  uVar1 = DAT_00007640;
  iVar5 = 0;
  for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1) {
    iVar4 = iVar5 + 1;
    *(char *)(param_1 + iVar5) = (char)(param_2 / uVar1) + '0';
    param_2 = param_2 - uVar1 * (param_2 / uVar1);
    uVar1 = uVar1 / 10;
    if (*(char *)(param_1 + iVar5) == '0' && iVar3 == 0) {
      iVar4 = 0;
    }
    else {
      iVar3 = iVar3 + 1;
    }
    iVar5 = iVar4;
  }
  return;
}



// ==========================================
// Function: FUN_0000754c
// Address:  0000754c
// Size:     244 bytes
// ==========================================

bool FUN_0000754c(char *param_1,int *param_2)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar3 = 0;
  bVar2 = false;
  iVar4 = 0;
  if ((*param_1 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
    for (uVar3 = 2;
        ((uVar3 < 0xb && (param_1[uVar3] != '\0')) &&
        ((((0x40 < (byte)param_1[uVar3] && ((byte)param_1[uVar3] < 0x47)) ||
          ((0x60 < (byte)param_1[uVar3] && ((byte)param_1[uVar3] < 0x67)))) ||
         ((0x2f < (byte)param_1[uVar3] && ((byte)param_1[uVar3] < 0x3a)))))); uVar3 = uVar3 + 1) {
      if (((byte)param_1[uVar3] < 0x30) || (0x39 < (byte)param_1[uVar3])) {
        if (((byte)param_1[uVar3] < 0x41) || (0x46 < (byte)param_1[uVar3])) {
          iVar5 = (byte)param_1[uVar3] - 0x57;
        }
        else {
          iVar5 = (byte)param_1[uVar3] - 0x37;
        }
      }
      else {
        iVar5 = (byte)param_1[uVar3] - 0x30;
      }
      iVar4 = iVar5 + iVar4 * 0x10;
    }
    cVar1 = param_1[uVar3];
    if (cVar1 == '\0') {
      *param_2 = iVar4;
    }
    return cVar1 == '\0';
  }
  while( true ) {
    if (10 < uVar3) {
      return bVar2;
    }
    if (bVar2 == true) break;
    if (param_1[uVar3] == '\0') {
      *param_2 = iVar4;
      bVar2 = true;
    }
    else if (((param_1[uVar3] == 'k') || (param_1[uVar3] == 'K')) && (uVar3 != 0)) {
      iVar4 = iVar4 << 10;
      *param_2 = iVar4;
      bVar2 = true;
    }
    else if (((param_1[uVar3] == 'm') || (param_1[uVar3] == 'M')) && (uVar3 != 0)) {
      iVar4 = iVar4 << 0x14;
      *param_2 = iVar4;
      bVar2 = true;
    }
    else {
      if (((byte)param_1[uVar3] < 0x30) || (0x39 < (byte)param_1[uVar3])) {
        return false;
      }
      iVar4 = ((byte)param_1[uVar3] - 0x30) + iVar4 * 10;
    }
    uVar3 = uVar3 + 1;
  }
  return true;
}



// ==========================================
// Function: FUN_00007644
// Address:  00007644
// Size:     44 bytes
// ==========================================

void FUN_00007644(undefined4 param_1,int param_2)

{
  bool bVar1;
  
  do {
    bVar1 = param_2 != 0;
    param_2 = param_2 + -1;
  } while (bVar1);
  return;
}



// ==========================================
// Function: FUN_00007670
// Address:  00007670
// Size:     206 bytes
// ==========================================

int FUN_00007670(undefined *param_1,uint *param_2,undefined4 param_3,uint param_4)

{
  undefined uVar1;
  undefined uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint local_20;
  
  uVar6 = 0;
  *param_2 = 0;
  local_20 = param_4;
  iVar3 = FUN_00007c20(&local_20,1,param_3);
  if (iVar3 != 0) goto LAB_00007738;
  uVar4 = local_20 & 0xff;
  if (uVar4 == 0x18) {
    iVar5 = FUN_00007c20(&local_20,1,param_3);
    if ((iVar5 == 0) && ((char)local_20 == '\x18')) {
      uVar6 = 2;
    }
    else {
      iVar3 = 1;
    }
  }
  else if (uVar4 < 0x19) {
    if (uVar4 == 1) {
      uVar6 = 0x80;
    }
    else {
      if (uVar4 != 2) {
        if (uVar4 == 4) {
          return 0;
        }
        goto LAB_000076e4;
      }
      uVar6 = 0x400;
    }
  }
  else if ((uVar4 == 0x41) || (uVar4 == 0x61)) {
    iVar3 = 2;
  }
  else {
LAB_000076e4:
    iVar3 = 1;
  }
  *param_1 = (char)local_20;
  if (0x7f < uVar6) {
    iVar3 = FUN_00007c20(param_1 + 2,uVar6 + 4,param_3);
    if (iVar3 == 0) {
      if (param_1[2] == (param_1[3] ^ 0xff)) {
        uVar1 = param_1[uVar6 + 4];
        uVar2 = param_1[uVar6 + 5];
        uVar4 = FUN_00007644(param_1 + 4,uVar6);
        if (uVar4 != CONCAT11(uVar1,uVar2)) {
          uVar6 = 0;
          iVar3 = 1;
        }
      }
      else {
        uVar6 = 0;
        iVar3 = 1;
      }
    }
    else {
      uVar6 = 0;
    }
  }
LAB_00007738:
  *param_2 = uVar6;
  return iVar3;
}



// ==========================================
// Function: FUN_0000773e
// Address:  0000773e
// Size:     450 bytes
// ==========================================

int FUN_0000773e(uint *param_1)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char local_50 [16];
  uint local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  local_2c = 0;
  uVar7 = 0;
  bVar1 = false;
  local_3c = 0;
  iVar6 = 0;
  iVar8 = 0x200000;
LAB_000078ec:
  if ((local_2c != 0) || (iVar6 != 0)) {
    return iVar6;
  }
  uVar5 = 0;
  local_30 = 0;
LAB_000078e0:
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          if ((local_30 != 0) || (iVar6 != 0)) goto LAB_000078ec;
          iVar2 = FUN_00007670(DAT_00007a3c,&local_28,0x1000000);
          if (iVar2 == 0) break;
          if (iVar2 == 2) {
            FUN_00007bc6(0x18);
            FUN_00007bc6(0x18);
            iVar6 = 2;
          }
          else {
            if (bVar1) {
              uVar7 = uVar7 + 1;
            }
            if (uVar7 < 6) {
              FUN_00007bc6(0x43);
            }
            else {
              FUN_00007bc6(0x18);
              FUN_00007bc6(0x18);
            }
          }
        }
        uVar7 = 0;
        if (local_28 != 0) break;
        FUN_00007bc6(6);
        local_30 = 1;
      }
      if (local_28 != 2) break;
      FUN_00007bc6(6);
      iVar6 = 2;
    }
    if ((uint)*(byte *)(DAT_00007a3c + 2) == (uVar5 & 0xff)) break;
    FUN_00007bc6(0x15);
  }
  if (uVar5 == 0) {
    if (*(char *)(DAT_00007a3c + 4) == '\0') {
      FUN_00007bc6(6);
      local_30 = 1;
      local_2c = 1;
      goto LAB_000078e0;
    }
    pcVar3 = (char *)(DAT_00007a3c + 4);
    for (uVar4 = 0; (*pcVar3 != '\0' && (uVar4 < 0x40)); uVar4 = uVar4 + 1) {
      *(char *)(DAT_00007a40 + uVar4) = *pcVar3;
      pcVar3 = pcVar3 + 1;
    }
    *(undefined *)(DAT_00007a40 + uVar4) = 0;
    for (uVar4 = 0; (pcVar3 = pcVar3 + 1, *pcVar3 != ' ' && (uVar4 < 0x10)); uVar4 = uVar4 + 1) {
      local_50[uVar4] = *pcVar3;
    }
    local_50[uVar4] = '\0';
    FUN_0000754c(local_50,&local_34);
    if (*param_1 < 0x3002) {
      FUN_00006d6c(0x200);
      *param_1 = local_34;
      local_3c = local_34 >> 10;
      FUN_00007bc6(6);
      FUN_00007bc6(0x43);
    }
    else {
      FUN_00007bc6(0x18);
      FUN_00007bc6(0x18);
      iVar6 = 5;
    }
  }
  else {
    local_38 = DAT_00007a3c + 4;
    iVar2 = FUN_00006c9a(iVar8,local_38,local_28);
    if (iVar2 == 0) {
      FUN_00007bc6(0x18);
      FUN_00007bc6(0x18);
      iVar6 = 4;
    }
    else {
      iVar8 = iVar8 + local_28;
      FUN_00007bc6(6);
    }
  }
  local_40 = (uVar5 * 100) / local_3c;
  FUN_0000c4a0(local_40 & 0xff);
  uVar5 = uVar5 + 1;
  bVar1 = true;
  goto LAB_000078e0;
}



// ==========================================
// Function: FUN_00007900
// Address:  00007900
// Size:     12 bytes
// ==========================================

void FUN_00007900(int param_1)

{
  bool bVar1;
  
  do {
    bVar1 = param_1 != 0;
    param_1 = param_1 + -1;
  } while (bVar1);
  return;
}



// ==========================================
// Function: FUN_0000790c
// Address:  0000790c
// Size:     168 bytes
// ==========================================

void FUN_0000790c(void)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_14 = 0;
  iVar1 = FUN_0000773e(&local_14);
  if (iVar1 == 0) {
    FUN_00007bda(DAT_00007a44);
    FUN_00007bda(DAT_00007a40);
    FUN_000074f8(&local_10,local_14);
    FUN_00007bda(s__Size__00007a48);
    FUN_00007bda(&local_10);
    FUN_00007bda(s__Bytes_00007a54);
    FUN_00007bda(s_____________________00007a60);
    local_10 = CONCAT22(local_10._2_2_,0xa55a);
    FUN_00006c9a(0x200000,&local_10);
    FUN_0000a52e(s_Transmission_completion__Restart_00007a7c,*DAT_00007a78,10,0xbe,0);
    FUN_00007900(0x2ffffff);
  }
  else if (iVar1 == 2) {
    FUN_00007bda(s__Aborted_by_user__00007b00);
  }
  else if (iVar1 == 4) {
    FUN_00007bda(s__Verification_failed__00007ae4);
  }
  else if (iVar1 == 5) {
    FUN_00007bda(s__The_image_size_is_higher_than_t_00007aa4);
  }
  else {
    FUN_00007bda(s__Failed_to_receive_the_file__00007b18);
  }
  return;
}



// ==========================================
// Function: FUN_000079b4
// Address:  000079b4
// Size:     132 bytes
// ==========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000079b4(void)

{
  FUN_00007b5c(&DAT_0001c200);
  FUN_000066b8(0);
  _DAT_e000e010 = _DAT_e000e010 & 0xfffffff8;
  FUN_0000a52e(&DAT_00007b38,*DAT_00007a78,0xf0,0x32,1);
  FUN_0000c518();
  FUN_0000790c();
  disableIRQinterrupts();
  *(uint *)(DAT_00007b50 + 0x7c) = *(uint *)(DAT_00007b50 + 0x7c) | 0x800000;
  DataSynchronizationBarrier(0xf);
  *DAT_00007b54 = (*DAT_00007b54 & 0x700 | DAT_00007b58) + 4;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==========================================
// Function: FUN_00007b5c
// Address:  00007b5c
// Size:     106 bytes
// ==========================================

undefined4 FUN_00007b5c(uint param_1)

{
  int iVar1;
  undefined *puVar2;
  
  *DAT_00007c48 = *DAT_00007c48 | 8;
  *DAT_00007c4c = *DAT_00007c4c | 4;
  iVar1 = DAT_00007c50;
  *(uint *)(DAT_00007c50 + 8) = *(uint *)(DAT_00007c50 + 8) & 0xfffffff8;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 1;
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffff8;
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 1;
  puVar2 = DAT_00007c54;
  DAT_00007c54[0xc] = 0x83;
  param_1 = (*DAT_00007c58 >> 4) / param_1;
  puVar2[4] = (char)(param_1 >> 8);
  *puVar2 = (char)param_1;
  puVar2[0xc] = 3;
  puVar2[8] = 7;
  return 1;
}



// ==========================================
// Function: FUN_00007bc6
// Address:  00007bc6
// Size:     20 bytes
// ==========================================

void FUN_00007bc6(undefined param_1)

{
  *DAT_00007c54 = param_1;
  do {
  } while ((DAT_00007c54[0x14] & 0x40) == 0);
  return;
}



// ==========================================
// Function: FUN_00007bda
// Address:  00007bda
// Size:     22 bytes
// ==========================================

void FUN_00007bda(char *param_1)

{
  char *pcVar1;
  
  while (*param_1 != '\0') {
    pcVar1 = param_1 + 1;
    FUN_00007bc6(*param_1);
    param_1 = pcVar1;
  }
  return;
}



// ==========================================
// Function: FUN_00007bf0
// Address:  00007bf0
// Size:     8 bytes
// ==========================================

undefined FUN_00007bf0(void)

{
  return *DAT_00007c54;
}



// ==========================================
// Function: FUN_00007bf8
// Address:  00007bf8
// Size:     40 bytes
// ==========================================

undefined4 FUN_00007bf8(undefined *param_1,int param_2)

{
  undefined uVar1;
  bool bVar2;
  
  do {
    bVar2 = param_2 == 0;
    param_2 = param_2 + -1;
    if (bVar2) {
      return 3;
    }
  } while ((*(byte *)(DAT_00007c54 + 0x14) & 1) == 0);
  uVar1 = FUN_00007bf0();
  *param_1 = uVar1;
  return 0;
}



// ==========================================
// Function: FUN_00007c20
// Address:  00007c20
// Size:     40 bytes
// ==========================================

undefined4 FUN_00007c20(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (param_2 <= uVar2) {
      return 0;
    }
    iVar1 = FUN_00007bf8(param_1 + uVar2,param_3);
    if (iVar1 != 0) break;
    uVar2 = uVar2 + 1;
  }
  return 3;
}



// ==========================================
// Function: FUN_00007c5c
// Address:  00007c5c
// Size:     30 bytes
// ==========================================

undefined4 FUN_00007c5c(undefined *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == (undefined *)0x0) || (param_2 == 0)) || (param_3 < 1)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
    param_1[1] = 0;
    *param_1 = 0;
    param_1[2] = 0;
    param_1[3] = (char)param_3;
    *(int *)(param_1 + 4) = param_2;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00007c7a
// Address:  00007c7a
// Size:     46 bytes
// ==========================================

undefined4 FUN_00007c7a(int param_1,undefined *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 2) == '\0')) {
    uVar2 = 1;
  }
  else {
    bVar1 = *(byte *)(param_1 + 1);
    *(byte *)(param_1 + 1) = bVar1 + 1;
    *param_2 = *(undefined *)(*(int *)(param_1 + 4) + (uint)bVar1);
    *(char *)(param_1 + 2) = *(char *)(param_1 + 2) + -1;
    if (*(byte *)(param_1 + 3) <= *(byte *)(param_1 + 1)) {
      *(undefined *)(param_1 + 1) = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_00007ca8
// Address:  00007ca8
// Size:     48 bytes
// ==========================================

undefined4 FUN_00007ca8(byte *param_1,undefined param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((param_1 == (byte *)0x0) || (param_1[3] <= param_1[2])) {
    uVar2 = 1;
  }
  else {
    bVar1 = *param_1;
    *param_1 = bVar1 + 1;
    *(undefined *)(*(int *)(param_1 + 4) + (uint)bVar1) = param_2;
    param_1[2] = param_1[2] + 1;
    if (param_1[3] <= *param_1) {
      *param_1 = 0;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_00008050
// Address:  00008050
// Size:     26 bytes
// ==========================================

void FUN_00008050(void)

{
  *DAT_00008454 =
       *(char *)(DAT_00008448 +
                (uint)*(byte *)(DAT_00008450 + (uint)*(byte *)(DAT_00008448 + (uint)*DAT_0000844c)))
       + *(byte *)(DAT_00008448 + (uint)*DAT_0000844c) * '\b';
  return;
}



// ==========================================
// Function: FUN_0000806a
// Address:  0000806a
// Size:     88 bytes
// ==========================================

void FUN_0000806a(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0000cb64();
  if ((*DAT_00008458 == '\0') && (*DAT_0000845c == '\0')) {
    FUN_00008050();
    *DAT_00008464 = *(int *)(DAT_00008460 + (uint)*DAT_00008454 * 4);
    if (*DAT_00008454 != *DAT_00008468) {
      *(int *)(*DAT_00008464 + 0x38) = *(int *)(*DAT_00008464 + 0x38) + 1;
      *DAT_0000846c = *DAT_0000846c + 1;
      FUN_0000cb92();
    }
  }
  FUN_0000cb6c(uVar1);
  return;
}



// ==========================================
// Function: FUN_000080c2
// Address:  000080c2
// Size:     82 bytes
// ==========================================

void FUN_000080c2(void)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*DAT_00008470 == '\x01') {
    uVar2 = FUN_0000cb64();
    pcVar1 = DAT_0000845c;
    if (*DAT_00008458 == '\0') {
      if (*DAT_0000845c == '\0') {
        FUN_0000cb6c(uVar2);
      }
      else {
        *DAT_0000845c = *DAT_0000845c + -1;
        if (*pcVar1 == '\0') {
          FUN_0000cb6c(uVar2);
          FUN_0000806a();
        }
        else {
          FUN_0000cb6c(uVar2);
        }
      }
    }
    else {
      FUN_0000cb6c(uVar2);
    }
  }
  return;
}



// ==========================================
// Function: FUN_00008114
// Address:  00008114
// Size:     108 bytes
// ==========================================

void FUN_00008114(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  *(undefined *)(param_1 + 0x21) = 3;
  if (param_2 == 1) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x1c) + *DAT_00008474;
  }
  else if (*(int *)(param_1 + 0x18) == 0) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x1c) + *DAT_00008474;
  }
  else {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x18) + *DAT_00008474;
  }
  piVar1 = (int *)(DAT_00008478 + (*(uint *)(param_1 + 0x14) % 3) * 8);
  if (*piVar1 == 0) {
    *piVar1 = param_1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined2 *)(piVar1 + 1) = 1;
  }
  else {
    iVar2 = *piVar1;
    *piVar1 = param_1;
    *(int *)(param_1 + 0xc) = iVar2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x10) = param_1;
    }
    *(short *)(piVar1 + 1) = *(short *)(piVar1 + 1) + 1;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



// ==========================================
// Function: FUN_00008180
// Address:  00008180
// Size:     70 bytes
// ==========================================

void FUN_00008180(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(DAT_00008478 + (*(uint *)(param_1 + 0x14) % 3) * 8);
  if (*piVar3 == param_1) {
    iVar1 = *(int *)(param_1 + 0xc);
    *piVar3 = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x10) = 0;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x10);
    iVar2 = *(int *)(param_1 + 0xc);
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0xc) = iVar2;
    }
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x10) = iVar1;
    }
  }
  *(undefined *)(param_1 + 0x21) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(short *)(piVar3 + 1) = *(short *)(piVar3 + 1) + -1;
  return;
}



// ==========================================
// Function: FUN_000081c6
// Address:  000081c6
// Size:     50 bytes
// ==========================================

void FUN_000081c6(void)

{
  undefined4 uVar1;
  
  if (*DAT_00008470 == '\x01') {
    uVar1 = FUN_0000cb64();
    if ((*DAT_00008458 == '\0') && (*DAT_0000845c != -1)) {
      *DAT_0000845c = *DAT_0000845c + '\x01';
    }
    FUN_0000cb6c(uVar1);
  }
  return;
}



// ==========================================
// Function: FUN_000081f8
// Address:  000081f8
// Size:     42 bytes
// ==========================================

void FUN_000081f8(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 0x34);
  *(byte *)(param_2 + 0xb + uVar1) = *(byte *)(param_2 + 0xb + uVar1) & ~*(byte *)(param_1 + 0x35);
  if (*(char *)(param_2 + 0xb + uVar1) == '\0') {
    *(byte *)(param_2 + 10) = *(byte *)(param_2 + 10) & ~*(byte *)(param_1 + 0x36);
  }
  return;
}



// ==========================================
// Function: FUN_00008222
// Address:  00008222
// Size:     112 bytes
// ==========================================

void FUN_00008222(int param_1)

{
  int iVar1;
  uint uVar2;
  
  *(int *)(*DAT_0000847c + 0x1c) = param_1;
  *(byte *)(param_1 + 0xb + (uint)*(byte *)(*DAT_0000847c + 0x34)) =
       *(byte *)(param_1 + 0xb + (uint)*(byte *)(*DAT_0000847c + 0x34)) |
       *(byte *)(*DAT_0000847c + 0x35);
  *(byte *)(param_1 + 10) = *(byte *)(param_1 + 10) | *(byte *)(*DAT_0000847c + 0x36);
  iVar1 = DAT_00008450;
  uVar2 = (uint)*(byte *)(*DAT_0000847c + 0x34);
  *(byte *)(DAT_00008450 + uVar2) =
       *(byte *)(DAT_00008450 + uVar2) & ~*(byte *)(*DAT_0000847c + 0x35);
  if (*(char *)(iVar1 + uVar2) == '\0') {
    *DAT_0000844c = *DAT_0000844c & ~*(byte *)(*DAT_0000847c + 0x36);
  }
  return;
}



// ==========================================
// Function: FUN_00008292
// Address:  00008292
// Size:     222 bytes
// ==========================================

void FUN_00008292(char *param_1,undefined4 param_2,undefined *param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*param_1 == '\x03') {
    if (*DAT_00008458 == '\0') {
      if (*DAT_0000845c == '\0') {
        uVar2 = FUN_0000cb64();
        if (*(short *)(param_1 + 8) == 0) {
          *(byte *)(*DAT_0000847c + 0x30) = *(byte *)(*DAT_0000847c + 0x30) | 1;
          *(undefined *)(*DAT_0000847c + 0x31) = 0;
          *(undefined4 *)(*DAT_0000847c + 0x2c) = param_2;
          FUN_00008222(param_1);
          FUN_0000cb6c(uVar2);
          FUN_0000806a();
          uVar2 = FUN_0000cb64();
          cVar1 = *(char *)(*DAT_0000847c + 0x31);
          if (cVar1 == '\0') {
            *param_3 = 0;
          }
          else if ((cVar1 == '\x01') || (cVar1 != '\x02')) {
            FUN_000081f8(*DAT_0000847c,param_1);
            *param_3 = 10;
          }
          else {
            *param_3 = 0xe;
          }
          *(undefined *)(*DAT_0000847c + 0x30) = 0;
          *(undefined *)(*DAT_0000847c + 0x31) = 0;
          *(undefined4 *)(*DAT_0000847c + 0x1c) = 0;
          FUN_0000cb6c(uVar2);
        }
        else {
          *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + -1;
          FUN_0000cb6c(uVar2);
          *param_3 = 0;
        }
      }
      else {
        *param_3 = 0xd;
      }
    }
    else {
      *param_3 = 2;
    }
  }
  else {
    *param_3 = 1;
  }
  return;
}



// ==========================================
// Function: FUN_000083e8
// Address:  000083e8
// Size:     290 bytes
// ==========================================

undefined4
FUN_000083e8(int param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5
            ,undefined4 param_6,undefined2 param_7)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar2 = FUN_0000cb64();
  puVar3 = (undefined4 *)*DAT_00008484;
  if (puVar3 == (undefined4 *)0x0) {
    FUN_0000cb6c(uVar2);
    uVar2 = 0x42;
  }
  else {
    *DAT_00008484 = puVar3[5];
    FUN_0000cb6c(uVar2);
    *puVar3 = param_2;
    *(byte *)((int)puVar3 + 0x32) = (byte)param_1;
    *(undefined *)(puVar3 + 0xc) = 0;
    *(undefined *)((int)puVar3 + 0x31) = 0;
    puVar3[0xb] = 0;
    puVar3[1] = param_6;
    puVar3[3] = param_5;
    puVar3[2] = param_3;
    *(undefined2 *)(puVar3 + 4) = param_7;
    *(undefined2 *)((int)puVar3 + 0x12) = param_4;
    *(undefined *)((int)puVar3 + 0x37) = 0;
    *(char *)(puVar3 + 0xd) = (char)(param_1 >> 3);
    *(byte *)((int)puVar3 + 0x33) = (byte)param_1 & 7;
    *(char *)((int)puVar3 + 0x36) = (char)(1 << *(sbyte *)(puVar3 + 0xd));
    *(char *)((int)puVar3 + 0x35) = (char)(1 << (uint)*(byte *)((int)puVar3 + 0x33));
    puVar3[7] = 0;
    puVar3[9] = 0;
    puVar3[8] = 0;
    puVar3[0xe] = 0;
    puVar3[0x10] = 0;
    puVar3[0xf] = 0;
    puVar3[0x11] = 0;
    puVar3[0x12] = 0;
    bVar1 = false;
    while (!bVar1) {
      puVar3[0x13] = 0;
      bVar1 = true;
    }
    FUN_0000a274(puVar3);
    uVar2 = FUN_0000cb64();
    *(undefined4 **)(DAT_000088d0 + param_1 * 4) = puVar3;
    FUN_0000cb6c(uVar2);
    FUN_0000a1d2(puVar3);
    uVar2 = FUN_0000cb64();
    puVar3[5] = *DAT_000088d4;
    puVar3[6] = 0;
    if (*DAT_000088d4 != 0) {
      *(undefined4 **)(*DAT_000088d4 + 0x18) = puVar3;
    }
    *DAT_000088d4 = (int)puVar3;
    *DAT_000088d8 = *(byte *)((int)puVar3 + 0x36) | *DAT_000088d8;
    *(byte *)(DAT_000088dc + (uint)*(byte *)(puVar3 + 0xd)) =
         *(byte *)(DAT_000088dc + (uint)*(byte *)(puVar3 + 0xd)) | *(byte *)((int)puVar3 + 0x35);
    *DAT_000088e0 = *DAT_000088e0 + '\x01';
    FUN_0000cb6c(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_0000854a
// Address:  0000854a
// Size:     26 bytes
// ==========================================

void FUN_0000854a(undefined4 *param_1,int param_2,uint param_3)

{
  if (((param_3 & 1) != 0) && ((param_3 & 2) != 0)) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
  }
  return;
}



// ==========================================
// Function: FUN_00008564
// Address:  00008564
// Size:     170 bytes
// ==========================================

int FUN_00008564(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0000cb64();
  if (*DAT_000088e4 == '\0') {
    if (*(int *)(DAT_000088d0 + param_4 * 4) == 0) {
      *(undefined4 *)(DAT_000088d0 + param_4 * 4) = 1;
      FUN_0000cb6c(uVar1);
      FUN_0000854a(param_6,param_7,param_9);
      uVar1 = FUN_0000a1da(param_1,param_2,param_3,param_9);
      iVar2 = FUN_000083e8(param_4,uVar1,param_6,param_5,param_7,param_8,param_9);
      if (iVar2 == 0) {
        if (*DAT_000088e8 == '\x01') {
          FUN_0000806a();
        }
      }
      else {
        uVar1 = FUN_0000cb64();
        *(undefined4 *)(DAT_000088d0 + param_4 * 4) = 0;
        FUN_0000cb6c(uVar1);
      }
    }
    else {
      FUN_0000cb6c(uVar1);
      iVar2 = 0x28;
    }
  }
  else {
    FUN_0000cb6c(uVar1);
    iVar2 = 0x3c;
  }
  return iVar2;
}



// ==========================================
// Function: FUN_0000860e
// Address:  0000860e
// Size:     42 bytes
// ==========================================

void FUN_0000860e(void)

{
  FUN_00008564(DAT_000088f0,0,DAT_000088ec + 0xfc,9,&DAT_0000fffd,DAT_000088ec,0x40,0,3);
  return;
}



// ==========================================
// Function: FUN_00008638
// Address:  00008638
// Size:     28 bytes
// ==========================================

void FUN_00008638(int param_1)

{
  uint uVar1;
  
  *(undefined *)(param_1 + 10) = 0;
  for (uVar1 = 0; uVar1 < 2; uVar1 = uVar1 + 1 & 0xff) {
    *(undefined *)(param_1 + 0xb + uVar1) = 0;
  }
  return;
}



// ==========================================
// Function: FUN_00008654
// Address:  00008654
// Size:     68 bytes
// ==========================================

undefined * FUN_00008654(undefined2 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  if (*DAT_000088e4 == '\0') {
    uVar2 = FUN_0000cb64();
    puVar1 = (undefined *)*DAT_000088f4;
    if (*DAT_000088f4 != 0) {
      *DAT_000088f4 = *(int *)(*DAT_000088f4 + 4);
    }
    FUN_0000cb6c(uVar2);
    if (puVar1 != (undefined *)0x0) {
      *puVar1 = 3;
      *(undefined2 *)(puVar1 + 8) = param_1;
      *(undefined4 *)(puVar1 + 4) = 0;
      FUN_00008638(puVar1);
    }
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}



// ==========================================
// Function: thunk_FUN_000086a4
// Address:  00008698
// Size:     2 bytes
// ==========================================

void thunk_FUN_000086a4(undefined *param_1,uint param_2)

{
  for (; param_2 != 0; param_2 = param_2 - 1 & 0xffff) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}



// ==========================================
// Function: FUN_000086a4
// Address:  000086a4
// Size:     16 bytes
// ==========================================

void FUN_000086a4(undefined *param_1,uint param_2)

{
  for (; param_2 != 0; param_2 = param_2 - 1 & 0xffff) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}



// ==========================================
// Function: FUN_000086aa
// Address:  000086aa
// Size:     138 bytes
// ==========================================

void FUN_000086aa(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  thunk_FUN_000086a4(DAT_000088f8,0x168);
  thunk_FUN_000086a4(DAT_000088fc,0x18);
  for (uVar3 = 0; uVar3 < 9; uVar3 = uVar3 + 1 & 0xffff) {
    puVar2 = (undefined *)(DAT_000088f8 + uVar3 * 0x24);
    iVar4 = DAT_000088f8 + (uVar3 + 1 & 0xffff) * 0x24;
    *puVar2 = 100;
    puVar2[0x21] = 0;
    *(int *)(puVar2 + 0xc) = iVar4;
  }
  puVar2 = (undefined *)(DAT_000088f8 + uVar3 * 0x24);
  *puVar2 = 100;
  puVar2[0x21] = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  *DAT_00008900 = 0;
  *DAT_00008904 = 0;
  *DAT_00008908 = 10;
  *DAT_0000890c = DAT_000088f8;
  uVar1 = FUN_00008654(1);
  *DAT_00008910 = uVar1;
  uVar1 = FUN_00008654(0);
  *DAT_00008914 = uVar1;
  FUN_0000860e();
  return;
}



// ==========================================
// Function: FUN_00008756
// Address:  00008756
// Size:     44 bytes
// ==========================================

void FUN_00008756(void)

{
  FUN_00008564(&LAB_00008734_1,0,DAT_0000891c + 0x7c,0xb,0xffff,DAT_0000891c,0x20,0,3);
  return;
}



// ==========================================
// Function: FUN_00008782
// Address:  00008782
// Size:     70 bytes
// ==========================================

void FUN_00008782(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  
  thunk_FUN_000086a4(DAT_00008920,0x50);
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xffff) {
    puVar1 = (undefined *)(DAT_00008920 + uVar2 * 0x10);
    iVar3 = DAT_00008920 + (uVar2 + 1 & 0xffff) * 0x10;
    *puVar1 = 0;
    *(int *)(puVar1 + 4) = iVar3;
    *(undefined **)(puVar1 + 0xc) = &DAT_00008924;
  }
  puVar1 = (undefined *)(DAT_00008920 + uVar2 * 0x10);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined **)(puVar1 + 0xc) = &DAT_00008924;
  *DAT_00008928 = DAT_00008920;
  return;
}



// ==========================================
// Function: FUN_000087c8
// Address:  000087c8
// Size:     62 bytes
// ==========================================

void FUN_000087c8(void)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  
  thunk_FUN_000086a4(DAT_0000892c,0xf0);
  for (uVar1 = 0; uVar1 < 0xe; uVar1 = uVar1 + 1 & 0xffff) {
    puVar2 = (undefined *)(DAT_0000892c + uVar1 * 0x10);
    iVar3 = DAT_0000892c + (uVar1 + 1 & 0xffff) * 0x10;
    *puVar2 = 0;
    *(int *)(puVar2 + 4) = iVar3;
  }
  puVar2 = (undefined *)(DAT_0000892c + uVar1 * 0x10);
  *puVar2 = 0;
  *(undefined4 *)(puVar2 + 4) = 0;
  *DAT_000088f4 = DAT_0000892c;
  return;
}



// ==========================================
// Function: FUN_00008806
// Address:  00008806
// Size:     82 bytes
// ==========================================

void FUN_00008806(void)

{
  uint uVar1;
  
  thunk_FUN_000086a4(DAT_00008930,0x2d0);
  thunk_FUN_000086a4(DAT_000088d0,0x30);
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1 & 0xff) {
    *(uint *)(DAT_00008930 + uVar1 * 0x50 + 0x14) = DAT_00008930 + (uVar1 + 1 & 0xff) * 0x50;
  }
  *(undefined4 *)(DAT_00008930 + uVar1 * 0x50 + 0x14) = 0;
  *DAT_000088d4 = 0;
  *DAT_00008934 = DAT_00008930;
  return;
}



// ==========================================
// Function: FUN_00008858
// Address:  00008858
// Size:     44 bytes
// ==========================================

void FUN_00008858(void)

{
  uint uVar1;
  
  *DAT_000088d8 = 0;
  for (uVar1 = 0; uVar1 < 2; uVar1 = uVar1 + 1 & 0xff) {
    *(undefined *)(DAT_000088dc + uVar1) = 0;
  }
  *DAT_00008938 = 0;
  *DAT_0000893c = 0;
  *DAT_00008940 = 0;
  *DAT_00008944 = 0;
  return;
}



// ==========================================
// Function: FUN_00008884
// Address:  00008884
// Size:     36 bytes
// ==========================================

void FUN_00008884(void)

{
  *DAT_00008948 = 0;
  *DAT_000088e4 = 0;
  *DAT_0000894c = 0;
  *DAT_000088e0 = 0;
  *DAT_000088e8 = 0;
  *DAT_00008950 = 0;
  *DAT_00008918 = 0;
  *DAT_00008954 = 0;
  return;
}



// ==========================================
// Function: FUN_000088a8
// Address:  000088a8
// Size:     40 bytes
// ==========================================

void FUN_000088a8(void)

{
  FUN_0000a1c8();
  FUN_00008884();
  FUN_00008858();
  FUN_00008806();
  FUN_000087c8();
  FUN_00008782();
  FUN_00008756();
  FUN_000086aa();
  FUN_0000a1d0();
  return;
}



// ==========================================
// Function: FUN_00008974
// Address:  00008974
// Size:     112 bytes
// ==========================================

void FUN_00008974(void)

{
  undefined4 uVar1;
  
  if (*DAT_00008d50 == '\x01') {
    uVar1 = FUN_0000cb64();
    if (*DAT_00008d54 != '\0') {
      *DAT_00008d54 = *DAT_00008d54 + -1;
    }
    if ((*DAT_00008d54 == '\0') && (*DAT_00008d58 == '\0')) {
      FUN_00008050();
      *DAT_00008d64 = *(int *)(DAT_00008d5c + (uint)*DAT_00008d60 * 4);
      if (*DAT_00008d60 != *DAT_00008d68) {
        *(int *)(*DAT_00008d64 + 0x38) = *(int *)(*DAT_00008d64 + 0x38) + 1;
        *DAT_00008d6c = *DAT_00008d6c + 1;
        FUN_0000cb9c();
      }
    }
    FUN_0000cb6c(uVar1);
  }
  return;
}



// ==========================================
// Function: FUN_000089e4
// Address:  000089e4
// Size:     48 bytes
// ==========================================

void FUN_000089e4(void)

{
  undefined4 *puVar1;
  
  if (*DAT_00008d50 == '\0') {
    FUN_00008050();
    *DAT_00008d68 = *DAT_00008d60;
    puVar1 = DAT_00008d64;
    *DAT_00008d64 = *(undefined4 *)(DAT_00008d5c + (uint)*DAT_00008d60 * 4);
    *DAT_00008d70 = *puVar1;
    FUN_0000cb72();
  }
  return;
}



// ==========================================
// Function: FUN_00008a14
// Address:  00008a14
// Size:     158 bytes
// ==========================================

void FUN_00008a14(void)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_0000a276();
  uVar1 = FUN_0000cb64();
  *DAT_00008d74 = *DAT_00008d74 + 1;
  FUN_0000cb6c(uVar1);
  if (*DAT_00008d50 == '\x01') {
    iVar2 = *DAT_00008d78;
    while (*(char *)(iVar2 + 0x32) != '\v') {
      uVar1 = FUN_0000cb64();
      if ((*(int *)(iVar2 + 0x2c) != 0) &&
         (*(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + -1, *(int *)(iVar2 + 0x2c) == 0)) {
        if ((*(byte *)(iVar2 + 0x30) & 0x37) == 0) {
          *(undefined *)(iVar2 + 0x31) = 0;
        }
        else {
          *(byte *)(iVar2 + 0x30) = *(byte *)(iVar2 + 0x30) & 200;
          *(undefined *)(iVar2 + 0x31) = 1;
        }
        if ((*(byte *)(iVar2 + 0x30) & 8) == 0) {
          *DAT_00008d7c = *(byte *)(iVar2 + 0x36) | *DAT_00008d7c;
          *(byte *)(DAT_00008d80 + (uint)*(byte *)(iVar2 + 0x34)) =
               *(byte *)(DAT_00008d80 + (uint)*(byte *)(iVar2 + 0x34)) | *(byte *)(iVar2 + 0x35);
        }
      }
      iVar2 = *(int *)(iVar2 + 0x14);
      FUN_0000cb6c(uVar1);
    }
  }
  return;
}



// ==========================================
// Function: FUN_00008ab8
// Address:  00008ab8
// Size:     2 bytes
// ==========================================

void FUN_00008ab8(void)

{
  return;
}



// ==========================================
// Function: FUN_00008aba
// Address:  00008aba
// Size:     114 bytes
// ==========================================

uint FUN_00008aba(int param_1,undefined4 param_2,byte param_3,undefined param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)*(byte *)(DAT_00008d84 + (uint)*(byte *)(param_1 + 10));
  uVar3 = (uint)*(byte *)(DAT_00008d84 + (uint)*(byte *)(param_1 + 0xb + uVar2)) + uVar2 * 8 & 0xff;
  iVar1 = *(int *)(DAT_00008d5c + uVar3 * 4);
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = param_2;
  *(byte *)(iVar1 + 0x30) = *(byte *)(iVar1 + 0x30) & ~param_3;
  *(undefined *)(iVar1 + 0x31) = param_4;
  if ((*(byte *)(iVar1 + 0x30) & 8) == 0) {
    *DAT_00008d7c = *(byte *)(iVar1 + 0x36) | *DAT_00008d7c;
    *(byte *)(DAT_00008d80 + uVar2) = *(byte *)(DAT_00008d80 + uVar2) | *(byte *)(iVar1 + 0x35);
  }
  FUN_000081f8(iVar1,param_1);
  return uVar3;
}



// ==========================================
// Function: thunk_FUN_00008b3a
// Address:  00008b2c
// Size:     2 bytes
// ==========================================

void thunk_FUN_00008b3a(undefined *param_1,undefined *param_2,uint param_3)

{
  for (; param_3 != 0; param_3 = param_3 - 1 & 0xffff) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



// ==========================================
// Function: FUN_00008b3a
// Address:  00008b3a
// Size:     18 bytes
// ==========================================

void FUN_00008b3a(undefined *param_1,undefined *param_2,uint param_3)

{
  for (; param_3 != 0; param_3 = param_3 - 1 & 0xffff) {
    *param_1 = *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



// ==========================================
// Function: FUN_00008b40
// Address:  00008b40
// Size:     20 bytes
// ==========================================

char FUN_00008b40(char *param_1)

{
  char cVar1;
  
  cVar1 = '\0';
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    cVar1 = cVar1 + '\x01';
  }
  return cVar1;
}



// ==========================================
// Function: FUN_00008b54
// Address:  00008b54
// Size:     128 bytes
// ==========================================

undefined4 FUN_00008b54(uint param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar1 = FUN_0000cb64();
  if (param_1 == 0xff) {
    param_1 = (uint)*(byte *)(*DAT_00008d70 + 0x32);
  }
  iVar2 = *(int *)(DAT_00008d5c + param_1 * 4);
  if (iVar2 == 0) {
    FUN_0000cb6c(uVar1);
    uVar1 = 0x43;
  }
  else if (iVar2 == 1) {
    FUN_0000cb6c(uVar1);
    uVar1 = 0x43;
  }
  else if ((*(byte *)(iVar2 + 0x10) & 1) == 0) {
    FUN_0000cb6c(uVar1);
    uVar1 = 0x45;
  }
  else {
    iVar3 = 0;
    iVar5 = *(int *)(iVar2 + 0xc);
    piVar4 = *(int **)(iVar2 + 8);
    FUN_0000cb6c(uVar1);
    while (*piVar4 == 0) {
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    }
    *param_2 = iVar3;
    param_2[1] = iVar5 - iVar3;
    uVar1 = 0;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00008d06
// Address:  00008d06
// Size:     90 bytes
// ==========================================

undefined * FUN_00008d06(undefined2 param_1,undefined *param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  if (*DAT_00008d54 == '\0') {
    uVar2 = FUN_0000cb64();
    puVar1 = (undefined *)*DAT_00008d88;
    if (puVar1 == (undefined *)0x0) {
      FUN_0000cb6c(uVar2);
      *param_2 = 0x72;
    }
    else {
      *DAT_00008d88 = *(int *)(*DAT_00008d88 + 4);
      *puVar1 = 5;
      *(undefined2 *)(puVar1 + 8) = param_1;
      *(undefined4 *)(puVar1 + 4) = 0;
      *(undefined **)(puVar1 + 0xc) = &DAT_00008924;
      FUN_0000cb6c(uVar2);
      *param_2 = 0;
    }
  }
  else {
    *param_2 = 0x10;
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}



// ==========================================
// Function: FUN_00008d9c
// Address:  00008d9c
// Size:     36 bytes
// ==========================================

void FUN_00008d9c(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[1];
  iVar1 = *param_1;
  if (piVar2 == (int *)0x0) {
    *(int *)(param_1[3] + 4) = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 4) = 0;
    }
  }
  else {
    *piVar2 = iVar1;
    if (iVar1 != 0) {
      *(int **)(iVar1 + 4) = piVar2;
    }
  }
  *(undefined4 *)(param_1[2] + 0x24) = 0;
  return;
}



// ==========================================
// Function: FUN_00008dc0
// Address:  00008dc0
// Size:     88 bytes
// ==========================================

bool FUN_00008dc0(int param_1,undefined2 param_2,undefined param_3)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar2 + 0x2c) = 0;
  *(undefined2 *)(iVar2 + 0x28) = param_2;
  *(byte *)(iVar2 + 0x30) = *(byte *)(iVar2 + 0x30) & 0xdf;
  *(undefined *)(iVar2 + 0x31) = param_3;
  bVar1 = *(char *)(iVar2 + 0x30) == '\0';
  if (bVar1) {
    *DAT_000091e4 = *(byte *)(iVar2 + 0x36) | *DAT_000091e4;
    *(byte *)(DAT_000091e8 + (uint)*(byte *)(iVar2 + 0x34)) =
         *(byte *)(DAT_000091e8 + (uint)*(byte *)(iVar2 + 0x34)) | *(byte *)(iVar2 + 0x35);
  }
  FUN_00008d9c(param_1);
  return bVar1;
}



// ==========================================
// Function: FUN_00008e18
// Address:  00008e18
// Size:     220 bytes
// ==========================================

char * FUN_00008e18(char *param_1,int param_2,undefined *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*DAT_000091ec == '\0') {
    if (*param_1 == '\x05') {
      uVar1 = FUN_0000cb64();
      iVar2 = *(int *)(param_1 + 4);
      if (param_2 == 0) {
        if (iVar2 != 0) {
          FUN_0000cb6c(uVar1);
          *param_3 = 0x49;
        }
        else {
          *(undefined **)(param_1 + 0xc) = &DAT_00008924;
          *param_1 = '\0';
          *(char **)(param_1 + 4) = *DAT_000091f0;
          *(undefined2 *)(param_1 + 8) = 0;
          *DAT_000091f0 = param_1;
          FUN_0000cb6c(uVar1);
          *param_3 = 0;
          param_1 = (char *)0x0;
        }
      }
      else if (param_2 == 1) {
        for (puVar3 = *(undefined4 **)(param_1 + 4); puVar3 != (undefined4 *)0x0;
            puVar3 = (undefined4 *)*puVar3) {
          FUN_00008dc0(puVar3,0,2);
        }
        *(undefined **)(param_1 + 0xc) = &DAT_00008924;
        *param_1 = '\0';
        *(char **)(param_1 + 4) = *DAT_000091f0;
        *(undefined2 *)(param_1 + 8) = 0;
        *DAT_000091f0 = param_1;
        FUN_0000cb6c(uVar1);
        if (iVar2 != 0) {
          FUN_0000806a();
        }
        *param_3 = 0;
        param_1 = (char *)0x0;
      }
      else {
        FUN_0000cb6c(uVar1);
        *param_3 = 7;
      }
    }
    else {
      *param_3 = 1;
    }
  }
  else {
    *param_3 = 0xf;
  }
  return param_1;
}



// ==========================================
// Function: FUN_00008ef4
// Address:  00008ef4
// Size:     80 bytes
// ==========================================

undefined4 FUN_00008ef4(char *param_1,undefined4 *param_2,undefined *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*DAT_000091ec == '\0') {
    uVar2 = FUN_0000cb64();
    if (*param_1 == '\x05') {
      *param_2 = *(undefined4 *)(param_1 + 0xc);
      uVar1 = FUN_00008b40(*param_2);
      FUN_0000cb6c(uVar2);
      *param_3 = 0;
    }
    else {
      FUN_0000cb6c(uVar2);
      *param_3 = 1;
      uVar1 = 0;
    }
  }
  else {
    *param_3 = 0x11;
    uVar1 = 0;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00008f44
// Address:  00008f44
// Size:     66 bytes
// ==========================================

void FUN_00008f44(char *param_1,undefined4 param_2,undefined *param_3)

{
  undefined4 uVar1;
  
  if (*DAT_000091ec == '\0') {
    uVar1 = FUN_0000cb64();
    if (*param_1 == '\x05') {
      *(undefined4 *)(param_1 + 0xc) = param_2;
      FUN_0000cb6c(uVar1);
      *param_3 = 0;
    }
    else {
      FUN_0000cb6c(uVar1);
      *param_3 = 1;
    }
  }
  else {
    *param_3 = 0x12;
  }
  return;
}



// ==========================================
// Function: FUN_00008f86
// Address:  00008f86
// Size:     152 bytes
// ==========================================

void FUN_00008f86(int param_1,undefined4 *param_2,undefined2 param_3,undefined param_4,
                 undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  
  *(byte *)(*DAT_000091f4 + 0x30) = *(byte *)(*DAT_000091f4 + 0x30) | 0x20;
  *(undefined *)(*DAT_000091f4 + 0x31) = 0;
  *(undefined4 *)(*DAT_000091f4 + 0x2c) = param_5;
  *(undefined4 **)(*DAT_000091f4 + 0x24) = param_2;
  *(undefined2 *)(param_2 + 4) = param_3;
  *(undefined *)((int)param_2 + 0x12) = param_4;
  param_2[2] = *DAT_000091f4;
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = 0;
  param_2[3] = param_1;
  if (*(int *)(param_1 + 4) != 0) {
    *(undefined4 **)(*(int *)(param_1 + 4) + 4) = param_2;
  }
  *(undefined4 **)(param_1 + 4) = param_2;
  iVar1 = DAT_000091e8;
  uVar2 = (uint)*(byte *)(*DAT_000091f4 + 0x34);
  *(byte *)(DAT_000091e8 + uVar2) =
       *(byte *)(DAT_000091e8 + uVar2) & ~*(byte *)(*DAT_000091f4 + 0x35);
  if (*(char *)(iVar1 + uVar2) == '\0') {
    *DAT_000091e4 = *DAT_000091e4 & ~*(byte *)(*DAT_000091f4 + 0x36);
  }
  return;
}



// ==========================================
// Function: FUN_0000901e
// Address:  0000901e
// Size:     588 bytes
// ==========================================

uint FUN_0000901e(char *param_1,uint param_2,uint param_3,undefined4 param_4,undefined *param_5)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined auStack_38 [20];
  
  if (*DAT_000091ec == '\0') {
    if (*DAT_000091f8 == '\0') {
      if (*param_1 == '\x05') {
        bVar5 = (param_3 & 0x80) != 0;
        if (bVar5) {
          param_3 = param_3 & 0x7f;
        }
        uVar4 = FUN_0000cb64();
        if (param_3 == 0) {
          uVar3 = param_2 & ~(uint)*(ushort *)(param_1 + 8);
          if (uVar3 == param_2) {
            if (bVar5) {
              *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | (ushort)uVar3;
            }
            *(ushort *)(*DAT_000091f4 + 0x28) = (ushort)uVar3;
            FUN_0000cb6c(uVar4);
            *param_5 = 0;
            return uVar3;
          }
          FUN_00008f86(param_1,auStack_38,param_2,0,param_4);
          FUN_0000cb6c(uVar4);
        }
        else if (param_3 == 1) {
          uVar3 = param_2 & ~(uint)*(ushort *)(param_1 + 8);
          if (uVar3 != 0) {
            if (bVar5) {
              *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | (ushort)uVar3;
            }
            *(ushort *)(*DAT_000091f4 + 0x28) = (ushort)uVar3;
            FUN_0000cb6c(uVar4);
            *param_5 = 0;
            return uVar3;
          }
          FUN_00008f86(param_1,auStack_38,param_2,1,param_4);
          FUN_0000cb6c(uVar4);
        }
        else if (param_3 == 2) {
          uVar3 = *(ushort *)(param_1 + 8) & param_2;
          if (uVar3 == param_2) {
            if (bVar5) {
              *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & ~(ushort)uVar3;
            }
            *(ushort *)(*DAT_000091f4 + 0x28) = (ushort)uVar3;
            FUN_0000cb6c(uVar4);
            *param_5 = 0;
            return uVar3;
          }
          FUN_00008f86(param_1,auStack_38,param_2,2,param_4);
          FUN_0000cb6c(uVar4);
        }
        else {
          if (param_3 != 3) {
            FUN_0000cb6c(uVar4);
            *param_5 = 0x6f;
            return 0;
          }
          uVar3 = *(ushort *)(param_1 + 8) & param_2;
          if (uVar3 != 0) {
            if (bVar5) {
              *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & ~(ushort)uVar3;
            }
            *(ushort *)(*DAT_000091f4 + 0x28) = (ushort)uVar3;
            FUN_0000cb6c(uVar4);
            *param_5 = 0;
            return uVar3;
          }
          FUN_00008f86(param_1,auStack_38,param_2,3,param_4);
          FUN_0000cb6c(uVar4);
        }
        FUN_0000806a();
        uVar4 = FUN_0000cb64();
        if (*(char *)(*DAT_000091f4 + 0x31) == '\0') {
          uVar1 = *(ushort *)(*DAT_00009624 + 0x28);
          uVar3 = (uint)uVar1;
          if (bVar5) {
            if ((param_3 == 0) || (param_3 == 1)) {
              *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | uVar1;
            }
            else {
              if ((param_3 != 2) && (param_3 != 3)) {
                FUN_0000cb6c(uVar4);
                *param_5 = 0x6f;
                return 0;
              }
              *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) & ~uVar1;
            }
          }
          FUN_0000cb6c(uVar4);
          *param_5 = 0;
        }
        else {
          cVar2 = *(char *)(*DAT_000091f4 + 0x31);
          *(undefined *)(*DAT_000091f4 + 0x31) = 0;
          FUN_00008d9c(auStack_38);
          *(undefined *)(*DAT_000091f4 + 0x30) = 0;
          FUN_0000cb6c(uVar4);
          if ((cVar2 == '\x01') || (cVar2 != '\x02')) {
            *param_5 = 10;
          }
          else {
            *param_5 = 0xe;
          }
          uVar3 = 0;
        }
      }
      else {
        *param_5 = 1;
        uVar3 = 0;
      }
    }
    else {
      *param_5 = 0xd;
      uVar3 = 0;
    }
  }
  else {
    *param_5 = 2;
    uVar3 = 0;
  }
  return uVar3;
}



// ==========================================
// Function: FUN_00009432
// Address:  00009432
// Size:     68 bytes
// ==========================================

undefined * FUN_00009432(undefined4 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  if (*DAT_00009628 == '\0') {
    uVar2 = FUN_0000cb64();
    puVar1 = (undefined *)*DAT_0000962c;
    if (*DAT_0000962c != 0) {
      *DAT_0000962c = *(int *)(*DAT_0000962c + 4);
    }
    FUN_0000cb6c(uVar2);
    if (puVar1 != (undefined *)0x0) {
      *puVar1 = 1;
      *(undefined2 *)(puVar1 + 8) = 0;
      *(undefined4 *)(puVar1 + 4) = param_1;
      FUN_00008638(puVar1);
    }
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}



// ==========================================
// Function: FUN_00009476
// Address:  00009476
// Size:     200 bytes
// ==========================================

char * FUN_00009476(char *param_1,int param_2,undefined *param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*param_1 == '\x01') {
    if (*DAT_00009628 == '\0') {
      uVar2 = FUN_0000cb64();
      cVar1 = param_1[10];
      if (param_2 == 0) {
        if (cVar1 != '\0') {
          FUN_0000cb6c(uVar2);
          *param_3 = 0x49;
        }
        else {
          *param_1 = '\0';
          *(char **)(param_1 + 4) = *DAT_0000962c;
          *(undefined2 *)(param_1 + 8) = 0;
          *DAT_0000962c = param_1;
          FUN_0000cb6c(uVar2);
          *param_3 = 0;
          param_1 = (char *)0x0;
        }
      }
      else if (param_2 == 1) {
        while (param_1[10] != '\0') {
          FUN_00008aba(param_1,0,2);
        }
        *param_1 = '\0';
        *(char **)(param_1 + 4) = *DAT_0000962c;
        *(undefined2 *)(param_1 + 8) = 0;
        *DAT_0000962c = param_1;
        FUN_0000cb6c(uVar2);
        if (cVar1 != '\0') {
          FUN_0000806a();
        }
        *param_3 = 0;
        param_1 = (char *)0x0;
      }
      else {
        FUN_0000cb6c(uVar2);
        *param_3 = 7;
      }
    }
    else {
      *param_3 = 0xf;
    }
  }
  else {
    *param_3 = 1;
  }
  return param_1;
}



// ==========================================
// Function: FUN_0000953e
// Address:  0000953e
// Size:     248 bytes
// ==========================================

int FUN_0000953e(char *param_1,undefined4 param_2,undefined *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*param_1 == '\x01') {
    if (*DAT_00009628 == '\0') {
      if (*DAT_00009630 == '\0') {
        uVar3 = FUN_0000cb64();
        iVar2 = *(int *)(param_1 + 4);
        if (iVar2 == 0) {
          *(byte *)(*DAT_00009624 + 0x30) = *(byte *)(*DAT_00009624 + 0x30) | 2;
          *(undefined *)(*DAT_00009624 + 0x31) = 0;
          *(undefined4 *)(*DAT_00009624 + 0x2c) = param_2;
          FUN_00008222(param_1);
          FUN_0000cb6c(uVar3);
          FUN_0000806a();
          uVar3 = FUN_0000cb64();
          cVar1 = *(char *)(*DAT_00009624 + 0x31);
          if (cVar1 == '\0') {
            iVar2 = *(int *)(*DAT_00009624 + 0x20);
            *param_3 = 0;
          }
          else if ((cVar1 == '\x01') || (cVar1 != '\x02')) {
            FUN_000081f8(*DAT_00009624,param_1);
            iVar2 = 0;
            *param_3 = 10;
          }
          else {
            iVar2 = 0;
            *param_3 = 0xe;
          }
          *(undefined *)(*DAT_00009624 + 0x30) = 0;
          *(undefined *)(*DAT_00009624 + 0x31) = 0;
          *(undefined4 *)(*DAT_00009624 + 0x1c) = 0;
          *(undefined4 *)(*DAT_00009a18 + 0x20) = 0;
          FUN_0000cb6c(uVar3);
        }
        else {
          *(undefined4 *)(param_1 + 4) = 0;
          FUN_0000cb6c(uVar3);
          *param_3 = 0;
        }
      }
      else {
        *param_3 = 0xd;
        iVar2 = 0;
      }
    }
    else {
      *param_3 = 2;
      iVar2 = 0;
    }
  }
  else {
    *param_3 = 1;
    iVar2 = 0;
  }
  return iVar2;
}



// ==========================================
// Function: FUN_00009646
// Address:  00009646
// Size:     128 bytes
// ==========================================

char FUN_00009646(char *param_1,int param_2,undefined *param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*param_1 == '\x01') {
    uVar2 = FUN_0000cb64();
    if (param_1[10] == '\0') {
      FUN_0000cb6c(uVar2);
      cVar1 = '\0';
      *param_3 = 0;
    }
    else {
      cVar1 = '\0';
      if ((param_2 == 0) || (param_2 != 1)) {
        FUN_00008aba(param_1,0,2);
        cVar1 = '\x01';
      }
      else {
        while (param_1[10] != '\0') {
          FUN_00008aba(param_1,0,2);
          cVar1 = cVar1 + '\x01';
        }
      }
      FUN_0000cb6c(uVar2);
      FUN_0000806a();
      *param_3 = 0xe;
    }
  }
  else {
    *param_3 = 1;
    cVar1 = '\0';
  }
  return cVar1;
}



// ==========================================
// Function: FUN_000096c6
// Address:  000096c6
// Size:     80 bytes
// ==========================================

undefined4 FUN_000096c6(char *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*param_1 == '\x01') {
    uVar1 = FUN_0000cb64();
    if (param_1[10] == '\0') {
      if (*(int *)(param_1 + 4) == 0) {
        *(undefined4 *)(param_1 + 4) = param_2;
        FUN_0000cb6c(uVar1);
        uVar1 = 0;
      }
      else {
        FUN_0000cb6c(uVar1);
        uVar1 = 0x14;
      }
    }
    else {
      FUN_00008aba(param_1,param_2,2,0);
      FUN_0000cb6c(uVar1);
      FUN_0000806a();
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00009716
// Address:  00009716
// Size:     120 bytes
// ==========================================

undefined4 FUN_00009716(char *param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (*param_1 == '\x01') {
    uVar1 = FUN_0000cb64();
    if (param_1[10] == '\0') {
      if (*(int *)(param_1 + 4) == 0) {
        *(undefined4 *)(param_1 + 4) = param_2;
        FUN_0000cb6c(uVar1);
        uVar1 = 0;
      }
      else {
        FUN_0000cb6c(uVar1);
        uVar1 = 0x14;
      }
    }
    else {
      if ((param_3 & 1) == 0) {
        FUN_00008aba(param_1,param_2,2,0);
      }
      else {
        while (param_1[10] != '\0') {
          FUN_00008aba(param_1,param_2,2,0);
        }
      }
      FUN_0000cb6c(uVar1);
      if ((param_3 & 4) == 0) {
        FUN_0000806a();
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_0000978e
// Address:  0000978e
// Size:     76 bytes
// ==========================================

undefined4 FUN_0000978e(char *param_1,undefined4 *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  
  if (*param_1 == '\x01') {
    uVar2 = FUN_0000cb64();
    *(char *)((int)param_2 + 6) = param_1[10];
    pcVar3 = param_1 + 0xb;
    puVar4 = param_2 + 1;
    for (bVar1 = 0; bVar1 < 2; bVar1 = bVar1 + 1) {
      *(char *)puVar4 = *pcVar3;
      pcVar3 = pcVar3 + 1;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    *param_2 = *(undefined4 *)(param_1 + 4);
    FUN_0000cb6c(uVar2);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_000097da
// Address:  000097da
// Size:     88 bytes
// ==========================================

undefined4 FUN_000097da(char *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == '\x03') {
    uVar1 = FUN_0000cb64();
    if (param_1[10] == '\0') {
      if (*(ushort *)(param_1 + 8) < 0xffff) {
        *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + 1;
        FUN_0000cb6c(uVar1);
        uVar1 = 0;
      }
      else {
        FUN_0000cb6c(uVar1);
        uVar1 = 0x33;
      }
    }
    else {
      FUN_00008aba(param_1,0,1);
      FUN_0000cb6c(uVar1);
      FUN_0000806a();
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00009832
// Address:  00009832
// Size:     148 bytes
// ==========================================

undefined8 FUN_00009832(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = param_2;
  uVar3 = param_3;
  iVar2 = param_4;
  uVar1 = FUN_0000cb64();
  if (*DAT_00009a1c == '\0') {
    if (*(int *)(DAT_00009a20 + param_4 * 4) == 0) {
      *(undefined4 *)(DAT_00009a20 + param_4 * 4) = 1;
      FUN_0000cb6c(uVar1);
      uVar3 = FUN_0000a1da(param_1,param_2,param_3,0,uVar4,uVar3,iVar2);
      uVar4 = 0;
      iVar2 = FUN_000083e8(param_4,uVar3,0,0,0,0,0);
      if (iVar2 == 0) {
        if (*DAT_00009a24 == '\x01') {
          FUN_0000806a();
        }
      }
      else {
        uVar3 = FUN_0000cb64();
        *(undefined4 *)(DAT_00009a20 + param_4 * 4) = 0;
        FUN_0000cb6c(uVar3);
      }
    }
    else {
      FUN_0000cb6c(uVar1);
      iVar2 = 0x28;
    }
  }
  else {
    FUN_0000cb6c(uVar1);
    iVar2 = 0x3c;
  }
  return CONCAT44(uVar4,iVar2);
}



// ==========================================
// Function: FUN_000098c6
// Address:  000098c6
// Size:     290 bytes
// ==========================================

undefined4 FUN_000098c6(uint param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*DAT_00009a1c == '\0') {
    if (param_1 == 0xb) {
      uVar3 = 0x3e;
    }
    else {
      uVar3 = FUN_0000cb64();
      iVar2 = DAT_00009a28;
      if (param_1 == 0xff) {
        param_1 = (uint)*(byte *)(*DAT_00009a18 + 0x32);
      }
      iVar4 = *(int *)(DAT_00009a20 + param_1 * 4);
      if (iVar4 == 0) {
        FUN_0000cb6c(uVar3);
        uVar3 = 0x43;
      }
      else if (iVar4 == 1) {
        FUN_0000cb6c(uVar3);
        uVar3 = 0x3d;
      }
      else {
        pbVar1 = (byte *)(iVar4 + 0x34);
        *(byte *)(DAT_00009a28 + (uint)*pbVar1) =
             *(byte *)(DAT_00009a28 + (uint)*pbVar1) & ~*(byte *)(iVar4 + 0x35);
        if (*(char *)(iVar2 + (uint)*pbVar1) == '\0') {
          *DAT_00009a2c = *DAT_00009a2c & ~*(byte *)(iVar4 + 0x36);
        }
        if (*(int *)(iVar4 + 0x1c) != 0) {
          FUN_000081f8(iVar4,*(undefined4 *)(iVar4 + 0x1c));
        }
        if (*(int *)(iVar4 + 0x24) != 0) {
          FUN_00008d9c(*(int *)(iVar4 + 0x24));
        }
        *(undefined4 *)(iVar4 + 0x2c) = 0;
        *(undefined *)(iVar4 + 0x30) = 0;
        *(undefined *)(iVar4 + 0x31) = 0;
        if (*DAT_00009a30 != -1) {
          *DAT_00009a30 = *DAT_00009a30 + '\x01';
        }
        FUN_0000cb6c(uVar3);
        FUN_00008ab8();
        uVar3 = FUN_0000cb64();
        if (*DAT_00009a30 != '\0') {
          *DAT_00009a30 = *DAT_00009a30 + -1;
        }
        FUN_0000a1d4(iVar4);
        *DAT_00009a34 = *DAT_00009a34 + -1;
        *(undefined4 *)(DAT_00009a20 + param_1 * 4) = 0;
        if (*(int *)(iVar4 + 0x18) == 0) {
          *(undefined4 *)(*(int *)(iVar4 + 0x14) + 0x18) = 0;
          *DAT_00009a38 = *(undefined4 *)(iVar4 + 0x14);
        }
        else {
          *(undefined4 *)(*(int *)(iVar4 + 0x18) + 0x14) = *(undefined4 *)(iVar4 + 0x14);
          *(undefined4 *)(*(int *)(iVar4 + 0x14) + 0x18) = *(undefined4 *)(iVar4 + 0x18);
        }
        *(int *)(iVar4 + 0x14) = *DAT_00009a3c;
        *DAT_00009a3c = iVar4;
        FUN_0000cb6c(uVar3);
        if (*DAT_00009a24 == '\x01') {
          FUN_0000806a();
        }
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 0x40;
  }
  return uVar3;
}



// ==========================================
// Function: FUN_000099e8
// Address:  000099e8
// Size:     100 bytes
// ==========================================

undefined FUN_000099e8(int param_1)

{
  undefined uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0xb) {
    uVar1 = 0x3e;
  }
  else if (param_1 == 0xff) {
    uVar2 = FUN_0000cb64();
    uVar1 = *(undefined *)(*DAT_00009a18 + 0x37);
    FUN_0000cb6c(uVar2);
  }
  else {
    uVar2 = FUN_0000cb64();
    iVar3 = *(int *)(DAT_00009e30 + param_1 * 4);
    if (iVar3 == 0) {
      FUN_0000cb6c(uVar2);
      uVar1 = 0x43;
    }
    else if (iVar3 == 1) {
      FUN_0000cb6c(uVar2);
      uVar1 = 0x3d;
    }
    else {
      *(undefined *)(iVar3 + 0x37) = 0x3f;
      FUN_0000cb6c(uVar2);
      uVar1 = 0;
    }
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00009a76
// Address:  00009a76
// Size:     154 bytes
// ==========================================

undefined4 FUN_00009a76(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_0000cb64();
  iVar3 = *(int *)(DAT_00009e30 + param_1 * 4);
  if (iVar3 == 0) {
    FUN_0000cb6c(uVar2);
    uVar2 = 0x46;
  }
  else if (iVar3 == 1) {
    FUN_0000cb6c(uVar2);
    uVar2 = 0x43;
  }
  else if ((*(byte *)(iVar3 + 0x30) & 8) == 0) {
    FUN_0000cb6c(uVar2);
    uVar2 = 0x44;
  }
  else {
    pbVar1 = (byte *)(iVar3 + 0x30);
    *pbVar1 = *pbVar1 & 0xf7;
    if (*pbVar1 == 0) {
      if (*(int *)(iVar3 + 0x2c) == 0) {
        *DAT_00009e34 = *(byte *)(iVar3 + 0x36) | *DAT_00009e34;
        *(byte *)(DAT_00009e38 + (uint)*(byte *)(iVar3 + 0x34)) =
             *(byte *)(DAT_00009e38 + (uint)*(byte *)(iVar3 + 0x34)) | *(byte *)(iVar3 + 0x35);
        FUN_0000cb6c(uVar2);
        if (*DAT_00009e3c == '\x01') {
          FUN_0000806a();
        }
      }
      else {
        FUN_0000cb6c(uVar2);
      }
    }
    else {
      FUN_0000cb6c(uVar2);
    }
    uVar2 = 0;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_00009b10
// Address:  00009b10
// Size:     152 bytes
// ==========================================

undefined4 FUN_00009b10(uint param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = FUN_0000cb64();
  iVar2 = DAT_00009e38;
  if (param_1 == 0xff) {
    param_1 = (uint)*(byte *)(*DAT_00009e40 + 0x32);
    bVar1 = true;
  }
  else if (*(byte *)(*DAT_00009e40 + 0x32) == param_1) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  iVar4 = *(int *)(DAT_00009e30 + param_1 * 4);
  if (iVar4 == 0) {
    FUN_0000cb6c(uVar3);
    uVar3 = 0x48;
  }
  else if (iVar4 == 1) {
    FUN_0000cb6c(uVar3);
    uVar3 = 0x43;
  }
  else {
    uVar5 = (uint)*(byte *)(iVar4 + 0x34);
    *(byte *)(DAT_00009e38 + uVar5) = *(byte *)(DAT_00009e38 + uVar5) & ~*(byte *)(iVar4 + 0x35);
    if (*(char *)(iVar2 + uVar5) == '\0') {
      *DAT_00009e34 = *DAT_00009e34 & ~*(byte *)(iVar4 + 0x36);
    }
    *(byte *)(iVar4 + 0x30) = *(byte *)(iVar4 + 0x30) | 8;
    FUN_0000cb6c(uVar3);
    if (bVar1) {
      FUN_0000806a();
    }
    uVar3 = 0;
  }
  return uVar3;
}



// ==========================================
// Function: FUN_00009ba8
// Address:  00009ba8
// Size:     82 bytes
// ==========================================

undefined4 FUN_00009ba8(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0000cb64();
  if (param_1 == 0xff) {
    param_1 = (uint)*(byte *)(*DAT_00009e40 + 0x32);
  }
  iVar2 = *(int *)(DAT_00009e30 + param_1 * 4);
  if (iVar2 == 0) {
    FUN_0000cb6c(uVar1);
    uVar1 = 0x29;
  }
  else if (iVar2 == 1) {
    FUN_0000cb6c(uVar1);
    uVar1 = 0x43;
  }
  else {
    thunk_FUN_00008b3a(param_2,iVar2,0x50);
    FUN_0000cb6c(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00009bfa
// Address:  00009bfa
// Size:     60 bytes
// ==========================================

undefined4 FUN_00009bfa(int param_1,int param_2,undefined *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_0000cb64();
  if (param_1 == 0xff) {
    iVar2 = *DAT_00009e40;
  }
  else {
    iVar2 = *(int *)(DAT_00009e30 + param_1 * 4);
  }
  uVar3 = *(undefined4 *)(iVar2 + 0x4c + param_2 * 4);
  FUN_0000cb6c(uVar1);
  *param_3 = 0;
  return uVar3;
}



// ==========================================
// Function: FUN_00009c36
// Address:  00009c36
// Size:     58 bytes
// ==========================================

char FUN_00009c36(undefined *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_0000cb64();
  if (*DAT_00009e44 == '\0') {
    cVar1 = *DAT_00009e44;
    *DAT_00009e44 = *DAT_00009e44 + '\x01';
    FUN_0000cb6c(uVar2);
    *param_1 = 0;
  }
  else {
    *param_1 = 0x96;
    FUN_0000cb6c(uVar2);
    cVar1 = '\x01';
  }
  return cVar1;
}



// ==========================================
// Function: FUN_00009c70
// Address:  00009c70
// Size:     62 bytes
// ==========================================

void FUN_00009c70(int param_1,int param_2,undefined4 param_3,undefined *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0000cb64();
  if (param_1 == 0xff) {
    iVar2 = *DAT_00009e40;
  }
  else {
    iVar2 = *(int *)(DAT_00009e30 + param_1 * 4);
  }
  *(undefined4 *)(iVar2 + 0x4c + param_2 * 4) = param_3;
  FUN_0000cb6c(uVar1);
  *param_4 = 0;
  return;
}



// ==========================================
// Function: FUN_00009cae
// Address:  00009cae
// Size:     18 bytes
// ==========================================

void FUN_00009cae(void)

{
  FUN_0000a1c4(*DAT_00009e40);
  FUN_000098c6(0xff);
  return;
}



// ==========================================
// Function: FUN_00009cc0
// Address:  00009cc0
// Size:     100 bytes
// ==========================================

void FUN_00009cc0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (((*DAT_00009e48 == '\0') && (*DAT_00009e4c == '\0')) && (param_1 != 0)) {
    uVar2 = FUN_0000cb64();
    iVar1 = DAT_00009e38;
    uVar3 = (uint)*(byte *)(*DAT_00009e40 + 0x34);
    *(byte *)(DAT_00009e38 + uVar3) =
         *(byte *)(DAT_00009e38 + uVar3) & ~*(byte *)(*DAT_00009e40 + 0x35);
    if (*(char *)(iVar1 + uVar3) == '\0') {
      *DAT_00009e34 = *DAT_00009e34 & ~*(byte *)(*DAT_00009e40 + 0x36);
    }
    *(int *)(*DAT_00009e40 + 0x2c) = param_1;
    FUN_0000cb6c(uVar2);
    FUN_0000806a();
  }
  return;
}



// ==========================================
// Function: FUN_00009d24
// Address:  00009d24
// Size:     168 bytes
// ==========================================

undefined4 FUN_00009d24(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 < 0xb) {
    uVar1 = FUN_0000cb64();
    iVar2 = *(int *)(DAT_00009e30 + param_1 * 4);
    if (iVar2 == 0) {
      FUN_0000cb6c(uVar1);
      uVar1 = 0x43;
    }
    else if (iVar2 == 1) {
      FUN_0000cb6c(uVar1);
      uVar1 = 0x43;
    }
    else if (*(int *)(iVar2 + 0x2c) == 0) {
      FUN_0000cb6c(uVar1);
      uVar1 = 0x50;
    }
    else {
      *(undefined4 *)(iVar2 + 0x2c) = 0;
      if ((*(byte *)(iVar2 + 0x30) & 0x37) == 0) {
        *(undefined *)(iVar2 + 0x31) = 0;
      }
      else {
        *(byte *)(iVar2 + 0x30) = *(byte *)(iVar2 + 0x30) & 200;
        *(undefined *)(iVar2 + 0x31) = 1;
      }
      if ((*(byte *)(iVar2 + 0x30) & 8) == 0) {
        *DAT_00009e34 = *(byte *)(iVar2 + 0x36) | *DAT_00009e34;
        *(byte *)(DAT_00009e38 + (uint)*(byte *)(iVar2 + 0x34)) =
             *(byte *)(DAT_00009e38 + (uint)*(byte *)(iVar2 + 0x34)) | *(byte *)(iVar2 + 0x35);
        FUN_0000cb6c(uVar1);
        FUN_0000806a();
      }
      else {
        FUN_0000cb6c(uVar1);
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x2a;
  }
  return uVar1;
}



// ==========================================
// Function: FUN_00009dfc
// Address:  00009dfc
// Size:     50 bytes
// ==========================================

int FUN_00009dfc(void)

{
  int iVar1;
  
  if (*DAT_00009e54 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *DAT_00009e54;
    *DAT_00009e54 = *(int *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *DAT_00009e58 = *DAT_00009e58 + 1;
    *DAT_00009e5c = *DAT_00009e5c + -1;
  }
  return iVar1;
}



// ==========================================
// Function: FUN_00009e60
// Address:  00009e60
// Size:     92 bytes
// ==========================================

int FUN_00009e60(undefined4 param_1,undefined4 param_2,undefined param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined *param_7)

{
  int iVar1;
  
  if (*DAT_0000a1ac == '\0') {
    FUN_000081c6();
    iVar1 = FUN_00009dfc();
    if (iVar1 == 0) {
      FUN_000080c2();
      *param_7 = 0x86;
      iVar1 = 0;
    }
    else {
      *(undefined *)(iVar1 + 0x21) = 1;
      *(undefined4 *)(iVar1 + 0x18) = param_1;
      *(undefined4 *)(iVar1 + 0x1c) = param_2;
      *(undefined *)(iVar1 + 0x20) = param_3;
      *(undefined4 *)(iVar1 + 4) = param_4;
      *(undefined4 *)(iVar1 + 8) = param_5;
      FUN_000080c2();
      *param_7 = 0;
    }
  }
  else {
    *param_7 = 0x8b;
    iVar1 = 0;
  }
  return iVar1;
}



// ==========================================
// Function: FUN_00009ebc
// Address:  00009ebc
// Size:     52 bytes
// ==========================================

void FUN_00009ebc(int param_1)

{
  *(undefined *)(param_1 + 0x21) = 0;
  *(undefined *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(int *)(param_1 + 0xc) = *DAT_0000a1b0;
  *DAT_0000a1b0 = param_1;
  *DAT_0000a1b4 = *DAT_0000a1b4 + -1;
  *DAT_0000a1b8 = *DAT_0000a1b8 + 1;
  return;
}



// ==========================================
// Function: FUN_00009ef0
// Address:  00009ef0
// Size:     124 bytes
// ==========================================

undefined4 FUN_00009ef0(char *param_1,undefined *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*param_1 == 'd') {
    if (*DAT_0000a1ac == '\0') {
      FUN_000081c6();
      cVar1 = param_1[0x21];
      if (cVar1 == '\0') {
        FUN_000080c2();
        *param_2 = 0x87;
        uVar2 = 0;
      }
      else if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
        FUN_00009ebc(param_1);
        FUN_000080c2();
        *param_2 = 0;
        uVar2 = 1;
      }
      else if (cVar1 == '\x03') {
        FUN_00008180(param_1);
        FUN_00009ebc(param_1);
        FUN_000080c2();
        *param_2 = 0;
        uVar2 = 1;
      }
      else {
        FUN_000080c2();
        *param_2 = 0x8d;
        uVar2 = 0;
      }
    }
    else {
      *param_2 = 0x8b;
      uVar2 = 0;
    }
  }
  else {
    *param_2 = 0x89;
    uVar2 = 0;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_00009f6c
// Address:  00009f6c
// Size:     164 bytes
// ==========================================

int FUN_00009f6c(char *param_1,undefined *param_2)

{
  char cVar1;
  int iVar2;
  
  if (*param_1 == 'd') {
    if (*DAT_0000a1ac == '\0') {
      FUN_000081c6();
      cVar1 = param_1[0x21];
      if (cVar1 == '\0') {
        FUN_000080c2();
        *param_2 = 0x87;
        iVar2 = 0;
      }
      else if (cVar1 == '\x01') {
        if ((param_1[0x20] == '\x01') || (param_1[0x20] != '\x02')) {
          iVar2 = *(int *)(param_1 + 0x18);
          FUN_000080c2();
          *param_2 = 0;
        }
        else {
          if (*(int *)(param_1 + 0x18) == 0) {
            iVar2 = *(int *)(param_1 + 0x1c);
          }
          else {
            iVar2 = *(int *)(param_1 + 0x18);
          }
          FUN_000080c2();
          *param_2 = 0;
        }
      }
      else if (cVar1 == '\x02') {
        FUN_000080c2();
        iVar2 = 0;
        *param_2 = 0;
      }
      else if (cVar1 == '\x03') {
        iVar2 = *(int *)(param_1 + 0x14) - *DAT_0000a1bc;
        FUN_000080c2();
        *param_2 = 0;
      }
      else {
        FUN_000080c2();
        *param_2 = 0x8d;
        iVar2 = 0;
      }
    }
    else {
      *param_2 = 0x8b;
      iVar2 = 0;
    }
  }
  else {
    *param_2 = 0x89;
    iVar2 = 0;
  }
  return iVar2;
}



// ==========================================
// Function: FUN_0000a010
// Address:  0000a010
// Size:     86 bytes
// ==========================================

char FUN_0000a010(char *param_1,undefined *param_2)

{
  char cVar1;
  
  if (*param_1 == 'd') {
    if (*DAT_0000a1ac == '\0') {
      FUN_000081c6();
      cVar1 = param_1[0x21];
      if ((((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x02')) || (cVar1 == '\x03')) {
        *param_2 = 0;
      }
      else {
        *param_2 = 0x8d;
      }
      FUN_000080c2();
    }
    else {
      *param_2 = 0x8b;
      cVar1 = '\0';
    }
  }
  else {
    *param_2 = 0x89;
    cVar1 = '\0';
  }
  return cVar1;
}



// ==========================================
// Function: FUN_0000a066
// Address:  0000a066
// Size:     128 bytes
// ==========================================

undefined4 FUN_0000a066(char *param_1,undefined *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*param_1 == 'd') {
    if (*DAT_0000a1ac == '\0') {
      FUN_000081c6();
      cVar1 = param_1[0x21];
      if (cVar1 == '\0') {
        FUN_000080c2();
        *param_2 = 0x87;
        uVar2 = 0;
      }
      else if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
        FUN_00008114(param_1,0);
        FUN_000080c2();
        *param_2 = 0;
        uVar2 = 1;
      }
      else if (cVar1 == '\x03') {
        FUN_00008180(param_1);
        FUN_00008114(param_1,0);
        FUN_000080c2();
        *param_2 = 0;
        uVar2 = 1;
      }
      else {
        FUN_000080c2();
        *param_2 = 0x8d;
        uVar2 = 0;
      }
    }
    else {
      *param_2 = 0x8b;
      uVar2 = 0;
    }
  }
  else {
    *param_2 = 0x89;
    uVar2 = 0;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_0000a0e6
// Address:  0000a0e6
// Size:     180 bytes
// ==========================================

undefined4 FUN_0000a0e6(char *param_1,int param_2,undefined4 param_3,undefined *param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  if (*param_1 == 'd') {
    if (*DAT_0000a1ac == '\0') {
      FUN_000081c6();
      cVar1 = param_1[0x21];
      if (cVar1 == '\0') {
        FUN_000080c2();
        *param_4 = 0x87;
        uVar2 = 0;
      }
      else if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
        FUN_000080c2();
        *param_4 = 0x8e;
        uVar2 = 1;
      }
      else if (cVar1 == '\x03') {
        FUN_00008180(param_1);
        *param_4 = 0;
        if (param_2 != 0) {
          if (param_2 == 3) {
            if (*(code **)(param_1 + 4) == (code *)0x0) {
              *param_4 = 0x8f;
            }
            else {
              (**(code **)(param_1 + 4))(param_1,*(undefined4 *)(param_1 + 8));
            }
          }
          else if (param_2 == 4) {
            if (*(code **)(param_1 + 4) == (code *)0x0) {
              *param_4 = 0x8f;
            }
            else {
              (**(code **)(param_1 + 4))(param_1,param_3);
            }
          }
          else {
            *param_4 = 0x84;
          }
        }
        FUN_000080c2();
        uVar2 = 1;
      }
      else {
        FUN_000080c2();
        *param_4 = 0x8d;
        uVar2 = 0;
      }
    }
    else {
      *param_4 = 0x8b;
      uVar2 = 0;
    }
  }
  else {
    *param_4 = 0x89;
    uVar2 = 0;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_0000a19a
// Address:  0000a19a
// Size:     16 bytes
// ==========================================

undefined4 FUN_0000a19a(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000097da(*DAT_0000a1c0);
  return uVar1;
}



// ==========================================
// Function: FUN_0000a1c4
// Address:  0000a1c4
// Size:     2 bytes
// ==========================================

void FUN_0000a1c4(void)

{
  return;
}



// ==========================================
// Function: FUN_0000a1c8
// Address:  0000a1c8
// Size:     8 bytes
// ==========================================

void FUN_0000a1c8(void)

{
  *DAT_0000a2e0 = 0;
  return;
}



// ==========================================
// Function: FUN_0000a1d0
// Address:  0000a1d0
// Size:     2 bytes
// ==========================================

void FUN_0000a1d0(void)

{
  return;
}



// ==========================================
// Function: FUN_0000a1d2
// Address:  0000a1d2
// Size:     2 bytes
// ==========================================

void FUN_0000a1d2(void)

{
  return;
}



// ==========================================
// Function: FUN_0000a1d4
// Address:  0000a1d4
// Size:     2 bytes
// ==========================================

void FUN_0000a1d4(void)

{
  return;
}



// ==========================================
// Function: FUN_0000a1d6
// Address:  0000a1d6
// Size:     2 bytes
// ==========================================

void FUN_0000a1d6(void)

{
  return;
}



// ==========================================
// Function: FUN_0000a1da
// Address:  0000a1da
// Size:     152 bytes
// ==========================================

undefined4 * FUN_0000a1da(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = 0x1000000;
  param_3[-1] = param_1;
  param_3[-2] = DAT_0000a2e4;
  param_3[-3] = 0x12121212;
  param_3[-4] = 0x3030303;
  param_3[-5] = 0x2020202;
  param_3[-6] = 0x1010101;
  param_3[-7] = param_2;
  param_3[-8] = 0x11111111;
  param_3[-9] = 0x10101010;
  param_3[-10] = 0x9090909;
  param_3[-0xb] = 0x8080808;
  param_3[-0xc] = 0x7070707;
  param_3[-0xd] = 0x6060606;
  param_3[-0xe] = 0x5050505;
  param_3[-0xf] = 0x4040404;
  return param_3 + -0xf;
}



// ==========================================
// Function: FUN_0000a274
// Address:  0000a274
// Size:     2 bytes
// ==========================================

void FUN_0000a274(void)

{
  return;
}



// ==========================================
// Function: FUN_0000a276
// Address:  0000a276
// Size:     30 bytes
// ==========================================

void FUN_0000a276(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_0000a2e0;
  *DAT_0000a2e0 = *DAT_0000a2e0 + 1;
  if (0x31 < *puVar1) {
    *puVar1 = 0;
    FUN_0000a19a();
  }
  return;
}



// ==========================================
// Function: FUN_0000a294
// Address:  0000a294
// Size:     34 bytes
// ==========================================

void FUN_0000a294(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0000cb64();
  *DAT_0000a2e8 = *DAT_0000a2e8 + '\x01';
  FUN_0000cb6c(uVar1);
  FUN_00008a14();
  FUN_00008974();
  return;
}



// ==========================================
// Function: FUN_0000a2b6
// Address:  0000a2b6
// Size:     42 bytes
// ==========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000a2b6(int param_1)

{
  _DAT_e000e014 = param_1 + -1;
  *DAT_0000a2ec = 0xff;
  _DAT_e000e010 = _DAT_e000e010 | 7;
  return;
}



// ==========================================
// Function: FUN_0000a2f0
// Address:  0000a2f0
// Size:     170 bytes
// ==========================================

void FUN_0000a2f0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 8);
  uVar2 = *(uint *)(param_1 + 4);
  if (uVar3 < uVar2) {
    uVar2 = uVar2 - uVar3;
    uVar3 = (uVar2 * 0x100) / 0x3000000;
    uVar1 = (uVar2 * 0x10000) / 0x3000000;
    uVar2 = (uVar2 & 0xff) / 3;
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 4);
    *(uint *)(param_1 + 0x1c) = *(int *)(param_1 + 8) + (uVar3 << 0x11 | uVar1 << 9 | uVar2 << 1);
    *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 8) + (uVar3 << 0x10 | uVar1 << 8 | uVar2);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 8);
  }
  else {
    uVar3 = uVar3 - uVar2;
    uVar2 = (uVar3 * 0x100) / 0x3000000;
    uVar1 = (uVar3 * 0x10000) / 0x3000000;
    uVar3 = (uVar3 & 0xff) / 3;
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 4);
    *(uint *)(param_1 + 0x1c) = *(int *)(param_1 + 4) + (uVar2 << 0x10 | uVar1 << 8 | uVar3);
    *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 4) + (uVar2 << 0x11 | uVar1 << 9 | uVar3 << 1);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 8);
  }
  return;
}



// ==========================================
// Function: FUN_0000a39a
// Address:  0000a39a
// Size:     154 bytes
// ==========================================

void FUN_0000a39a(void)

{
  int *piVar1;
  
  FUN_0000c91c(DAT_0000a698,DAT_0000a694,0x28);
  piVar1 = DAT_0000a69c;
  *DAT_0000a69c = DAT_0000a698;
  if (*(char *)(DAT_0000a6a0 + 4) == '\x01') {
    *(undefined4 *)(*piVar1 + 4) = 0xffffff;
    *(undefined4 *)(*DAT_0000a69c + 8) = 0;
    *DAT_0000a6a4 = 0xffffff;
  }
  else {
    *(undefined4 *)(*DAT_0000a69c + 4) = 0;
    *(undefined4 *)(*DAT_0000a69c + 8) = 0xffffff;
    *DAT_0000a6a4 = 0;
  }
  FUN_0000a2f0(*DAT_0000a69c);
  FUN_0000c91c(DAT_0000a6ac,DAT_0000a6a8,0x28);
  piVar1 = DAT_0000a6b0;
  *DAT_0000a6b0 = DAT_0000a6ac;
  if (*(char *)(DAT_0000a6a0 + 4) == '\x01') {
    *(undefined4 *)(*piVar1 + 4) = 0xffffff;
    *(undefined4 *)(*DAT_0000a6b0 + 8) = 0;
  }
  else {
    *(undefined4 *)(*DAT_0000a6b0 + 4) = 0;
    *(undefined4 *)(*DAT_0000a6b0 + 8) = 0xffffff;
  }
  FUN_0000a2f0(*DAT_0000a6b0);
  return;
}



// ==========================================
// Function: FUN_0000a434
// Address:  0000a434
// Size:     26 bytes
// ==========================================

void FUN_0000a434(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  if (*(char *)(DAT_0000a6a0 + 4) == '\x01') {
    *(undefined4 *)(param_1 + 8) = param_2;
  }
  FUN_0000a2f0(param_1);
  return;
}



// ==========================================
// Function: FUN_0000a44e
// Address:  0000a44e
// Size:     26 bytes
// ==========================================

void FUN_0000a44e(int param_1)

{
  if (*(char *)(DAT_0000a6a0 + 4) == '\x01') {
    *(undefined4 *)(param_1 + 4) = 0xffffff;
  }
  FUN_0000a2f0(param_1);
  return;
}



// ==========================================
// Function: FUN_0000a468
// Address:  0000a468
// Size:     164 bytes
// ==========================================

void FUN_0000a468(byte *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  int local_34;
  int local_30;
  uint local_2c;
  
  local_30 = *(int *)(param_1 + 0xc);
  local_34 = *(int *)(param_1 + 0x10);
  pbVar7 = (byte *)(*(int *)(param_1 + 0x14) + (param_2 + -1) * 8);
  bVar1 = pbVar7[1];
  bVar2 = *pbVar7;
  for (uVar5 = 0; uVar5 < *param_1; uVar5 = uVar5 + 1) {
    local_2c = 0;
    for (uVar6 = 0; uVar6 < bVar1; uVar6 = uVar6 + 1) {
      bVar3 = *(byte *)(*(int *)(pbVar7 + 4) + uVar5 * bVar1 + uVar6);
      uVar4 = 0;
      for (; (uVar4 < 4 && (local_2c < bVar2)); local_2c = local_2c + 1) {
        FUN_000066ca(local_30,local_34,
                     *(undefined4 *)
                      (param_1 + ((int)(uint)bVar3 >> (uVar4 * -2 + 6 & 0xff) & 3U) * 4 + 0x18));
        uVar4 = uVar4 + 1;
        local_30 = local_30 + 1;
      }
    }
    local_34 = local_34 + 1;
    local_30 = *(int *)(param_1 + 0xc);
  }
  *(uint *)(param_1 + 0xc) = (uint)bVar2 + *(int *)(param_1 + 0xc);
  return;
}



// ==========================================
// Function: FUN_0000a50c
// Address:  0000a50c
// Size:     34 bytes
// ==========================================

int FUN_0000a50c(byte *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  for (; *param_1 != 0; param_1 = param_1 + 1) {
    iVar1 = iVar1 + (uint)*(byte *)(*(int *)(param_2 + 0x14) + (*param_1 - 1) * 8);
  }
  return iVar1;
}



// ==========================================
// Function: FUN_0000a52e
// Address:  0000a52e
// Size:     112 bytes
// ==========================================

uint FUN_0000a52e(char *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  
  uVar1 = FUN_0000a50c(param_1,param_2);
  if (param_5 == 0) {
    *(int *)(param_2 + 0xc) = param_3;
  }
  else if (param_5 == 1) {
    *(uint *)(param_2 + 0xc) = param_3 - (uVar1 >> 1);
  }
  else if (param_5 == 2) {
    *(uint *)(param_2 + 0xc) = param_3 - uVar1;
  }
  *(undefined4 *)(param_2 + 0x10) = param_4;
  FUN_0000a2f0(param_2);
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    FUN_0000a468(param_2,*param_1);
  }
  return uVar1;
}



// ==========================================
// Function: FUN_0000a59e
// Address:  0000a59e
// Size:     246 bytes
// ==========================================

undefined4
FUN_0000a59e(byte *param_1,byte *param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  *(undefined4 *)(param_2 + 0xc) = param_3;
  *(undefined4 *)(param_2 + 0x10) = param_4;
  FUN_0000a2f0(param_2);
  while( true ) {
    if (*param_1 == 0) {
      FUN_000066ee(*(int *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10),
                   param_5 - *(int *)(param_2 + 0xc),*param_2,*(undefined4 *)(param_2 + 4));
      return 1;
    }
    local_44 = *(uint *)(param_2 + 0xc);
    local_48 = *(int *)(param_2 + 0x10);
    iVar3 = *param_1 - 1;
    uVar4 = (uint)*(byte *)(*(int *)(param_2 + 0x14) + iVar3 * 8 + 1);
    uVar5 = (uint)*(byte *)(*(int *)(param_2 + 0x14) + iVar3 * 8);
    for (uVar6 = 0; uVar6 < *param_2; uVar6 = uVar6 + 1) {
      local_40 = 0;
      for (local_3c = 0; local_3c < uVar4; local_3c = local_3c + 1) {
        bVar1 = *(byte *)(*(int *)(*(int *)(param_2 + 0x14) + iVar3 * 8 + 4) +
                         uVar6 * uVar4 + local_3c);
        uVar2 = 0;
        for (; (uVar2 < 4 && (local_40 < uVar5)); local_40 = local_40 + 1) {
          if (local_44 < param_5) {
            FUN_000066ca(local_44,local_48,
                         *(undefined4 *)
                          (param_2 + ((int)(uint)bVar1 >> (uVar2 * -2 + 6 & 0xff) & 3U) * 4 + 0x18))
            ;
          }
          uVar2 = uVar2 + 1;
          local_44 = local_44 + 1;
        }
      }
      local_48 = local_48 + 1;
      local_44 = *(uint *)(param_2 + 0xc);
    }
    *(uint *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + uVar5;
    if (param_5 < *(uint *)(param_2 + 0xc)) break;
    param_1 = param_1 + 1;
  }
  return 0;
}



// ==========================================
// Function: FUN_0000a6b4
// Address:  0000a6b4
// Size:     66 bytes
// ==========================================

void FUN_0000a6b4(void)

{
  undefined4 uVar1;
  
  if ((*DAT_0000aaac == '\x01') || (*DAT_0000aaac == '\x02')) {
    if (*(char *)(DAT_0000aab0 + 2) == '\x02') {
      FUN_0000c34e(DAT_0000aab4,0xc,200,1,1);
    }
    else {
      uVar1 = FUN_00000e70();
      FUN_000066ee(0,0xb4,0x2e,0x50,uVar1);
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000a6f6
// Address:  0000a6f6
// Size:     96 bytes
// ==========================================

void FUN_0000a6f6(void)

{
  char cVar1;
  
  cVar1 = *DAT_0000aab8;
  if ((((cVar1 == '\x03') || (cVar1 == '\x05')) || (cVar1 == '\x06')) &&
     (*(char *)(DAT_0000aabc + 7) != '\0')) {
    if (*DAT_0000aac0 == '\x01') {
      FUN_0000c34e(DAT_0000aac4,0x1ba,0x20,1,1);
    }
    else if (*DAT_0000aac0 == '\x03') {
      FUN_0000c34e(DAT_0000aac8,0x1ba,0x20,1,1);
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000a756
// Address:  0000a756
// Size:     52 bytes
// ==========================================

void FUN_0000a756(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < 6; uVar2 = uVar2 + 1) {
    uVar1 = FUN_00000e70();
    FUN_000066ee(*(undefined2 *)(DAT_0000aacc + uVar2 * 4),
                 *(undefined2 *)(DAT_0000aacc + uVar2 * 4 + 2),0x2e,0x50,uVar1);
  }
  FUN_0000a6b4();
  FUN_0000a6f6();
  return;
}



// ==========================================
// Function: FUN_0000a78a
// Address:  0000a78a
// Size:     38 bytes
// ==========================================

void FUN_0000a78a(void)

{
  FUN_0000c34e(DAT_0000aad0,0xe,0x75,1,1);
  FUN_0000c34e(DAT_0000aad4,0x1c0,0x75,1,1);
  return;
}



// ==========================================
// Function: FUN_0000a7b0
// Address:  0000a7b0
// Size:     40 bytes
// ==========================================

void FUN_0000a7b0(void)

{
  FUN_0000c34e(DAT_0000aad8,0x1b5,0x80,1,1);
  FUN_0000c34e(DAT_0000aadc,0x1b5,0xd4,1,1);
  return;
}



// ==========================================
// Function: FUN_0000a7d8
// Address:  0000a7d8
// Size:     94 bytes
// ==========================================

void FUN_0000a7d8(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00000e70();
  FUN_000066ee(10,0xdb - param_1,0x20,3,uVar1 ^ 0xffffff);
  uVar1 = FUN_00000e70();
  FUN_000066ee(0x1b9,0xdb - param_1,0x20,3,uVar1 ^ 0xffffff);
  uVar1 = FUN_00000e70();
  FUN_000066ee(0x1c8,0xcc - param_1,3,0x20,uVar1 ^ 0xffffff);
  return;
}



// ==========================================
// Function: FUN_0000a836
// Address:  0000a836
// Size:     28 bytes
// ==========================================

undefined4 FUN_0000a836(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = DAT_0000aae4;
    if (param_2 == 0) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = DAT_0000aae0;
    if (param_2 == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// ==========================================
// Function: FUN_0000a852
// Address:  0000a852
// Size:     134 bytes
// ==========================================

void FUN_0000a852(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0000a836(*DAT_0000aae8 == '\0',param_1 & 0x10,*DAT_0000aae8 == '\0',param_4,param_4);
  if (iVar1 != 0) {
    FUN_0000c34e(iVar1,0x37,0x5f,1,1);
  }
  iVar1 = FUN_0000a836(*DAT_0000aae8 == '\x01',param_1 & 0x20);
  if (iVar1 != 0) {
    FUN_0000c34e(iVar1,0x37,0x9b,1,1);
  }
  iVar1 = FUN_0000a836(*DAT_0000aae8 == '\x02',param_1 & 0x40);
  if (iVar1 != 0) {
    FUN_0000c34e(iVar1,0x37,0xd7,1,1);
  }
  return;
}



// ==========================================
// Function: FUN_0000a8d8
// Address:  0000a8d8
// Size:     460 bytes
// ==========================================

void FUN_0000a8d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00000e80(param_1);
  FUN_0000a434(*DAT_0000aaec,uVar1);
  if (param_4 == 0) {
    FUN_0000a52e(*(undefined4 *)
                  (DAT_0000aaf4 + (uint)*DAT_0000aaf0 * 0x24 + (uint)*DAT_0000aaf8 * 4),
                 *DAT_0000aaec,param_2,param_3,1);
  }
  else {
    switch(*DAT_0000aaf8) {
    case 0:
      FUN_0000a52e(*(undefined4 *)
                    (DAT_0000ab1c + (uint)*DAT_0000aaf0 * 0x3c +
                    (uint)*(byte *)(DAT_0000ab20 + 5) * 4),*DAT_0000aaec,param_2,param_3,1);
      break;
    case 1:
      FUN_0000a52e(*(undefined4 *)(DAT_0000aafc + (uint)*DAT_0000aaf0 * 8 + (uint)*DAT_0000ab00 * 4)
                   ,*DAT_0000aaec,param_2,param_3,1);
      break;
    case 2:
      FUN_0000a52e(*(undefined4 *)
                    (DAT_0000ab04 + (uint)*DAT_0000aaf0 * 0xc + (uint)*DAT_0000ab00 * 4),
                   *DAT_0000aaec,param_2,param_3,1);
      break;
    default:
      FUN_0000a52e(*(undefined4 *)
                    (DAT_0000aaf4 + (uint)*DAT_0000aaf0 * 0x24 + (uint)*DAT_0000aaf8 * 4),
                   *DAT_0000aaec,param_2,param_3,1);
      break;
    case 4:
      if ((*(byte *)(DAT_0000aabc + 5) & 0x10) == 0) {
        FUN_0000a52e(*(undefined4 *)
                      (DAT_0000ab0c + (uint)*DAT_0000aaf0 * 0x14 + (uint)*DAT_0000ab00 * 4),
                     *DAT_0000aaec,param_2,param_3,1);
      }
      else {
        FUN_0000a52e(*(undefined4 *)
                      (DAT_0000ab08 + (uint)*DAT_0000aaf0 * 0x18 + (uint)*DAT_0000ab00 * 4),
                     *DAT_0000aaec,param_2,param_3,1);
      }
      break;
    case 5:
      FUN_0000a52e(*(undefined4 *)
                    (DAT_0000ab10 + (uint)*DAT_0000aaf0 * 0xc + (uint)*DAT_0000ab00 * 4),
                   *DAT_0000aaec,param_2,param_3,1);
      break;
    case 6:
      FUN_0000a52e(*(undefined4 *)
                    (DAT_0000ab14 + (uint)*DAT_0000aaf0 * 0xc + (uint)*DAT_0000ab00 * 4),
                   *DAT_0000aaec,param_2,param_3,1);
      break;
    case 7:
      FUN_0000a52e(*(undefined4 *)
                    (DAT_0000ab18 + (uint)*DAT_0000aaf0 * 0x1c + (uint)*DAT_0000ab00 * 4),
                   *DAT_0000aaec,param_2,param_3,1);
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000ab24
// Address:  0000ab24
// Size:     260 bytes
// ==========================================

void FUN_0000ab24(int param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_24;
  undefined4 uStack_20;
  
  local_24 = *DAT_0000af1c;
  uStack_20 = DAT_0000af1c[1];
  uVar2 = DAT_0000af24;
  if (*DAT_0000af20 == '\x02') {
    uVar2 = 0xffffff;
  }
  uVar2 = FUN_00000e80(uVar2);
  FUN_0000a434(*DAT_0000af28,uVar2);
  if (param_1 != 0) {
    if (*(ushort *)(DAT_0000af2c + 6) < 0xe10) {
      FUN_0000c5d0(&local_24,s__02d__02d_0000af30,*(ushort *)(DAT_0000af2c + 6) / 0x3c,
                   (uint)*(ushort *)(DAT_0000af2c + 6) % 0x3c,param_2);
    }
    else {
      FUN_0000c5d0(&local_24,s__2d__02dh_0000af3c,*(ushort *)(DAT_0000af2c + 6) / 0xe10,
                   (*(ushort *)(DAT_0000af2c + 6) / 0x3c) % 0x3c,param_2);
    }
  }
  uVar3 = FUN_0000a52e(&local_24,*DAT_0000af28,0x78,0xbe,1);
  puVar1 = DAT_0000af48;
  *DAT_0000af48 = uVar3 >> 1;
  if (*puVar1 < *DAT_0000af4c) {
    uVar2 = FUN_00000e70();
    FUN_000066ee(0x78 - *DAT_0000af4c,0xbe,*DAT_0000af4c - *DAT_0000af48,0x34,uVar2);
    uVar2 = FUN_00000e70();
    FUN_000066ee(*DAT_0000af48 + 0x78,0xbe,*DAT_0000af4c - *DAT_0000af48,0x34,uVar2);
  }
  *DAT_0000af4c = *DAT_0000af48;
  return;
}



// ==========================================
// Function: FUN_0000ac28
// Address:  0000ac28
// Size:     262 bytes
// ==========================================

void FUN_0000ac28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uVar5;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  uVar3 = DAT_0000af24;
  if (*DAT_0000af20 == '\x01') {
    uVar3 = 0xffffff;
  }
  uStack_1c = param_3;
  uStack_18 = param_4;
  uVar3 = FUN_00000e80(uVar3);
  FUN_0000a434(*DAT_0000af28,uVar3);
  if (*(char *)(DAT_0000af50 + 0xb) == '\0') {
    uVar2 = (ushort)*(byte *)(DAT_0000af2c + 8);
  }
  else {
    uVar2 = (short)(((uint)*(byte *)(DAT_0000af2c + 8) * 9) / 5) + 0x20;
  }
  if ((((*DAT_0000af54 == '\x03') || (*DAT_0000af54 == '\x10')) || (*DAT_0000af54 == '\0')) &&
     (*(char *)(DAT_0000af2c + 8) == '\x1d')) {
    if (*(char *)(DAT_0000af50 + 0xb) == '\0') {
      puVar4 = &DAT_0000af5c;
    }
    else {
      puVar4 = &DAT_0000af58;
    }
    FUN_0000c5d0(&uStack_1c,&DAT_0000af60,puVar4);
  }
  else {
    if (*(char *)(DAT_0000af50 + 0xb) == '\0') {
      puVar4 = &DAT_0000af5c;
    }
    else {
      puVar4 = &DAT_0000af58;
    }
    FUN_0000c5d0(&uStack_1c,&DAT_0000af68,uVar2,puVar4,param_2);
  }
  uVar5 = FUN_0000a52e(&uStack_1c,*DAT_0000af28,0x16c,0xbe,1);
  puVar1 = DAT_0000af70;
  *DAT_0000af70 = uVar5 >> 1;
  if (*puVar1 < *DAT_0000af74) {
    uVar3 = FUN_00000e70();
    FUN_000066ee(0x16c - *DAT_0000af74,0xbe,*DAT_0000af74 - *DAT_0000af70,0x34,uVar3);
    uVar3 = FUN_00000e70();
    FUN_000066ee(*DAT_0000af70 + 0x16c,0xbe,*DAT_0000af74 - *DAT_0000af70,0x34,uVar3);
  }
  *DAT_0000af74 = *DAT_0000af70;
  return;
}



// ==========================================
// Function: FUN_0000ad2e
// Address:  0000ad2e
// Size:     118 bytes
// ==========================================

void FUN_0000ad2e(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = FUN_0000a52e(param_1,*DAT_0000af28,0xf5,0xbe,1);
  puVar1 = DAT_0000af78;
  *DAT_0000af78 = uVar2 >> 1;
  if (*puVar1 < *DAT_0000af7c) {
    uVar3 = FUN_00000e70();
    FUN_000066ee(0xf5 - *DAT_0000af7c,0xbe,*DAT_0000af7c - *DAT_0000af78,0x34,uVar3);
    uVar3 = FUN_00000e70();
    FUN_000066ee(*DAT_0000af78 + 0xf5,0xbe,*DAT_0000af7c - *DAT_0000af78,0x34,uVar3);
  }
  *DAT_0000af7c = *DAT_0000af78;
  return;
}



// ==========================================
// Function: FUN_0000ada4
// Address:  0000ada4
// Size:     182 bytes
// ==========================================

void FUN_0000ada4(void)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = 0;
  local_14 = 0;
  uVar1 = DAT_0000af24;
  if (*DAT_0000af20 == '\x04') {
    uVar1 = 0xffffff;
  }
  uVar1 = FUN_00000e80(uVar1);
  FUN_0000a434(*DAT_0000af28,uVar1);
  if ((*(char *)(DAT_0000af2c + 5) == '\x01') || (*(char *)(DAT_0000af2c + 5) == '\x02')) {
    FUN_0000c5d0(&local_18,&DAT_0000af80,*(undefined *)(DAT_0000af2c + 5));
  }
  else {
    iVar2 = FUN_0000176e();
    if (iVar2 == 0) {
      cVar3 = *(char *)(DAT_0000af2c + 5) + -2;
      if (cVar3 != '\0') {
        cVar3 = *(char *)(DAT_0000af2c + 5);
      }
      if ((*(short *)(DAT_0000af2c + 6) != 0) && (-1 < (int)((uint)*DAT_0000af8c << 0x1a))) {
        if ((*DAT_0000af54 == '\x05') && (*(ushort *)(DAT_0000af2c + 6) < 0x5b)) {
          cVar3 = '\x12';
        }
        else if ((*DAT_0000af54 == '\x06') && (*(ushort *)(DAT_0000af2c + 6) < 0x1f)) {
          cVar3 = '\r';
        }
      }
      FUN_0000c5d0(&local_18,&DAT_0000af90,cVar3);
    }
    else {
      FUN_0000c5d0(&local_18,&DAT_0000af84);
    }
  }
  FUN_0000ad2e(&local_18);
  return;
}



// ==========================================
// Function: FUN_0000ae5a
// Address:  0000ae5a
// Size:     74 bytes
// ==========================================

void FUN_0000ae5a(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uVar4;
  
  if ((param_1 != 0) && (*(char *)(param_1 + 1) != '\0')) {
    if (*(char *)(param_1 + 2) == '\0') {
      iVar3 = (int)(0x1df - (uint)*(ushort *)(param_1 + 6)) / 2;
      uVar4 = *(undefined2 *)(param_1 + 6);
    }
    else {
      iVar3 = 0x2e;
      uVar4 = 0x184;
      *(undefined *)(param_1 + 2) = 0;
    }
    uVar1 = *(undefined2 *)(param_1 + 4);
    uVar2 = FUN_00000e70();
    FUN_000066ee(iVar3,uVar1,uVar4,0x1c,uVar2);
    *(undefined *)(param_1 + 1) = 0;
  }
  return;
}



// ==========================================
// Function: FUN_0000aea4
// Address:  0000aea4
// Size:     118 bytes
// ==========================================

void FUN_0000aea4(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = FUN_0000a50c(param_2,param_1 + 8,param_3,param_4,param_4);
  FUN_0000a44e(param_1 + 8);
  *(short *)(param_1 + 6) = (short)uVar1;
  if (uVar1 < 0x185) {
    param_1[2] = 0;
    param_1[1] = 1;
    FUN_0000a52e(param_2,param_1 + 8,0xf0,*(undefined2 *)(param_1 + 4),1);
  }
  else {
    param_1[2] = 1;
    *param_1 = 0;
    param_1[1] = 2;
    thunk_FUN_000086a4(param_1 + 0x30,0x78);
    FUN_0000c8bc(param_1 + 0x30,param_2);
    FUN_0000a59e(param_1 + *param_1 + 0x30,param_1 + 8,0x2e,*(undefined2 *)(param_1 + 4),0x1b2);
  }
  return;
}



// ==========================================
// Function: FUN_0000af94
// Address:  0000af94
// Size:     144 bytes
// ==========================================

void FUN_0000af94(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = param_1[1];
  if (bVar1 == 0) {
    if ((*DAT_0000b38c == '\x04') && (iVar2 = FUN_0000144e(), iVar2 != 0)) {
      FUN_0000aea4(*DAT_0000b398,*(undefined4 *)(DAT_0000b390 + (uint)*DAT_0000b394 * 4));
    }
  }
  else if ((bVar1 != 1) && (bVar1 == 2)) {
    if ((*DAT_0000b38c == '\a') ||
       ((iVar2 = FUN_0000144e(), iVar2 != 0 ||
        (iVar2 = FUN_0000a010(*DAT_0000b3a0,DAT_0000b39c), iVar2 == 3)))) {
      if (param_1[2] != 0) {
        iVar2 = FUN_0000a59e(param_1 + *param_1 + 0x30,param_1 + 8,0x2e,*(undefined2 *)(param_1 + 4)
                             ,0x1b2);
        if (iVar2 == 0) {
          *param_1 = *param_1 + 1;
        }
        else {
          *param_1 = 0;
        }
      }
    }
    else {
      FUN_0000ae5a(*DAT_0000b398);
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000b024
// Address:  0000b024
// Size:     86 bytes
// ==========================================

void FUN_0000b024(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((int)((uint)*DAT_0000b3a4 << 0x1a) < 0) {
    bVar1 = *(byte *)(DAT_0000b3a8 + 1);
  }
  else {
    bVar1 = FUN_00001142();
  }
  if ((bVar1 & 0x10) != 0) {
    if (*DAT_0000b3ac == '\x02') {
      FUN_0000c34e(DAT_0000b3b0,0xb9,0x50,1,1);
    }
    else {
      uVar2 = DAT_0000b3bc;
      if (*DAT_0000b3b4 == '\x04') {
        uVar2 = DAT_0000b3b8;
      }
      FUN_0000c34e(uVar2,0xcb,0x60,1,1);
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000b07a
// Address:  0000b07a
// Size:     26 bytes
// ==========================================

void FUN_0000b07a(void)

{
  if (*DAT_0000b3c0 < 0x3d) {
    *DAT_0000b3c4 = 1;
  }
  else {
    *DAT_0000b3c4 = 2;
  }
  return;
}



// ==========================================
// Function: FUN_0000b094
// Address:  0000b094
// Size:     380 bytes
// ==========================================

void FUN_0000b094(void)

{
  char cVar1;
  int iVar2;
  char cVar3;
  
  cVar3 = '\0';
  if (*(char *)(DAT_0000b3a8 + 8) != '\0') {
    if ((*DAT_0000b38c == '\x04') || (*DAT_0000b38c == '\x05')) {
      if (*DAT_0000b3b4 == '\x01') {
        iVar2 = *(int *)(DAT_0000b3c8 + (uint)*DAT_0000b3cc * 4);
      }
      else if ((*DAT_0000b3d0 == '\x03') && (*(char *)(DAT_0000b3a8 + 8) == '\x1d')) {
        iVar2 = *(int *)(DAT_0000b3d4 + (uint)*DAT_0000b3cc * 4);
      }
      else {
        iVar2 = *(int *)(DAT_0000b3d8 + (uint)*DAT_0000b3cc * 4);
      }
    }
    else if (*DAT_0000b3b4 == '\x01') {
      iVar2 = DAT_0000b3dc[*DAT_0000b3cc];
    }
    else {
      iVar2 = *(int *)(DAT_0000b3d4 + (uint)*DAT_0000b3cc * 4);
    }
    cVar3 = (char)((iVar2 - *DAT_0000b3dc) / 0xc) + '\x01';
    FUN_0000c34e(iVar2,0x155,0x69,0,1);
    cVar1 = *DAT_0000b3c4;
    if (cVar1 == '\0') {
      FUN_0000b07a();
    }
    else if (cVar1 == '\x01') {
      if ((*(byte *)(DAT_0000b3a8 + 8) < 0x3d) || (*DAT_0000b3cc != 5)) {
        *DAT_0000b3a4 = *DAT_0000b3a4 & 0xfbff;
      }
      else {
        *DAT_0000b3a4 = (*DAT_0000b3a4 & 0xfbff) + 0x400;
      }
      if ((*DAT_0000b3c0 < 0x3d) && (-1 < (int)((uint)*DAT_0000b3a4 << 0x15))) {
        if (0x3c < *DAT_0000b3c0) {
          *DAT_0000b3c4 = '\x02';
        }
      }
      else {
        FUN_0000c34e(*(undefined4 *)(DAT_0000b3e0 + (uint)*DAT_0000b3cc * 4),0x155,0x69,1,0);
        *DAT_0000b3e4 = *DAT_0000b3cc;
      }
    }
    else if (cVar1 == '\x02') {
      if (*DAT_0000b3c0 < 0x3d) {
        if (*DAT_0000b3c0 < 0x3c) {
          *DAT_0000b3c4 = '\x01';
        }
      }
      else {
        FUN_0000c34e(*(undefined4 *)(DAT_0000b3e0 + (uint)*DAT_0000b3cc * 4),0x155,0x69,1,0);
        *DAT_0000b3e4 = *DAT_0000b3cc;
      }
    }
  }
  *DAT_0000b3e8 = cVar3;
  return;
}



// ==========================================
// Function: FUN_0000b210
// Address:  0000b210
// Size:     60 bytes
// ==========================================

void FUN_0000b210(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  if ((int)((uint)*DAT_0000b3a4 << 0x1a) < 0) {
    bVar1 = *(byte *)(DAT_0000b3a8 + 1);
  }
  else {
    bVar1 = FUN_00001142();
  }
  if ((bVar1 & 0x20) != 0) {
    uVar2 = DAT_0000b3f0;
    if (*DAT_0000b3b4 == '\x02') {
      uVar2 = DAT_0000b3ec;
    }
    FUN_0000c34e(uVar2,100,100,0,1);
  }
  return;
}



// ==========================================
// Function: FUN_0000b24c
// Address:  0000b24c
// Size:     88 bytes
// ==========================================

void FUN_0000b24c(void)

{
  if (*(short *)(DAT_0000b3a8 + 6) != -1) {
    FUN_0000b210();
    FUN_0000ab24(1);
  }
  if (*(char *)(DAT_0000b3a8 + 8) == '\0') {
    *DAT_0000b3e8 = 0;
    *DAT_0000b3e4 = 0;
  }
  else {
    FUN_0000b094();
    FUN_0000ac28();
  }
  switch(*DAT_0000b3d0) {
  case 4:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
    break;
  default:
    FUN_0000b024();
    FUN_0000ada4();
  }
  return;
}



// ==========================================
// Function: FUN_0000b2ae
// Address:  0000b2ae
// Size:     36 bytes
// ==========================================

void FUN_0000b2ae(void)

{
  undefined4 uVar1;
  
  *DAT_0000b3f4 = 0xff;
  uVar1 = FUN_00000e70();
  FUN_000066ee(0x2e,0xbe,0x184,0x34,uVar1);
  FUN_0000b24c();
  return;
}



// ==========================================
// Function: FUN_0000b2d2
// Address:  0000b2d2
// Size:     112 bytes
// ==========================================

void FUN_0000b2d2(void)

{
  undefined4 uVar1;
  
  *DAT_0000b38c = 7;
  FUN_0000c34e(DAT_0000b3f8,10,0x26,1,1);
  uVar1 = FUN_00000e70();
  FUN_000066ee(0x2e,0xbe,0x184,0x34,uVar1);
  if ((*DAT_0000b3ac == '\x05') && ((*DAT_0000b3fc & 0x10) != 0)) {
    FUN_0000aea4(*DAT_0000b404,*(undefined4 *)(DAT_0000b400 + (uint)*DAT_0000b394 * 4));
  }
  else {
    FUN_0000aea4(*DAT_0000b404,
                 *(undefined4 *)
                  (DAT_0000b408 + (uint)*DAT_0000b394 * 0x20 + (uint)*DAT_0000b3f4 * 4));
  }
  return;
}



// ==========================================
// Function: FUN_0000b342
// Address:  0000b342
// Size:     248 bytes
// ==========================================

void FUN_0000b342(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = FUN_00000e58(*(undefined *)(DAT_0000b40c + (uint)*DAT_0000b3ac));
  if (1 < iVar1) {
    uVar6 = 0;
    uVar7 = 0;
    while ((int)uVar7 < iVar1) {
      if (((uint)*(byte *)(DAT_0000b40c + (uint)*DAT_0000b3ac) & 1 << uVar6) != 0) {
        iVar2 = FUN_00000e70();
        iVar5 = DAT_0000b810;
        if (iVar2 == 0) {
          iVar5 = DAT_0000b410;
        }
        FUN_0000c34e(*(undefined4 *)(*(int *)(iVar5 + (uint)*DAT_0000b814 * 4) + uVar6 * 4),
                     (iVar1 * -0x14 + 0xf0U & 0xff) + uVar7 * 0x28,0x2c,1,0);
        uVar7 = uVar7 + 1 & 0xff;
      }
      uVar6 = uVar6 + 1 & 0xff;
    }
  }
  iVar2 = FUN_0000161a(*DAT_0000b818,*DAT_0000b814);
  iVar3 = FUN_000015e8(*DAT_0000b818,*DAT_0000b814);
  iVar4 = FUN_00000e70();
  iVar1 = DAT_0000b828;
  iVar5 = DAT_0000b824;
  if (iVar4 == 0) {
    iVar1 = DAT_0000b820;
    iVar5 = DAT_0000b81c;
  }
  FUN_0000c34e(*(undefined4 *)(iVar5 + (uint)*DAT_0000b814 * 4),0xb9,0x59,1,0);
  FUN_0000c34e(*(undefined4 *)(iVar1 + iVar2 * 4),0x53,0x6c,1,0);
  FUN_0000c34e(*(undefined4 *)(iVar1 + iVar3 * 4),0x145,0x6c,1,0);
  FUN_0000a8d8(0xffffff,0xf0,0xcc,0);
  return;
}



// ==========================================
// Function: FUN_0000b4c4
// Address:  0000b4c4
// Size:     178 bytes
// ==========================================

void FUN_0000b4c4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_r3;
  
  FUN_0000a8d8(DAT_0000b82c,0xf0,0x18,0,in_r3);
  iVar1 = FUN_00000e70();
  iVar3 = DAT_0000b834;
  if (iVar1 == 0) {
    iVar3 = DAT_0000b830;
  }
  FUN_0000c34e(*(undefined4 *)(*(int *)(iVar3 + (uint)*DAT_0000b814 * 4) + (uint)*DAT_0000b838 * 4),
               0xb7,0x4f,1,0);
  iVar1 = FUN_0000161a(*(undefined *)(DAT_0000b83c + (uint)*DAT_0000b814),*DAT_0000b838);
  iVar2 = FUN_00000e70();
  iVar3 = DAT_0000b844;
  if (iVar2 == 0) {
    iVar3 = DAT_0000b840;
  }
  FUN_0000c34e(*(undefined4 *)(*(int *)(iVar3 + (uint)*DAT_0000b814 * 4) + iVar1 * 4),0x51,0x62,1,0)
  ;
  iVar1 = FUN_000015e8(*(undefined *)(DAT_0000b83c + (uint)*DAT_0000b814),*DAT_0000b838);
  FUN_0000c34e(*(undefined4 *)(*(int *)(iVar3 + (uint)*DAT_0000b814 * 4) + iVar1 * 4),0x143,0x62,1,0
              );
  FUN_0000a8d8(0xffffff,0xf0,0xc3,1);
  return;
}



// ==========================================
// Function: FUN_0000b576
// Address:  0000b576
// Size:     32 bytes
// ==========================================

void FUN_0000b576(int param_1)

{
  if (*(byte *)(param_1 + 5) < *(byte *)(param_1 + 4)) {
    *(undefined *)(param_1 + 4) = *(undefined *)(param_1 + 5);
  }
  else if (5 < (int)((uint)*(byte *)(param_1 + 5) - (uint)*(byte *)(param_1 + 4))) {
    *(char *)(param_1 + 4) = *(char *)(param_1 + 5) + -5;
  }
  return;
}



// ==========================================
// Function: FUN_0000b596
// Address:  0000b596
// Size:     102 bytes
// ==========================================

void FUN_0000b596(undefined2 *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_1 + 2);
  uVar3 = *param_1;
  uVar4 = param_1[1];
  bVar2 = **DAT_0000b848;
  for (iVar6 = 0; iVar6 < 6; iVar6 = iVar6 + 1) {
    uVar5 = DAT_0000b82c;
    if ((uint)*(byte *)((int)param_1 + 5) == (uint)bVar1 + iVar6) {
      uVar5 = 0xffffff;
    }
    uVar5 = FUN_00000e80(uVar5);
    FUN_0000a434(*DAT_0000b848,uVar5);
    FUN_0000a59e(*(undefined4 *)(*(int *)(param_1 + 4) + ((uint)bVar1 + iVar6) * 4),*DAT_0000b848,
                 uVar3,iVar6 * (bVar2 + 4) + (uint)uVar4,0x1b2);
  }
  return;
}



// ==========================================
// Function: FUN_0000b5fc
// Address:  0000b5fc
// Size:     36 bytes
// ==========================================

void FUN_0000b5fc(void)

{
  FUN_0000c34e(*(undefined4 *)(DAT_0000b84c + (uint)*DAT_0000b850 * 4),0x78,0x82,0,1);
  FUN_000061f4(*DAT_0000b850);
  return;
}



// ==========================================
// Function: FUN_0000b620
// Address:  0000b620
// Size:     504 bytes
// ==========================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000b620(void)

{
  undefined4 uVar1;
  undefined auStack_50 [32];
  char local_30;
  undefined local_2f;
  char local_2e;
  char local_2d;
  undefined local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = s_SYSTEM_0000b854._0_4_;
  uStack_c = s_SYSTEM_0000b854._4_4_;
  local_1c = s_Motor_0000b85c._0_4_;
  uStack_18 = s_Motor_0000b85c._4_4_;
  uStack_14 = ram0x0000b864;
  local_28 = DAT_0000b868;
  uStack_24 = DAT_0000b86c;
  uStack_20 = DAT_0000b870;
  uVar1 = FUN_00000e80(0xffffff,DAT_0000b86c,DAT_0000b870,&local_1c);
  FUN_0000a434(*DAT_0000b848,uVar1);
  FUN_0000a52e(*(undefined4 *)(DAT_0000b874 + (uint)*DAT_0000b878 * 4),*DAT_0000b848,0x3c,0x43,0);
  FUN_0000a52e(*(undefined4 *)(DAT_0000b87c + (uint)*DAT_0000b878 * 4),*DAT_0000b848,0xf8,0x43,0);
  uVar1 = FUN_00000e80(DAT_0000b82c);
  FUN_0000a434(*DAT_0000b848,uVar1);
  FUN_0000c8bc(auStack_50,&local_10);
  FUN_0000c904(auStack_50,DAT_0000b880);
  FUN_0000a52e(auStack_50,*DAT_0000b848,0x3c,0x5f,0);
  local_30 = *DAT_0000b884 / 100 + 0x30;
  local_2f = 0x2e;
  local_2e = (char)(((uint)*DAT_0000b884 % 100) / 10) + '0';
  local_2d = *DAT_0000b884 % 10 + 0x30;
  local_2c = 0;
  FUN_0000c8bc(auStack_50,&local_1c);
  FUN_0000c904(auStack_50,&local_30);
  FUN_0000a52e(auStack_50,*DAT_0000b848,0x3c,0x78,0);
  local_30 = *DAT_0000b888 / 100 + 0x30;
  local_2f = 0x2e;
  local_2e = (char)(((uint)*DAT_0000b888 % 100) / 10) + '0';
  local_2d = *DAT_0000b888 % 10 + 0x30;
  local_2c = 0;
  FUN_0000c8bc(auStack_50,&local_28);
  FUN_0000c904(auStack_50,&local_30);
  FUN_0000a52e(auStack_50,*DAT_0000b848,0x3c,0x91,0);
  FUN_0000c5d0(auStack_50,s_Motor__d_0000b890,*(uint *)(DAT_0000b88c + 0xc0) / 0xe10);
  FUN_0000a52e(auStack_50,*DAT_0000b848,0xfa,0x5f,0);
  FUN_0000c5d0(auStack_50,s_NTC__d_0000b89c,*(uint *)(DAT_0000b88c + 0xc4) / 0xe10);
  FUN_0000a52e(auStack_50,*DAT_0000b848,0xfa,0x78,0);
  FUN_0000c5d0(auStack_50,s_Screen__d_0000b8a8,*(uint *)(DAT_0000b88c + 200) / 0xe10);
  FUN_0000a52e(auStack_50,*DAT_0000b848,0xfa,0x91,0);
  return;
}



// ==========================================
// Function: FUN_0000b8bc
// Address:  0000b8bc
// Size:     326 bytes
// ==========================================

void FUN_0000b8bc(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined auStack_24 [8];
  undefined auStack_1c [8];
  
  uVar1 = FUN_00000e80(0xffffff);
  FUN_0000a434(*DAT_0000bcc8,uVar1);
  iVar4 = 0x3c;
  iVar5 = 0xab;
  for (uVar3 = 0; uVar3 < 0x18; uVar3 = uVar3 + 1) {
    if (*(uint *)(DAT_0000bccc + uVar3 * 8 + 4) / 0xe10 < 1000) {
      uVar2 = *(uint *)(DAT_0000bccc + uVar3 * 8 + 4) / 0xe10;
    }
    else {
      uVar2 = 999;
    }
    FUN_0000c5d0(auStack_1c,&DAT_0000bcd0,uVar2);
    if (*(uint *)(DAT_0000bccc + uVar3 * 8) < 1000) {
      uVar1 = *(undefined4 *)(DAT_0000bccc + uVar3 * 8);
    }
    else {
      uVar1 = 999;
    }
    FUN_0000c5d0(auStack_24,&DAT_0000bcd0,uVar1);
    FUN_0000a52e(auStack_1c,*DAT_0000bcc8,iVar4,iVar5,0);
    FUN_0000a52e(auStack_24,*DAT_0000bcc8,iVar4 + 0x2d,iVar5,0);
    iVar4 = iVar4 + 0x5a;
    if ((uVar3 + 1 & 3) == 0) {
      iVar5 = iVar5 + 0x19;
      iVar4 = 0x3c;
    }
  }
  if (*(uint *)(DAT_0000bccc + 0xc4) / 0xe10 < 1000) {
    uVar3 = *(uint *)(DAT_0000bccc + 0xc4) / 0xe10;
  }
  else {
    uVar3 = 999;
  }
  FUN_0000c5d0(auStack_1c,&DAT_0000bcd0,uVar3);
  if (*(uint *)(DAT_0000bccc + 200) / 0xe10 < 1000) {
    uVar3 = *(uint *)(DAT_0000bccc + 200) / 0xe10;
  }
  else {
    uVar3 = 999;
  }
  FUN_0000c5d0(auStack_24,&DAT_0000bcd0,uVar3);
  FUN_0000a52e(auStack_1c,*DAT_0000bcc8,iVar4,iVar5,0);
  FUN_0000a52e(auStack_24,*DAT_0000bcc8,iVar4 + 0x2d,iVar5,0);
  return;
}



// ==========================================
// Function: FUN_0000ba02
// Address:  0000ba02
// Size:     192 bytes
// ==========================================

void FUN_0000ba02(void)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_00000e80(0xffffff);
  FUN_0000a434(*DAT_0000bcc8,uVar2);
  cVar1 = *(char *)(DAT_0000bcd4 + 2);
  if (cVar1 == '\0') {
    FUN_0000a52e(*(undefined4 *)(DAT_0000bcd8 + (uint)*DAT_0000bcdc * 8),*DAT_0000bcc8,0xf0,0x78,1);
    FUN_0000a52e(*(undefined4 *)(DAT_0000bcd8 + (uint)*DAT_0000bcdc * 8 + 4),*DAT_0000bcc8,0xf0,0x96
                 ,1);
  }
  else if (cVar1 == '\x01') {
    FUN_0000a52e(*(undefined4 *)(DAT_0000bce0 + (uint)*DAT_0000bcdc * 4),*DAT_0000bcc8,0xf0,0x87,1);
  }
  else if (cVar1 == '\x02') {
    FUN_0000c34e(DAT_0000bce4,0x50,0x7d,1,1);
    FUN_0000a52e(*(undefined4 *)(DAT_0000bce8 + (uint)*DAT_0000bcdc * 4),*DAT_0000bcc8,0x6e,0x87,0);
    FUN_0000a52e(DAT_0000bcd4 + 0x28,*DAT_0000bcc8,0xf0,0xaa,1);
  }
  return;
}



// ==========================================
// Function: FUN_0000bac2
// Address:  0000bac2
// Size:     74 bytes
// ==========================================

void FUN_0000bac2(void)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *DAT_0000bcec;
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    FUN_0000a6b4();
  }
  else if (((cVar1 == '\x03') && (*DAT_0000bcf0 == '\0')) && (*(char *)(DAT_0000bcf4 + 5) == '\0'))
  {
    uVar2 = FUN_00000e70();
    FUN_000066ee(0x46,0x78,0x14a,0x50,uVar2);
    FUN_0000ba02();
  }
  return;
}



// ==========================================
// Function: FUN_0000bb0c
// Address:  0000bb0c
// Size:     54 bytes
// ==========================================

void FUN_0000bb0c(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00000e70();
  FUN_000066ee(0,0,0x1e0,0x110,uVar1);
  FUN_0000a52e(*(undefined4 *)(DAT_0000bcf8 + (uint)*DAT_0000bcdc * 4),*DAT_0000bcc8,0xf0,0x78,1);
  return;
}



// ==========================================
// Function: FUN_0000bb42
// Address:  0000bb42
// Size:     852 bytes
// ==========================================

void FUN_0000bb42(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = **DAT_0000bcc8 + 4;
  switch(*(undefined *)(DAT_0000bcf4 + 5)) {
  case 0:
    FUN_0000ba02();
    break;
  case 1:
    FUN_0000a7b0();
    if (*(char *)(DAT_0000bd0c + 0xd) == '\0') {
      uVar5 = 3;
    }
    else {
      uVar5 = 4;
    }
    for (uVar4 = 0; uVar4 < uVar5; uVar4 = uVar4 + 1) {
      uVar3 = DAT_0000bd00;
      if (uVar4 == *DAT_0000bcfc) {
        uVar3 = 0xffffff;
      }
      uVar3 = FUN_00000e80(uVar3);
      FUN_0000a434(*DAT_0000bcc8,uVar3);
      FUN_0000a52e(*(undefined4 *)(DAT_0000bd10 + (uint)*DAT_0000bcdc * 0x10 + uVar4 * 4),
                   *DAT_0000bcc8,300,uVar4 * iVar6 + 0x50,2);
    }
    break;
  case 2:
    *(uint *)(DAT_0000c15c + 0x4c) = *(uint *)(DAT_0000c15c + 0x4c) | 0x1000;
    FUN_0000b5fc();
    break;
  case 3:
    iVar2 = FUN_00000e70();
    iVar6 = DAT_0000bd18;
    if (iVar2 == 0) {
      iVar6 = DAT_0000bd14;
    }
    FUN_0000a7b0();
    for (uVar5 = 0; uVar5 < *(byte *)(DAT_0000bd08 + (uint)*(byte *)(DAT_0000bcf4 + 5));
        uVar5 = uVar5 + 1) {
      bVar1 = *DAT_0000bcfc;
      uVar3 = DAT_0000bd00;
      if ((uVar5 != bVar1) == 0) {
        uVar3 = 0xffffff;
      }
      uVar3 = FUN_00000e80(uVar3);
      FUN_0000a434(*DAT_0000bcc8,uVar3);
      FUN_0000a52e(*(undefined4 *)(DAT_0000bd1c + (uint)*DAT_0000bcdc * 0xc + uVar5 * 4),
                   *DAT_0000bcc8,0x50,uVar5 * 0x3c + 0x5a,0);
      FUN_0000c34e(*(undefined4 *)(*(int *)(iVar6 + uVar5 * 4) + (uint)(uVar5 != bVar1) * 4),0x140,
                   uVar5 * 0x3c + 0x50,1,0);
    }
    break;
  case 4:
    FUN_0000a7b0();
    for (uVar5 = 0; uVar5 < *(byte *)(DAT_0000c158 + (uint)*(byte *)(DAT_0000c154 + 5));
        uVar5 = uVar5 + 1) {
      uVar3 = DAT_0000c140;
      if (uVar5 == *DAT_0000c13c) {
        uVar3 = 0xffffff;
      }
      uVar3 = FUN_00000e80(uVar3);
      FUN_0000a434(*DAT_0000c144,uVar3);
      FUN_0000a52e(*(undefined4 *)(DAT_0000c16c + (uint)*DAT_0000c148 * 8 + uVar5 * 4),*DAT_0000c144
                   ,200,uVar5 * iVar6 + 0x50,0);
    }
    break;
  case 5:
    FUN_0000a7b0();
    for (uVar5 = 0; uVar5 < *(byte *)(DAT_0000c158 + (uint)*(byte *)(DAT_0000c154 + 5));
        uVar5 = uVar5 + 1) {
      bVar1 = *DAT_0000c13c;
      uVar3 = DAT_0000c140;
      if ((uVar5 == bVar1) != 0) {
        uVar3 = 0xffffff;
      }
      uVar3 = FUN_00000e80(uVar3);
      FUN_0000a434(*DAT_0000c144,uVar3);
      FUN_0000a52e(*(undefined4 *)(DAT_0000c14c + (uint)*DAT_0000c148 * 0xc + uVar5 * 4),
                   *DAT_0000c144,0x50,uVar5 * 0x3c + 0x5a,0);
      FUN_0000c34e(*(undefined4 *)(*(int *)(DAT_0000c150 + uVar5 * 4) + (uint)(uVar5 == bVar1) * 4),
                   0x140,uVar5 * 0x3c + 0x50,1,0);
    }
    break;
  case 6:
    goto LAB_0000be24;
  case 7:
    goto LAB_0000be24;
  case 8:
    FUN_0000c34e(DAT_0000c170,0xaa,0x55,0,0);
    break;
  case 9:
    goto LAB_0000be0e;
  case 10:
LAB_0000be0e:
    FUN_0000a7b0();
    FUN_0000b576(DAT_0000c164);
    FUN_0000b596(DAT_0000c164);
    break;
  case 0xb:
    FUN_0000a7b0();
    for (uVar5 = 0; uVar5 < *(byte *)(DAT_0000bd08 + (uint)*(byte *)(DAT_0000bcf4 + 5));
        uVar5 = uVar5 + 1) {
      uVar3 = DAT_0000bd00;
      if (uVar5 == *DAT_0000bcfc) {
        uVar3 = 0xffffff;
      }
      uVar3 = FUN_00000e80(uVar3);
      FUN_0000a434(*DAT_0000bcc8,uVar3);
      FUN_0000a52e(*(undefined4 *)(DAT_0000bd04 + uVar5 * 4),*DAT_0000bcc8,200,uVar5 * iVar6 + 0x50,
                   0);
    }
    break;
  case 0xc:
    FUN_0000b620();
    if ((int)((uint)*DAT_0000c160 << 0x17) < 0) {
      FUN_0000b8bc();
    }
    else {
      uVar3 = FUN_00000e70();
      FUN_000066ee(0x3c,0xab,0x184,0x65,uVar3);
    }
    break;
  case 0xd:
LAB_0000be24:
    FUN_0000a7b0();
    for (uVar5 = 0; uVar5 < *(byte *)(DAT_0000c158 + (uint)*(byte *)(DAT_0000c154 + 5));
        uVar5 = uVar5 + 1) {
      uVar3 = DAT_0000c140;
      if (uVar5 == *DAT_0000c13c) {
        uVar3 = 0xffffff;
      }
      uVar3 = FUN_00000e80(uVar3);
      FUN_0000a434(*DAT_0000c144,uVar3);
      FUN_0000a52e(*(undefined4 *)(DAT_0000c168 + (uint)*DAT_0000c148 * 8 + uVar5 * 4),*DAT_0000c144
                   ,200,uVar5 * iVar6 + 0x50,0);
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000befe
// Address:  0000befe
// Size:     102 bytes
// ==========================================

void FUN_0000befe(void)

{
  uint uVar1;
  
  FUN_0000a8d8(0xffffff,0xf0,0x18,1);
  if ((int)((uint)*DAT_0000c160 << 0x1a) < 0) {
    uVar1 = (uint)*(byte *)(DAT_0000c174 + 1);
  }
  else {
    uVar1 = FUN_00001142();
  }
  if (1 < *(byte *)(DAT_0000c178 + (uVar1 & 7))) {
    FUN_0000a78a();
  }
  if ((int)((uint)*DAT_0000c160 << 0x1a) < 0) {
    uVar1 = (uint)*(byte *)(DAT_0000c174 + 1);
  }
  else {
    uVar1 = FUN_00001142();
  }
  if ((*(char *)(DAT_0000c178 + (uVar1 & 7)) != '\0') && (*DAT_0000c17c != '\b')) {
    FUN_0000a7d8(0);
  }
  FUN_0000b24c();
  return;
}



// ==========================================
// Function: FUN_0000bf64
// Address:  0000bf64
// Size:     684 bytes
// ==========================================

void FUN_0000bf64(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    uVar2 = FUN_00000e70();
    FUN_000066ee(0,0,0x1e0,0x110,uVar2);
  }
  FUN_0000a756();
  switch(*DAT_0000c180) {
  case 0:
    FUN_0000c34e(DAT_0000c184,0xb7,0x4f,1,0);
    FUN_0000c34e(DAT_0000c188,0x1ba,0x20,1,1);
    FUN_0000a52e(*(undefined4 *)(DAT_0000c18c + (uint)*DAT_0000c148 * 4),*DAT_0000c144,0xf0,0xd2,1);
    break;
  case 1:
    FUN_0000a78a();
    FUN_0000c34e(DAT_0000c190,0x1b4,0x26,1,1);
    FUN_0000b342();
    break;
  case 2:
    if (*DAT_0000c17c == '\0') {
      FUN_0000c34e(DAT_0000c194,10,0x26,1,1);
      FUN_0000c34e(DAT_0000c190,0x1b4,0x26,1,1);
      FUN_0000a8d8(0xffffff,0xf0,0x12,0);
      FUN_0000a7b0();
      *DAT_0000c13c = 0;
      FUN_0000b576(DAT_0000c154);
      FUN_0000b596(DAT_0000c154);
    }
    else {
      FUN_0000a78a();
      FUN_0000c34e(DAT_0000c194,10,0x26,1,1);
      FUN_0000c34e(DAT_0000c190,0x1b4,0x26,1,1);
      FUN_0000b4c4();
    }
    break;
  case 3:
    if (*DAT_0000c17c == '\0') {
      FUN_0000c34e(DAT_0000c194,10,0x26,1,1);
      FUN_0000c34e(DAT_0000c190,0x1b4,0x26,1,1);
      FUN_0000a8d8(0xffffff,0xf0,0x12,1);
      cVar1 = *(char *)(DAT_0000c154 + 5);
      if (cVar1 == '\x02') {
        FUN_0000a7d8(0x55);
      }
      else if ((cVar1 == '\x03') || (cVar1 == '\x05')) {
        FUN_0000a852(*(undefined *)(DAT_0000c198 + (uint)*(byte *)(DAT_0000c154 + 5)));
      }
      *DAT_0000c19c = 0;
      *DAT_0000c13c = *(byte *)(DAT_0000c198 + (uint)*(byte *)(DAT_0000c154 + 5)) & 0xf;
      FUN_0000bb42();
    }
    else if (*DAT_0000c17c == '\x01') {
      FUN_0000c34e(DAT_0000c194,10,0x26,1,1);
      FUN_0000a8d8(0xffffff,0xf0,0x12,1);
      FUN_0000c34e(*(undefined4 *)(DAT_0000c1a0 + (uint)*DAT_0000c1a4 * 4),0xa5,0x50,0,0);
    }
    else {
      FUN_0000befe();
      if ((int)((uint)*(byte *)DAT_0000c284 << 0x1c) < 0) {
        *DAT_0000c284 = *DAT_0000c284 & 0xfff7;
        FUN_00005818();
        FUN_00000744();
        if (*DAT_0000c288 != '\0') {
          FUN_0000c34e(DAT_0000c28c,10,0x26,1,1);
        }
        *DAT_0000c290 = 0x880;
        FUN_000096c6(*DAT_0000c294);
      }
      else {
        FUN_0000c34e(DAT_0000c28c,10,0x26,1,1);
      }
    }
    break;
  case 4:
    FUN_0000befe();
    FUN_00001316();
    break;
  case 5:
    goto LAB_0000c216;
  case 6:
    goto LAB_0000c216;
  case 7:
LAB_0000c216:
    FUN_0000c34e(DAT_0000c28c,10,0x26,1,1);
    FUN_0000a8d8(0xffffff,0xf0,0x18,1);
    if ((int)((uint)*(byte *)DAT_0000c284 << 0x1a) < 0) {
      uVar3 = (uint)*(byte *)(DAT_0000c298 + 1);
    }
    else {
      uVar3 = FUN_00001142();
    }
    if (1 < *(byte *)(DAT_0000c29c + (uVar3 & 7))) {
      FUN_0000a78a();
    }
    FUN_0000b24c();
    if ((*DAT_0000c2a0 != '\b') &&
       ((*DAT_0000c2a0 != '\x06' || ((int)((uint)*(byte *)DAT_0000c284 << 0x1a) < 0)))) {
      FUN_0000a7d8(0);
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000c2a4
// Address:  0000c2a4
// Size:     40 bytes
// ==========================================

void FUN_0000c2a4(undefined4 param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  
  do {
    bVar1 = param_3 != 0;
    param_3 = param_3 - 1 & 0xffff;
  } while (bVar1);
  return;
}



// ==========================================
// Function: FUN_0000c2cc
// Address:  0000c2cc
// Size:     130 bytes
// ==========================================

void FUN_0000c2cc(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (*DAT_0000c484 == 0) {
    uVar2 = *DAT_0000c48c / (uint)**DAT_0000c488;
    uVar1 = *DAT_0000c48c - (uint)**DAT_0000c488 * (*DAT_0000c48c / (uint)**DAT_0000c488);
  }
  else {
    uVar1 = *DAT_0000c48c / (uint)(*DAT_0000c488)[1];
    uVar2 = *DAT_0000c48c - (uint)(*DAT_0000c488)[1] * (*DAT_0000c48c / (uint)(*DAT_0000c488)[1]);
  }
  if ((param_1 != 0) || (*DAT_0000c490 == '\0')) {
    if (param_2 != 0) {
      param_1 = FUN_00000e80(param_1);
    }
    FUN_000066ca(*DAT_0000c498 + uVar1,*DAT_0000c494 + uVar2,param_1);
  }
  *DAT_0000c48c = *DAT_0000c48c + 1;
  return;
}



// ==========================================
// Function: FUN_0000c34e
// Address:  0000c34e
// Size:     306 bytes
// ==========================================

void FUN_0000c34e(ushort *param_1,undefined4 param_2,undefined4 param_3,undefined param_4,
                 undefined4 param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar7 = 0;
  uVar8 = 0;
  **DAT_0000c488 = *param_1;
  (*DAT_0000c488)[1] = param_1[1];
  (*DAT_0000c488)[2] = param_1[2];
  (*DAT_0000c488)[3] = param_1[3];
  *(undefined4 *)(*DAT_0000c488 + 4) = *(undefined4 *)(param_1 + 4);
  *DAT_0000c484 = **DAT_0000c488 & 0x8000;
  *DAT_0000c490 = param_4;
  **DAT_0000c488 = **DAT_0000c488 & 0x7fff;
  *DAT_0000c48c = 0;
  *DAT_0000c498 = param_2;
  *DAT_0000c494 = param_3;
  do {
    uVar4 = FUN_0000cb64();
    FUN_00006b94(*(undefined4 *)(*DAT_0000c488 + 4),DAT_0000c49c,(*DAT_0000c488)[2]);
    FUN_0000cb6c(uVar4);
    uVar7 = FUN_0000c2a4(uVar7,DAT_0000c49c,(*DAT_0000c488)[2]);
    uVar8 = uVar8 + 1;
    if (5 < uVar8) {
      return;
    }
    pbVar6 = DAT_0000c49c;
  } while ((*DAT_0000c488)[3] != uVar7);
  while (pbVar6 < DAT_0000c49c + (*DAT_0000c488)[2]) {
    uVar7 = (uint)pbVar6[2] << 0x10;
    uVar8 = uVar7 | (uint)pbVar6[1] << 8 | (uint)*pbVar6;
    if ((uVar7 & 0x800000) == 0) {
      pbVar5 = pbVar6 + 3;
      bVar1 = pbVar6[5];
      bVar2 = pbVar6[4];
      bVar3 = *pbVar5;
      while (bVar9 = uVar8 != 0, uVar8 = uVar8 - 1, bVar9) {
        FUN_0000c2cc((uint)bVar1 << 0x10 | (uint)bVar2 << 8 | (uint)bVar3,param_5);
      }
    }
    else {
      uVar7 = uVar7 & 0xff7fffff | (uint)pbVar6[1] << 8 | (uint)*pbVar6;
      pbVar5 = pbVar6;
      while (bVar9 = uVar7 != 0, uVar7 = uVar7 - 1, bVar9) {
        FUN_0000c2cc((uint)pbVar5[5] << 0x10 | (uint)pbVar5[4] << 8 | (uint)pbVar5[3],param_5);
        pbVar5 = pbVar5 + 3;
      }
    }
    pbVar6 = pbVar5 + 3;
  }
  return;
}



// ==========================================
// Function: FUN_0000c4a0
// Address:  0000c4a0
// Size:     120 bytes
// ==========================================

void FUN_0000c4a0(int param_1)

{
  if (param_1 < 0x65) {
    if (param_1 == 0) {
      FUN_0000c34e(DAT_0000c5bc,**DAT_0000c5b8 - (*DAT_0000c5bc & 0xffff7fff),(*DAT_0000c5b8)[4],0,0
                  );
    }
    else if (param_1 == 100) {
      FUN_0000c34e(DAT_0000c5c0,**DAT_0000c5b8 + (*DAT_0000c5b8)[2],(*DAT_0000c5b8)[4],0,0);
    }
    else {
      FUN_000066ee(**DAT_0000c5b8 + (param_1 + -1) * 4,(*DAT_0000c5b8)[4],8,0xc,0);
    }
  }
  return;
}



// ==========================================
// Function: FUN_0000c518
// Address:  0000c518
// Size:     158 bytes
// ==========================================

void FUN_0000c518(void)

{
  int **ppiVar1;
  
  ppiVar1 = DAT_0000c5b8;
  *DAT_0000c5b8 = DAT_0000c5c4;
  **ppiVar1 = 0x28;
  (*DAT_0000c5b8)[1] = 0xa0;
  (*DAT_0000c5b8)[2] = 400;
  (*DAT_0000c5b8)[3] = 0x14;
  (*DAT_0000c5b8)[4] = 0xa4;
  FUN_0000c34e(DAT_0000c5c8,**DAT_0000c5b8 - (*DAT_0000c5c8 & 0xffff7fff),(*DAT_0000c5b8)[1],0,0);
  FUN_000066ee(**DAT_0000c5b8,(*DAT_0000c5b8)[1],(*DAT_0000c5b8)[2],(*DAT_0000c5b8)[3],0xffffff);
  FUN_0000c34e(DAT_0000c5cc,**DAT_0000c5b8 + (*DAT_0000c5b8)[2],(*DAT_0000c5b8)[1],0,0);
  return;
}



// ==========================================
// Function: FUN_0000c5d0
// Address:  0000c5d0
// Size:     34 bytes
// ==========================================

void FUN_0000c5d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_20 = param_1;
  uStack_1c = param_4;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0000ca92(param_2,&local_20,&uStack_8,DAT_0000c5f4 + 0xc5dc);
  FUN_0000cab8(0,&local_20);
  return;
}



// ==========================================
// Function: FUN_0000c5f8
// Address:  0000c5f8
// Size:     44 bytes
// ==========================================

void FUN_0000c5f8(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[6];
  if ((int)(*param_1 << 0x1b) < 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x20;
  }
  if ((*param_1 & 1) != 0) {
    return;
  }
  while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
    (*(code *)param_1[1])(uVar2,param_1[2]);
    param_1[8] = param_1[8] + 1;
  }
  return;
}



// ==========================================
// Function: FUN_0000c624
// Address:  0000c624
// Size:     34 bytes
// ==========================================

void FUN_0000c624(byte *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((*param_1 & 1) == 0) {
    return;
  }
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(param_1 + 4))(0x20,*(undefined4 *)(param_1 + 8));
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  return;
}



// ==========================================
// Function: FUN_0000c646
// Address:  0000c646
// Size:     82 bytes
// ==========================================

void FUN_0000c646(byte *param_1,undefined *param_2,uint param_3)

{
  uint uVar1;
  undefined *puVar2;
  
  if (param_3 == 1) {
    uVar1 = 1;
  }
  else {
    if ((int)((uint)*param_1 << 0x1a) < 0) {
      param_3 = *(uint *)(param_1 + 0x1c);
    }
    for (uVar1 = 0; (uVar1 < param_3 && (param_2[uVar1] != '\0')); uVar1 = uVar1 + 1) {
    }
  }
  puVar2 = param_2 + uVar1;
  *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - uVar1;
  *(uint *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar1;
  FUN_0000c5f8(param_1);
  for (; param_2 < puVar2; param_2 = param_2 + 1) {
    (**(code **)(param_1 + 4))(*param_2,*(undefined4 *)(param_1 + 8));
  }
  FUN_0000c624(param_1);
  return;
}



// ==========================================
// Function: FUN_0000c710
// Address:  0000c710
// Size:     388 bytes
// ==========================================

uint FUN_0000c710(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  iVar1 = DAT_0000c894;
  param_1[8] = 0;
  while (uVar2 = (*(code *)param_1[3])(param_1), uVar2 != 0) {
    if (uVar2 == 0x25) {
      uVar5 = 0;
      while (((uVar2 = (*(code *)param_1[3])(param_1), 0x1f < (int)uVar2 && (uVar2 < 0x31)) &&
             ((byte)(&DAT_0000c704)[iVar1 + uVar2] != 0))) {
        uVar5 = uVar5 | (byte)(&DAT_0000c704)[iVar1 + uVar2];
      }
      if ((int)(uVar5 << 0x1e) < 0) {
        uVar5 = uVar5 & 0xfffffffb;
      }
      param_1[7] = 0;
      iVar6 = 0;
      param_1[6] = 0;
      puVar7 = param_2;
      do {
        if (uVar2 == 0x2a) {
          param_2 = puVar7 + 1;
          param_1[iVar6 + 6] = *puVar7;
          uVar2 = (*(code *)param_1[3])(param_1);
          if (iVar6 == 1) {
            if ((int)param_1[7] < 0) {
              uVar5 = uVar5 & 0xffffffdf;
            }
            break;
          }
        }
        else {
          iVar3 = FUN_0000cc04(uVar2);
          if (iVar3 != 0) {
            param_1[iVar6 + 6] = uVar2 - 0x30;
            while( true ) {
              uVar2 = (*(code *)param_1[3])(param_1);
              iVar3 = FUN_0000cc04();
              if (iVar3 == 0) break;
              param_1[iVar6 + 6] = (uVar2 + param_1[iVar6 + 6] * 10) - 0x30;
            }
          }
          param_2 = puVar7;
          if (iVar6 == 1) break;
        }
        if (uVar2 != 0x2e) break;
        uVar2 = (*(code *)param_1[3])(param_1);
        iVar6 = iVar6 + 1;
        uVar5 = uVar5 | 0x20;
        puVar7 = param_2;
      } while (iVar6 < 2);
      if ((int)param_1[6] < 0) {
        uVar5 = uVar5 | 1;
        param_1[6] = -param_1[6];
      }
      if ((uVar5 & 1) != 0) {
        uVar5 = uVar5 & 0xffffffef;
      }
      if ((uVar2 == 0x6c) || (uVar2 == 0x68)) {
        uVar4 = (*(code *)param_1[3])(param_1);
        if (uVar4 == uVar2) {
          if (uVar2 == 0x6c) goto LAB_0000c87c;
          uVar2 = 0x400;
          goto LAB_0000c832;
        }
        if (uVar2 == 0x6c) {
          uVar2 = 0x40;
        }
        else {
          uVar2 = 0x100;
        }
        uVar5 = uVar5 | uVar2;
        uVar2 = uVar4;
      }
      else {
        if (uVar2 != 0x4c) {
          if (uVar2 == 0x6a) {
LAB_0000c87c:
            uVar2 = 0x80;
            goto LAB_0000c832;
          }
          if ((uVar2 != 0x74) && (uVar2 != 0x7a)) goto LAB_0000c848;
        }
        uVar2 = 0;
LAB_0000c832:
        uVar5 = uVar5 | uVar2;
        uVar2 = (*(code *)param_1[3])(param_1);
      }
LAB_0000c848:
      if (uVar2 == 0) break;
      if (uVar2 - 0x41 < 0x1a) {
        uVar2 = uVar2 + 0x20;
        uVar5 = uVar5 | 0x800;
      }
      *param_1 = uVar5;
      iVar6 = FUN_00000198(param_1,uVar2,param_2);
      if (iVar6 == 0) goto LAB_0000c734;
      if (iVar6 == 1) {
        param_2 = param_2 + 1;
      }
      else {
        param_2 = (uint *)(((int)param_2 + 7U & 0xfffffff8) + 8);
      }
    }
    else {
LAB_0000c734:
      (*(code *)param_1[1])(uVar2,param_1[2]);
      param_1[8] = param_1[8] + 1;
    }
  }
  return param_1[8];
}



// ==========================================
// Function: FUN_0000c898
// Address:  0000c898
// Size:     36 bytes
// ==========================================

byte * FUN_0000c898(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = param_2;
  pbVar4 = param_1;
LAB_0000c8a0:
  bVar1 = *pbVar3;
  pbVar2 = (byte *)(uint)*param_1;
  if (pbVar2 != (byte *)0x0) goto code_r0x0000c8aa;
  goto LAB_0000c8ae;
code_r0x0000c8aa:
  param_1 = param_1 + 1;
  pbVar3 = pbVar3 + 1;
  if (pbVar2 != (byte *)(uint)bVar1) {
LAB_0000c8ae:
    pbVar3 = pbVar4;
    if (((byte *)(uint)bVar1 == (byte *)0x0) || (pbVar3 = pbVar2, pbVar2 == (byte *)0x0)) {
      return pbVar3;
    }
    param_1 = pbVar4 + 1;
    pbVar3 = param_2;
    pbVar4 = param_1;
  }
  goto LAB_0000c8a0;
}



// ==========================================
// Function: FUN_0000c8bc
// Address:  0000c8bc
// Size:     72 bytes
// ==========================================

void FUN_0000c8bc(uint *param_1,uint *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    while( true ) {
      uVar4 = *param_2;
      param_2 = param_2 + 1;
      if ((uVar4 + 0xfefefeff & ~uVar4 & 0x80808080) != 0) break;
      *param_1 = uVar4;
      param_1 = param_1 + 1;
    }
    while( true ) {
      *(char *)param_1 = (char)uVar4;
      if ((uVar4 & 0xff) == 0) break;
      uVar4 = uVar4 >> 8;
      param_1 = (uint *)((int)param_1 + 1);
    }
  }
  else {
    do {
      pcVar2 = (char *)((int)param_2 + 1);
      cVar1 = *(char *)param_2;
      pcVar3 = (char *)((int)param_1 + 1);
      *(char *)param_1 = cVar1;
      if (cVar1 == '\0') {
        return;
      }
      param_2 = (uint *)((int)param_2 + 2);
      cVar1 = *pcVar2;
      param_1 = (uint *)((int)param_1 + 2);
      *pcVar3 = cVar1;
    } while (cVar1 != '\0');
  }
  return;
}



// ==========================================
// Function: FUN_0000c904
// Address:  0000c904
// Size:     24 bytes
// ==========================================

void FUN_0000c904(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + -1);
  do {
    pcVar2 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  do {
    cVar1 = *param_2;
    *pcVar2 = cVar1;
    param_2 = param_2 + 1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return;
}



// ==========================================
// Function: FUN_0000c91c
// Address:  0000c91c
// Size:     100 bytes
// ==========================================

undefined8 FUN_0000c91c(undefined4 *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  
  uVar4 = param_3 - 0x20;
  if (0x1f < param_3) {
    do {
      uVar6 = param_2[1];
      uVar7 = param_2[2];
      uVar8 = param_2[3];
      bVar10 = 0x1f < uVar4;
      uVar4 = uVar4 - 0x20;
      *param_1 = *param_2;
      param_1[1] = uVar6;
      param_1[2] = uVar7;
      param_1[3] = uVar8;
      param_4 = param_2[4];
      uVar6 = param_2[5];
      uVar7 = param_2[6];
      uVar8 = param_2[7];
      param_2 = param_2 + 8;
      param_1[4] = param_4;
      param_1[5] = uVar6;
      param_1[6] = uVar7;
      param_1[7] = uVar8;
      param_1 = param_1 + 8;
    } while (bVar10);
  }
  if ((uVar4 & 0x10) != 0) {
    param_4 = *param_2;
    uVar6 = param_2[1];
    uVar7 = param_2[2];
    uVar8 = param_2[3];
    param_2 = param_2 + 4;
    *param_1 = param_4;
    param_1[1] = uVar6;
    param_1[2] = uVar7;
    param_1[3] = uVar8;
    param_1 = param_1 + 4;
  }
  if ((int)(uVar4 << 0x1c) < 0) {
    param_4 = *param_2;
    uVar6 = param_2[1];
    param_2 = param_2 + 2;
    *param_1 = param_4;
    param_1[1] = uVar6;
    param_1 = param_1 + 2;
  }
  puVar1 = param_1;
  puVar3 = param_2;
  if ((uVar4 & 4) != 0) {
    puVar3 = param_2 + 1;
    param_4 = *param_2;
    puVar1 = param_1 + 1;
    *param_1 = param_4;
  }
  uVar5 = (undefined2)param_4;
  if ((uVar4 & 3) != 0) {
    bVar10 = (uVar4 & 2) != 0;
    uVar4 = uVar4 << 0x1f;
    bVar9 = (int)uVar4 < 0;
    puVar2 = puVar3;
    if (bVar10) {
      puVar2 = (undefined4 *)((int)puVar3 + 2);
      uVar5 = *(undefined2 *)puVar3;
    }
    puVar3 = puVar2;
    if (bVar9) {
      puVar3 = (undefined4 *)((int)puVar2 + 1);
      uVar4 = (uint)*(byte *)puVar2;
    }
    puVar2 = puVar1;
    if (bVar10) {
      puVar2 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = uVar5;
    }
    puVar1 = puVar2;
    if (bVar9) {
      puVar1 = (undefined4 *)((int)puVar2 + 1);
      *(char *)puVar2 = (char)uVar4;
    }
    return CONCAT44(puVar3,puVar1);
  }
  return CONCAT44(puVar3,puVar1);
}



// ==========================================
// Function: FUN_0000c980
// Address:  0000c980
// Size:     78 bytes
// ==========================================

undefined4 * FUN_0000c980(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar4) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar4 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar4);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar3 = param_2 << 0x1e;
  puVar2 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar3 != 0) {
    puVar1 = puVar2;
    if ((int)uVar3 < 0) {
      puVar1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = 0;
    }
    puVar2 = puVar1;
    if ((uVar3 & 0x40000000) != 0) {
      puVar2 = (undefined4 *)((int)puVar1 + 1);
      *(undefined *)puVar1 = 0;
    }
    return puVar2;
  }
  return puVar2;
}



// ==========================================
// Function: FUN_0000c9d4
// Address:  0000c9d4
// Size:     178 bytes
// ==========================================

undefined4 FUN_0000c9d4(uint *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((int)(*param_1 << 0x1a) < 0) {
    uVar1 = param_1[7];
    *param_1 = *param_1 & 0xffffffef;
  }
  else {
    uVar1 = 1;
  }
  if (param_2 < (int)uVar1) {
    iVar4 = uVar1 - param_2;
  }
  else {
    iVar4 = 0;
  }
  param_1[6] = param_1[6] - (iVar4 + param_2 + param_4);
  if (-1 < (int)((uint)*(byte *)param_1 << 0x1b)) {
    FUN_0000c5f8(param_1);
  }
  for (iVar3 = 0; iVar3 < param_4; iVar3 = iVar3 + 1) {
    (*(code *)param_1[1])(*(undefined *)(param_3 + iVar3),param_1[2]);
    param_1[8] = param_1[8] + 1;
  }
  if ((int)((uint)*(byte *)param_1 << 0x1b) < 0) {
    FUN_0000c5f8(param_1);
  }
  while (0 < iVar4) {
    (*(code *)param_1[1])(0x30,param_1[2]);
    param_1[8] = param_1[8] + 1;
    iVar4 = iVar4 + -1;
  }
  while (0 < param_2) {
    (*(code *)param_1[1])(*(byte *)((int)param_1 + param_2 + 0x23),param_1[2]);
    param_1[8] = param_1[8] + 1;
    param_2 = param_2 + -1;
  }
  FUN_0000c624(param_1);
  if ((int)((uint)*(byte *)param_1 << 0x18) < 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



// ==========================================
// Function: FUN_0000ca92
// Address:  0000ca92
// Size:     32 bytes
// ==========================================

void FUN_0000ca92(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined auStack_40 [4];
  undefined4 local_3c;
  undefined4 uStack_38;
  int local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  
  local_2c = 0;
  local_34 = DAT_0000cab4 + 0xcaa4;
  local_3c = param_4;
  uStack_38 = param_2;
  uStack_30 = param_1;
  FUN_0000c710(auStack_40,param_3);
  return;
}



// ==========================================
// Function: FUN_0000cab8
// Address:  0000cab8
// Size:     10 bytes
// ==========================================

void FUN_0000cab8(undefined param_1,undefined4 *param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)*param_2;
  *puVar1 = param_1;
  *param_2 = puVar1 + 1;
  return;
}



// ==========================================
// Function: FUN_0000cb38
// Address:  0000cb38
// Size:     64 bytes
// ==========================================

void FUN_0000cb38(undefined4 param_1,undefined4 param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  FUN_000001b2();
  UNRECOVERED_JUMPTABLE = (code *)0x1d5;
  FUN_0000cb54(param_1,param_2);
  FUN_0000cbde();
  FUN_000088a8();
  FUN_00009832(DAT_000001fc,0,DAT_000001f8,2);
  FUN_000089e4();
                    /* WARNING: Could not recover jumptable at 0x000001f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0);
  return;
}



// ==========================================
// Function: FUN_0000cb54
// Address:  0000cb54
// Size:     8 bytes
// ==========================================

void FUN_0000cb54(void)

{
  software_bkpt(0xab);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==========================================
// Function: FUN_0000cb64
// Address:  0000cb64
// Size:     8 bytes
// ==========================================

undefined4 FUN_0000cb64(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  return uVar2;
}



// ==========================================
// Function: FUN_0000cb6c
// Address:  0000cb6c
// Size:     6 bytes
// ==========================================

void FUN_0000cb6c(uint param_1)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_1 & 1) == 1);
  }
  return;
}



// ==========================================
// Function: FUN_0000cb72
// Address:  0000cb72
// Size:     32 bytes
// ==========================================

void FUN_0000cb72(void)

{
  bool bVar1;
  
  *DAT_0000cbe8 = 0xff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(0);
  }
  *DAT_0000cbec = 1;
  *DAT_0000cbf0 = 0x10000000;
  enableIRQinterrupts();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ==========================================
// Function: FUN_0000cb92
// Address:  0000cb92
// Size:     10 bytes
// ==========================================

void FUN_0000cb92(void)

{
  *DAT_0000cbf0 = 0x10000000;
  return;
}



// ==========================================
// Function: FUN_0000cb9c
// Address:  0000cb9c
// Size:     10 bytes
// ==========================================

void FUN_0000cb9c(void)

{
  *DAT_0000cbf0 = 0x10000000;
  return;
}



// ==========================================
// Function: FUN_0000cbde
// Address:  0000cbde
// Size:     10 bytes
// ==========================================

undefined4 FUN_0000cbde(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts(1);
  }
  return 1;
}



// ==========================================
// Function: FUN_0000cc04
// Address:  0000cc04
// Size:     14 bytes
// ==========================================

undefined4 FUN_0000cc04(int param_1)

{
  if (param_1 - 0x30U < 10) {
    return 1;
  }
  return 0;
}



// ==========================================
// Function: FUN_0000cc14
// Address:  0000cc14
// Size:     776 bytes
// ==========================================

/* WARNING: Control flow encountered bad instruction data */

ulonglong FUN_0000cc14(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar11;
  bool bVar12;
  byte bVar13;
  ulonglong uVar14;
  
  if ((int)(param_2 ^ param_4) < 0) {
    param_4 = param_4 ^ 0x80000000;
    bVar11 = param_3 <= param_1;
    uVar6 = param_1 - param_3;
    if (param_2 <= param_4 && (uint)bVar11 <= param_2 - param_4) {
      bVar12 = CARRY4(param_3,uVar6);
      param_3 = param_3 + uVar6;
      uVar7 = (param_2 - param_4) - (uint)!bVar11 ^ 0x80000000;
      param_4 = param_4 + uVar7 + bVar12;
      bVar11 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      param_2 = (param_2 - uVar7) - (uint)bVar11;
    }
    uVar7 = param_2 >> 0x14;
    uVar6 = uVar7 - (param_4 >> 0x14);
    bVar11 = (DAT_0000d03c & param_4 << 1) == 0;
    if (!bVar11) {
      bVar11 = DAT_0000d03c == uVar7 << 0x15;
    }
    if (bVar11) {
      if (DAT_0000d03c != uVar7 << 0x15) {
        if ((param_2 & DAT_0000d03c >> 1) == 0) {
          param_2 = 0;
          param_1 = 0;
        }
        return CONCAT44(param_2,param_1);
      }
      UNRECOVERED_JUMPTABLE = (code *)0xd02e;
      FUN_0000cdc2();
      software_interrupt(0x40);
                    /* WARNING: Could not recover jumptable at 0x0000d03a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar14 = (*UNRECOVERED_JUMPTABLE)(param_3,param_4 ^ 0x80000000);
      return uVar14;
    }
    uVar5 = -param_3;
    uVar2 = param_2 & ~(param_2 & 0xfff00000);
    iVar8 = ((int)DAT_0000d03c >> 1) - (param_4 & ~((int)DAT_0000d03c >> 1));
    if (param_3 != 0) {
      iVar8 = iVar8 + -1;
    }
    if (uVar6 < 0x21) {
      uVar1 = uVar5 >> (uVar6 & 0xff);
      uVar9 = param_1 + uVar1;
      uVar2 = uVar2 + (iVar8 >> (uVar6 & 0xff)) + (uint)CARRY4(param_1,uVar1);
      uVar1 = iVar8 << (0x20 - uVar6 & 0xff);
      bVar12 = CARRY4(uVar9,uVar1);
      uVar9 = uVar9 + uVar1;
      bVar11 = CARRY4(uVar2,(uint)bVar12);
      iVar8 = uVar2 + bVar12;
      uVar6 = 0x20 - uVar6;
    }
    else {
      param_3 = param_3 * -2;
      if (param_3 != 0) {
        param_3 = 1;
      }
      uVar5 = param_3 | (iVar8 * 2 + (uint)CARRY4(uVar5,uVar5)) * 2;
      uVar6 = uVar6 - 0x20;
      if (0x1d < uVar6) {
        return CONCAT44(uVar2 + (param_2 & 0xfff00000),param_1);
      }
      uVar9 = iVar8 >> (uVar6 & 0xff);
      bVar12 = CARRY4(param_1,uVar9);
      uVar9 = param_1 + uVar9;
      bVar11 = uVar2 != 0 || CARRY4(uVar2 - 1,(uint)bVar12);
      iVar8 = (uVar2 - 1) + (uint)bVar12;
      uVar6 = 0x1e - uVar6;
    }
    if (-1 < iVar8) {
      iVar4 = uVar5 << (uVar6 & 0xff);
      iVar8 = iVar8 + (param_2 & 0xfff00000);
      if (-1 < iVar4) {
        return CONCAT44(iVar8,uVar9);
      }
      uVar9 = uVar9 + 1;
      if (uVar9 != 0 && iVar4 != -0x80000000) {
        return CONCAT44(iVar8,uVar9);
      }
      if (uVar9 == 0) {
        iVar8 = iVar8 + 1;
        uVar9 = 0;
      }
      else {
        uVar9 = uVar9 & 0xfffffffe;
      }
      return CONCAT44(iVar8,uVar9);
    }
    uVar2 = uVar6 + 1 & 0xff;
    bVar11 = uVar2 == 0 && bVar11 || uVar2 != 0 && (uVar5 << uVar2 - 1 & 0x80000000) != 0;
    uVar1 = uVar9 * 2 + (uint)bVar11;
    uVar6 = iVar8 * 2 + (uint)(CARRY4(uVar9,uVar9) || CARRY4(uVar9 * 2,(uint)bVar11));
    uVar9 = uVar6 + uVar7 * 0x200000;
    bVar11 = (uVar9 >> 0x14 & 1) != 0;
    if (bVar11 && uVar9 >> 0x15 != 0) {
      uVar7 = -((int)(uVar5 << uVar2) >> 0x1f);
      uVar9 = uVar1 + uVar7;
      bVar11 = uVar9 == 0;
      iVar8 = uVar6 + (param_2 & 0xfff00000);
      if (CARRY4(uVar1,uVar7) == false) {
        bVar11 = uVar5 << uVar2 == -0x80000000;
      }
      if (!bVar11) {
        return CONCAT44(iVar8,uVar9);
      }
      if (uVar9 == 0) {
        iVar8 = iVar8 + 1;
        uVar9 = 0;
      }
      else {
        uVar9 = uVar9 & 0xfffffffe;
      }
      return CONCAT44(iVar8,uVar9);
    }
    if (!bVar11) {
      iVar8 = uVar6 + 0x200000;
      if (iVar8 == 0) {
        uVar6 = uVar1 << LZCOUNT(uVar1);
        if (uVar6 == 0) {
          return (ulonglong)uVar1;
        }
        iVar4 = ((uVar7 & 0xfffff7ff) - LZCOUNT(uVar1)) + -0x17;
        iVar8 = uVar6 << 0x15;
        uVar6 = uVar6 >> 0xb;
      }
      else {
        uVar5 = LZCOUNT(iVar8) - 0xb;
        iVar4 = ((uVar7 & 0xfffff7ff) - uVar5) + -2;
        uVar6 = iVar8 << (uVar5 & 0xff) | uVar1 >> (0x20 - uVar5 & 0xff);
        iVar8 = uVar1 << (uVar5 & 0xff);
      }
      iVar3 = uVar6 + (param_2 & 0x80000000) + iVar4 * 0x100000;
      if (-1 < iVar4) {
        return CONCAT44(iVar3,iVar8);
      }
      return (ulonglong)(iVar3 + 0x60000000U & 0x80000000) << 0x20;
    }
    uVar7 = ((int)uVar6 >> 1) + (param_2 & 0xfff00000);
    uVar6 = (uint)((uVar6 & 1) != 0) << 0x1f | uVar1 >> 1;
    if (uVar7 * 2 == 0 && uVar6 == 0) {
      return (ulonglong)uVar6;
    }
    if (0x1fffff < uVar7 * 2) {
      return CONCAT44(uVar7,uVar6);
    }
    return (ulonglong)(uVar7 & 0x80000000) << 0x20;
  }
  uVar6 = param_1 - param_3;
  iVar8 = (param_2 - param_4) - (uint)(param_3 > param_1);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar11 = CARRY4(param_3,uVar6);
    param_3 = param_3 + uVar6;
    param_4 = param_4 + iVar8 + (uint)bVar11;
    bVar11 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = (param_2 - iVar8) - (uint)bVar11;
  }
  uVar7 = param_2 >> 0x14;
  uVar6 = uVar7 - (param_4 >> 0x14);
  bVar11 = (DAT_0000cd60 & param_4 << 1) == 0;
  if (!bVar11) {
    bVar11 = DAT_0000cd60 == uVar7 << 0x15;
  }
  if (bVar11) {
    if (DAT_0000cd60 != uVar7 << 0x15) {
      if ((param_2 & DAT_0000cd60 >> 1) == 0) {
        param_2 = param_2 & 0x80000000;
        param_1 = 0;
      }
      return CONCAT44(param_2,param_1);
    }
    FUN_0000cdc2();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar2 = param_2 & ~(param_2 & 0xfff00000);
  uVar5 = param_4 & ~DAT_0000cd60 | 0x100000;
  if (uVar6 < 0x21) {
    uVar9 = param_3 >> (uVar6 & 0xff);
    uVar7 = param_1 + uVar9;
    uVar10 = uVar5 << (0x20 - uVar6 & 0xff);
    uVar1 = uVar7 + uVar10;
    uVar2 = uVar2 + (uVar5 >> (uVar6 & 0xff)) + (uint)CARRY4(param_1,uVar9) +
            (uint)CARRY4(uVar7,uVar10);
    uVar6 = 0x20 - uVar6;
    if (uVar2 < 0x100000) {
      uVar2 = uVar2 + (param_2 & 0xfff00000);
      goto LAB_0000cc90;
    }
LAB_0000ccf2:
    bVar13 = (byte)uVar1 & 1;
    uVar7 = (uint)((uVar2 + 0x100000 & 1) != 0) << 0x1f | uVar1 >> 1;
    uVar2 = (uVar2 + 0x100000 >> 1) + (param_2 & 0xfff00000);
    if ((uVar1 & 1) == 0) {
LAB_0000cd20:
      if (uVar2 * 2 < 0xffe00000) {
        return CONCAT44(uVar2,uVar7);
      }
      goto LAB_0000ce5e;
    }
    bVar11 = CARRY4(uVar7,(uint)bVar13);
    uVar7 = uVar7 + bVar13;
    uVar5 = uVar7;
    if (!bVar11) {
      uVar5 = param_3 << (uVar6 & 0xff);
    }
    if (uVar5 != 0) goto LAB_0000cd20;
  }
  else {
    param_3 = uVar5 * 2 + (uint)(param_3 != 0);
    uVar9 = uVar6 - 0x20;
    uVar6 = 0x1f - uVar9;
    if (uVar9 < 0x20) {
      uVar5 = uVar5 >> (uVar9 & 0xff);
      uVar1 = param_1 + uVar5;
    }
    else {
      uVar6 = 0;
      uVar1 = param_1;
    }
    uVar2 = uVar2 + (param_2 & 0xfff00000) + (uint)(uVar9 < 0x20 && CARRY4(param_1,uVar5));
    if (uVar7 != uVar2 >> 0x14) {
      uVar2 = uVar2 - (param_2 & 0xfff00000);
      goto LAB_0000ccf2;
    }
LAB_0000cc90:
    param_3 = param_3 << (uVar6 & 0xff);
    if (-1 < (int)param_3) {
      return CONCAT44(uVar2,uVar1);
    }
    uVar7 = uVar1 + 1;
    uVar6 = uVar7;
    if (uVar1 != 0xffffffff) {
      uVar6 = param_3 & 0x7fffffff;
    }
    if (uVar6 != 0) {
      return CONCAT44(uVar2,uVar7);
    }
  }
  if (uVar7 == 0) {
    uVar2 = uVar2 + 1;
    uVar7 = 0;
  }
  else {
    uVar7 = uVar7 & 0xfffffffe;
  }
  if (uVar2 << 1 < 0xffe00000) {
    return CONCAT44(uVar2,uVar7);
  }
LAB_0000ce5e:
  return (ulonglong)((uint)((int)(uVar2 + 0xa0000000) < 0) << 0x1f | 0x7ff00000) << 0x20;
}



// ==========================================
// Function: FUN_0000cd64
// Address:  0000cd64
// Size:     92 bytes
// ==========================================

uint FUN_0000cd64(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 *unaff_r4;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar5;
  bool bVar6;
  
  iVar2 = ((uint)(param_2 << 1) >> 0x15) - 0x400;
  bVar6 = SBORROW4(0x1e,iVar2);
  iVar1 = -iVar2;
  uVar3 = iVar1 + 0x1e;
  bVar5 = uVar3 == 0;
  uVar4 = uVar3;
  if (!bVar5 && iVar2 < 0x1f) {
    bVar6 = SBORROW4(0x21,uVar3);
    uVar4 = 0x21 - uVar3;
    bVar5 = uVar3 == 0x21;
  }
  if (!bVar5 && (int)uVar4 < 0 == bVar6) {
    return ((param_2 << 0xb | 0x80000000U | param_1 >> 0x15) >> (uVar3 & 0xff) ^ param_2 >> 0x1f) -
           (param_2 >> 0x1f);
  }
  if (0x10 < (int)uVar3) {
    param_1 = 0;
  }
  if (uVar3 != 0x10 && iVar1 + 0xe < 0 == SBORROW4(uVar3,0x10)) {
    return param_1;
  }
  if (iVar1 != -0x3ff) {
    return param_2 >> 0x20 ^ 0x7fffffff;
  }
  UNRECOVERED_JUMPTABLE = (code *)0xcdb8;
  FUN_0000cdc2(param_1);
  *unaff_r4 = (short)unaff_r4;
                    /* WARNING: Could not recover jumptable at 0x0000cdbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar4 = (*UNRECOVERED_JUMPTABLE)(0);
  return uVar4;
}



// ==========================================
// Function: FUN_0000cdc2
// Address:  0000cdc2
// Size:     152 bytes
// ==========================================

int FUN_0000cdc2(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint unaff_r5;
  uint uVar2;
  uint uVar3;
  int in_lr;
  uint *puVar4;
  bool bVar5;
  
  puVar4 = (uint *)(in_lr + 2U & 0xfffffffc);
  uVar2 = *puVar4;
  if ((((int)uVar2 < 0) || (unaff_r5 = param_4 * 2 + (uint)(param_3 != 0), unaff_r5 < 0xffe00001))
     && (uVar3 = param_2 * 2 + (uint)(param_1 != 0), uVar3 < 0xffe00001)) {
    if (uVar3 == 0xffe00000) {
      uVar3 = ((int)param_2 >> 0x1f) * -3 + 2;
      if (unaff_r5 == 0xffe00000) {
        uVar3 = uVar3 + ((uint)(0xffdfffff < unaff_r5) - ((int)param_4 >> 0x1f));
      }
    }
    else {
      uVar3 = param_4 >> 0x1f;
    }
  }
  else {
    uVar3 = 8;
  }
  uVar2 = uVar2 >> (uVar3 * 3 & 0xff) & 7;
  switch(uVar2) {
  case 4:
    param_1 = param_3;
    param_2 = param_4;
switchD_0000ce2e_caseD_5:
    bVar5 = CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)(param_1 != 0));
    uVar2 = param_2 * 2 + (uint)(param_1 != 0);
    if (uVar2 != 0) {
      bVar5 = uVar2 < 0x200001;
    }
    if (bVar5 && (uVar2 != 0 && uVar2 != 0x200000)) {
      param_1 = 0;
    }
    return param_1;
  case 5:
    goto switchD_0000ce2e_caseD_5;
  case 6:
  case 7:
    return 0;
  default:
                    /* WARNING: Could not recover jumptable at 0x0000ce2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)(puVar4 + uVar2 + 1))();
    return iVar1;
  }
}



// ==========================================
// Function: FUN_0000d040
// Address:  0000d040
// Size:     72 bytes
// ==========================================

longlong FUN_0000d040(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0x1f;
  uVar2 = (param_1 << 1) >> 4;
  uVar4 = param_1 << 1 ^ param_1;
  bVar5 = uVar4 == 0;
  if (!bVar5) {
    param_1 = param_1 << 0x1d;
    param_2 = (uVar1 | uVar2) + 0x38000000;
    bVar5 = (uVar4 & 0x7f000000) == 0;
  }
  if (bVar5) {
    if ((uVar2 & 0x8000000) != 0) {
      iVar3 = FUN_0000d3f8(uVar1 | param_1 >> 0x1d | uVar2 << 3,param_2);
      return (ulonglong)((uint)(iVar3 < 0) << 0x1f | 0x7ff00000) << 0x20;
    }
    return (ulonglong)uVar1 << 0x20;
  }
  return CONCAT44(param_2,param_1);
}



// ==========================================
// Function: FUN_0000d174
// Address:  0000d174
// Size:     316 bytes
// ==========================================

ulonglong FUN_0000d174(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  bool bVar8;
  
  uVar3 = param_1 >> 7 & 0xff0000;
  bVar8 = uVar3 == 0;
  if (!bVar8) {
    param_4 = param_2 >> 7 & 0xff0000;
    bVar8 = param_4 == 0;
  }
  if (!bVar8) {
    bVar8 = uVar3 == 0xff0000;
  }
  if (!bVar8) {
    bVar8 = param_4 == 0xff0000;
  }
  if (bVar8) {
    uVar6 = param_2 >> 7 & 0xff0000;
    if ((int)(param_1 ^ param_2) < 0) {
      uVar3 = uVar3 | 0x100;
    }
    if (uVar3 < 0xff0000 && uVar6 < 0xff0000) {
      if (uVar6 != 0) {
        return CONCAT44(param_2,param_1 ^ param_2) & 0xffffffff80000000;
      }
      if ((uVar3 & 0xff0000) == 0) {
        return CONCAT44(param_2,DAT_0000d2f4);
      }
      param_1 = param_1 ^ param_2;
    }
    else {
      param_1 = FUN_0000d3f8();
      param_1 = param_1 & 0x80000000;
    }
  }
  else {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar3 = uVar3 | 0x100;
    }
    uVar2 = param_1 & 0xffffff | 0x800000;
    uVar1 = param_2 & 0xffffff | 0x800000;
    bVar8 = uVar1 <= uVar2;
    uVar6 = -uVar1;
    uVar1 = (uint)*(byte *)(0xd2bc - (uVar1 >> 0x11));
    iVar7 = uVar1 * 2;
    if (!bVar8) {
      uVar2 = uVar2 << 1;
    }
    iVar4 = (uVar3 - param_4) + 0x7d0000;
    iVar7 = uVar1 * 0x100 + (((int)(uVar6 * iVar7) >> 4) * iVar7 >> 0x15);
    uVar1 = iVar4 + (iVar4 >> 0x10) + (uint)bVar8;
    uVar5 = iVar7 * (uVar2 >> 8) >> 0x14;
    uVar3 = uVar6 * uVar5 + uVar2 * 0x800;
    uVar2 = iVar7 * (uVar3 >> 8) >> 0x13;
    uVar3 = uVar6 * uVar2 + uVar3 * 0x1000;
    bVar8 = CARRY4(uVar3,uVar6);
    if (bVar8 != false) {
      uVar3 = uVar3 + uVar6;
    }
    iVar7 = uVar6 + uVar3 * 2;
    param_1 = uVar2 + uVar5 * 0x1000 + (uint)bVar8 +
              uVar1 * 0x800000 + (uint)CARRY4(uVar6,uVar3 * 2);
    if (uVar1 < 0xfc0000) {
      return CONCAT44(iVar7,param_1);
    }
    if ((int)(uVar1 - 0xfc0000) < 0) {
      if ((uVar1 & 0xf0) != 0) {
        param_1 = param_1 + 0x60000000 & 0x80000000;
      }
      return CONCAT44(iVar7,param_1);
    }
    if (0xfdffffff < param_1 * 2 + 0x1000000) {
      return CONCAT44(iVar7,param_1);
    }
    param_1 = param_1 + 0xa0000000;
  }
  return CONCAT44(0xff,(param_1 >> 0x17 | 0xff) << 0x17);
}



// ==========================================
// Function: FUN_0000d2f8
// Address:  0000d2f8
// Size:     56 bytes
// ==========================================

uint FUN_0000d2f8(uint param_1)

{
  uint uVar1;
  undefined2 *unaff_r4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 >> 0x17 < 0x9f) {
    return (param_1 << 8 | 0x80000000) >> (0x9e - (param_1 >> 0x17) & 0xff);
  }
  if (((int)param_1 < 0) && (param_1 << 1 < 0x7f000000)) {
    return 0;
  }
  UNRECOVERED_JUMPTABLE = (code *)0xd328;
  FUN_0000d3f8();
  *unaff_r4 = (short)unaff_r4;
                    /* WARNING: Could not recover jumptable at 0x0000d32e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(0);
  return uVar1;
}



// ==========================================
// Function: FUN_0000d338
// Address:  0000d338
// Size:     48 bytes
// ==========================================

uint FUN_0000d338(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 & 0x80000000;
  if ((int)uVar1 < 0) {
    param_1 = -param_1;
  }
  uVar2 = param_1 << LZCOUNT(param_1);
  if (uVar2 != 0) {
    param_1 = (uVar1 | (0x9d - LZCOUNT(param_1)) * 0x800000) + (uVar2 >> 8);
    if ((uVar2 & 0x80) == 0) {
      return param_1;
    }
    param_1 = param_1 + 1;
    if ((uVar2 & 0x7f) == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
  }
  return param_1;
}



// ==========================================
// Function: FUN_0000d368
// Address:  0000d368
// Size:     38 bytes
// ==========================================

uint FUN_0000d368(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 != 0) {
    param_1 = (0x9d - LZCOUNT(param_1)) * 0x800000 + (uVar1 >> 8);
    if ((uVar1 & 0x80) == 0) {
      return param_1;
    }
    param_1 = param_1 + 1;
    if ((uVar1 & 0x7f) == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
  }
  return param_1;
}



// ==========================================
// Function: FUN_0000d3f8
// Address:  0000d3f8
// Size:     136 bytes
// ==========================================

uint FUN_0000d3f8(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int in_lr;
  uint *puVar3;
  bool bVar4;
  
  puVar3 = (uint *)(in_lr + 2U & 0xfffffffc);
  uVar1 = *puVar3;
  if ((((int)uVar1 < 0) || (param_3 = param_2 * 2, param_3 < 0xff000001)) &&
     (param_1 * 2 < 0xff000001)) {
    if (param_1 * 2 == 0xff000000) {
      uVar2 = ((int)param_1 >> 0x1f) * -3 + 2;
      if (param_3 == 0xff000000) {
        uVar2 = uVar2 + ((uint)(0xfeffffff < param_3) - ((int)param_2 >> 0x1f));
      }
    }
    else {
      uVar2 = param_2 >> 0x1f;
    }
  }
  else {
    uVar2 = 8;
  }
  uVar1 = uVar1 >> (uVar2 * 3 & 0xff) & 7;
  switch(uVar1) {
  case 4:
    param_1 = param_2;
switchD_0000d460_caseD_5:
    bVar4 = (param_1 & 0x80000000) != 0;
    uVar1 = param_1 * 2;
    if (uVar1 != 0) {
      bVar4 = uVar1 < 0x1000001;
    }
    if (bVar4 && (uVar1 != 0 && uVar1 != 0x1000000)) {
      param_1 = param_1 & 0x80000000;
    }
    return param_1;
  case 5:
    goto switchD_0000d460_caseD_5;
  case 6:
  case 7:
    return 0x7fc00000;
  default:
                    /* WARNING: Could not recover jumptable at 0x0000d45e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(puVar3 + uVar1 + 1))();
    return uVar1;
  }
}



// ==========================================
// Function: FUN_0000d48e
// Address:  0000d48e
// Size:     144 bytes
// ==========================================

void FUN_0000d48e(uint param_1,uint param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar2;
  bool bVar3;
  byte in_Q;
  
  uVar1 = param_2 | param_1;
  if ((int)uVar1 < 0) {
    if ((int)(uVar1 + 0x800000) < 0) {
      if (-1 < (int)(uVar1 - 0x800000)) {
        return;
      }
      return;
    }
    bVar2 = 0xfeffffff < param_2 << 1;
    if (!bVar2) {
      bVar2 = 0xfeffffff < param_1 << 1;
    }
    if (!bVar2) {
      return;
    }
  }
  else {
    bVar3 = SCARRY4(uVar1,0x800000);
    bVar2 = (int)(uVar1 + 0x800000) < 0;
    if (!bVar2) {
      bVar3 = SBORROW4(uVar1,0x800000);
      bVar2 = (int)(uVar1 - 0x800000) < 0;
    }
    if (!bVar2) {
      return;
    }
    if (bVar3 == false) {
      return;
    }
    bVar2 = (int)(param_2 + 0x800000) < 0;
    if (!bVar2) {
      bVar2 = (int)(param_1 + 0x800000) < 0;
    }
    if (!bVar2) {
      return;
    }
  }
  UNRECOVERED_JUMPTABLE = (code *)0xd3e8;
  FUN_0000d3f8(param_2);
                    /* WARNING: Could not recover jumptable at 0x0000d172. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)((uint)(in_Q | 4) << 0x1b);
  return;
}



// ==========================================
// Function: FUN_0000d4f0
// Address:  0000d4f0
// Size:     418 bytes
// ==========================================

/* WARNING: Control flow encountered bad instruction data */

uint FUN_0000d4f0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint extraout_r1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *UNRECOVERED_JUMPTABLE;
  bool bVar8;
  bool bVar9;
  
  param_1 = param_1 ^ 0x80000000;
  if ((int)(param_1 ^ param_2) < 0) {
    param_2 = param_2 ^ 0x80000000;
    if (param_1 < param_2 || param_1 - param_2 == 0) {
      uVar4 = param_1 - param_2 ^ 0x80000000;
      param_1 = param_1 - uVar4;
      param_2 = param_2 + uVar4;
    }
    uVar4 = param_1 >> 0x17;
    bVar8 = (param_2 & 0x7f800000) == 0;
    uVar5 = uVar4 - (param_2 >> 0x17);
    if (!bVar8) {
      bVar8 = (uVar4 & 0xff) == 0xff;
    }
    if (bVar8) {
      if ((uVar4 & 0xff) != 0xff) {
        if ((param_1 & 0x7f800000) == 0) {
          param_1 = 0;
        }
        return param_1;
      }
      UNRECOVERED_JUMPTABLE = (code *)0xd5e4;
      FUN_0000d3f8();
      software_interrupt(0x40);
                    /* WARNING: Could not recover jumptable at 0x0000d5ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*UNRECOVERED_JUMPTABLE)(extraout_r1 ^ 0x80000000);
      return uVar4;
    }
    uVar2 = param_2 << 8 | 0x80000000;
    uVar7 = (param_1 << 8 | 0x80000000) - (uVar2 >> (uVar5 & 0xff));
    if (-1 < (int)uVar7) {
      if ((uVar4 & 0xfe) == 0) {
        if (uVar7 >> 7 == 0) {
          return 0;
        }
      }
      else {
        uVar1 = uVar7 * 2;
        if ((int)uVar1 < 0) {
          bVar8 = ((int)uVar1 >> 7 & 1U) != 0;
          uVar4 = ((int)uVar1 >> 8) + (param_1 & 0xff800000) + (uint)bVar8;
          if (!bVar8) {
            return uVar4;
          }
          if ((uVar7 & 0x3f) != 0) {
            return uVar4;
          }
          goto LAB_0000d586;
        }
        uVar1 = uVar1 >> 2;
        if (uVar1 == 0) {
          return 0;
        }
        uVar2 = uVar4 - LZCOUNT(uVar1);
        uVar5 = 0x28U - LZCOUNT(uVar1) & 0x1f;
        if ((uVar4 ^ uVar2) >> 8 == 0) {
          return (uVar1 >> uVar5 | uVar1 << 0x20 - uVar5) + uVar2 * 0x800000;
        }
      }
      return param_1 & 0x80000000;
    }
    bVar8 = (uVar7 >> 7 & 1) != 0;
    uVar4 = (uVar7 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
    if (!bVar8) {
      return uVar4;
    }
    if ((uVar7 & 0x7f) != 0) {
      return uVar4;
    }
LAB_0000d586:
    if (uVar2 << (0x20 - uVar5 & 0xff) == 0) {
      uVar4 = uVar4 & 0xfffffffe;
    }
    else {
      uVar4 = uVar4 - 1;
    }
    return uVar4;
  }
  iVar3 = param_1 - param_2;
  if (param_1 < param_2) {
    param_1 = param_1 - iVar3;
    param_2 = param_2 + iVar3;
  }
  uVar4 = param_1 >> 0x17;
  bVar8 = (param_2 & 0x7f800000) == 0;
  uVar5 = uVar4 - (param_2 >> 0x17);
  if (!bVar8) {
    bVar8 = (uVar4 & 0xff) == 0xff;
  }
  if (bVar8) {
    if ((uVar4 & 0xff) != 0xff) {
      if ((param_1 & 0x7f800000) == 0) {
        param_1 = param_1 & 0x80000000;
      }
      return param_1;
    }
    FUN_0000d3f8();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uVar2 = param_1 << 8 | 0x80000000;
  uVar7 = param_2 << 8 | 0x80000000;
  uVar1 = uVar7 >> (uVar5 & 0xff);
  bVar8 = CARRY4(uVar2,uVar1);
  uVar2 = uVar2 + uVar1;
  if (bVar8 == false) {
    bVar8 = (uVar2 >> 7 & 1) != 0;
    uVar1 = (uVar2 >> 8) + (uVar4 - 1) * 0x800000 + (uint)bVar8;
    if (!bVar8) {
      return uVar1;
    }
    uVar6 = uVar1 * 2;
    if ((uVar2 & 0x7f) != 0) {
      bVar8 = 0xfeffffff < uVar6;
    }
    if (!bVar8) {
      return uVar1;
    }
  }
  else {
    bVar9 = (uVar2 >> 1 & 0x80) != 0;
    uVar4 = ((uint)bVar8 << 0x1f | uVar2 >> 1) >> 8;
    uVar1 = uVar4 + (param_1 & 0xff800000) + (uint)bVar9;
    if (bVar9) {
      uVar4 = uVar2 & 0xff;
    }
    uVar6 = uVar1 * 2;
    if (uVar4 != 0) {
      if (uVar4 != 0) {
        bVar9 = 0xfeffffff < uVar6;
      }
      if (!bVar9) {
        return uVar1;
      }
      goto LAB_0000d114;
    }
  }
  if (uVar7 << (0x20 - uVar5 & 0xff) == 0) {
    uVar1 = uVar1 & 0xfffffffe;
  }
  if (uVar6 < 0xff000000) {
    return uVar1;
  }
LAB_0000d114:
  return (uVar1 + 0xa0000000 >> 0x17 | 0xff) << 0x17;
}



