public class Main {
    public static void main(String[] args) {
        Student2StrExec exec;
        BST<Student> tree = new BST<>(new StudentComparator());

        tree.insert(new Student(2, "a"));
        tree.insert(new Student(4, "b"));
        tree.insert(new Student(5, "C"));
        tree.insert(new Student(1, "D"));
        tree.insert(new Student(3, "e"));
        tree.insert(new Student(7, "f"));
        tree.insert(new Student(9, "G"));
        tree.insert(new Student(6, "H"));

        exec = new Student2StrExec();
        tree.inOrderWalk(exec);
        System.out.println(exec.getResult());

        tree.printTree();
    }
}