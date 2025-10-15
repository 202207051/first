<%@ page contentType="text/html; charset=utf-8" %>
<html>
<head>
    <title>Form Processing</title>
</head>
<body>

    <h3>회원 가입</h3>

    <form action="#" name="member" method="post">
        
        <div>
            <label for="userId">아이디</label>
            <input type="text" id="userId" name="id">
            <button type="button">아이디 중복 검사</button>
        </div>

        <div>
            <label for="userPasswd">비밀번호</label>
            <input type="password" id="userPasswd" name="passwd">
        </div>

        <div>
            <label for="userName">이름</label>
            <input type="text" id="userName" name="name">
        </div>

        <div>
            <label for="phone1">연락처</label>
            <input type="text" id="phone1" name="phone1" maxlength="4" size="4"> -
            <input type="text" name="phone2" maxlength="4" size="4"> -
            <input type="text" name="phone3" maxlength="4" size="4">
        </div>

        <fieldset>
            <legend>성별</legend>
            <input type="radio" id="male" name="sex" value="남성" checked>
            <label for="male">남성</label>
            <input type="radio" id="female" name="sex" value="여성">
            <label for="female">여성</label>
        </fieldset>

        <fieldset>
            <legend>취미</legend>
            <input type="checkbox" id="hobby1" name="hobby1" value="reading" checked>
            <label for="hobby1">독서</label>
            <input type="checkbox" id="hobby2" name="hobby2" value="exercise">
            <label for="hobby2">운동</label>
            <input type="checkbox" id="hobby3" name="hobby3" value="movie">
            <label for="hobby3">영화</label>
        </fieldset>

        <div>
            <input type="submit" value="가입하기">
            <input type="reset" value="다시쓰기">
        </div>

    </form>

</body>
</html>