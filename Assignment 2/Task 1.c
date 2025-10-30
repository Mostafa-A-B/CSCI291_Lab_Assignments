#include <stdio.h>
#include <stdbool.h>


void DispArr(int arr[], int arrLen){
    printf("Array Contents:\n");
    for(int i=0; i<arrLen; i++){
        printf("Array[%d] = %d\n", i, arr[i]);
    }
}

void SetArray(int arr[], int arrLen){
    for(int i=0; i<arrLen; i++){
        arr[i]=i;
    }
}

void RemAlign(int arr[], int arrLen, int index){
    for(index;index<arrLen-1;index++){
        arr[index] = arr[index+1];
    }
}

void InsertAlign(int arr[], int arrLen, int index, int element){
    for(int i = arrLen-1; i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=element;
}

void reshape(int arr[], int arrLen, int R, int C, int arr2d[R][C]){
    if(arrLen==(R*C)){
        for(int r = 0; r<=R; r++){
            for(int c = 0; c<=C; c++){
                arr[(r*C)+c] = arr2d[r][c];
            }
        }
    }
    else{
        printf("\n\nGIVEN 1D ARRAY SIZE IS NOT EQUAL TO NUMBER OF 2D ARRAY ELEMENTS\n\n");
    }
}

void PrintTransMatrix(int R, int C, int arr[R][C]){
    for(int c=0; c<=c; c++){
        printf("column[%s]:", c);
        for(int r=0;r<=R; r++){
            printf("%s, ", arr[r][c]);
        }
        printf("\n");
    }
}

bool FoundDuplicate(int arr[], int arrLen){
    bool dupe = false;
    for(int i=0; i<arrLen-1; i++){
        for(int x=i+1; x<arrLen; x++){
            if(arr[i]==arr[x]){
                dupe = true;
                break;
            }
        }
        if(dupe)
        break;
    }
    return dupe;
}

int* FlipArray(int arr[], int arrLen){
    int farray[arrLen];
    int f=0;
    for(int i=arrLen-1; i>=0; i++){
        farray[f] = arr[i];
        f++;
    }
    return farray;
}




int main()
{
    int array1[] = {1,2,3,4,5,6,7,8,9};
    int array2[] = {2,3,4,5,6,7,8,9};
    int array3[] = {3,4,5,6,7,8,9};
    int array4[] = {4,5,6,7,8,9};
    /*printf("before and after SetArray function:\n");
    DispArr(array1);
    SetArray(array1);
    DispArr(array1);
    
    printf("\nbefore and after RemAlign(index 3):\n");
    DispArr(array2);
    RemAlign(array2, 3);
    DispArr(array2);
    
    printf("\nbefore and after InsertAlign(index 4, value 12):");
    DispArr(array3);
    InsertAlign(array3, 4, 12);
    DispArr(array3);
    
    printf("\nbefore and after FlipArray:\n");
    DispArr(array4);
    farray4 = FlipArray(array4);
    DispArr(farray4);
    */
    int array2d[][] = ((1,2,3),(4,5,6),(7,8,9));
    int longarray[9];
    //printf("before and after reshape")
    printf(array1);
    printf("\n\n");
    printf(array2d);
    
    
    return 0;
}






