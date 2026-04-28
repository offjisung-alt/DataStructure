#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"


//큐 초기화
void QueueInit(Queue * pq)
{
    pq->front = 0;
    pq->rear = 0;
}


//큐가 비었는지
//rear가 한칸 뒤로 움직이고 그 공간에 데이터 저장. front = rear면 비었고 front = rear + 1이면 가득 참.
int QIsEmpty(Queue * pq)
{
    if(pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

//환형큐를 만들기 위한 다음 인덱스 받아오기
int NextPosIdx(int pos)
{
    if(pos == QUE_LEN - 1)
        return 0;
    else
        return pos + 1;
}


//데이터 삽입. rear + 1 한 곳에 저장
void Enqueue(Queue * pq, Data data)
{
    if(NextPosIdx(pq->rear) == pq->front)
    {
        printf("큐가 가득 참\n");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}


//데이터 삭제. front를 +1 시켜줌
Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("큐가 비었음\n");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

//데이터 보여주는 함수
Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("큐가 비었음\n");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)];
}