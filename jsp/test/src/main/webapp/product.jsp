<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>상품 목록</title>
</head>
<body>
    <h2> 상품 목록</h2>
    <hr>
    <form action="cart.jsp" method="get">
        <p>
            <input type="radio" name="item" value="사과 (1000원)" checked> 사과 (1000원)
        </p>
        <p>
            <input type="radio" name="item" value="바나나 (2000원)"> 바나나 (2000원)
       
 </p>
        <p>
            <input type="radio" name="item" value="딸기 (3000원)"> 딸기 (3000원)
        </p>
        <p>
            <input type="radio" name="item" value="수박 (5000원)"> 수박 (5000원)
        </p>
        <p>
            <input type="submit" value="장바구니에 담기">
        
 </p>
    </form>
    <p>
        <a href="cart.jsp"> 장바구니 보기</a>
    </p>
    <p>
        <a href="clearCart.jsp"> 장바구니 비우기</a>
    </p>
</body>
</html>