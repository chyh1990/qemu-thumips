/*
 * Author: Nuk
 * 2012.06
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "thumips.h"

static char inst_arr[500][50];
static int inst_num;
static char inst_name[500][50];

/* int stripe_binary(char* binary) */
/* { */
/*   int i = 0; */
/*   int len = strlen(binary); */
/*   for(i = 0;i < len; i ++){ */
/*     if(binary[i] == '0' || binary[i] == '1') continue; */
/*     binary[i] = '0'; */
/*   } */
/*   return 0; */
/* } */

void print_opcode(uint32_t opcode){
  int i = 0;
  for(i = 0;i < 32; i ++){
    printf("%d", (opcode & 0x1));
    opcode = opcode >> 1;
  }
  printf("\n");
  /* printf("%08x\n", opcode); */
}

int load_thumips()
{
  int i = 0;
  int j = 0;
  for(i = 0; i < 500; i ++){
    for(j = 0; j < 50; j ++){
      inst_name[i][j] = 0;
      inst_arr[i][j] = 0;
    }
  }
  FILE *fp;
  const char* filename = "thumips_insn.txt";
  fp = fopen(filename, "r");

  if(!fp){
    fprintf(stderr, "qemu-thumips: ERROR failed to open instruction file: %s\n", filename);
    exit(-1);
  }

  inst_num = 0;
  while(!feof(fp)){
    //指令二进制格式
    char temp[100];
    char binary[100];

    memset(temp, 0, sizeof(temp));
    memset(binary, 0, sizeof(binary));

    fscanf(fp, "%s %s", temp, binary);

    if(strlen(binary) != 0 && strlen(temp) != 0){
      printf("[INFO]Supporting instruction: %s\n", temp);
      strcpy(inst_name[inst_num], temp);
      strcpy(inst_arr[inst_num], binary);
      inst_num ++;
    }
  }
  fclose(fp);
  return 0;
}


int verify_inst(uint32_t opcode, char* inst){
  int i = 0;
  int len = strlen(inst);
  for(i = len - 1; i >= 0; i --){
    if(inst[i] == '0' || inst[i] == '1'){
      if((opcode & 0x1) == (inst[i] - '0')){
      /* do nothing */
      }else{
        return -1;
      }
    }else{
      /* Do nothing. */
    }
    opcode = opcode >> 1;
  }
  /* succeeded. */
  return 0;
}

int check_thumips(uint32_t opcode){
  int i = 0;
  for(i = 0;i < inst_num; i ++){
    if(verify_inst(opcode, inst_arr[i]) == 0){
      /* printf("opcode: "); */
      /* print_opcode(opcode); */
      /* printf("instru: %s\n", inst_arr[i]); */
      return i;
    }
  }
  printf("opcode: ");
  print_opcode(opcode);
  return -1;
}
