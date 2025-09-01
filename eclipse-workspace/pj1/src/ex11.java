public class ex11 {

    public static void main(String[] args) {
        // Define purchase and sales prices
        int canCoffeePurchase = 500;
        int canCoffeeSale = 1800;
        int triangleKimbapPurchase = 900;
        int triangleKimbapSale = 1400;
        int bananaMilkPurchase = 800;
        int bananaMilkSale = 1800;
        int lunchBoxPurchase = 3500;
        int lunchBoxSale = 4000;
        int colaPurchase = 700;
        int colaSale = 1500;
        int shrimpSnackPurchase = 1000;
        int shrimpSnackSale = 2000;

        // Calculate total sales and purchase costs based on today's sales record
        long totalSales = 0;
        long totalPurchaseCost = 0;

        // Today's sales and purchases
        // 1. 삼각 김밥 (Triangle Kimbap)
        // Image shows: "삼각 김밥(900원) 10개 구입" and "삼각 김밥(1400원) ?" - the number of triangle kimbap sold is not specified. 
        // Based on the context of the problem asking for profit from sales, we can assume the purchases listed are the initial stock for the day, and we calculate profit based on what was sold.
        // There is a slight ambiguity in the image; it lists "구입" (purchase) and "판매" (sale) events mixed together. 
        // The prompt asks to calculate profit from today's sales ("오늘 판매하여 얻은 순 이익금").
        // Let's assume the purchase records are stock purchases, and we only need the sales records for profit calculation.
        // We will calculate profit based on the items sold.

        // Sale of Banana Milk
        int bananaMilkSold = 2;
        totalSales += (long) bananaMilkSold * bananaMilkSale;
        totalPurchaseCost += (long) bananaMilkSold * bananaMilkPurchase;

        // Sale of Lunch Boxes
        int lunchBoxSold = 4;
        totalSales += (long) lunchBoxSold * lunchBoxSale;
        totalPurchaseCost += (long) lunchBoxSold * lunchBoxPurchase;

        // Sale of Cola
        int colaSold = 1;
        totalSales += (long) colaSold * colaSale;
        totalPurchaseCost += (long) colaSold * colaPurchase;

        // Sale of Shrimp Snacks
        int shrimpSnackSold = 4;
        totalSales += (long) shrimpSnackSold * shrimpSnackSale;
        totalPurchaseCost += (long) shrimpSnackSold * shrimpSnackPurchase;

        // Sale of Can Coffee
        int canCoffeeSold = 5;
        totalSales += (long) canCoffeeSold * canCoffeeSale;
        totalPurchaseCost += (long) canCoffeeSold * canCoffeePurchase;

        // Calculate gross profit
        long grossProfit = totalSales - totalPurchaseCost;

        // Calculate tax (10% of profit)
        double tax = grossProfit * 0.10;

        // Calculate net profit
        double netProfit = grossProfit - tax;

        // Print the results
        System.out.println("총 판매 금액: " + totalSales + "원");
        System.out.println("총 구입 원가: " + totalPurchaseCost + "원");
        System.out.println("총 이익금 (세전): " + grossProfit + "원");
        System.out.println("세금 (10%): " + (int) tax + "원");
        System.out.println("순 이익금 (세후): " + (int) netProfit + "원");
    }
}