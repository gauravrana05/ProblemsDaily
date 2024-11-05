from linked_list import LinkedListSeq

def test_cycle(new_list):
  temp = new_list.head
  while temp.next.next != None:
    temp = temp.next 
  temp.next = new_list.head
  print(new_list.cycle())

def get_middle(new_list):
  slow = new_list.head
  fast = new_list.head
  
  while fast != None and fast.next != None:
    fast = fast.next.next 
    slow = slow.next 
  return slow.item

def reverse(new_list):
  if new_list.head == None or new_list.head.next == None:
    return new_list
  prev = new_list.head
  curr = new_list.head.next 
  nexxt = new_list.head.next.next
  
  while(curr != None):
    curr.next = prev 
    prev = curr
    curr = nexxt
    if nexxt: 
      nexxt = nexxt.next
  new_list.head.next = None 
  new_list.head = prev
  
  def recursive_reverse(head):
    if head == None or head.next == None:
      return head 
    node = recursive_reverse(head.next)
    head.next.next = head 
    head.next = None 
    return node 
    

if __name__ == "__main__":
  def main():
    new_list = LinkedListSeq()
    
    n = list(map(int, input().split()))
    new_list.build(n)
    new_list.print()
    
    # test_cycle(new_list)
    #print(get_middle(new_list))
    reverse(new_list)
    new_list.print()

  
  main()