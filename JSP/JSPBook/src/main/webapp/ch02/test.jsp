<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.util.Random"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>랜덤 숫자 생성기</title>
</head>
<body>
	<h2>1부터 100 사이의 랜덤 숫자</h2>
	<%
	Random rand = new Random();
	int randomNumber = rand.nextInt(100) + 1;
	%>
	<p>
		생성된 랜덤 숫자:
		<%=randomNumber%></p>
</body>
</html>