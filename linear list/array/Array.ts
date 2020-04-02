class Array<T> {
  private items: T[];
  constructor(...items: T[]) {
    this.items = items;
  }
  // O(n)
  append(item: T) {
    this.items.push(item);
  }
  // O(n)
  removeAt(index: number) {
    if (index < 0 || index >= this.items.length)
      throw new Error("invalid index!");
    this.items.splice(index, 1);
  }
  // O(n)
  indexOf(item: T): number {
    for (let index = 0; index < this.items.length; index++)
      if (this.items[index] == item) return index;
    return -1;
  }
  // O(n)
  print() {
    for (let item of this.items) console.log(item);
  }
}

export default Array;
