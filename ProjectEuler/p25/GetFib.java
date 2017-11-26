import java.math.BigInteger;

public class GetFib{
    public static void main(String [] args) {
        BigInteger b = BigInteger.ONE;
        BigInteger next = b.add(b), tmp = BigInteger.ZERO;

        int index = 3;
        for (; next.toString().length() < 1000; index++) {
            tmp = next;
            next = next.add(b);
            b = tmp;

            if (next.toString().length() % 10 == 0) {
                System.out.println (index + ": " + next.toString().length());
            }
        }
        System.out.println( index + "");
    }
}
