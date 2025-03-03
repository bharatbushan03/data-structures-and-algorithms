#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void Insert(int* arr,int n,int* size){
    if(n==*size)
        return;
    else{
            int a;
            scanf("%d",&a);
            arr[*size] = a;
            (*size)++;
        }
}
void Display(int* arr,int size){
    for(int i=0;i<size;i++) printf("%d ",arr[i]);
    
}

int main() {
    int n;
    scanf("%d",&n);
    int size=0;
    int arr[n];
    for(int i=0;i<n;i++) Insert(arr,n,&size);
    Display(arr,size);
    
    return 0;
}