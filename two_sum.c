#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void Insert(int* arr,int n,int* size){
    if(*size == n) return;
    else{
        scanf("%d",&arr[*size]);
        (*size)++;
    }
}
void Find(int* arr,int* size,int tar,int* sum) {
    for(int i=0;i<*size;i++){
        for(int j=0;j<i;j++){
            if(arr[i]+arr[j] == tar){
                sum[0] = j;
                sum[1] = i;
                return;
            }
        }
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int arr[n];
    int size=0;
    for(int i=0;i<n;i++) Insert(arr,n,&size);
    int sum[2]={};
    int tar;
    scanf("%d",&tar);
    Find(arr,&size,tar,sum);
    printf("%d %d ",sum[0],sum[1]);
    return 0;
}
