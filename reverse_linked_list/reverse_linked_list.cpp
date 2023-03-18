#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // Constructer
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        reverse(nullptr, head);
        return f_head;
    }
private:
    ListNode* f_head = nullptr;
    void reverse(ListNode *prev, ListNode *ptr){
        if (ptr == nullptr) return;
        if (ptr->next == nullptr){
            f_head = ptr;
            ptr->next = prev;
            return;
        }

        reverse(ptr, ptr->next);
        ptr->next = prev;
    }
};

int main(void){

    Solution sol;
    ListNode *head = nullptr;
    ListNode *ptr;

    // for (int i = 0; i < 5; i++){
    //     ListNode *new_node = new ListNode(i + 1);
        
    //     if (i == 0){
    //         head = new_node;
    //         ptr = head;
    //         continue;
    //     }

    //     ptr->next = new_node;
    //     ptr = new_node;
    // }

    for (auto *ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << " ";
    }
    cout << "\n";

    head = sol.reverseList(head);

    for (auto *ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << " ";
    }
    cout << "\n";
}