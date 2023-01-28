#include <iostream>
#include <list>
using namespace std;

class Solution{
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
            ListNode* head = new ListNode(0); //一個初始化的空節點
            ListNode* current = head;

            //如果l1和l2都不為空則繼續做
            while(l1 && l2){
                if(l1->val > l2->val){
                    current->next = l2;
                    l2 = l2->next;
                }
                else{
                    current->next = l1;
                    l1 = l1-> next;
                }
                current = current->next;
            }
            
            //如果l1還有值，但l2已經空了
            if(l1){
                current->next = l1;
            }
            else if(l2){
                current->next = l2;
            }

            return head->next;
        }
};