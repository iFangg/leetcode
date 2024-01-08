// Solution 1
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    if (list1 === null) return list2;
    if (list2 === null) return list1;
    if (list1 === null && list2 === null) return [];
    let head;
    if (list1.val <= list2.val) {
        head = new ListNode(list1.val, null);
        list1 = list1.next;
    } else {
        head = new ListNode(list2.val, null);
        list2 = list2.next;
    }
    let start = head;

    while (list1 != null) {
        let num = list1.val;
        if (list2 == null) {
            head.next = list1;
            break;
        } else {
            if (list2.val < num) {
                num = list2.val;
                list2 = list2.next;
            } else {
                list1 = list1.next;
            }
        }

        head.next = new ListNode(num, null);
        head = head.next;
    }

    if (list2 != null) {
        head.next = list2;
    }

    return start;
};


// Solution 2
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function(list1, list2) {
    let dummy = new ListNode();
    let current = dummy;
    while(list1 && list2){

        if (list1.val > list2.val){
            current.next = list2;
            current = current.next;
            list2 = list2.next;
        }
        else{
            current.next = list1;
            current = current.next;
            list1 = list1.next;
        }
    }
    if (!list1){
        current.next = list2;
    }
    if (!list2){
        current.next = list1;
    }
    return dummy.next;
    
};
