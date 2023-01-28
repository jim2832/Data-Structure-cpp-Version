#include <iostream>
#include <list>
using namespace std;

class Solution{
    public:
        ListNode* swapPairs(ListNode* head){
            //若沒有資料 or 只有一筆
            if(head == nullptr || head->next == nullptr){
                return head;
            }

            ListNode* temp = head->next;
            head->next = swapPairs(temp->next);
            temp->next = head;
            return temp;
        }
};