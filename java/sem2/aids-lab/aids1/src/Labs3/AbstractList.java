package Labs3;

public abstract class AbstractList <E> implements IList<E> {
    Node<E> head, tail;
    public AbstractList() {

    }
    @Override
    public void add(int index, E data) {
        Node<E> node = new Node<>(data, null);
        if (head == null)
            tail = head = node;
        else {
            tail.setNext(node);
            tail = node;
        }
    }
    public Node<E> getHead() {
        return head;
    }
    public Node<E> getTail() {
        return tail;
    }
}
