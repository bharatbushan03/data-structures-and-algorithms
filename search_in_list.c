#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void Insert(int* arr,int n,int* size){
    if(n == *size) return;
    else{
        scanf("%d",&arr[*size]);
        (*size)++;
    }
}
void Check(int* arr,int* size,int tar){
    for(int i=0;i<*size;i++){
        if(arr[i] == tar){
            printf("Found\n");
            return;
        }
    }
    
    printf("Not Found\n");
}
int main() {
    int n;
    scanf("%d",&n);
    
    int size = 0;
    int arr[n];
    for(int i=0;i<n;i++) Insert(arr,n,&size);
    
    int tar;
    scanf("%d",&tar);
    Check(arr,&size,tar);
    return 0;
}