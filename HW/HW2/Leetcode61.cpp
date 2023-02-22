#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            int len = 0;
            ListNode* cur = head;
            ListNode* tail;
            while(cur != nullptr){
                cur = cur->next;
                len++;
            }
            if(k != 0 && len != 0){
                k %= len;
            }
            
            for(int i=0; i<k; i++){
                cur = head;
                tail = nullptr;
                ListNode* tail = nullptr;
                while(cur->next->next != nullptr){
                    cur = cur->next; //cur會停在倒數第二個節點
                }
                tail = cur->next;
                cur->next = nullptr;
                tail->next = head;
                head = tail;
            }

            return head;
        }
};
*/

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        int n = 0;
        ListNode *cur = head;
        while (cur) {
            ++n;
            cur = cur->next;
        }
        k %= n;
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < k; ++i) {
            if (fast) fast = fast->next;
        }
        if (!fast) return head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        fast = slow->next;
        slow->next = NULL;
        return fast;
    }
};