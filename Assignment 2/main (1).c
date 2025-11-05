#include <stdio.h>
#include <stdbool.h>
#define SIZE 24
#define nRows 8
#define nCols 3


void DispArr(int arr[], int arrLen){
    printf("\nArray Contents:\n");
    for(int i=0; i<arrLen; i++){
        printf("Array[%d] = %d\n", i, arr[i]);
    }
}//outputs array contents to console. each element on a new line

void SetArray(int arr[], int arrLen){
    for(int i=0; i<arrLen; i++){
        arr[i]=i;
    }//loops through array elements and sets their value to the current index
}//sets every element in the array to the value of its index

void RemAlign(int arr[], int arrLen, int index){
    for(index;index<arrLen-1;index++){
        arr[index] = arr[index+1];
    }
}//moves all elements after the index to end back by one index(last element remains the same)

void InsertAlign(int arr[], int arrLen, int index, int element){
    for(int i = arrLen-1; i>index;i--){
        arr[i]=arr[i-1];
    }//moves all elements(from end to index) down by one
    arr[index]=element;//inputs element at index
}//inserts input element at input index and moves all from the index forward by one(last element is overwritten)

void reshape(int arr[], int arrLen, int R, int C, int arr2d[R][C]){
    if(arrLen==(R*C)){
        for(int i=0; i<arrLen; i++){
            arr2d[i/C][i%C] = arr[i];
        }//loops through 1d array elements and assigns each one to its respective place in the 2d array
    }
    else{
        printf("\n\nGIVEN 1D ARRAY SIZE IS NOT EQUAL TO NUMBER OF 2D ARRAY ELEMENTS\n\n");
    }//if else statement to make sure all elements from 1d array can be transfered to 2d array
}

void DispMatrix(int R, int C, int arr[R][C]){
    printf("\n2D Array:\n");
    for(int c=0; c<C; c++){
        printf("column[%d]:", c);
        for(int r=0;r<R; r++){
            if(r!=R-1)
            printf("%d, ", arr[r][c]);
            else if(r==R-1)
            printf("%d", arr[r][c]);
        }
        printf("\n");
    }
}//loops through each collumn of 2d array and outputs the values in that column row by row

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
}//loops through array untill the second last element while checking every subsequent element against current element, breaks on duplicate. returns true if duplicate was found and false if not

void FlipArray(int arr[], int arrLen, int farray[]){
    int f=0;
    for(int i=arrLen-1; i>=0; i--){
        farray[f] = arr[i];
        f++;
    }
}//loops backwards through 1d array and assigns the values to the flipped 1d array. assuming size of array 1 is less than or equal to array 2




int main(){
    int array1[] = {1,2,3,4,5,6,7,8,9};
    int array2[] = {2,3,4,5,6,7,8,9};
    int array3[] = {3,4,5,6,7,8,9};
    int array4[] = {4,5,6,7,8,9};
    printf("before and after SetArray function:");
    DispArr(array1, 9);
    SetArray(array1, 9);
    DispArr(array1, 9);
    
    printf("\n\nbefore and after RemAlign(index 3):");
    DispArr(array2, 8);
    RemAlign(array2, 8, 3);
    DispArr(array2, 8);
    
    printf("\n\nbefore and after InsertAlign(index 4, value 12):");
    DispArr(array3, 7);
    InsertAlign(array3, 7, 4, 12);
    DispArr(array3, 7);
    
    printf("\nbefore and after FlipArray:");
    DispArr(array4, 6);
    int farray4[6];
    FlipArray(array4, 6, farray4);
    DispArr(farray4, 6);
    
    int array2d[nRows][nCols];
    int longarray[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    printf("\n\nbefore and after reshape:");
    DispArr(longarray, SIZE);
    DispMatrix(nRows, nCols, array2d);
    reshape(longarray, SIZE, nRows, nCols, array2d);
    DispArr(longarray, SIZE);
    DispMatrix(nRows, nCols, array2d);
    
    
    return 0;
}//main






