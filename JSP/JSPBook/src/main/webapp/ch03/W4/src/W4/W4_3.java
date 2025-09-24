//BankAc 클래스 생성
package W4;

class BankAc{
    private int balance; //잔액

    //입금 setter
    public void setBalance(int amount) {
        if( amount > 0 ) {
            balance = amount;
        } else {
            System.out.println("Check amount!");
        }
    }

    //잔액 조회 getter
    public int getBalance() {
        return balance;
    }
}

public class W4_3 {
    public static void main(String[] args) {
        // TODO Auto-generated method stub

        //인스턴스 변수 선언
        BankAc ac = new BankAc();

        //값 지정 : setter
        ac.setBalance(1000000);

        //값 확인 : getter
        System.out.println("Balance : " + ac.getBalance());

        ac.setBalance(-5000); //입금 오류
    }
}
