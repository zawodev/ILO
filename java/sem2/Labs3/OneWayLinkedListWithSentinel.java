package Labs3;

import java.util.Iterator;
import java.util.ListIterator;

public class OneWayLinkedListWithSentinel<E> extends AbstractList<E>{

    Node<E> head = null, tail = null;

    public OneWayLinkedListWithSentinel(E data) {
        add(data);
    }

    public void add(E data) {
        Node<E> node = new Node<>(data, null);
        if (head == null)
            tail = head = node;
        else {
            tail.setNext(node);
            tail = node;
        }
    }
    @Override
    public Iterator<E> iterator() {
        return new Iterator<E>() {
            @Override
            public boolean hasNext() {
                return false;
            }
            @Override
            public E next() {
                return null;
            }
        };
    }

    public Node<E> getHead() {
        return head;
    }
    public Node<E> getTail() {
        return tail;
    }
}
