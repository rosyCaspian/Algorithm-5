class myNode<T> {
  public item: T;
  public next: myNode<T>;

  constructor(item: T) {
    this.item = item;
  }
}

class LinkedList<T> {
  private first: myNode<T>;
  private last: myNode<T>;
  private len: number;

  constructor() {
    this.first = null;
    this.last = null;
    this.len = 0;
  }

  // O(1)
  addFirst(item: T) {
    let node = new myNode<T>(item);
    node.next = null;
    if (this.isEmpty()) this.first = this.last = node;
    else {
      node.next = this.first;
      this.first = node;
    }
    this.len++;
  }

  // O(1)
  addLast(item: T) {
    let node = new myNode<T>(item);
    node.next = null;
    if (this.isEmpty()) this.first = this.last = node;
    else {
      this.last.next = node;
      this.last = node;
    }
    this.len++;
  }

  // O(1)
  removeFirst() {
    if (this.isEmpty()) throw new Error("NoSuchElementException");

    if (this.first == this.last) this.first = this.last;
    else {
      let second = this.first.next;
      this.first.next = null;
      this.first = second;
    }
    this.len--;
  }

  // O(n)
  removeLast() {
    if (this.isEmpty()) throw new Error("NoSuchElementException");

    if (this.first == this.last) this.first = this.last;
    else {
      let previous = this.getPreviousNode(this.last);
      this.last = previous;
      previous.next = null;
    }
    this.len--;
  }

  // O(n)
  indexOf(item: T): number {
    let node = this.first;

    for (let i = 0; i < this.len; i++) {
      if (node.item === item) return i;
      node = node.next;
    }
    return -1;
  }

  // O(n)
  contains(item: T): boolean {
    return this.indexOf(item) !== -1;
  }

  // O(n)
  toArray(): T[] {
    let node = this.first;
    let arr: T[] = [];

    while (node) {
      arr.push(node.item);
      node = node.next;
    }
    return arr;
  }

  // O(1)
  size(): number {
    return this.len;
  }

  // O(n)
  reverse() {
    if (this.isEmpty()) return;

    let previous = this.first;
    let current = this.first.next;
    while (current !== null) {
      let next = current.next;
      current.next = previous;
      previous = current;
      current = next;
    }

    // 首尾引用交换
    this.last = this.first;
    this.first = previous;
    // 反转后，最后一个节点的 next 滞空
    this.last.next = null;
  }

  // O(n)
  getKthNodeFromTheEnd(k: number) {
    if (this.isEmpty()) throw new Error("IllegalStateEexception");
    if (k > this.len) throw new Error("IllegalArgumentException");

    let current = this.first;
    let end = this.first;
    for (let i = 0; i < k - 1; i++) {
      end = end.next;
      /*
      如果不知道链表的长度的话
      if(end === null)
        throw new Error("IllegalArgumentException");
      */
    }

    while (end !== this.last) {
      current = current.next;
      end = end.next;
    }
    return current.item;
  }

  // O(n)
  print() {
    let node = this.first;
    while (node) {
      console.log(node.item);
      node = node.next;
    }
  }

  // O(1)
  private isEmpty(): boolean {
    return this.first === null;
  }

  // O(n)
  private getPreviousNode(node: myNode<T>): myNode<T> {
    let current = this.first;
    while (current) {
      if (current.next === node) return current;
      current = current.next;
    }
    return null;
  }
}

export default LinkedList;
