package W5;

class Cal{
    int add(int n1, int n2) {
        return n1 + n2;
    }
    
    double add(double n1, double n2) {
        return n1 + n2;
    }
}

public class W5_3 {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Cal myCal = new Cal();

        System.out.println("int type OL : " + myCal.add(10,20));
        System.out.println("double type OL : " + myCal.add(10.2,20.3));
    }
}