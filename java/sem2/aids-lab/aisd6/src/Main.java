import java.util.Comparator;
import java.util.List;

import core.SortingAlgorithm;
import testing.*;
import testing.generation.*;
import testing.generation.array.*;

public class Main {

	public static void main(String[] args) {
		Comparator<Integer> comparator = new MyComparator<>();
		
		Comparator<MarkedValue<Integer>> markedComparator = new MarkedValueComparator<>(comparator);
		Generator<MarkedValue<Integer>> generator = new RandomMarkedIntegerArrayGenerator(1000);

		SortingAlgorithm<MarkedValue<Integer>> algorithm = new BubbleSort<>(markedComparator);
		
		Result result = Tester.runNTimes(algorithm, generator, 1000, 1000);
		
		System.out.println("time [ms]: " + result.averageTimeInMilliseconds() + " +- " + result.timeStandardDeviation());
		System.out.println("comparisons: " + result.averageComparisons() + " +- " + result.comparisonsStandardDeviation());
		System.out.println("swaps: " + result.averageSwaps() + " +- " + result.swapsStandardDeviation());
		System.out.println("always sorted: " + result.sorted());
		System.out.println("always stable: " + result.stable());
	}

}
