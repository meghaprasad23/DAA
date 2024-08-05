#include<stdio.h>

int countingInversion(int arr[], int n){
    int count = 0;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(arr[i] > arr[j])
                count++;
    return count;
}

int main(){
    int n = 8;
    int user1[] = {3, 1, 4, 5, 2, 6, 8, 7};
    int user2[] = {8, 6, 4, 2, 1, 7, 5, 3};
    int user3[] = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("User 1 playlist inversion: %d\n",countingInversion(user1,n));
    printf("User 2 playlist inversion: %d\n",countingInversion(user2,n));
    printf("User 3 playlist inversion: %d\n",countingInversion(user3,n));

    return 0;
}
