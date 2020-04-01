package src

import "fmt"

type array struct {
	items []interface{}
}

func NewArray(capacity int) *array {
	return &array{
		make([]interface{}, 0, capacity),
	}
}

// O(n)
func (a *array) Insert(item interface{}) {
	if len(a.items) == cap(a.items) {
		a.enlarge(cap(a.items) * 2)
	}
	a.items = append(a.items, item)
}

// O(n)
func (a *array) RemoveAt(index int) {
	if index < 0 || index > len(a.items) {
		panic("index error")
	}
	a.items = append(a.items[:index], a.items[index+1:]...)
}

// O(n)
func (a *array) IndexOf(element interface{}) int {
	for index, item := range a.items {
		if element == item {
			return index
		}
	}
	return -1
}

// O(n)
func (a *array) Print() {
	for _, item := range a.items {
		fmt.Printf("%v ", item)
	}
	fmt.Println("")
}

// O(n)
func (a *array) enlarge(capacity int) {
	newItems := make([]interface{}, cap(a.items), capacity)
	for index, item := range a.items {
		newItems[index] = item
	}
	a.items = newItems
}
