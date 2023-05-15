import java.util.EmptyStackException;

public class ListStack<T extends Comparable<T>> implements IStack<T>{

    OneWayLinkedList<T> list;
    public ListStack(){
        list = new OneWayLinkedList<T>();
    }

    @Override
    public boolean isEmpty() throws EmptyStackException {
        return list.isEmpty();
    }

    @Override
    public boolean isFull() throws FullStackException {
        return false;
    }

    @Override
    public T pop() throws EmptyStackException {
        T val = list.remove(0);
        if(val == null) throw new EmptyStackException();
        return val;
    }

    @Override
    public void push(T elem) {
        list.add(0, elem);
    }

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public T top() throws EmptyStackException {
        T val = list.get(0);
        if(val == null) throw new EmptyStackException();
        return val;
    }

    @Override
    public String toString(){
        return list.toString();
    }
}
