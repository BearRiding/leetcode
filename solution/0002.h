/*
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
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
    ListNode* addTwoNumbers(ListNode* &l1, ListNode* &l2) {
        ListNode *result, *p1 = l1, *p2 = l2, *p3;
        p3 = result = new ListNode(0);
        
        int adder_flag = 0;
        while(p1 && p2){
            int num = p1->val + p2->val + adder_flag;
            adder_flag = 0;
            p1 = p1->next; p2= p2->next;
            if(num > 9) {
                adder_flag = 1;
                num = num % 10;
            }
            p3->next = new ListNode(num);
            p3 = p3->next;
        }
        ListNode *q = p1 ? p1 : p2;
        while(q){
            int num = q->val + adder_flag;
            adder_flag = 0;
            q = q->next;
            if(num > 9) {
                adder_flag = 1;
                num = num % 10;
            }
            p3->next = new ListNode(num);    
            p3 = p3->next;
        }
        
        if(adder_flag){
            p3->next = new ListNode(1);
        }
        
        return result->next;
        
    }
    
    void listInit(ListNode* &l1){
        l1 = new ListNode(rand()%10);
        ListNode *p;
        p = l1;
        int max = rand()%10 + 3;
        for(int i = 0; i < max; i++){
            p->next = new ListNode(rand()%10);
            p = p->next;
        }
    }

    void printList(ListNode* &l1){
        stack<int> nums;
        ListNode *p = l1;
        while(p){
            nums.push(p->val);
            p = p->next;        
        }
        
        while(!nums.empty()){
            cout << nums.top();
            nums.pop();        
        }
        cout << endl;
    }

    void printList_Node(ListNode* l1){
        ListNode* p = l1;
        cout << p->val;
        p = p->next;
        while(p){
            cout << " -> " << p->val;
            p = p->next;
        }
        cout << endl;
    }

    void run()
    {
        ListNode *l1, *l2;
        listInit(l1);
        printList_Node(l1);
        listInit(l2);
        printList_Node(l2);
        Solution solution;
        ListNode *result = solution.addTwoNumbers(l1, l2);
        printList_Node(result);
        
        return 0;
    }

};

