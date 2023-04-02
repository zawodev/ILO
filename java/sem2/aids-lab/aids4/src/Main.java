import java.util.AbstractList;

public class Main {
    //static AbstractList<Integer> myList = new OneWayLinkedList();
    static AbstractList<Integer> myList = new OneWayCyclicLinkedList();
    //static AbstractList<Integer> myList = new TwoWayLinkedList<>();
    //static AbstractList<Integer> myList = new TwoWayCyclicLinkedList<>();
    public static void main(String[] args) {
        System.out.println(myList.isEmpty());

        myList.add(1);
        myList.add(2);
        myList.add(3);

        System.out.println(myList.isEmpty());

        for (int i : myList){
            System.out.print(i + "; ");
        }

        System.out.println("\n" + myList);

        myList.add(0, 4);
        myList.add(1, 5);

        System.out.println(myList);

        myList.remove((Integer) 2);

        System.out.println(myList);

        myList.remove(1);

        System.out.println(myList);
        System.out.println(myList.contains(8));
        System.out.println(myList.contains(3));

        myList.clear();

        System.out.println(myList);
    }
}