import java.util.AbstractList;
import java.util.Iterator;

public class OneWayLinkedList<E> extends AbstractList<E> {
    private class Node<E> {
        E data;
        Node<E> next;
        public Node(E data) {
            this.data = data;
        }
        public void setData(E data) {
            this.data = data;
        }
        public void setNext(Node<E> next) {
            this.next = next;
        }
        public E getData() {
            return data;
        }
        public Node<E> getNext() {
            return next;
        }
        public void insertAfter(Node<E> elem){
            elem.setNext(this.getNext());
            this.setNext(elem);
        }
    }
    Node sentinel = null;
    public OneWayLinkedList(){
        sentinel = new Node(null);
        sentinel.setNext(sentinel);
    }
    private Node getNode(int index){
        if(index < 0 || index >= size()) throw new IndexOutOfBoundsException();
        Node<E> node = sentinel.getNext();
        int counter = 0;
        while(node != sentinel && counter < index){
            counter++;
            node = node.getNext();
        }
        if(node == sentinel)
            throw new IndexOutOfBoundsException();
        return node;
    }
    private Node<E> getNode(E value){
        Node<E> node = sentinel.getNext();
        while(node != sentinel && !value.equals(node.getData())){
            node = node.getNext();}
        if(node == sentinel)
            return null;
        return node;
    }
    public boolean isEmpty() {
        return sentinel.getNext() == sentinel;
    }
    public void clear() {
        sentinel.setNext(sentinel);
    }
    public boolean contains(Object value) {
        return indexOf((E)value) != -1;
    }
    public E get(int index) {
        if(index < 0 || index >= size()) return null;
        Node<E> node = getNode(index);
        return node.getData();
    }
    public E set(int index, E value) {
        Node<E> node = getNode(index);
        E nodeData = node.getData();
        node.setData(value);
        return nodeData;
    }
    public boolean add(E value) {
        Node<E> newNode = new Node<E>(value);
        Node<E> tail = sentinel;
        while(tail.getNext() != sentinel)
            tail = tail.getNext();
        tail.setNext(newNode);
        newNode.setNext(sentinel);
        return true;
    }
    public void add(int index, E data) {
        Node<E> newNode = new Node<E>(data);
        if(index == 0) sentinel.insertAfter(newNode);
        else{
            Node<E> prevNode = getNode(index - 1);
            prevNode.insertAfter(newNode);
        }
    }
    public int indexOf(Object data) {
        Node<E> node = sentinel.getNext();
        int counter = 0;
        while(node != sentinel && !node.getData().equals((E)data)){
            counter++;
            node = node.getNext();
        }
        if(node == sentinel)
            return -1;
        return counter;
    }
    public E remove(int index) {
        if(index == 0) {
            E val = (E) sentinel.getNext().getData();
            sentinel.setNext(sentinel.getNext().getNext());
            return val;
        }
        Node<E> node = getNode(index-1);
        if(node.getNext() == null) throw new IndexOutOfBoundsException();
        E val = node.getNext().getData();
        node.setNext(node.getNext().getNext());
        return val;
    }
    public boolean remove(Object value) {
        Node<E> node = getNode((E)value);
        if(sentinel.getNext().getData().equals(value)) sentinel.setNext(sentinel.getNext().getNext());
        while(node.getNext() != sentinel && !node.getNext().getData().equals(value)){
            node = node.getNext();
        }
        return true;
    }
    public int size() {
        Node<E> node = sentinel.getNext();
        int counter = 0;
        while(node != sentinel){
            counter++;
            node = node.getNext();
        }
        return counter;
    }
    public void testNextIteration(){
        Node<E> node = sentinel.getNext();
        while(node != sentinel) {
            System.out.print(node.getData() + "; ");
            node = node.getNext();
        }
        System.out.println();
    }

    public Iterator<E> iterator() {
        return new MyIterator();
    }
    private class MyIterator implements Iterator<E>{
        Node<E> currentNode = sentinel;
        public boolean hasNext() {
            return currentNode.getNext() != sentinel;
        }
        public E next() {
            currentNode = currentNode.getNext();
            return currentNode.getData();
        }
    }
}
