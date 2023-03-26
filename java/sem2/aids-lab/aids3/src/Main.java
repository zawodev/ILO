public class Main {
    public static void main(String args[]){
        OneWayLinkedListWithSentinel<Integer> integers = new OneWayLinkedListWithSentinel<>(10);
        OneWayLinkedListWithSentinel<String> strings = new OneWayLinkedListWithSentinel<>("10");

        integers.add(2);
        integers.add(6);

        strings.add("(3)");
        strings.add("a");

        for(Integer i : integers){
            System.out.print(i + " ");
        }
        System.out.println();
        for(String s : strings){
            System.out.print(s + " ");
        }
    }
}
