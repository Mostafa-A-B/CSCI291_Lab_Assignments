#include <stdio.h>


void print(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}//function to print array elements

void ReorganizeIterative(int arr[], int n){
    int odd=0, OddArr[n], even=0, EvenArr[n];
    for(int i=0; i<n; i++){
        if(arr[i]%2==0)
            EvenArr[even++] = arr[i];
        else
            OddArr[odd++] = arr[i];
    }//loops through array and seperates odd elements into OddArr and even elements into EvenArr
    
    for(int i=0; i<odd; i++)//inserts odd elements into the original array from 0 till number of odd elements
        arr[i] = OddArr[i];
    for(int i=0; i<even; i++)// inserts even elements into the original array from after the last odd element
        arr[i+odd] = EvenArr[i];
}


int even, odd, i, start=0;//because c doesn't support default argument values
void ReorganizeRecursive(int arr[], int n, int sorted[]){
    if (start==0){
        even = n-1;
        odd = 0;
        i = 0;
        start++;
    }//sets the initial values of the required variables and increments start to avoid infinite recursive loop
    
    if(i<n){
        if(arr[i]%2==0){//recursively loops through array elements then sends even numbers to the back of the sorted array and odd numbers to the start of sorted array
            sorted[even--] = arr[i++];
        } else{
            sorted[odd++] = arr[i++];
        }
        ReorganizeRecursive(arr, n, sorted);
    } else{
        start=0;
    }//sets start to 0 for the next time function is called
}






int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, arr2[] = {123, 342, 543, 543, 65, 76, 23, 5, 5678, 63}, NewArr2[10];
    
    printf("Array 1 before iterative: ");
    print(arr1, 10);//prints array elements
    ReorganizeIterative(arr1, 10);//calls iterative function
    printf("Array 1 after iterative: ");
    print(arr1, 10);
    
    
    printf("\nArray 2 before recursive: ");
    print(arr2, 10);
    ReorganizeRecursive(arr2, 10, NewArr2);//calls recursive function
    printf("Array 2 after recursive: ");
    print(NewArr2, 10);
    
    
    
    return 0;
}
