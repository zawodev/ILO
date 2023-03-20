package Labs2.SeriesGenerator;

import Labs2.SeriesIterator.Series;

public class StringSeriesGenerator implements SeriesGenerator{
    @Override
    public Series<String> generate(int n) {
        Series<String> stringSeries = new Series<>();
        String temp = "";
        for(int i = 0; i < n; i++){
            temp += "a";
            stringSeries.add(temp);
        }
        return stringSeries;
    }
}
