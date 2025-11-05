<%@ page contentType="text/html; charset=utf-8"%>
<html>
<head>
<title>Validation</title>
</head>
<script type="text/javascript">
	function checkForm() {
        // 1. JavaScript 구문 오류 수정 (+ 추가)
		alert("이름 : " + document.loginForm.me.value + "\n" + 
				"아이디 : "+ document.loginForm.id.value + "\n" + 
				"비밀번호 : "+ document.loginForm.passwd.value);
	}
</script>
<body>
	<form name="loginForm">
		<p>
			이름 : <input type='text' name='me'>
		<p>
			아 이 디 : <input type="text" name="id">
		<p>
			비밀번호 : <input type="password" name="passwd">
		<p>
            <input type="button" value="전송" onclick="checkForm()">
	</form>
</body>
</html>