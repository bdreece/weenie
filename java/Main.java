public class Main {
	public static void main(String[] args) {
        Main obj = new Main();
    	int n = args.length;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
        	a[i] = Integer.parseInt(args[i]);	
        }

        Main.bubbleSort(a, n);

        for (int i = 0; i < n; i++) {
        	System.out.print(Integer.toString(a[i]) + ", ");
        }
        System.out.println("");
    }

    public static void bubbleSort(int[] a, int n) {
    	boolean swapped = true;
        while (swapped) {
        	swapped = false;
            for (int i = 0; i < n - 1; i++) {
            	if (a[i] > a[i + 1]) {
                	int tmp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = tmp;
                    swapped = true;
                }
            }
        }
    }
}
