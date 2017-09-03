class ListNode(object):
    
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.previous = None
        self.next = None
        
        
class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.mapping = {}
        self.tail = None
        self.head = None
        self.capacity = capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.mapping:
            return -1
        
        self.move_to_tail(self.mapping[key])
        return self.mapping[key].value

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.mapping:
            self.mapping[key].value = value
            self.move_to_tail(self.mapping[key])
            return
        
        self.mapping[key] = ListNode(key, value)
        self.add_to_tail(self.mapping[key])
        if self.capacity == 0:
            del self.mapping[self.head.key]
            self.remove_head()
        else:
            self.capacity -= 1
    
    def add_to_tail(self, node):
        if not self.head:
            self.head = node
            self.tail = node
            return
        
        self.tail.next = node
        node.previous = self.tail
        self.tail = node
    
    def remove_head(self):
        if not self.head:
            return
        
        if self.head == self.tail:
            self.head = None
            self.tail = None
            return
        
        self.head = self.head.next
        
    def move_to_tail(self, node):
        if node == self.tail:
            return
        
        if node == self.head:
            self.head = node.next
            node.next.previous = None
            self.tail.next = node
            node.previous = self.tail
            self.tail = node
            return
        
        node.next.previous = node.previous
        node.previous.next = node.next;
        self.tail.next = node
        node.previous = self.tail
        self.tail = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
