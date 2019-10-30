#include <stdio.h>
void solve(int, char, char, char);

int main (void){
    int rings;
    char A='A',B='B',C='C';
    printf("Enter the number of rings: ");
    scanf("%d", &rings);
    solve(rings, A, C, B);
    return 0;
}

void solve(int num, char source, char dest, char aux){
    if(num!=0){
        //move smaller tower from source to aux via dest
        solve(num-1,source, aux, dest);
        //move largest ring from source to dest
        printf("Move Ring from %c to %c\n", source, dest);
        //move smaller tower from aux to dest via source
        solve(num-1,aux, dest, source);
    }else{
        return;
    } 
}