#include <iostream>
#include <list>
using namespace std;

class MyLinkedList{
    struct ListNode{
        int val;
        ListNode* next;
    };

    ListNode* head;
    ListNode* tail;
    int len;
    
    public:
        MyLinkedList(){
            head = nullptr;
            tail = nullptr;
            len = 0;
        }
        
        int get(int index){
            //例外處理
            if(index >= len){
                return -1;
            }

            ListNode* current = head;
            for(int i=0; i<index; i++){
                current = current->next;
            }
            return current->val;
        }
        
        void addAtHead(int val){
            head = new ListNode{val, head};
            len++;
            //若一開始為空，則新增資料後也要改tail指標
            if(tail == nullptr){
                tail = head;
            }
        }
        
        void addAtTail(int val){
            //如果tail不是空的
            if(tail){
                tail->next = new ListNode{val, nullptr};
                tail = tail->next;
            }
            //tail為空
            else{
                head = tail = new ListNode{val, nullptr};
            }
            len++;
        }
        
        void addAtIndex(int index, int val){
            //違法動作
            if(index > len){
                return;
            }
            //代表在尾端新增資料
            if(index == len){
                addAtTail(val);
            }
            //代表在頭端新增資料
            else if(index == 0){
                addAtHead(val);
            }
            //其他情況
            else{
                // A B C => A D B C
                ListNode* current = head;
                for(int i=1; i<index; i++){
                    current = current->next;
                }
                ListNode* temp = current->next; //紀錄B以防丟失資料
                current->next = new ListNode{val, temp}; //指向新的節點
                len++;
            }
        }
        
        void deleteAtIndex(int index){
            //違法操作
            if(index >= len){
                return;
            }

            //在頭端刪除
            if(index == 0){
                ListNode* temp = head;
                head = head->next;
                delete temp;
                len--;
                if(head == nullptr){
                    tail = nullptr;
                }
                return;
            }

            //其他情況
            // A B C D, delete C, current->B
            // 要移動index - 1次
            ListNode* current = head;
            for(int i=1; i<index; i++){
                current = current->next;
            }
            //如果刪除的是最後一筆資料
            if(index == len-1){
                delete tail;
                current->next = nullptr;
                tail = current;
            }
            //其他情況
            else{
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            len--;
        }
    };

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */