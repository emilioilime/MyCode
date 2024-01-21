//
//  main.cpp
//  sort
//
//  Created by Emilio-v on 2023/10/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sort_algorithm.hpp"
using namespace std;

void output_array(int  a[],int size){
    for(int i=0;i<size;i++)
    {
        std::cout<<a[i]<<' ';
    }
    std::cout<<'\n';
}
void InsertSort(int A[], int n) {
    int i, j;
    for (i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) { // 如果当前元素比前一个元素小
            A[0] = A[i]; // 将当前元素存储在哨兵 A[0] 中
            for (j = i - 1; A[0] < A[j]; j--) {
                A[j + 1] = A[j]; // 向后挪位，为插入元素腾出位置
            }
            A[j + 1] = A[0]; // 将 A[0] 复制到插入位置
        }
    }
}
void swaparr(int a[],int x,int y){
    int temp;
    temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}
void sortfrontback(int a[],int b){
    int i=1,j=5;//未排序在数组中的上下标范围
    //第一次排序从左到右将最大的放到最右边
    while(i<j)
    {
        for(int x=i;x<j;x++)//1到 4
        {
            if(a[x]>a[x+1])
                swaparr(a,x,x+1);
            
        }
        j--;//每次排序上标-1
        output_array(a,b);
        for(int y=j;y>i;y--)
        {
            if(a[y]<a[y-1])
                swaparr(a,y,y-1);
        }
        i++;//每次排序上标+1
        output_array(a,b);
    }
    
}

int main(int argc, const char * argv[]) {
    int a[6]={0,7,2,9,4,5};
    output_array(a,6);
    sortfrontback(a,6);
    
    return 0;
}
