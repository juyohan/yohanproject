#include <stdio.h>
#include <stdlib.h>

typedef struct NodeStruct
{
    int value; // 입력받은 값
    struct NodeStruct* leftChild; // 왼쪽자식 (부모보다 작음)
    struct NodeStruct* rightChild; // 오른쪽자식 (부모보다 큼)
}Node;

Node* root = NULL; // 초기화

Node* BST_insert(Node* root, int value) // 노드에 값을 추가
{
    if(root == NULL) // 부모노드가 없는 경우
    {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->value = value;
        return root;
    }
    else  // 부모노드가 있는 경우
    {
        if(root->value > value)
            root->leftChild = BST_insert(root->leftChild, value);
        else
            root->rightChild = BST_insert(root->rightChild, value);
    }
    return root;
}
Node* findMinNode(Node* root)
{
    Node* tmp = root;
    while(tmp->leftChild != NULL)
        tmp = tmp->leftChild;
    return tmp;
}
Node* BST_delete(Node* root, int value) // 해당 노드 삭제
{
    Node* tNode = NULL; // 초기화
    if(root == NULL) // 노드의 값이 없는 경우
        return NULL;

    if(root->value > value) 
        root->leftChild = BST_delete(root->leftChild, value);
    else if(root->value < value)
        root->rightChild = BST_delete(root->rightChild, value);
    else
    {
        // 자식 노드가 둘 다 있을 경우
        if(root->rightChild != NULL && root->leftChild != NULL)
        {
            tNode = findMinNode(root->rightChild);
            root->value = tNode->value;
            root->rightChild = BST_delete(root->rightChild, tNode->value);
        }
        else
        {
            tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
            free(root);
            return tNode;
        }
    }

    return root;
}
Node* BST_search(Node* root, int value)
{
    if(root == NULL)
        return NULL;

    if(root->value == value)
        return root;
    else if(root->value > value)
        return BST_search(root->leftChild, value);
    else
        return BST_search(root->rightChild, value);
}
void BST_print(Node* root)
{
    if(root == NULL)
        return;

    printf("%d ", root->value);
    BST_print(root->leftChild);
    BST_print(root->rightChild);
}

int main()
{
    int i = 0;
    int num[10],temp;
    printf("이진탐색트리에 넣을 숫자 10개를 입력해주세요. : ");
    while (i < 10){
        scanf("%d",&num[i]);
        root = BST_insert(root, num[i]);
        i++;
    }
    
    printf("입력한 숫자들 중 삭제할 숫자를 입력해주세요. : ");
    scanf("%d",&temp);
    root = BST_delete(root, temp);

    BST_print(root);
}