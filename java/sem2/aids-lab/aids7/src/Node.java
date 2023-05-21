public class Node<T> {
    private T data;
    private Node left;
    private Node right;
    private Node parent;

    public Node (T data){
        this.data = data;
    }
    public Node (T data, Node left, Node<T> right){
        this.data = data;
        this.left = left;
        this.right = right;
    }

    public void setLeft(Node left) {
        this.left = left;
    }
    public void setRight(Node right) {
        this.right = right;
    }
    public void setParent(Node parent) {
        this.parent = parent;
    }
    public void setData(T data) {
        this.data = data;
    }

    public Node getLeft(){
        return left;
    }
    public Node getRight(){
        return right;
    }
    public Node getParent(){
        return parent;
    }
    public T getData() {
        return data;
    }
}
