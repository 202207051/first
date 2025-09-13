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
	<h2>50부터 150 사이의 랜덤 숫자</h2>
	<%
	int min = 50;
	int max = 150;

	Random rand = new Random();
	int randomNumber = rand.nextInt(max - min + 1) + min;
	%>
	<p>
		생성된 랜덤 숫자:
		<%=randomNumber%></p>
</body>
</html>