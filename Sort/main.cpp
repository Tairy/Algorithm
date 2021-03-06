#include <iostream>

#define MAXSIZE 10

using namespace std;

typedef struct{
    int r[MAXSIZE+1];
    int length;
}SqList;

void swap(SqList *L, int i, int j){
    int temp = L -> r[i];
    L -> r[i] = L -> r[j];
    L -> r[j] = temp;
}

/*冒泡排序*/
void BubbleSort0(SqList *L){
    int i, j;
    for(i = 1; i < L->length; i++){
        for(j = 0;j < L->length; j++){
            if(L ->r[i] < L->r[j]){
                swap(L, i, j);
            }
        }
    }
}

void BubbleSort1(SqList *L){
    int i, j;
    for(i = 1; i < L->length; i++){
        for(j = L -> length-1; j >= i; j--){
            if(L -> r[j] > L -> r[j+1]){
                swap(L,j,j+1);
            }
        }
    }
}

void BubbleSort2(SqList *L){
    int i,j;
    bool flag = true;
    for(i = 1; i < L->length && flag; i++){
        flag = false;
        for(j = L -> length-1; j >= i; j--){
            if(L -> r[j] > L -> r[j+1]){
                swap(L,j,j+1);
                flag = true;
            }
        }
    }
}

/*选择排序*/
void SelectSort1(SqList *L){
    int i, j, min;
    for(i = 1; i < L -> length; i++){
        min = i;
        for(j = i+1;j < L -> length;j++){
            if(L->r[min]>L->r[j]){
                min = j;
            }
        }
        if(min!=i){
            swap(L,i,min);
        }
    }
}

/*插入排序 未完成*/

void InsertSort0(SqList *L){
    int i, j;
    for(i = 1; i < L -> length; i++){
        for(j = i+1; j < L -> length; j++){
            if(L -> r[i] < L -> r[j]){
                swap(L,i,j);
            }
        }
    }
}

void InsertSort1(SqList *L){
    int i,j;
    for(i=2;i<L->length;i++){
        if(L->r[i]<L->r[i-1]){
            L->r[0]=L->r[i];
            for(j=i-1;L->r[j]>L->r[0];j--){
                L->r[j+1]=L->r[j];
            }
            L->r[j+1]=L->r[0];
        }
    }
}

void InsertSort2(SqList *L){

}

/*快速排序*/

int Partition(SqList *L, int low, int high){
    int pivotkey;
    pivotkey=L->r[low];
    while(low<high){
        while(low<high&&L->r[high]>=pivotkey)
            high--;
        swap(L,low,high);
        while(low<high&&L->r[low]<=pivotkey)
            low++;
        swap(L,low,high);
    }

    return low;
}

void QSort(SqList *L, int low, int high){
    int pivot;
    if(low<high){
        pivot=Partition(L,low,high);

        QSort(L,low,pivot-1);
        QSort(L,pivot+1,high);
    }
}

void QuickSort(SqList *L){
    QSort(L,1,L->length);
}

int main()
{
    int a[11] = {0,3,2,5,4,6,1,7,9,8};
    SqList L;
    for(int t = 0; t < 11; t++){
       L.r[t] = a[t];
    }
    L.length = 11;
    InsertSort1(&L);
    for(int i = 0; i < L.length; i++){
        cout<<L.r[i]<<endl;
    }
    return 0;
}
