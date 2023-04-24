import java.util.Arrays;
import java.util.Comparator;

public class SorterClass {
    public static void binaryInsertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int insertIndex = binarySearch(arr, 0, i - 1, key);
            for (int j = i - 1; j >= insertIndex; j--) {
                arr[j + 1] = arr[j];
            }
            arr[insertIndex] = key;
        }
    }

    public static int binarySearch(int[] arr, int left, int right, int key) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == key) {
                return mid + 1;
            } else if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    public static void selectionSortWithMinMax(int[] arr) {
        int n = arr.length;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int minIndex = i, maxIndex = j;
            for (int k = i; k <= j; k++) {
                if (arr[k] < arr[minIndex]) {
                    minIndex = k;
                }
                if (arr[k] > arr[maxIndex]) {
                    maxIndex = k;
                }
            }
            swap(arr, i, minIndex);
            if (arr[minIndex] == arr[maxIndex]) {
                break;
            }
            swap(arr, j, maxIndex);
        }
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    public static void shakerSort(int[] arr) {
        int n = arr.length;
        int left = 0, right = n - 1;
        while (left <= right) {
            for (int i = left; i < right; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr, i, i + 1);
                }
            }
            right--;
            for (int i = right; i > left; i--) {
                if (arr[i - 1] > arr[i]) {
                    swap(arr, i - 1, i);
                }
            }
            left++;
        }
    }
    public static void main(String[] args) {
        Comparator<Integer> comparator = new MyComparator<>();
        int[] arr = {5, 1, 3, 2, 4};
        binaryInsertionSort(arr);
        System.out.println(Arrays.toString(arr)); // [1, 2, 3, 4, 5]

        arr = new int[]{5, 1, 3, 2, 4};
        selectionSortWithMinMax(arr);
        System.out.println(Arrays.toString(arr)); // [1, 2, 3, 4, 5]

        arr = new int[]{5, 1, 3, 2, 4};
        shakerSort(arr);
        System.out.println(Arrays.toString(arr)); // [1, 2, 3, 4, 5]
    }
}