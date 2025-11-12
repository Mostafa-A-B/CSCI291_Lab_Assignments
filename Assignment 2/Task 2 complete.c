#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define NumOfSubjects 8
#define NumOfStudents 5
#ifdef _WIN32
#define strcasecmp _stricmp
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

typedef struct{
    char Fname[25], Lname[25], grade[10];
    int ID, FinalMark;
    float marks[NumOfSubjects];
}student;

void DispStudent(student *stu){
    printf("Student Details:\nFirst Name: %s\nLast Name: %s\nStudent ID: %d\nSubject Marks:\n", stu->Fname, stu->Lname, stu->ID);
    for(int i=0; i<NumOfSubjects; i++){
        switch(i){
            case 0:
            printf("  Math: ");
            break;
            case 1:
            printf("\n  English: ");
            break;
            case 2:
            printf("\n  History: ");
            break;
            case 3:
            printf("\n  Geography: ");
            break;
            case 4:
            printf("\n  Physics: ");
            break;
            case 5:
            printf("\n  Chemistry: ");
            break;
            case 6:
            printf("\n  Biology: ");
            break;
            case 7:
            printf("\n  Computer Science: ");
            break;
        }
        printf("%.2f", stu->marks[i]);
    }
    printf("\nAggregate Mark: %d\nGrade: %s", stu->FinalMark ,stu->grade);
}

void grading(student *stu){
    int final = stu->FinalMark;
    if(final>=85){
        strcpy(stu->grade, "HD");
    }else if(final>=75){
        strcpy(stu->grade, "D");
    }else if(final>=65){
        strcpy(stu->grade, "C");
    }else if(final>=50){
        strcpy(stu->grade, "P");
    }else if(final<50 && final>=0){
        strcpy(stu->grade, "F");
    }else if(final==-1){
        strcpy(stu->grade, "undefined");
    }
}

void aggregate(student *stu){
    int graded = 1;
    for(int i=0; i<NumOfSubjects; i++){
        if(stu->marks[i]==-1){
            graded = 0;
            break;
        }
    }
    if(graded){
        float final=0;
        for(int i=0; i<NumOfSubjects; i++){
            final+=stu->marks[i];
        }
        stu->FinalMark = (int)(final/NumOfSubjects);
    } else{
        stu->FinalMark = -1;
    }
    grading(stu);
}

