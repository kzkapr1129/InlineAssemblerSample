//
//  main.cpp
//  InlineAssembler
//
//  Created by 中山一輝 on 2018/10/24.
//  Copyright © 2018年 中山一輝. All rights reserved.
//

#include <iostream>

void mv_sample() {
    int a=21, b;
    asm("movl %1, %%eax;"
        "movl %%eax, %0;"
        : "=r"(b)
        : "r"(a)
        : "%eax");
    printf("%s: b=%d\n", __FUNCTION__, b);
}

void decinc_sample() {
    int var = 101;
    asm("decl %0" : "=m"(var):"m"(var));
    asm("decl %0" : "=r"(var):"r"(var));
    asm("incl %0" : "=m"(var):"m"(var));
    asm("incl %0" : "=r"(var):"r"(var));
    printf("%s: var=%d\n", __FUNCTION__, var);
}

int main(int argc, const char * argv[]) {
    mv_sample();
    decinc_sample();
    
    return 0;
}
