#include<iostream>
#include<stdlib.h>

using namespace std;

#define TREELEN 6

struct NODE {
    NODE *pLeft;
    NODE *pRight;
    char chValue;
};

void ReBuild(char *pPreOrder, char *pInOrder, int nTreeLen, NODE **pRoot) {
    if (pPreOrder == NULL || pInOrder == NULL)
        return;

    NODE *pTemp = new NODE;
    pTemp->chValue = *pPreOrder;
    pTemp->pLeft = NULL;
    pTemp->pRight = NULL;

    if (*pRoot == NULL)
        *pRoot = pTemp;

    if (nTreeLen == 1)
        return;

    char *pOrgInOrder = pInOrder;
    char *pLeftEnd = pInOrder;
    int nTempLen = 0;

    while (*pLeftEnd != *pPreOrder) {
        if (pPreOrder == NULL || pLeftEnd == NULL)
            return;

        nTempLen++;

        if (nTempLen > nTreeLen)
            break;

        pLeftEnd++;
    }

    int nLeftLen = 0;
    nLeftLen = (int)(pLeftEnd - pOrgInOrder);

    int nRightLen = 0;
    nRightLen = nTreeLen - nLeftLen - 1;

    if (nLeftLen > 0)
        ReBuild(pPreOrder + 1, pInOrder, nLeftLen, &((*pRoot) -> pLeft));

    if (nRightLen > 0)
        ReBuild(pPreOrder + nLeftLen + 1, pInOrder + nLeftLen + 1, nRightLen, &((*pRoot) -> pRight));

}

void PostOrderTraverse(NODE *pRoot) {
    if (pRoot != NULL) {
        PostOrderTraverse(pRoot->pLeft);
        PostOrderTraverse(pRoot->pRight);
        cout << pRoot->chValue << "\n";
    }
}

int main(int argc, char *argv[]) {
    char szPreOrder[TREELEN] = {'a', 'b', 'd', 'c', 'e', 'f'};
    char szInOrder[TREELEN] = {'d', 'b', 'a', 'e', 'c', 'f'};

    NODE *pRoot = NULL;
    ReBuild(szPreOrder, szInOrder, TREELEN, &pRoot);

    PostOrderTraverse(pRoot);
}