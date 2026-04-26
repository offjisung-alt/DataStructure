#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

int main(void)
{
    Node * head = NULL;
    Node * tail = NULL;
    Node * cur = NULL;

    Node * newNode = NULL;
    int readData;

    while(1)
    {
        printf("자연수 입력: ")
        scanf("%d", &readData);
        if(readData < 1)
            break;

        //노드 추가
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if(head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }
    printf("\n");


    //데이터 출력
    printf("데이텉 전체 출력\n");

    if(head==NULL)
    {
        printf("저장된 데이터 없음\n");
    }
    else
    {
        cur = head;
        while(cur != NULL)
        {
            printf("%d\n", cur->data);
            cur = cur->next;
        }
    }
    printf("\n\n");

    
    //메모리 해제
    if(head == NULL)
        return 0;
    else
    {
        Node * delNode = head;
        Node * delNextNode = head->next;

        printf("%d를 삭제합니다.\n", head->data);
        free(delNode);

        while(delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("%d를 삭제합니다.\n", delNode->data);
            free(delNode);
        }
    }

    return 0;

}