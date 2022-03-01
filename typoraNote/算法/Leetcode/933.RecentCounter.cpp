#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 20

//循环队列的结构
typedef struct {
    int* Data;
    int Front;
    int Rear;
    int MaxSize;  //队列最大容量
} RecentCounter;

//循环队列的初始化
RecentCounter* recentCounterCreate() {
    RecentCounter* obj=(RecentCounter*)malloc(sizeof(RecentCounter));
    obj->Data=(int*)malloc(MAXSIZE*sizeof(int));
    obj->Front=0;
    obj->Rear=0;
    obj->MaxSize=MAXSIZE;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {

    obj->Data[obj->Rear++]=t;
    //压缩区间
    while(obj->Data[obj->Front]<t-3000)
    {
       obj->Front++;
    }
    return (obj->Rear)-(obj->Front);
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
    obj=NULL;
}
int main()
{
	return 0;
}

