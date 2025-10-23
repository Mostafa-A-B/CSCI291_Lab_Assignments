#include <stdio.h>
#include <stdlib.h> //required for system("cls")
#include <unistd.h> // required for usleep(microseconds) and sleep(seconds)
#include <time.h> //required for getting current time for random number seeding
#define CoffeeBeanCost 8 //since all coffee types have the same coffee bean consumption per serving they will share the same variable
#define WaterCostnotMocha 30 //since espresso and cappuccino have the same water consumption per serving they will share the same variable
#define WaterCostMocha 39
#define MilkCostCappuccino 70
#define MilkCostMocha 160
#define ChocolateSyrupCostMocha 30
#define CoffeeBeanThreshold 40
#define WaterThreshold 200
#define MilkThreshold 500
#define ChocolateSyrupThreshold 150
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
//initializing required variables
int CoffeeBeanStock = 2000, WaterStock = 2000, MilkStock = 2000, ChocolateSyrupStock = 2000, UserInput, AdminPassword = 5749; //I want to add a password change function so i cant have AdminPassword be a constant, thats why its initialized as an int
float payment, price, revenue = 0.0, EspressoPrice = 3.5, CappuccinoPrice = 4.5, MochaPrice = 5.5;//revenue is the requested Total_Amount variable
void EspressoOrder(){
    CoffeeBeanStock -= CoffeeBeanCost;
    WaterStock -= WaterCostnotMocha;
}

void CappuccinoOrder(){
    CoffeeBeanStock -= CoffeeBeanCost;
    WaterStock -= WaterCostnotMocha;
    MilkStock -= MilkCostCappuccino;
}

void MochaOrder(){
    CoffeeBeanStock -= CoffeeBeanCost;
    WaterStock -= WaterCostMocha;
    MilkStock -= MilkCostMocha;
    ChocolateSyrupStock -= ChocolateSyrupCostMocha;
}

