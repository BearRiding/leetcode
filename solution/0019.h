/**
 * @brief 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * @return 
 */

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vec;
        ListNode *node = head;
        while(node){
            vec.push_back(node);
            node = node->next;
        }
        int num = vec.size();
        if(num == n) return head->next;

        node = vec[vec.size()-n-1];
        node->next = node->next->next;
        return head;
    }
    
    
    void print(ListNode *head){
        ListNode *node = head;
        while(node){
            cout << node->val << "  ";
            node = node->next;
        }
        cout << endl;
    }

    void run()
    {
        vector<int> vec = {1,2,3,4,5};
        ListNode *head = new ListNode(vec[0]);
        ListNode *node = head;
        for(int i = 1; i < vec.size(); i++){
            ListNode *temp = new ListNode(vec[i]);
            node->next = temp;
            node = temp;
        }
        print(head);
        
        Solution solution;
        head = solution.removeNthFromEnd(head, 2);
        print(head);
        
        return 0;
    }

};
