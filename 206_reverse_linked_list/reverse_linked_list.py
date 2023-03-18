from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
def plist(ptr: Optional[ListNode]):
    while (ptr != None):
        print(ptr.val, end=" ")
        ptr = ptr.next
    print()
        
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr, prev = head, None
        
        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
            
        return prev

list = [1,2,3,4,5]
head = None
tail = None

for i in list:
    new_node = ListNode(i)
    
    if not head: 
        head = new_node
        tail = new_node
        continue
    
    tail.next = new_node
    tail = new_node

del tail

sol = Solution()
ans = sol.reverseList(head)

plist(ans)