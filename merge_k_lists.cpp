// Time : O(nk log k)
// Space: O(k)

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

class cmp
{
public:
    bool operator()(ListNode* l1, ListNode* l2)
    {
        if(l1->val > l2->val)return true;
        return false;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // auto cmp = [](ListNode* l1, ListNode* l2) {return l1->val > l2->val;};
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // push the heads of all lists to pq
        for(auto list_head: lists)
        {
            if(list_head != nullptr)
            {pq.push(list_head);}
        }

        // process the node and put next of processed node in the queue
        // dummy head
        ListNode* head = new ListNode(0);
        ListNode* point = head;
        while(pq.empty() == false)
        {
            point->next = pq.top();
            pq.pop();
            point = point->next;
            if(point->next) pq.push(point->next);
        }

        return head->next;

    }
};