#include<stdio.h>
#include<string.h>

typedef struct DFA
{
    int nos;
    int noi;
    int nof;
    int delta[10][10];
    int final[10];
    char inputSymbols[10];
} DFA;

int checkSymbol(char ch,DFA d)
{
    for(int i=0;i<d.noi;i++)
    {
        if(ch == d.inputSymbols[i]) {
            return i;  
        }
    }
    return -1;
}

int checkFinalState(int st,DFA d)
{
    for(int i=0;i<d.nof;i++) {
        if(st == d.final[i]) {
            return 1;  
        }
    }
    return 0;
}

int main()
{
    DFA d;
    printf("\nEnter no of states: ");
    scanf(" %d",&d.nos);
    printf("\nEnter no of final states: ");
    scanf(" %d",&d.nof);
    printf("\nEnter no of input symbols: ");
    scanf(" %d",&d.noi);
    // accept the input symbols
    for(int i=0;i<d.noi;i++) {
        printf("Enter input symbol no %d : ",i+1);
        scanf(" %c",&d.inputSymbols[i]);
    }
    // accept the final states
    for(int i=0;i<d.nof;i++) {
        printf("Enter final state no %d : ",i+1);
        scanf(" %d",&d.final[i]);
    }
    printf("\nEnter transitions: ");

    for(int i=0;i<d.nos;i++)
        for(int j=0;j<d.noi;j++) {
            printf("\nd(q%d,%c) : ", i,d.inputSymbols[j]);
            scanf(" %d",&d.delta[i][j]);
        }

    // print the transition table
    // print the symbols as columns of transition table
    for(int i=0;i<d.noi;i++)
        printf("\t %c",d.inputSymbols[i]);
    printf("\n");
    for(int i=0;i<d.nos;i++) {
        printf("\nq%d",i);  
        for(int j=0;j<d.noi;j++) {
            printf("\t%d",d.delta[i][j]);
        }
        printf("\n");
    }
    char ch = 'n';
    do {
        char string[10]; 
        printf("\nEnter a string: ");
        scanf("%s",string);
        int stateCounter = 0;
        int flag = 1;
        for(int i=0;i<strlen(string);i++) {
            int symPos = checkSymbol(string[i],d);
            if(symPos==-1) {
                flag = 0;
                break;
            }
            stateCounter = d.delta[stateCounter][symPos];
        }
        if(flag==1 && checkFinalState(stateCounter,d)==1) {
            printf("%s is accepted. ",string);
        }
        else {
            printf("%s is not accpeted. ",string);
        }
    } while(1); 
    return 0;
}