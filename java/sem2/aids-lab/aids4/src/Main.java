public class Main {
    static OneWayCyclicLinkedList<Integer> mojaLista = new OneWayCyclicLinkedList<>();
    public static void main(String[] args) {

        System.out.println(mojaLista.isEmpty());

        mojaLista.add(1);
        mojaLista.add(2);
        mojaLista.add(3);

        System.out.println(mojaLista);

        mojaLista.add(0, 4);
        mojaLista.add(1, 5);

        System.out.println(mojaLista);

        mojaLista.remove((Integer) 2);

        System.out.println(mojaLista);
        System.out.println(mojaLista.contains(8));

        mojaLista.clear();

        System.out.println(mojaLista);



    }
}