//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//示例:
//
//给定 1->2->3->4, 你应该返回 2->1->4->3.

#ifdef t0024

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *i;
        ListNode *j;
        ListNode *temp;
        if(!head || !head->next) return head;
        i = head;
        j = head->next;
        head = head->next;
        while(i && j){
            temp = j->next ? j->next : NULL;
            i->next = temp && temp->next ? temp->next : (temp ? temp : NULL);
            j->next = i;
            i = temp;
            j = temp ? temp->next : NULL;
        }
        return head;
    }
    
    void run()
    {
        vector<int> vec = {1,2,3,4,5};
        ListNode *head, *node;
        head = new ListNode(vec[0]);
        node = head;
        for(int i = 1; i < vec.size(); i++){
            ListNode *temp = new ListNode(vec[i]);
            node->next = temp;
            node = node->next;
        }
        node = head;
        while(node){
            cout << node->val << "  ";
            node = node->next;
        }
        cout << endl;
        swapPairs(head);
        while(node){
            cout << node->val << "  ";
            node = node->next;
        }
        cout << endl;
        return 0;
    }
};




#endif