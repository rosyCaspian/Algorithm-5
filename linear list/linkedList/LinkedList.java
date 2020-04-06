import java.util.NoSuchElementException;

public class LinkedList {
    private class Node {
        private int value;
        private Node next;
        public Node(int value){
            this.value = value;
        }
    }

    private Node first;
    private Node last;
    private int len;

    // O(1)
    public void addFirst(int item){
        var node = new Node(item);
        if(isEmpty())
            first = last = node;
        else{
            node.next = first;
            first = node;
        }
        len++;
    }

    // O(1)
    public void addLast(int item){
        var node = new Node(item);

        if (isEmpty())
            first = last = node;
        else{
            last.next = node;
            last = node;
        }
        len++;
    }

    // O(1)
    public void removeFirst(){
        if(isEmpty())
            throw new NoSuchElementException();

        if(first == last)
            first = last = null;
        else{
            var second = first.next;
            first.next = null;  // 解除 next 关系之后，这个节点才会被 java 内存回收机制回收 ♻️
            first = second;
        }
        len--;
    }

    // O(n)
    public void removeLast(){
        if(isEmpty())
            throw new NoSuchElementException();

        if(first == last)
            first = last = null;
        else {
            var previous = getPrevious(last);
            last = previous;
            previous.next = null;
        }
        len--;
    }

    // O(n)
    public boolean contains(int item){
        return indexOf(item) != -1;
    }

    // O(n)
    public int indexOf(int item){
        var current = first;
        int index = 0;

        while(current != null){
            if(current.value == item) return index;
            current = current.next;
            index++;
        }
        return -1;
    }

    // O(1)
    public int size(){
        return len;
    }

    // O(n)
    public int[] toArray(){
        var array = new int[len];
        var current = first;

        for(int i = 0; i < len; i++){
            array[i] = current.value;
            current = current.next;
        }
        return array;
    }

    // O(n)
    public void print(){
        var temp = first;
        System.out.printf("[ ");
        while(temp != null){
            System.out.printf("%d ", temp.value);
            temp = temp.next;
        }
        System.out.printf("]\n");
    }

    // O(1)
    private boolean isEmpty(){
        return first == null;
    }

    // O(n)
    private Node getPrevious(Node node){
        var current = first;
        while(current != null){
            while (current.next == node) return current;
            current = current.next;
        }
        return null;
    }

}
