import java.util.Arrays;
import java.util.Collections;

class CountingSort {
	public static int max(int[] array) {
		int greatest = array[0];
		for (int i = 0; i < array.length; i++) {
			if (array[i] > greatest) {
				greatest = array[i];
			}
		}
		return greatest;
	}
	public static int[] sort(int[] input) {
		int greatest = max(input);
		int[] counts = new int[greatest + 1];
		for (int i = 0; i < input.length; i++) {
			counts[input[i]]++;
		}
		int counter = 0;
		for (int i = 0; i < counts.length; i++) {
			for (int j = 0; j < counts[i]; j++) {
				input[counter++] = i;
			}
		}
		return input;
	}
	public static void main(String[] args) {
		int[] input = new int[args.length];
		for(int i = 0; i < args.length; i++) {
			input[i] = Integer.parseInt(args[i]);
		}
		int[] output = sort(input);
		for(int i = 0; i < args.length; i++) {
			System.out.print("" + output[i] + " ");
		}
		System.out.println("");
	}
}
