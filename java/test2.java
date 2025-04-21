public class test2 {
    public static void add(float x, float y) {
        System.out.println("두 수의 합? " + (x + y));
    }

    public static void sub(int x, int y) {
        System.out.println("두 수의 차차? " + (x - y));
    }

    public static void mult(int x, int y) {
        System.out.println("두 수의 곱? " + (x * y));
    }

    public static void div(int x, int y) {
        System.out.println("두 수의 나누기? " + (x / y));
    }

    public static void main(String[] args) {
        int a = 10, b = 6;
        add(a, b);
        sub(a, b);
        mult(a, b);
        div(a, b);
    }
}
