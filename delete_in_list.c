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
void Del(int* arr,int* size,int tar){
    if((*size) == 0) return;
    int i;
    for(i=0;i<*size;i++) if(arr[i] == tar) break;
    if(i!= *size){
        for(int j=i;j<*size-1;j++) arr[j] = arr[j+1];
        (*size)--;
    }
}
void Display(int* arr,int* size){
    for(int i=0;i<*size;i++)
        printf("%d ",arr[i]);
}

int main() {
    int n;
    scanf("%d",&n);
    int size = 0;
    int arr[n];
    for(int i=0;i<n;i++) Insert(arr,n,&size);
    int tar;
    scanf("%d",&tar);
    Del(arr,&size,tar);
    Display(arr,&size);
    
    return 0;
}
