<%@ page contentType="text/html; charset=UTF-8" %>
<html>
<head>
<title>Validation</title>
<script type="text/javascript">
    function checkLogin() {
        var form = document.loginForm;
        
        if (form.id.value == "") {
            alert("아이디를 입력해주세요.");
            form.id.focus();
            return false; 
        } 
        else if (form.passwd.value == "") {
            alert("비밀번호를 입력해주세요");
            form.passwd.focus();
            return false; 
        }
        
        return true;
    }
</script>
</head>
<body>

    <form name="loginForm" action="validation02_process.jsp" method="post" onsubmit="return checkLogin();">
        <p> 아 이 디 : <input type="text" name="id"> </p>
        <p> 비밀번호 : <input type="password" name="passwd"> </p>
        
        <p> <input type="submit" value="전송"> </p>
    </form>

</body>
</html>