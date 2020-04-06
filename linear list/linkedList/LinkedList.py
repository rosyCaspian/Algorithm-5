
class LinkList:

    class _Node:
        def __init__(self, value):
            self._value = value
            self._next = None
    
    def __init__(self):
        self._first = None
        self._last = None
        self._len = 0
    
    # O(1)
    def __len__(self):
        return self._len
    
    # O(n)
    def __getitem__(self, index):
        if not 0 <= index < self._len:
            raise IndexError("invalid index!")

        current = self._first
        for _ in range(index):
            current = current._next
        return current._value

    # O(1)
    def addFirst(self, item):
        node = self._Node(item)

        if self._isEmpty():
            self._first = self._last = node
        else:
            node._next = self._first
            self._first = node

        self._len += 1
    
    # O(1)
    def addLast(self, item):
        node = self._Node(item)

        if self._isEmpty():
            self._first = self._last = node
        else:
            self._last._next = node
            self._last = node
        
        self._len += 1

    # O(1)
    def removeFirst(self):
        if self._isEmpty():
            raise Exception("NoSuchElementException")

        if self._first == self._last:
            self._first = self._last = None
        else:
            second = self._first._next
            self._first._next = None
            self._first = second

        self._len -= 1

    # O(n)
    def removeLast(self):
        if self._isEmpty():
            raise Exception("NoSuchElementException")
        
        if self._first == self._last:
            self._first = self._last = None
        else:
            previous = self._getPrevious(self._last)
            self._last = previous
            previous._next = None
        
        self._len -= 1

    # O(n)
    def indexOf(self, item):
        current = self._first
        
        for index in range(self._len):
            if current._value == item:
                return index
            current = current._next

        return -1

    # O(n)
    def contains(self, item):
        return self.indexOf(item) != -1

    # O(n)
    def printf(self):
        current = self._first
        output = "[ "

        while current:
            output += (str(current._value) + ' ')
            current = current._next
        output += ']'

        print(output)
        
    # O(1)
    def _isEmpty(self):
        return self._first == None
    
    # O(n)
    def _getPrevious(self, node):
        current = self._first

        while current:
            if current._next == node:
                return current
            current = current._next
        
        return None
    