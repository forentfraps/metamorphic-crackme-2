#include "aes_home/aes.h"
#include "funcs_enc.c"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef int (*FuncPtr)(unsigned char*, unsigned char*);

extern void* GetRip();

#define  TOMFOOLERY asm volatile(\
        "call AddrOffset\n\t"\
        ".byte 0x9a\n\t"\
    );

char fail[9] = {0x47,0x60,0x68,0x6d,0x21,0x3b,0x29,0x0b,0x00};

void func_wrapper(unsigned char** KeyList, unsigned long long params){
    TOMFOOLERY
    unsigned int sz = sizeof(hello_enc);
    unsigned char f[sizeof(hello_enc)];
    memcpy(&f, &hello_enc, sz);
    // printf("%llu is the key\n", rip ^ 0x0011223344332211ULL);
    unsigned long long ptr = (unsigned long long) params;
    TOMFOOLERY
    for (int i = 0; i<sz; i +=16){
        TOMFOOLERY
        Decrypt((f + i), KeyList);
        TOMFOOLERY

    }
    TOMFOOLERY
    FuncPtr rf;
    TOMFOOLERY
    PDWORD junk = malloc(sizeof(PDWORD));
    TOMFOOLERY
    VirtualProtect(&f, sz, PAGE_EXECUTE_READWRITE, junk);
    TOMFOOLERY
    rf = (FuncPtr)(f);
    TOMFOOLERY
    // key before xor is 2575293002485481311
    // key is unsigned long long res = 0x23ac656419811d4e;
    unsigned long long ans = ptr ^ 0x0011223344332211ULL;
    TOMFOOLERY
    rf(ans, &fail);
    for (int i =0; i<sz; i += 16){
        TOMFOOLERY
        Encrypt(f + i, KeyList);
        TOMFOOLERY
    }
    return;
}


int main(){
    TOMFOOLERY
    unsigned char MasterKey[16];
    unsigned char KeyList[176];
    unsigned long long p;
    printf("Input Key:\n");
    for (int i = 0; i< 16; ++i){
        MasterKey[i] = i*16 + i;
    }
    // PrintBlock(MasterKey);
    TOMFOOLERY
    KeyScheduler(MasterKey, KeyList);
    TOMFOOLERY
    scanf("%llu", &p);
    TOMFOOLERY
    func_wrapper(KeyList, p);
        // printf("Success!!\n");
        // *(unsigned long long*) fail = *(unsigned long long*) fail ^ 0x005b49450f0a1415;
    TOMFOOLERY
    printf(fail);
    TOMFOOLERY
    scanf("\n");
    return 0;
}