#include <iostream>
#include <vector>
#include <tuple>

#define empty(i) (i == nullptr)

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* ptr){
    while (ptr != nullptr){
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2, *head = new ListNode, *tail = head;
        int carry_in = 0;
        
        // Add each l1, l2 node
        while (true){
            int sum;

            // Add two node & carry_in
            if (!empty(ptr1) && !empty(ptr2)){
                sum = ptr1->val + ptr2->val + carry_in;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else if (empty(ptr1) && !empty(ptr2)){
                sum = ptr2->val + carry_in;
                ptr2 = ptr2->next;
            }
            else if (!empty(ptr1) && empty(ptr2)){
                sum = ptr1->val + carry_in;
                ptr1 = ptr1->next;
            }
            else if (carry_in != 0) sum = carry_in;
            else break;

            carry_in = sum / 10;

            // Create new node
            ListNode *new_node = new ListNode(sum % 10);
            tail->next = new_node;
            tail = new_node;

        }
        return head->next;
    }
};

int main(void){
    vector <int> lst1 = {9,9,9,9};
    vector <int> lst2 = {9,9,9,9,9};
    ListNode *l1 = nullptr, *l2 = nullptr, *ptr;

    // Create input
    for (auto i: lst1){
        if (l1 == nullptr){
            l1 = new ListNode(i);
            ptr = l1;
            continue;
        }

        ListNode *new_node = new ListNode(i);
        ptr->next = new_node;
        ptr = ptr->next;
    }

    for (auto i: lst2){
        if (l2 == nullptr){
            l2 = new ListNode(i);
            ptr = l2;
            continue;
        }

        ListNode *new_node = new ListNode(i);
        ptr->next = new_node;
        ptr = ptr->next;
    }
    // print(l1);
    // print(l2);
    
    Solution sol;

    auto ans = sol.addTwoNumbers(l1, l2);
    print(ans);
}