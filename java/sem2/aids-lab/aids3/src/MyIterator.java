import java.util.Iterator;
import java.util.NoSuchElementException;

public class MyIterator<E> implements Iterator<E> {
    Node<E> current;
    public MyIterator(OneWayLinkedListWithSentinel<E> series){
        current = series.getHead();
    }

    @Override
    public boolean hasNext() {
        return current != null;
    }

    @Override
    public E next() throws NoSuchElementException {
        if (hasNext()) {
            E data = current.getData();
            current = current.getNext();
            return data;
        }
        else
            throw new NoSuchElementException();
    }

    @Override
    public void remove() {
        throw new UnsupportedOperationException();
    }
}
