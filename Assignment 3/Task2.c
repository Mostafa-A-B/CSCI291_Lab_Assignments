#include <stdio.h>
#include <string.h>
#define LOCAL "AED"


typedef struct {
    char name[10];
    float rate;
} Currency;//struct definition for curency objects


void exchange(float amCur1, float amMax, float excRate, float *amCur2, float *leftOver);


int main() {
    Currency CurrencyArray[3] = {
        {"USD", 0.27},//1 AED = 0.27 USD
        {"EUR", 0.25},
        {"JPY", 42.58}
    };//struct array of foreign currencies and their rates
    
    //initializing required 
    float amount, converted = 0, overflow = 0, LocalMax = 15000.0, rate, DynamicMax;
    char operation, target[4];
    int c, i;
    
    //while loop to continue transactions
    while(1){
        int confirm = 1;
        printf("select transaction type; 'B' to buy, 'S' to sell, 0 to exit: ");
        scanf("%c", &operation);
        while ((c = getchar()) != '\n' && c != EOF) { }
        if(operation=='0'){//loop exit condition
            break;
        }
        if(operation=='B'||operation=='b'||operation=='S'||operation=='s'){
            printf("enter transaction amount: ");
            if(scanf("%f", &amount)!=1 || amount<=0){
                while ((c = getchar()) != '\n' && c != EOF) { }
                puts("INVALID INPUT!\n\n");
                continue;
            }
        }//if statement to avoid asking for amount when input is invalid and not 0
        switch(operation){
            case 'B':
            case 'b':
                DynamicMax = LocalMax;
                printf("what currency would you like to buy (USD/EUR/JPY): ");
                if(scanf("%s", target)!=1){
                    puts("\nINVALID INPUT!\n\n");
                    confirm = 0;
                    break;
                }
                while ((c = getchar()) != '\n' && c != EOF) { }
                if(strcasecmp(target, "usd")==0)
                    i=0;
                else if(strcasecmp(target, "eur")==0)
                    i=1;
                else if(strcasecmp(target, "jpy")==0)
                    i=2;
                else
                    i=-1;
                
                if(i!=-1){
                    rate = CurrencyArray[i].rate;
                } else{
                    puts("currency unkown!\n");
                    confirm = 0;
                }
                break;
            
            case 'S':
            case 's':
                printf("what currency would you like to sell (USD/EUR/JPY): ");
                if(scanf("%s", target)!=1){
                    puts("\nINVALID INPUT!\n\n");
                    confirm = 0;
                    break;
                }
                while ((c = getchar()) != '\n' && c != EOF) { }
                if(strcasecmp(target, "usd")==0)//made a mistake with code logic and was too lazy to rewrite it, this fixes the issue with minimal code modification
                    i=0;
                else if(strcasecmp(target, "eur")==0)
                    i=1;
                else if(strcasecmp(target, "jpy")==0)
                    i=2;
                else
                    i=-1;
                
                if(i!=-1){
                    rate = (1/CurrencyArray[i].rate);
                    DynamicMax = LocalMax/rate;//sets relative max amount scaled to local max depending on desired foreign currency
                } else{
                    puts("currency unkown!\n");
                    confirm = 0;
                }
                break;
            
            default:
                puts("INVALID OPERATION!\n\n");
                confirm = 0;
                break;
            
        }
        
        if(confirm){
            exchange(amount, DynamicMax, rate, &converted, &overflow);//calling function
            switch(operation){//switch case statement to output converted and overflow amounts
                case 'B':
                case 'b':
                    switch(i){
                        case 0:
                            printf("\n\nExchange Balance: %f %s\nLeftover Balance Due to Exchange Limit: %f AED", converted, CurrencyArray[i].name, overflow);
                            break;
                        case 1:
                            printf("\n\nExchange Balance: %f %s\nLeftover Balance Due to Exchange Limit: %f AED", converted, CurrencyArray[i].name, overflow);
                            break;
                        case 2:
                            printf("\n\nExchange Balance: %f %s\nLeftover Balance Due to Exchange Limit: %f AED", converted, CurrencyArray[i].name, overflow);
                            break;
                    }
                    break;
                case 'S':
                case 's':
                    switch(i){
                        case 0:
                            printf("\n\nExchange Balance: %f AED\nLeftover Balance Due to Exchange Limit: %f %s", converted, overflow, CurrencyArray[i].name);
                            break;
                        case 1:
                            printf("\n\nExchange Balance: %f AED\nLeftover Balance Due to Exchange Limit: %f %s", converted, overflow, CurrencyArray[i].name);
                            break;
                        case 2:
                            printf("\n\nExchange Balance: %f AED\nLeftover Balance Due to Exchange Limit: %f %s", converted, overflow, CurrencyArray[i].name);
                            break;
                    }
                    break;
            }
            puts("\n\n");
        }
    }
    return 0;
}

void exchange(float amCur1, float amMax, float excRate, float *amCur2, float *leftOver) {
    *amCur2 = 0;
    *leftOver = 0;
    
    if(amCur1>amMax){
        *amCur2 = amMax*excRate;//calculates conversion and saves it in the memory address amCur2 points to
        *leftOver = amCur1-amMax;//finds over-limit amount and saves it in the memory address leftOver points to
    } else{
        *amCur2 = amCur1*excRate;
    }
}