void coffee(int a){
    UserInput = a;
    int confirm, CappuccinoAvailable = 1, MochaAvailable = 1, loop = 1;//if espresso is not available then no coffee type can be available so a variable EspressoAvailable is not needed
    float refund;
        if(CoffeeBeanStock<CoffeeBeanCost || WaterStock<WaterCostnotMocha){//all coffee types need coffee beans and water with a minimum of 8 and 30 respectively so if either stock are less than the minimum then no coffee can be ordered
            system(CLEAR);
            printf("Sorry! Machine is out of ingredients! please contact an admin for refill\n");
            fflush(stdout);
            sleep(1);
            printf("returning to main menu");
            fflush(stdout);
            usleep(500000);
            printf(".");
            fflush(stdout);
            usleep(500000);
            printf(".");
            fflush(stdout);
            usleep(500000);
            printf(".");
            fflush(stdout);
            usleep(500000);//does a loading effect
            system(CLEAR);
            return;
        }
    while(UserInput!=0){
        printf("---Coffee Machine---\n1. Espresso%-12.2fAED\n2. Cappuccino%-12.2fAED", EspressoPrice, CappuccinoPrice);//if the previous if statement did no trigger then there is no way there is not enough stock for espresso
        if(MilkStock<MilkCostCappuccino){//water and beans stock already checked in first if statement. if milk stock is less than cappuccino requirement, adds a N/A tag and updates CappuccinoAvailable variable
            printf(" (Unavailable due to temporarily insufficient ingredients)");
            CappuccinoAvailable = 0;
        }
        printf("\n3. Mocha%-12.2fAED", MochaPrice);
        if(WaterStock<WaterCostMocha || MilkStock<MilkCostMocha || ChocolateSyrupStock<ChocolateSyrupCostMocha){// if any ingredient stock is less than mocha requirements, adds a N/A tag and updates MochaAvailable variable
            printf(" (Unavailable due to temporarily insufficient ingredients)");
            MochaAvailable = 0;
        }
        printf("\n0. back\nPlease enter the number corrisponding with the desired option: ");
        scanf("%d", &UserInput);
        system(CLEAR);
        switch(UserInput){
            case 1:
                printf("Selected: Espresso\nPrice:%-12.2fAED", EspressoPrice);
                break;
            case 2:
                printf("Selected: Cappuccino\nPrice:%-12.2fAED", CappuccinoPrice);
                break;
            case 3:
                printf("Selected: Mocha\nPrice:%-12.2fAED", MochaPrice);
                break;
            case 0:
                printf("return to main menu?");
                break;
            default:
                usleep(200000);
                printf("INVALID INPUT!! please try again\n\n");
        }
        while(1){
            printf("\nconfirm(1) cancel(0): ");
            scanf("%d", &confirm);
            if(confirm!=1 && confirm!=0){
                printf("\n\nINVALID INPUT!! please try again\n");
            }
            else{
                break;
            }
        }
        if(confirm==0){
            UserInput = 9;
            system(CLEAR);
            continue;
        }
        system(CLEAR);
        if(UserInput==1){
            EspressoOrder();
            price = EspressoPrice;
        }
        else if(UserInput==2 && CappuccinoAvailable){
            CappuccinoOrder();
            price = CappuccinoPrice;
        }
        else if(UserInput==3 && MochaAvailable){
            MochaOrder();
            price = MochaPrice;
        }
        else if(UserInput==0){
            break;
        }
        else{
            printf("SELECTION NOT AVAILABLE!! please try again\n");
            continue;
        }
        while(price>0){
            printf("Outstanding Balance:%-12.2fAED\nPlease insert 1 or 0.5 to pay: ", price);
            scanf("%f", &payment);
            if(payment==1){
                price -= payment;
                revenue += payment;
            }
            else if(payment==0.5){
                price -= payment;
                revenue += payment;
            }
            else{
                printf("\n\nPlease use one of the accepted currency values listed!\nInserted currency has been returned in the change tray!");
            }
            printf("\n\n");
        }
        if(price<-0.001){//since price is a float there is a chance it becomes 0.00001 when its supposed to be 0 so just for safe measure 0.001 is used for logic instead of 0
            refund = 0-price;
            switch (UserInput){
                case 1:
                    printf("Your order:\ncoffee: Espresso\nPrice:%-12.2fAED\nPayment:%-12.2fAED", EspressoPrice, (EspressoPrice+refund));
                    break;
                case 2:
                    printf("Your order:\ncoffee: Cappuccino\nPrice:%-12.2fAED\nPayment:%-12.2fAED", CappuccinoPrice, (CappuccinoPrice+refund));
                    break;
                case 3:
                    printf("Your order:\ncoffee: Mocha\nPrice:%-12.2fAED\nPayment:%-12.2fAED", MochaPrice, (MochaPrice+refund));
                    break;
            }
            printf("\nplease pick up your change from the change tray:%-12.2fAED", refund);
            revenue -= refund;
            price = 0;
        }
        else{
            switch (UserInput){
                case 1:
                    printf("Your order:\ncoffee: Espresso\nPrice:%-12.2fAED\nPayment:%-12.2fAED", EspressoPrice, EspressoPrice);
                    break;
                case 2:
                    printf("Your order:\ncoffee: Cappuccino\nPrice:%-12.2fAED\nPayment:%-12.2fAED", CappuccinoPrice, CappuccinoPrice);
                    break;
                case 3:
                    printf("Your order:\ncoffee: Mocha\nPrice:%-12.2fAED\nPayment:%-12.2fAED", MochaPrice, MochaPrice);
                    break;
            }
        }
        printf("\nThank you for your patronage :)");
        fflush(stdout);
        sleep(5);
        system(CLEAR);
        if(CoffeeBeanStock<=CoffeeBeanThreshold){
            printf("Machine is running low on coffee beans. Please contact admin for refill!\n\n");
        }
        if(WaterStock<=WaterThreshold){
            printf("Machine is running low on water. Please contact admin for refill!\n\n");
        }
        if(MilkStock<=MilkThreshold){
            printf("Machine is running low on milk. Please contact admin for refill!\n\n");
        }
        if(ChocolateSyrupStock<=ChocolateSyrupThreshold){
            printf("Machine is running low on chocolate syrup. Please contact admin for refill!\n\n");
        }
    }
}

void GetValues(int a){
    UserInput = a;
    while(UserInput!=0){
        printf("Machine Stock:\nCoffee Beans:%-12d(grams)\nWater:%-12d(mL)\nMilk:%-12d(mL)\nChocolate Syrup:%-12d(mL)\n\nTotal Sale Amount:%-12.2fAED\n\nto reset Total Sales Amount enter 1 or to continue enter 0: ", CoffeeBeanStock, WaterStock, MilkStock, ChocolateSyrupStock, revenue);
        scanf("%d", &UserInput);
        switch(UserInput){
            case 1:
                revenue = 0;
                UserInput = 0;
                break;
            case 0:
                break;
            default:
                system(CLEAR);
                usleep(200000);
                printf("please choose a valid option!\n");
        }
    }
    system(CLEAR);
}

void restock(){
    srand(time(NULL));
    CoffeeBeanStock = 1000+rand() % (5000-1000+1);//generates a random number with a lower bound of 1000 and an upper bound of 5000
    WaterStock = 1000+rand() % (5000-1000+1);
    MilkStock = 1000+rand() % (5000-1000+1);
    ChocolateSyrupStock = 1000+rand() % (5000-1000+1);
    printf("Ingredients restocked");
    fflush(stdout);
    sleep(2);
    system(CLEAR);
}

