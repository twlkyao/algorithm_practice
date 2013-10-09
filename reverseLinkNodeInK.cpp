/*
Description: Reverse Nodes in k-Group

链接：http://oj.leetcode.com/problems/reverse-nodes-in-k-group/

基本算法描述:
对联调进行指针翻转，O(n)复杂度
 */

#include <iostream>
using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int i, j, n = 0;
        ListNode *p1, *p2, *p3, *HH, *T1, *T2, *temp;

        if (head == NULL)
            return NULL;

        temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        if (k <= 1 || k > n || n == 0)
            return head;

        p1 = head;
        p2 = p1->next;

        for (i = 1; i <= n / k; ++i) {
            for (j = 1; j < k; ++j) {
                if (j == 1)
                    T2 = p1;    // 当前循环的链位指针T2

                p3 = p2->next;  // 链表翻转
                p2->next = p1;
                p1 = p2;
                p2 = p3;

                if (i == 1 && j == k - 1)
                    HH = p1;    // 翻转后的链表头指针
                else if (j == k - 1)
                    T1->next = p1; // 将当前循环的链头赋给上一次循环的链尾指针的next
            }
            p1 = p2;
            if (p2)         // 若不进行判空，会导致k被n整除时，因为p2为空，p2->next会出现segment fault
                p2 = p2->next;
            T1 = T2;            // T1代表上层循环的链尾指针
        }
        T1->next = p1;

        return HH;

    }
};

int main() {
    int val, k = 3;
    ListNode *head, *temp, *temp2;
    Solution *s;

    cin >> val;
    temp = head = new ListNode(val);

    while (cin >> val && val != EOF) {
        temp->next = new ListNode(val);
        temp = temp->next;
    }

    s = new Solution;
    temp = s->reverseKGroup(head, k);

    while (temp) {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

/*
1
2
3
4
5
6
7

3
2
1
6
5
4
7
 */