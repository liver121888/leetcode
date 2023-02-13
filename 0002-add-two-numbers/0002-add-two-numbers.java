/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        byte val1 = 0, val2 = 0, tmp, carrier = 0;
        ListNode curans = null;
        ListNode ans = new ListNode();
        boolean firsttime = true;
        boolean l1empty = false, l2empty = false;
        
        while (true)
        {

            // check if l1 has value
            if (l1 != null)
                val1 = (byte) l1.val;
            else
                l1empty = true;


            // check if l2 has value 
            if (l2 != null)
                val2 = (byte) l2.val;
            else
                l2empty = true;
            
            if (l1empty && l2empty && carrier != 1)
                break;

            tmp = (byte)(val1 + val2 + carrier);
            carrier = 0;
            if (tmp - (byte) 9 > 0)
            {
                carrier = 1;
                tmp = (byte) (tmp -  10);
            }
            
            // new a node and store value
            ListNode tmpnode = new ListNode(tmp);
            
            if (firsttime)
            {
                ans = tmpnode;
                curans = tmpnode;
                firsttime = false;
            }
            else
            {
                curans.next = tmpnode;
                curans = tmpnode;
            }

            // move to next l1, l2
            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
            val1 = 0;
            val2 = 0;

        }

        return ans;
    }
}