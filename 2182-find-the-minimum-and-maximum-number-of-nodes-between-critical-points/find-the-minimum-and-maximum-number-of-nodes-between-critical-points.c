int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
     *returnSize = 2;
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = -1; res[1] = -1;
    if (!head || !head->next || !head->next->next) return res;
    int fcp = -1, pcp = -1, min_dist = INT_MAX;
    int idx = 1;
    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    while (curr->next) {
        struct ListNode* nxt = curr->next;
        if ((curr->val > prev->val && curr->val > nxt->val) || 
            (curr->val < prev->val && curr->val < nxt->val)) {
            
            if (fcp == -1) {
                fcp = idx;
            } else {
                int dist = idx - pcp;
                if (dist < min_dist) min_dist = dist;
            }
            pcp = idx;
        }
        prev = curr;
        curr = nxt;
        idx++;
    }

    if (fcp != pcp) {
        res[0] = min_dist;
        res[1] = pcp - fcp;
    }

    return res;
    
}