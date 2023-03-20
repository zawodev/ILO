package Labs2.SeriesIterator;

import java.util.*;

public class Series <E> implements Iterable<E> {
    Node<E> head, tail;
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
        return new SeriesIterator<E>(this);
    }

    public Node<E> getHead() {
        return head;
    }
    public Node<E> getTail() {
        return tail;
    }
}
