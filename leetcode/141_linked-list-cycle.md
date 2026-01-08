## [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/description/)

**simplified problem statement**
given a linked list, find out if the list ends up in a cycle or not.

**
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
**

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* temp = head;

        while (temp!=nullptr) {
            if (visited.count(temp)) return true;
            visited.insert(temp);
            temp=temp->next;
        }
        return false;
    }
};

```