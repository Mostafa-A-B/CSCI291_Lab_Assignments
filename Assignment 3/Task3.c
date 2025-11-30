#include <stdio.h>
#include <ctype.h>
#include <string.h>


int isValidName(const char *name) {
    if (strlen(name) == 0) return 0;

    for (int i = 0; name[i] != '\0'; i++) {
        if (!isprint(name[i])) return 0;//must be printable
        if (isdigit(name[i])) return 0;//no digits allowed
    }
    return 1;
}

int isValidInteger(const char *num) {
    if (strlen(num) == 0) return 0;

    for (int i = 0; num[i] != '\0'; i++) {
        if (!isdigit(num[i])) return 0;
    }
    return 1;
}


int main() {
    FILE *fp = fopen("students.txt", "r");//file access
    if (!fp) {
        printf("file access failed!\n");
        return 1;
    }//file not found error handling
    
    char line[50];
    int valid = 0, corrupted = 0;
    int totalMarks = 0;
    
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        char name[25], markStr[5];
        
        //parses two tokens: name and mark
        if (sscanf(line, "%24s %4s", name, markStr) != 2) {
            corrupted++;
            continue;
        }
        
        //validates both fields
        if (!isValidName(name) || !isValidInteger(markStr)) {
            corrupted++;
            continue;
        }
        
        //converts mark from string to integer
        int mark;
        sscanf(markStr, "%d", &mark);
        
        //prints valid record
        printf("name: %-10s  mark: %d\n", name, mark);
        
        totalMarks += mark;
        valid++;
    }
    
    printf("\ntotal valid records: %d\n", valid);
    printf("total corrupted records: %d\n", corrupted);
    
    if (valid > 0) {
        printf("mean average mark of valid records: %.2f\n", 
               (float)totalMarks / valid);
    } else {
        printf("Average mark: N/A (no valid records)\n");
    }
    
    fclose(fp);
    return 0;
}
