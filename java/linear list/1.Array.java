// java.util 包中的两种动态数组
// Vector: 扩展数组容量时，翻一倍；方法都是同步的(synchronized: 只有一个线程可以访问该方法)
// ArrayList: 扩展数组容量时，翻半倍；方法都是异步的(asynchronous: 允许多个线程访问该方法)

public class Array {
    private int[] items;
    private int len;
    private int cap;

    public Array(int length){
        items = new int[length];
         len = 0;
         cap = length;
    }

    // O(n)
    public void append(int item){
        // 注释不许要解释代码在做什么，只需要解释 why how
        if (len == cap){
            cap = cap + ((cap >> 1) > 1 ? (cap >> 1):1);
            int[] newItems = new int[cap];
            for(int i=0;i<len;i++)
                newItems[i] = items[i];
            // java中数组名赋值是引用传递
            items = newItems;
        }
        items[len++] = item;
    }

    // O(n)
    public void removeAt(int index){
        if(index < 0 || index >= len)
            throw new IllegalArgumentException();

        for (int i=index; i<len-1; i++)
            items[i] = items[i+1];
        len--;

    }

    // O(n)
    public int indexOf(int item){
        for(int i=0; i<len; i++){
            if(items[i] == item)
                return i;
        }
        return -1;
    }

    // O(n)
    public void print(){
        for(int i = 0; i< len; i++)
            System.out.println(items[i]);
    }
}
