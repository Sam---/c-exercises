import java.util.Scanner;
import java.util.Arrays;
import static java.lang.Math.min;
import static java.lang.Math.max;


public class WordSwap {
    private static int costToSwap(String word1, String word2) {
        /* ------------------- INSERT CODE HERE ---------------------*/
    	int result = 0;
    	for (int i = 0; i < min(word1.length(), word2.length()); i++) {
    		result += word1.codePointAt(i) - word2.codePointAt(i);
    	}
    	
    	return result;
        /* -------------------- END OF INSERTION --------------------*/
    }

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int numOfTestCases = sc.nextInt();

		for (int testCase=0; testCase < numOfTestCases; testCase++) {
			String word1 = sc.next();
			String word2 = sc.next();

			int cost = costToSwap(word1, word2);

			System.out.print(
				"Swapping letters to make " +
				word1 + 
				" look like " +
				word2 
			);
			if (cost > 0) {
				System.out.println(
					" earned " + cost + " coins."
				);
			}
			else if (cost < 0) {
				System.out.println(
					" cost " + ((-1)*(cost)) + " coins."
				);
			}
			else {
				System.out.println(
					" was FREE."
				);
			}

		}
		
		sc.close();
	}
}

