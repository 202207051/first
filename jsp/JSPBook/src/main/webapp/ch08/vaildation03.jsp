<%@ page contentType="text/html; charset=UTF-8"%>
<html>
<head>
<title>Validation</title>
</head>
<body>

	<form id="loginForm" action="validation03_process.jsp" method="post">
		<p>
			아 이 디 : <input type="text" name="id" id="loginId">
		</p>
		<p>
			비밀번호 : <input type="password" name="passwd" id="loginPasswd">
		</p>
		<p>
			<input type="submit" value="전송">
		</p>
	</form>

	<script type="text/javascript">
        document.getElementById("loginForm").addEventListener("submit", function(event) {
            
            const idField = document.getElementById("loginId");
            const passwdField = document.getElementById("loginPasswd");
            
            const idValue = idField.value;
            const passwdValue = passwdField.value;

            if (idValue.length < 4 || idValue.length > 12) {
                alert("아이디는 4~12자 이내로 입력 가능합니다!");
                idField.select();
                event.preventDefault(); 
                return; 
            }

            if (passwdValue.length < 4) {
                alert("비밀번호는 4자 이상으로 입력해야 합니다!");
                passwdField.select();
                event.preventDefault(); 
                return; 
            }
            
        });
    </script>

</body>
</html>