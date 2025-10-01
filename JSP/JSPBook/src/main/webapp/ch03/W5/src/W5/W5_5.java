package W5;

class Student{
    String name;

    public Student(String name){
        this.name = name;
    }

    public void sayHello() {
        System.out.println("Hi! I'm " + name );
    }
}

public class W5_5 {
    public static void main(String[] args) {
        Student[] st = new Student[3];

        st[0] = new Student("Panda");
        st[1] = new Student("House");
        st[2] = new Student("Happy");

        for( int i = 0; i < st.length; i++ ) {
            st[i].sayHello();
        }
    }
}