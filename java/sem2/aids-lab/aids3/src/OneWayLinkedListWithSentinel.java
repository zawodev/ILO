import java.util.Iterator;

public class OneWayLinkedListWithSentinel<E> extends AbstractList<E> {

    Node<E> head = null, tail = null;

    public OneWayLinkedListWithSentinel() {

    }

    public void add(E data) {
        Node<E> node = new Node<>(data, null);
        if (head == null) head = tail = node;
        else {
            tail.setNext(node);
            tail = node;
        }
    }

    @Override
    public void clear() {
        head = tail = null;
    }

    private Node<E> getNode(int index){
        if (index < 0) throw new IndexOutOfBoundsException();
        Node<E> current = head;
        while (index > 0 && current != null) {
            index--;
            current = current.getNext();
        }
        if (current == null)
            throw new IndexOutOfBoundsException();
        return current;
    }

    @Override
    public int indexOf(E data) {
        int pos=0;
        Node<E> actElem= head;
        while(actElem!=null)
        {
            if(actElem.getData().equals(data))
                return pos;
            pos++;
            actElem=actElem.getNext();
        }
        return -1;}
    @Override
    public boolean contains(E data) {
        return indexOf(data)>=0;
    }
    @Override
    public E get(int index) {
        Node<E> actElem = getNode(index);
        return actElem.getData();
    }
    @Override
    public E set(int index, E data) {
        Node<E> actElem=getNode(index);
        E elemData=actElem.getData();
        actElem.setData(data);
        return elemData;
    }

    @Override
    public boolean isEmpty() {
        return head == null;
    }

    @Override
    public Iterator<E> iterator() {
        return new MyIterator<>(this);
    }

    @Override
    public E remove(int index) {
        if(index<0 || head ==null) throw new IndexOutOfBoundsException();
        if(index==0){
            E retValue= head.getData();
            head = head.getNext();
            return retValue;}
        Node<E> actElem=getNode(index-1);
        if(actElem.getNext()==null)
            throw new IndexOutOfBoundsException();
        E retValue=actElem.getNext().getData();
        actElem.setNext(actElem.getNext().getNext());
        return retValue;
    }

    @Override
    public boolean remove(E value) {
        if(head ==null)
            return false;
        if(head.getNext().getData().equals(value)){
            head = head.getNext();
            return true;
        }
        Node<E> actElem = head;
        while(actElem.getNext()!=null && !actElem.getNext().getData().equals(value))
            actElem=actElem.getNext();
        if(actElem.getNext()==null)
            return false;
        actElem.setNext(actElem.getNext().getNext());
        return true;}

    @Override
    public int size() {
        int pos = 0;
        Node<E> current = head;
        while(current != null) {
            pos++;
            current = current.getNext();
        }
        return pos;
    }
    public Node<E> getHead() {
        return head;
    }
}
