//给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
//
//k 是一个正整数，它的值小于或等于链表的长度。
//
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
//
//示例 :
//
//给定这个链表：1->2->3->4->5
//
//当 k = 2 时，应当返回: 2->1->4->3->5
//
//当 k = 3 时，应当返回: 3->2->1->4->5

#ifdef t0025

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *nodes[k];
        ListNode *pnode = head;
        ListNode *result = NULL;
        ListNode *lastNode = NULL;
        while(1){
            for(int i = 0; i < k; i++){
                if(!pnode) {
                    goto complete;
                }
                nodes[i] = pnode;
                pnode = pnode->next;
            }
            if(!result) result = nodes[k-1];
            if(lastNode) lastNode->next = nodes[k-1];
            for(int i = k-1; i > 0; i--){
                nodes[i]->next = nodes[i-1];
            }
            
            lastNode = nodes[0];
            nodes[0]->next = pnode;
        }
        complete:
        if(!result) result = head;
        return result;
    }
    
    void main()
    {
        vector<int> vec = {1,2,3,4,5,6,7};
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
        reverseKGroup(head,1);
        while(node){
            cout << node->val << "  ";
            node = node->next;
        }
        cout << endl;
        return 0;
    }
};



#endif