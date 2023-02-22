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
        ListNode* reverseList(ListNode* head) {
            ListNode *Next, *Prev = nullptr;
            while(head){
                Next = head->next;
                head->next = Prev;
                Prev = head;
                head = Next;
            }
            return Prev;
        }
};