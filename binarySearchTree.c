#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int arr[100],temp;

    srand(time(NULL));

    for (int i = 0 ; i < 100; i++){
        arr[i] = (rand() % 100) + 1;

        for (int j = 0 ; j < i ; j++){
            if (arr[i] == arr[j]){
                i--;
                break;
            }
        }
    }

    for (int i = 0 ; i < 100 ; i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
    
    int tmp = 0, tmp1 = 0;

    while(1){
        printf("1. 검색, 2. 삭제, 3. 종료 : ");
        scanf("%d",&tmp);
        // Node *root = NULL;

        while (1){
            if (tmp == 1){
                printf("검색할 숫자를 입력해주세요. : ");
                scanf("%d",&tmp1);
                
                root = BST_search(root, tmp1);
                if (root == NULL){
                    printf("검색한 숫자가 없습니다.처음으로 돌아갑니다.\n");
                    break;
                }
                else {
                    printf("해당 부모부터 탐색한 결과값 \n: ");
                    BST_print(root);
                    printf("\n");
                    break;
                }
            }

            else if  (tmp == 2){
                printf("입력한 숫자들 중 삭제할 숫자를 입력해주세요. : ");
                scanf("%d",&temp);
                root = BST_delete(root, temp);
                break;
            }

            else if (tmp == 3){
                printf("프로그램을 종료합니다.\n");
                exit(1);
            }

            else {
                printf("숫자를 잘 못 입력하셨습니다. 처음으로 돌아갑니다.\n");
                break;
            }
        }
    }
}