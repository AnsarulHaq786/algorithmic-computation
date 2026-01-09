## [Reverse Linkded List](https://leetcode.com/problems/reverse-linked-list/description/)

**simplified problem statement:**
given a singly linked list, reverse the list

```
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

```cpp
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr->next!=NULL) {
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
};
```