void SetPrice(int a){
    UserInput = a;
    float newprice = 0.0;
    while(UserInput!=0){
        system(CLEAR);
        printf("1. Espresso\n2. Cappuccino\n3. Mocha\nselect coffee to modify price or 0 to exit: ");
        scanf("%d", &UserInput);
        printf("\n");
        switch(UserInput){
            case 1:
                printf("current Espresso price:%-12.2f\nNew Espresso price: ", EspressoPrice);
                scanf("%f", &newprice);
                EspressoPrice = newprice;
                printf("\n\nPrice Modified Successfully!\n");
                fflush(stdout);
                sleep(2);
                break;
            case 2:
                printf("current Cappuccino price:%-12.2f\nNew Cappuccino price: ", CappuccinoPrice);
                scanf("%f", &newprice);
                CappuccinoPrice = newprice;
                printf("\n\nPrice Modified Successfully!");
                fflush(stdout);
                sleep(2);
                break;
            case 3:
                printf("current Mocha price:%-12.2f\nNew Mocha price: ", MochaPrice);
                scanf("%f", &newprice);
                MochaPrice = newprice;
                printf("\n\nPrice Modified Successfully!");
                fflush(stdout);
                sleep(2);
                break;
            case 0:
                break;
            default:
                system(CLEAR);
                usleep(100000);
                printf("ERROR! please make a valid selection!");
                fflush(stdout);
                sleep(1);
                continue;
        }

    }
    system(CLEAR);
}    

void NewPassword(){
    int password, passwordconfirm;
    system(CLEAR);
    printf("Password Rules:\n1. Only numbers\n2. No letters\n3. No special characters\n4. No white spaces\n5. No decimals\n\nNew Password: ");
    scanf("%d", &password);
    printf("\nConfirm Password: ");
    scanf("%d", &passwordconfirm);
    if(password==passwordconfirm){
        AdminPassword = password;
        printf("\n\nPassWord Changed!");
    }
    else{
        printf("\n\nPassword Confirmation Failed!");
    }
    printf("\nreturning to admin menu");
    fflush(stdout);
    usleep(300000);
    printf(".");
    fflush(stdout);
    usleep(300000);
    printf(".");
    fflush(stdout);
    usleep(300000);
    printf(".");
    fflush(stdout);
    usleep(200000);
    system(CLEAR);
}

void admin(){
    int tries = 3;
    while(tries>0){
        printf("remaining tries:%-12d\nAdmin Password: ", tries);
        scanf("%d", &UserInput);
        if(UserInput==AdminPassword){
            break;
        }
        else{
            system(CLEAR);
            usleep(200000);
            printf("Password Incorrect!\n");
            fflush(stdout);
            usleep(200000);
        }
        tries--;
    }
    system(CLEAR);
    if(tries==0){
        printf("Access Denied");
        fflush(stdout);
        usleep(500000);
        printf(".");
        fflush(stdout);
        usleep(500000);
        printf(".");
        fflush(stdout);
        usleep(500000);
        printf(".");
        fflush(stdout);
        usleep(500000);
        system(CLEAR);
        return;
    }
    int AdminMode = 1;
    while(AdminMode){
        printf("1. Display the quantity of each ingredient in the machine and the total sale amount\n2. Replenish ingredients in the machine\n3. Change coffee price\n4. Change admin password\n0. Exit the Admin Mode function\nselection: ");
        scanf("%d", &UserInput);
        system(CLEAR);
        switch (UserInput){
            case 1:
                GetValues(UserInput);
                break;
            case 2:
                restock();
                break;
            case 3:
                SetPrice(UserInput);
                 break;
            case 4:
                NewPassword();
                break;
            case 0:
                AdminMode = 0;
                break;
            default:
                printf("please choose a valid option!");
        }
        
        
    }
}

int main() {
    int loop = 1;
    while (loop){//a while loop to allow for an infinite loop
        printf("Welcome to the automatic coffee server system:\n1. Order a coffee\n2. System admin mode\n0. System shutdown\nplease enter the number corrisponding with the desired action: ");
        scanf("%d", &UserInput);
        switch(UserInput){
            case 1:
                system(CLEAR);
                coffee(UserInput);
                break;
            case 2:
                system(CLEAR);
                admin();
                break;
            case 0:
                system(CLEAR);//added beacuse i thought the console looked too crouded with all old prompts and inputs present
                printf("WARNING!!! ALL SYSTEM INFORMATION WILL EXPERIENCE A FULL RESET!\nARE YOU SURE YOU WANT TO SHUTDOWN? yes(1)/no(0): ");
                scanf("%d", &UserInput);
                switch(UserInput){
                    case 1:
                        loop = 0;
                        break;
                    case 0:
                        break;
                    default:
                        system(CLEAR);
                        printf("Invalid Input! Returning to Main Menu");
                        fflush(stdout);
                        usleep(300000);
                        printf(".");
                        fflush(stdout);
                        usleep(300000);
                        printf(".");
                        fflush(stdout);
                        usleep(300000);
                        printf(".");
                        fflush(stdout);
                        usleep(200000);
                        system(CLEAR);
                }
                break;
            default:
                system(CLEAR);
                usleep(200000);//added because consecutive invalid inputs looked like the system was not responding
                printf("ERROR! PLEASE MAKE A VALID SELECTION!\n\n");
                fflush(stdout);
                usleep(100000);
                continue;
        }
    }

    return 0;
}
