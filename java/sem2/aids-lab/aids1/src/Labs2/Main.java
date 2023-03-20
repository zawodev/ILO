package Labs2;

import Labs2.SeriesGenerator.IntSeriesGenerator;
import Labs2.SeriesGenerator.StringSeriesGenerator;
import Labs2.SeriesIterator.Series;

public class Main  {
    public static void main(String[] args) {
        int n = 5;
        IntSeriesGenerator integerSeriesGenerator = new IntSeriesGenerator();
        StringSeriesGenerator stringSeriesGenerator = new StringSeriesGenerator();

        Series<Integer> intSeries = integerSeriesGenerator.generate(n);
        Series<String> stringSeries = stringSeriesGenerator.generate(n);

        for(Integer i : intSeries){
            System.out.print(i + " ");
        }
        System.out.println();

        for(String s : stringSeries){
            System.out.print(s + " ");
        }
    }
}
