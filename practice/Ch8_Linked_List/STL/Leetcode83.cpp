#include <iostream>
#include <list>
using namespace std;

class Solution{
    public:
        ListNode* deleteDuplicates(ListNode* head){
            //完全沒有資料 or 只有一筆資料
            if(head == nullptr || head->next == nullptr){
                return head;
            }

            //大於兩筆資料
            ListNode* current = head;
            //當current 和 current->next 不為空時繼續做
            while(current && current->next){
                // A A B, delete 2nd A
                // 1st A->B
                if(current->val == current->next->val){
                    ListNode* temp = current->next->next; //紀錄B以防丟失資料
                    delete current->next;
                    current->next = temp;
                }
                else{
                    current = current->next;
                }
            }

            return head;
        }

};