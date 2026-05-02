#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data)
{
    BTreeNode * pNode = NULL; // 부모 노드
    BTreeNode * cNode = *pRoot; // 현재 노드
    BTreeNode * nNode = NULL; // 새로운 노드

    while(cNode != NULL)
    {
        if(data == GetData(cNode))
            return;

        pNode = cNode;
        
        if (GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    nNode = MakeBTreeNode();
    SetData(nNode, data);

    if(pNode != NULL)
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else
    {
        *pRoot = nNode;
    }
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst;
    BSTData cd;

    while(cNode != NULL)
    {
        cd = GetData(cNode);

        if(target == cd)
            return cNode;
        else if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);
{
    //삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다
    BTreeNode * pVRoot = MakeBTreeNode();
    BTreeNode * pNode = pVRoot;
    BTreeNode * cNode = *pRoot;
    BTreeNode * dNode; 
    
    // 루트 노드를 pVRoot의 오른쪽 자식이 되도록 한다
    ChangeRightSubTree(pVRoot, *pRoot);

    //삭제 대상인 노드를 탐색
    while(cNode != NULL && GetData(cNode) != target)
    {
       pNode = cNode;
       
        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode); 
    }

    if(cNode == NULL)
        return NULL;

    dNode = cNode;

    //삭제 첫 케이스: 삭제 대상이 단말 노드인 경우
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }

    //삭제 두 번째 케이스: 삭제 대상의 자식노드가 하나일 때
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode * dcNode;

        // 삭제할 노드의 자식노드 찾기
        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);

        // 삭제할 노드의 부모노드와 삭제할 노드의 자식노드를 연결
        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);   
    }

    //삭제 세 번째 케이스: 삭제 대상의 자식노드가 두 개인 경우
    else
    {
        BTreeNode * mNode = GetRightSubTree(dNode); // 대체 노드 가리킴
        BTreeNode * mpNode = dNode; 
        int delData;

        //대체 노드 찾는 과정
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        // 대체 노드에 저장된 값을 삭제할 노드에 대입
        delData = GetData(dNode); // 대체 노드의 데이터 보관
        SetData(dNode, GetData(mNode)); // 대체 노드의 데이터를 삭제할 노드에 대입

        if(GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode,GetRightSUbTree(mNode));

        dNode = mNode;
        SetData(dNode, delData);
    }

    // 삭제된 노드가 루트 노드인 경우
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);

    free(pVRoot);
    return dNode;
}

void ShowIntData(int data)
{
    printf("%d ", data);
}

void BSTShowAll(BTreeNode * bst)
{
    InorderTraverse(bst, ShowIntData);
}