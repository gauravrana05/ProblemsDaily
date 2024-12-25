def removeDuplicate(head):
    if head == None or head.next == None:
        return
    if head.next.data == head.data:
        head.next = head.next.next
        removeDuplicate(head)
    removeDuplicate(head.next)
    