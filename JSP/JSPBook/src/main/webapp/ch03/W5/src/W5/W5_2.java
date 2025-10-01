package W5;

class Calculate{
    void add(int n1, int n2) {
        System.out.println("int type OL : " + (n1 + n2)); 
        //연산을 원하면 수식을 괄호로 처리
    }
    
    void add(double n1, double n2) {
        System.out.println("double type OL : " + (n1 + n2)); 
        //연산을 원하면 수식을 괄호로 처리
    }
}

public class W5_2 {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Calculate myCal = new Calculate();

        myCal.add(10,20);
        myCal.add(10.2,20.3);
    }
}

/* --- 실행 결과 ---
int type OL : 30
double type OL : 30.5
*/