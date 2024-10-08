/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* tempA = a;
        ListNode* tempB = b;
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        while(tempA != NULL && tempB != NULL){
            if(tempA -> val <= tempB -> val){
                ListNode* t = new ListNode(tempA->val);
                tempC -> next = t;
                tempC = t;
                tempA = tempA -> next;
            }
            else{
                ListNode* t = new ListNode(tempB->val);
                tempC->next = t;
                tempC = t;
                tempB = tempB -> next;
            }
        }
        if(tempA == NULL){
            tempC -> next = tempB;
        }
        else{
            tempC -> next = tempA;
        }
        return c-> next;


    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size() == 0) return NULL;
        while(arr.size() > 1){
            ListNode *a = arr[0];
            arr.erase(arr.begin());
            ListNode *b = arr[0];
            arr.erase(arr.begin());
            ListNode *c = mergeTwoLists(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};