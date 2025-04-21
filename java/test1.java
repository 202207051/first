public class test1 {
    public static void greeting1() {
        System.out.println("Good morning");
    }

    public static void greeting2() {
        System.out.println("Good afternoon");
    }

    public static void greeting3() {
        System.out.println("Good evening");
    }

    public static void main(String[] args) {
        System.out.print("In the morning --> ");
        greeting1();
        System.out.print("In the afternoon --> ");
        greeting2();
        System.out.print("In the evening --> ");
        greeting3();
    }
}
