public class hw {

    public static void main(String[] args) {

        int cannedCoffeePurchasePrice = 500;
        int cannedCoffeeSellingPrice = 1800;
        int triangleKimbapPurchasePrice = 900;
        int triangleKimbapSellingPrice = 1400;
        int bananaMilkPurchasePrice = 800;
        int bananaMilkSellingPrice = 1800;
        int dosirakPurchasePrice = 3500;
        int dosirakSellingPrice = 4000;
        int cokePurchasePrice = 700;
        int cokeSellingPrice = 1500;
        int shrimpSnackPurchasePrice = 1000;
        int shrimpSnackSellingPrice = 2000;

        int triangleKimbapSold = 10;
        int bananaMilkSold = 2;
        int dosirakSold = 5;
        int cokeSold = 1;
        int shrimpSnackSold = 4;
        int cannedCoffeeSold = 5;

        int totalProfit = 0;

        totalProfit += (triangleKimbapSellingPrice - triangleKimbapPurchasePrice) * triangleKimbapSold;

        totalProfit += (bananaMilkSellingPrice - bananaMilkPurchasePrice) * bananaMilkSold;

        totalProfit += (dosirakSellingPrice - dosirakPurchasePrice) * dosirakSold;

        totalProfit += (cokeSellingPrice - cokePurchasePrice) * cokeSold;

        totalProfit += (shrimpSnackSellingPrice - shrimpSnackPurchasePrice) * shrimpSnackSold;

        totalProfit += (cannedCoffeeSellingPrice - cannedCoffeePurchasePrice) * cannedCoffeeSold;
        
        double taxRate = 0.10;
        int taxAmount = (int) (totalProfit * taxRate);

        int netProfit = totalProfit - taxAmount;

        System.out.println("오늘의 총 이익금: " + totalProfit + "원");
        System.out.println("세금 (총 이익의 10%): " + taxAmount + "원");
        System.out.println("오늘의 순 이익금: " + netProfit + "원");
    }
}

