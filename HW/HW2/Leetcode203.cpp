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


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //如果只剩head這一筆資料
        while(head != NULL && head->val == val){
            head = head->next;
        }
        if(head == nullptr){
            return nullptr;
        }

        ListNode* current = head;

        while(current->next != nullptr){
            if(current->next->val == val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};