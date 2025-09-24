<%@ page contentType="text/html; charset=utf-8" %>
<html>
<head>
    <title>Action Tag</title>
</head>
<body>
    <jsp:useBean id="person" class="ch04.com.dao.Person" scope="request" />
    <p>아이디 : <%=person.getid() %></p>
    <p>이름 : <%=person.getName() %></p>
</body>
</html>