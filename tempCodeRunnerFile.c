#include<stdio.h>
int main(){
    int a[5] = { [0 ... (5 - 1)] = -1 };
    for(int i=0; i<5; i++) printf("%d", a[i]);
    return 0;
}