void enroll(student arr[], int index){
    int c;
    system(CLEAR);
    printf("Enter Student ID: ");
    while(scanf("%d", &arr[index].ID)!=1){
        printf("\nInput Datatype Invalid!\nEnter Student ID: ");
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    printf("\nEnter Student First Name: ");
    scanf(" %24s", arr[index].Fname);
    printf("\nEnter Student Last Name: ");
    scanf(" %24s", arr[index].Lname);
    char choice[4];
    for(int i=0; i<NumOfSubjects; i++){
        switch(i){
            case 0:
            printf("\nEnter marks for Math? (Yes/No): ");
            break;
            case 1:
            printf("\nEnter marks for English? (Yes/No): ");
            break;
            case 2:
            printf("\nEnter marks for History? (Yes/No): ");
            break;
            case 3:
            printf("\nEnter marks for Geography? (Yes/No): ");
            break;
            case 4:
            printf("\nEnter marks for Physics? (Yes/No): ");
            break;
            case 5:
            printf("\nEnter marks for Chemistry? (Yes/No): ");
            break;
            case 6:
            printf("\nEnter marks for Biology? (Yes/No): ");
            break;
            case 7:
            printf("\nEnter marks for Computer Science? (Yes/No): ");
            break;
        }
        while(1){
            scanf(" %3s", choice);
            if(strcasecmp(choice, "yes")==0 || strcasecmp(choice, "y")==0){
                printf("\nMark: ");
                float temp;
                while(1){
                    if(scanf("%f", &temp)==1 && temp<=100 && temp>=-1){
                        arr[index].marks[i] = temp;
                        break;
                    }
                    printf("\n\nInput Invalid!\nMark: ");
                    while ((c = getchar()) != '\n' && c != EOF) { }
                }
                break;
            }
            else if(strcasecmp(choice, "no")==0 || strcasecmp(choice, "n")==0){
                arr[index].marks[i] = -1;
                break;
            }
            else{
                printf("\n\nInput Invalid!\n(Yes/No): ");
            }
        }
        
    }
    aggregate(&arr[index]);
    system(CLEAR);
}

void ModifyStudent(student *stu){
    char modify, fname[25], lname[25];
    int id, c;
    float mark;
    while(1){
        printf("\n\nStudent Found!\n\nmodify student first name? (y/n): ");
        scanf(" %c", &modify);
        if(modify == 'y' || modify == 'Y'){
            printf("New First Name: ");
            scanf(" %24s", fname);
            strcpy(stu->Fname, fname);
            break;
        }
        else if(modify == 'n' || modify == 'N')
            break;
        else
            printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
    }
    system(CLEAR);
    while(1){
        printf("\nmodify student last name? (y/n): ");
        scanf(" %c", &modify);
        if(modify == 'y' || modify == 'Y'){
            printf("New Last Name: ");
            scanf(" %24s", lname);
            strcpy(stu->Lname, lname);
            break;
        }
        else if(modify == 'n' || modify == 'N')
            break;
        else
            printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
    }
    system(CLEAR);
    while(1){
        printf("\nmodify student ID? (y/n): ");
        scanf(" %c", &modify);
        if(modify == 'y' || modify == 'Y'){
            printf("New ID: ");
            scanf("%d", &id);
            stu->ID = id;
            break;
        }
        else if(modify == 'n' || modify == 'N')
            break;
        else
            printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
    }
    system(CLEAR);
    while(1){
        printf("\nmodify student subject marks? (y/n): ");
        scanf(" %c", &modify);
        if(modify == 'y' || modify == 'Y'){
            while(1){
                printf("\nmodify Math mark? (y/n): ");
                scanf(" %c", &modify);
                if(modify=='y' || modify=='Y'){
                    printf("New Mark: ");
                    while(scanf("%f", &mark)!=1 || mark>100 || mark<-1){
                        printf("\n\nInput Invalid!\nNew Mark: ");
                        while ((c = getchar()) != '\n' && c != EOF) { }
                    }
                    stu->marks[0] = mark;
                    break;
                } else if(modify=='n' || modify=='N'){
                    break;
                } else{
                    printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
                }
            }
            while(1){
                printf("\nmodify English mark? (y/n): ");
                scanf(" %c", &modify);
                if(modify=='y' || modify=='Y'){
                    printf("New Mark: ");
                    while(scanf("%f", &mark)!=1 || mark>100 || mark<-1){
                        printf("\n\nInput Invalid!\nNew Mark: ");
                        while ((c = getchar()) != '\n' && c != EOF) { }
                    }
                    stu->marks[1] = mark;
                    break;
                } else if(modify=='n' || modify=='N'){
                    break;
                } else{
                    printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
                }
            }
            while(1){
                printf("\nmodify History mark? (y/n): ");
                scanf(" %c", &modify);
                if(modify=='y' || modify=='Y'){
                    printf("New Mark: ");
                    while(scanf("%f", &mark)!=1 || mark>100 || mark<-1){
                        printf("\n\nInput Invalid!\nNew Mark: ");
                        while ((c = getchar()) != '\n' && c != EOF) { }
                    }
                    stu->marks[2] = mark;
                    break;
                } else if(modify=='n' || modify=='N'){
                    break;
                } else{
                    printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
                }
            }
            while(1){
                printf("\nmodify Geography mark? (y/n): ");
                scanf(" %c", &modify);
                if(modify=='y' || modify=='Y'){
                    printf("New Mark: ");
                    while(scanf("%f", &mark)!=1 || mark>100 || mark<-1){
                        printf("\n\nInput Invalid!\nNew Mark: ");
                        while ((c = getchar()) != '\n' && c != EOF) { }
                    }
                    stu->marks[3] = mark;
                    break;
                } else if(modify=='n' || modify=='N'){
                    break;
                } else{
                    printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
                }
            }
            while(1){
                printf("\nmodify Physics mark? (y/n): ");
                scanf(" %c", &modify);
                if(modify=='y' || modify=='Y'){
                    printf("New Mark: ");
                    while(scanf("%f", &mark)!=1 || mark>100 || mark<-1){
                        printf("\n\nInput Invalid!\nNew Mark: ");
                        while ((c = getchar()) != '\n' && c != EOF) { }
                    }
                    stu->marks[4] = mark;
                    break;
                } else if(modify=='n' || modify=='N'){
                    break;
                } else{
                    printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
                }
            }
            while(1){
                printf("\nmodify Chemistry mark? (y/n): ");
                scanf(" %c", &modify);
                if(modify=='y' || modify=='Y'){
                    printf("New Mark: ");
                    while(scanf("%f", &mark)!=1 || mark>100 || mark<-1){
                        printf("\n\nInput Invalid!\nNew Mark: ");
                        while ((c = getchar()) != '\n' && c != EOF) { }
                    }
                    stu->marks[5] = mark;
                    break;
                } else if(modify=='n' || modify=='N'){
                    break;
                } else{
                    printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
                }
            }
            while(1){
                printf("\nmodify Biology mark? (y/n): ");
                scanf(" %c", &modify);
                if(modify=='y' || modify=='Y'){
                    printf("New Mark: ");
                    while(scanf("%f", &mark)!=1 || mark>100 || mark<-1){
                        printf("\n\nInput Invalid!\nNew Mark: ");
                        while ((c = getchar()) != '\n' && c != EOF) { }
                    }
                    stu->marks[6] = mark;
                    break;
                } else if(modify=='n' || modify=='N'){
                    break;
                } else{
                    printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
                }
            }
            while(1){
                printf("\nmodify Computer Science mark? (y/n): ");
                scanf(" %c", &modify);
                if(modify=='y' || modify=='Y'){
                    printf("New Mark: ");
                    while(scanf("%f", &mark)!=1 || mark>100 || mark<-1){
                        printf("\n\nInput Invalid!\nNew Mark: ");
                        while ((c = getchar()) != '\n' && c != EOF) { }
                    }
                    stu->marks[7] = mark;
                    break;
                } else if(modify=='n' || modify=='N'){
                    break;
                } else{
                    printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
                }
            }
            break;
        }
        else if(modify == 'n' || modify == 'N')
            break;
        else
            printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
    }
    aggregate(stu);
}

void SearchUpdate(student arr[], int enrolled){
    char SearchType;
    int i, NotFound=1;
    system(CLEAR);
    while(1){
        printf("Prefered Search Method:\nSearch by Last Name (n)\nSearch by Student ID number (i)\nSelect (n/i): ");
        scanf(" %c", &SearchType);
        if(SearchType == 'n' || SearchType == 'N' ||SearchType == 'i' || SearchType == 'I')
            break;
        else
            printf("\n\nError: Invalid Input\nPlease Enter a Valid Option!");
    }
    system(CLEAR);
    switch(SearchType){
        case 'N':
        case 'n':{
            char name[25];
            printf("Enter Student Surname: ");
            scanf(" %24s", name);
            for(i=0; i<enrolled; i++){
                if(strcasecmp(name, arr[i].Lname)==0){
                    DispStudent(&arr[i]);
                    NotFound=0;
                    break;
                }
            }
            if(NotFound){
                printf("\n\nunfound\nreturning to main menu");
                fflush(stdout);
                sleep(2);
            } else{
                ModifyStudent(&arr[i]);
            }
            break;
        }
        case 'I':
        case 'i':{
            int id;
            printf("Enter Student ID: ");
            while(scanf("%d", &id)!=1){
                printf("\n\nInput Datatype  Invalid!\nEnter Student ID: ");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) { }
            }
            for(i=0; i<enrolled; i++){
                if(arr[i].ID == id){
                    DispStudent(&arr[i]);
                    NotFound=0;
                    break;
                }
            }
            if(NotFound){
                printf("\n\nunfound\nreturning to main menu");
                fflush(stdout);
                sleep(2);
            } else{
                ModifyStudent(&arr[i]);
            }
            break;
        }
    }
    system(CLEAR);
}

