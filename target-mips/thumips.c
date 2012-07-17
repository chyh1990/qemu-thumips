/*
 * Author: Nuk
 * 2012.06
 * */

#ifndef TSINGCPUINSTRUCTIONCHECK
#define TSINGCPUINSTRUCTIONCHECK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int inst_arr[500];
static unsigned int inst_num;

static int stripe_binary(char* binary)
{
	int i = 0;
	int len = strlen(binary);
	for(i = 0;i < len; i ++){
		if(binary[i] == '0' || binary[i] == '1') continue;
		binary[i] = '0';
	}
	return 0;
}

int load_thumips()
{
	FILE *fp;
  const char* filename = "thumips_insn.txt";
	fp = fopen(filename, "r");

  if(!fp){
    fprintf(stderr, "qemu-thumips: ERROR failed to open instruction file: %s\n", filename);
    exit(-1);
  }

	inst_num = 0;
	while(!feof(fp)){
		//指令名
		char temp[100];
		//指令二进制格式
		char binary[100];

		memset(temp, 0, sizeof(temp));
		memset(binary, 0, sizeof(binary));

		fscanf(fp, "%s %s", temp, binary);

		if(strlen(binary) != 0){
			//预处理binary
			stripe_binary(binary);
			if(strlen(binary) != 32){
				printf("[Warning] Parsing intr %s error!\n", temp);
				printf("[Warning]Please check your thumips.txt file!!\n");
			}
			printf("[INFO]Supporting instruction: %s\n", temp);
			//二进制字符串转unsigned int
			inst_arr[inst_num] = (unsigned int)strtol(binary, NULL, 2);
			inst_num ++;
		}
	}
	fclose(fp);
	return 0;
}

int check_thumips(uint32_t opcode){
	//printf("[INFO]Supporting %d instructions!\n", inst_num);
	unsigned int i = 0;
	for(i = 0; i < inst_num; i ++){
		if((opcode & inst_arr[inst_num]) == inst_arr[inst_num]){
			return 1;
		}
	}
	return 0;
}

#endif
