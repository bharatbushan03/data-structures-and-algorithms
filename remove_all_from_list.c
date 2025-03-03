#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
}
    int tar;
    scanf("%d",&tar);
    int x=n;
    while(x--){
        int i;
        for( i=0;i<n;i++){
            if(arr[i] == tar)
                break;
        }
        if(i == n) break;
        for(int j=i;j<n-1;j++) arr[j] = arr[j+1];
        n--;
    }
        for(int j=0;j<n;j++){
            printf("%d ",arr[j]);
        
        }
    return 0;
}
