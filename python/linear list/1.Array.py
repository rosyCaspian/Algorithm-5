# 因为 python 中 list 本身是动态的，所以引入原始数组，不实用 built-in list
import ctypes

class Array:
    """A dynamic array class."""
    
    def __init__(self, cap=10):
        """Create an empty array."""
        self._len = 0
        self._cap = cap
        self._items = self._make(cap)
    
    # O(1)
    def __len__(self):
        """Return the number of the elements stored in the array."""
        return self._len
    
    # O(1)
    def __getitem__(self, index):
        """Return element by index."""
        if not 0 <= index < self._len:
            raise IndexError("invalid index!")

        return self._items[index]
    
    # O(n)
    def append(self, element):
        if self._len == self._cap:
            self._enlarge(2 * self._cap)

        self._items[self._len] = element
        self._len += 1
    
    # O(n)
    def removeAt(self, index):
        """Remove element of array by index."""
        if not 0 <= index < self._len:
            raise IndexError("invalid index!")

        for i in range(index, self._len-1):
            self._items[i] = self._items[i+1]
        self._len -= 1

    # O(n)
    def indexOf(self, element):
        """Return index of array by element."""
        for index in range(self._len):
            if element == self._items[index]:
                return index

        return -1

    # O(n)
    def printf(self):
        for index in range(self._len):
            print(self._items[index])
    
    def _enlarge(self, cap):
        """Enlarge the capacity of the array to capacity cap."""
        temp = self._make(cap)

        for index in range(self._len):
            temp[index] = self._items[index]
        self._items = temp
        self._cap = cap

    def _make(self, cap):
        """Return new a array with capacity cap."""
        return (cap * ctypes.py_object)()