class BankAccount {
	String name; // 고객명
	double balance; // 계좌 잔고
	static int count; // 고객 수
	BankAccount(String name, double balance) {
		this.name = name;
		this.balance = balance;
		count ++;
		System.out.println(name + " 고객의 잔고 : " + balance);
	}
}
public class code99 {
	public static void main(String[] args) {
		BankAccount ba1 = new BankAccount("Alice", 100000);
		BankAccount ba2 = new BankAccount("Paul", 50000);
		BankAccount ba3 = new BankAccount("Cindy", 30000);
		BankAccount ba4 = new BankAccount("David", 150000);
		BankAccount ba5 = new BankAccount("Tom", 200000);

		System.out.println();
		System.out.println("number of accounts : " + BankAccount.count);
	}
}