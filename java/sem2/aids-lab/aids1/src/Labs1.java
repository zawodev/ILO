import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class Labs1 {
    public static void drawPyramid(int n, int h){
        for(int i = 0; i < h; i++){
            String s = "";
            for(int j = 0; j < h-i-1; j++){
                s+=" ";
            }
            for(int j = 0; j < 2*(i+n)+1; j++){
                s+="X";
            }
            System.out.println(s);
        }
    }
    public static void drawAFigure(int n){
        for(int i = 0; i < n; i++){
            drawPyramid(i,n-i);
        }
    }
    public static void drawAFigure2(int n, int i){ //rekurencyjny
        if(i == n) return;
        drawPyramid(i, n-i);
        drawAFigure2(n, i+1);
    }


    //shift or alg lub szukanie wzorca w tekscie + zlozonosc jego zapisac
    //swap na jednym stringu
    //wzorzec projektowy strategia zeby przelaczac miedzy wzorcami
    public static String SwapWords(String text, String key){
        return text;
    }
    public static String Exercise2(String text){
        ArrayList<String> words = new ArrayList<>();
        String lastWord = "";
        for (int i = 0; i < text.length(); i++) {
            if(text.charAt(i) == ' '){
                words.add(lastWord);
                lastWord = "";
            }
            else {
                lastWord += text.charAt(i);
                if (i == text.length() - 1) words.add(lastWord);
            }
        }
        for (int i = 0; i < words.size(); i++) {
            String word = words.get(i);
            //String key = "e=ni";
            String key = "=";
            int equalsSignPos = shift_or(word, key);
            if(equalsSignPos > 0) {
                word += key;
                if (equalsSignPos >= 0) {
                    for (int j = 0; j < equalsSignPos; j++) {
                        word = (word + word.charAt(0)).substring(1);
                    }
                }
                word = word.substring(key.length());
                words.set(i, word);
            }
        }
        text = String.join(" ", words);
        return text;
    }
    public static String pairSwap(String text) {
        String key = "[ ,.:;?/!]";
        String[] words = text.split(key);
        ArrayDeque<Character> queue = new ArrayDeque<>();
        for (int i = 0; i < text.length(); i++)
            if(key.indexOf(text.charAt(i)) > 0)
                queue.add(text.charAt(i));

        System.out.println(Arrays.toString(words));
        for (int i = 0; i < words.length; i++) {
            String[] ids = words[i].split("=");
            if (isValidPair(ids)) {
                if (ids.length == 2) {
                    words[i] = ids[1] + "=" + ids[0];
                }
            }
        }

        text = "";
        int i = 0;
        while(i < words.length || !queue.isEmpty()) {
            if(i < words.length) {
                text += words[i];
                i++;
            }
            if(!queue.isEmpty()) {
                text += queue.getFirst();
                queue.removeFirst();
            }
        }
        return text;
        //return String.join(" ", words);
    }

    private static boolean isValidPair(String[] ids) {
        if (ids.length != 2)
            return false;

        for (String id : ids)
            if (!isValidId(id))
                return false;

        return true;
    }

    private static boolean isValidId(String text) {
        if (text.isEmpty() || !Character.isLetter(text.charAt(0)) && text.charAt(0) != '_')
            return false;

        for (int i = 1; i < text.length(); i++)
            if (!Character.isLetterOrDigit(text.charAt(i)))
                return false;

        return true;
    }
    public static int shift_or(String t, String p) {
        int m = p.length();//length of pattern.
        long[] pattern_mask = new long[256];//creation of array.
        long R = ~1;

        if (m == 0)
            return -1;//If no pattern has been given.
        if (m >63) {
            return -1;
        }
        for (int i = 0; i <=255; ++i){
            pattern_mask[i] = ~0;//initializing pattern mask array.
        }
        for (int i = 0; i < m; ++i){
            pattern_mask[p.charAt(i)] &= ~(1L << i);
        }
        for (int i = 0; i < t.length(); ++i) {
            R |= pattern_mask[t.charAt(i)];
            R <<= 1;
            if ((R & (1L << m)) == 0)
                return i - m + 1;
        }
        return -1;
    }
    public static void printPyramid(String exNum, int n, int h){
        System.out.println("\nZAD " + exNum + ", n: " + n + ", h: " + h);
        drawPyramid(n, h);
    }
    public static void printFigure(String exNum, int n){
        System.out.println("\nZAD " + exNum + ", n: " + n);
        drawAFigure(n);
        //drawAFigure2(n, 0);
    }
    public static void printExercise2(String input){
        String output = Exercise2(input);
        System.out.println(input);
        System.out.println(output+"\n");
    }

    public static void main(String[] args) {

        printPyramid("1a1", 3, 5);
        printPyramid("1a2", 3, 7);
        printPyramid("1a3", 2, 3);
        printPyramid("1a4", 1, 4);
        printPyramid("1a5", 0, 4);

        System.out.println("\n========================");

        printFigure("1b1", 4);
        printFigure("1b2", 2);

        System.out.println("\n========================\nZAD 2\n========================");

        String input1 = "WOW ale to bylo ciekawe=interesujace doswiadczenie";
        String input2 = "jak to jest byc skryba dobrze=nie ma tak ze dobrze albo nie dobrze";
        String input3 = "halo halo tu polskie=radio radio=pio pio slowikowe radio";
        String input4 = "dzien=dobry halo=malo shiftuje or=nie shitfuje oto jest pytanie";

        printExercise2(input1);
        printExercise2(input2);
        printExercise2(input3);
        printExercise2(input4);

        String s = "ABCDEF";
        System.out.println((s + s.charAt(0)).substring(1));
    }
}