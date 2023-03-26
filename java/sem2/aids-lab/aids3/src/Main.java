public class Main {
    public static void main(String args[]){
        OneWayLinkedListWithSentinel<Integer> integers = new OneWayLinkedListWithSentinel<>();
        OneWayLinkedListWithSentinel<String> strings = new OneWayLinkedListWithSentinel<>();

        System.out.println(integers);
        System.out.println(strings);
        System.out.println();

        integers.add(2);
        strings.add("darek");

        System.out.println(integers);
        System.out.println(strings);
        System.out.println();

        integers.add(6);
        integers.add(8);
        strings.add("g");
        strings.add("k");
        strings.add("s");

        System.out.println(integers);
        System.out.println(strings);
        System.out.println();
    }
}
