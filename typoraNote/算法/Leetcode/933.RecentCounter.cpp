#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 20

//ѭ�����еĽṹ
typedef struct {
    int* Data;
    int Front;
    int Rear;
    int MaxSize;  //�����������
} RecentCounter;

//ѭ�����еĳ�ʼ��
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
    //ѹ������
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

