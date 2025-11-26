<%@ page import="java.util.ArrayList" %>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%
    ArrayList<String> cart = (ArrayList<String>) session.getAttribute("cartList");  // (2) 세션 이름 작성

    if (cart == null) {
        cart = new ArrayList<String>();
    }

    String item = request.getParameter("item");  // (3) 폼에서 전달된 상품명 가져오기

    if (item != null && !item.trim().equals("")) {
        cart.add(item);
    }

    session.setAttribute("cartList", cart);  // (4) 세션에 장바구니 저장
%>

<% if (cart.size() == 0) { %>
    <p>장바구니가 비어 있습니다.</p>
<% } else { %>
    <ul>
        <% for (String i : cart) { %>
            <li><%= i %></li>
        <% } %>
    </ul>
<% } %>