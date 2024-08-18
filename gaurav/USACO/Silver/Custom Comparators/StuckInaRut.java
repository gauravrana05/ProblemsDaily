import java.util.*;

public class StuckInaRut {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    List<Integer> eastCows = new ArrayList<>();
    List<Integer> northCows = new ArrayList<>();
    int n = in.nextInt();
    int[] xs = new int[n];
    int[] ys = new int[n];

    for (int i = 0; i < n; i++) {
      if (in.next().charAt(0) == 'E') {
        eastCows.add(i);
      } else {
        northCows.add(i);
      }
      xs[i] = in.nextInt();
      ys[i] = in.nextInt();

    }
    eastCows.sort(Comparator.comparingInt(j -> ys[j]));
    northCows.sort(Comparator.comparingInt(j -> xs[j]));
    boolean[] isStopped = new boolean[n];
    int[] amtStopped = new int[n];
    for (int j : eastCows) {
      for (int k : northCows) {
        if (!isStopped[j] && !isStopped[k] && xs[k] > xs[j] && ys[j] > ys[k]) {
          if (xs[k] - xs[j] > ys[j] - ys[k]) {
            isStopped[j] = true;
            amtStopped[k] += 1 + amtStopped[j];
          } else if (xs[k] - xs[j] < ys[j] - ys[k]) {
            isStopped[k] = true;
            amtStopped[j] += 1 + amtStopped[k];

          }
        }
      }
    }
    for (int i = 0; i < n; i++) {
      System.out.println(amtStopped[i]);
    }
  }
}