void TopStudents(student arr[], int enrolled){
    system(CLEAR);
    int top = -1, c;
    for(int i=0; i<enrolled; i++){
        if(arr[i].FinalMark>top){
            top = arr[i].FinalMark;
        }
    }
    printf("Top Students:");
    for(int i=0; i<enrolled; i++){
        if(arr[i].FinalMark==top){
            printf("\n  ");
            DispStudent(&arr[i]);
            puts("");
        }
    }
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("\n\nPress ENTER to Continue!");
    getchar();
    system(CLEAR);
}



int main(){
    int enrolled = 0;
    student registry[NumOfStudents];
    int input = -1, c;
    while(input!=0){
        printf("1. Enroll a student\n2. SearchUpdate\n3. Top Students\n0. Quit\nSelect (1/2/3/0): ");
        scanf("%d", &input);
        switch(input){
            case 0:
                break;
            case 1:
                if(enrolled<NumOfStudents){
                    enroll(registry, enrolled);
                    enrolled++;
                } else{
                    system(CLEAR);
                    usleep(250000);
                    printf("Registry Database Full!\nUnable to Enroll New Students\n\n");
                }
                break;
            case 2:
                if(enrolled>0)
                    SearchUpdate(registry, enrolled);
                else{
                    system(CLEAR);
                    printf("No Enrolled Students in Registry\n");
                }
                break;
            case 3:
                if(enrolled>0)
                    TopStudents(registry, enrolled);
                else{
                    system(CLEAR);
                    printf("No Enrolled Students in Registry\n");
                }
                break;
            default:
                system(CLEAR);
                usleep(250000);
                printf("Invalid Input!\n\n");
                break;
        }
        if(input==0)
            break;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    
    
    
    
    
    return 0;
}

