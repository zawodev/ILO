package Labs2.SeriesGenerator;

import Labs2.SeriesIterator.Series;

public class IntSeriesGenerator implements SeriesGenerator{
    @Override
    public Series<Integer> generate(int n) {
        Series<Integer> intSeries = new Series<>();
        for(int i = 0; i < n; i++){
            intSeries.add((i+1)*2);
        }
        return intSeries;
    }
}
