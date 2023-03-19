import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
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
    public static void drawAFigure2(int n, int i){
        if(i == n) return;
        drawPyramid(i, n-i);
        drawAFigure2(n, i+1);
    }
    //shift or alg lub szukanie wzorca w tekscie + zlozonosc jego zapisac
    //swap na jednym stringu
    //wzorzec projektowy strategia zeby przelaczac miedzy wzorcami
    public static String pairSwap2(String text){
        ArrayList<String> words = new ArrayList<>();
        String lastWord = "";
        for (int i = 0; i < text.length(); i++) {
            if(text.charAt(i) == ' '){
                words.add(lastWord);
                lastWord = "";
            }
            else
                lastWord += text.charAt(i);
        }
        for (int i = 0; i < words.size(); i++) {
            String word = words.get(i);
            String key = "=";
            int equalsSignPos = shift_or(word, key);
            word += key;
            if(equalsSignPos >= 0) {
                for(int j = 0; j < equalsSignPos; j++){
                    word += word.charAt(0);
                    word.substring(1);
                }
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
    public static void printPair(String input){
        String output = pairSwap2(input);
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

        String input1 = "Litw0=0jczyzno moja, Ty jestes jak zdr0w13, ile C13=c3n1c, t3n ty1k0 si3 d0wie=_kt0 C13 stracil.";
        String input2 = "ania=makota,kot=_maanie KA=jak";
        String input3 = "_nia=makota, kot=ma?anie 1ka=_oaak";
        String input4 = "4nia=makota,kot=ma _anie _1ka=Ja1k";

        printPair(input1);
        printPair(input2);
        printPair(input3);
        printPair(input4);
    }
}