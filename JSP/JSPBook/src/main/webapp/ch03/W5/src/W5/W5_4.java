package W5;

class aa {
    public void greet() {
        System.out.println("Hello~!");
    }
}

class bb {
    aa a = new aa();

    public void start() {
        a.greet();
    }
}

public class W5_4 {
    public static void main(String[] args) {
        bb b = new bb();
        b.start();
    }
}