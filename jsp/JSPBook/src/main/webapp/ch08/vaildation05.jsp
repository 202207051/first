<%@ page contentType="text/html; charset=utf-8" %>
<html>
<head>
<title>Validation</title>
<script type="text/javascript">
    // 💡 DOM(문서 객체 모델)이 완전히 로드된 후 스크립트를 실행합니다.
    document.addEventListener("DOMContentLoaded", function() {

        // 💡 id로 폼 엘리먼트를 선택합니다.
        const form = document.getElementById("memberForm");

        // 💡 폼에서 'submit' 이벤트가 발생했을 때 실행될 함수를 연결합니다.
        form.addEventListener("submit", function(event) {
            
            // --- 유효성 검사를 위한 정규 표현식 ---
            const regExpId = /^[a-z|A-Z|ㄱ-ㅎ|ㅏ-ㅣ|가-힣]/;
            const regExpName = /^[가-힣]*$/;
            const regExpPasswd = /^[0-9]*$/;
            const regExpPhone = /^\d{3}-\d{3,4}-\d{4}$/;
            const regExpEmail = /^[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*\.[a-zA-Z]{2,3}$/i;

            // --- 폼 필드 값 가져오기 ---
            const id = form.id.value;
            const name = form.name.value;
            const passwd = form.passwd.value;
            const phone = form.phone1.value + "-" + form.phone2.value + "-" + form.phone3.value;
            const email = form.email.value;

            // --- 유효성 검사 시작 ---
            if (!regExpId.test(id)) {
                alert("아이디는 문자로 시작해주세요!");
                form.id.select(); // 아이디 필드에 포커스
                event.preventDefault(); // 💡 폼 제출(submit)을 막습니다.
                return;
            }

            if (!regExpName.test(name)) {
                alert("이름은 한글만 입력해주세요!");
                event.preventDefault(); // 💡 폼 제출을 막습니다.
                return;
            }

            if (!regExpPasswd.test(passwd)) {
                alert("비밀번호는 숫자만 입력해주세요!");
                event.preventDefault(); // 💡 폼 제출을 막습니다.
                return;
            }

            if (!regExpPhone.test(phone)) {
                alert("연락처 입력을 확인해주세요!");
                event.preventDefault(); // 💡 폼 제출을 막습니다.
                return;
            }

            if (!regExpEmail.test(email)) {
                alert("이메일 입력을 확인해주세요!");
                event.preventDefault(); // 💡 폼 제출을 막습니다.
                return;
            }

            // 💡 모든 유효성 검사를 통과하면 event.preventDefault()가 호출되지 않아
            // 폼이 <form> 태그의 'action' 속성에 지정된 'validation05_process.jsp'로 제출됩니다.
        });
    });
</script>
</head>
<body>
    <h3>회원 가입</h3>
    
    <form action="validation05_process.jsp" name="Member" id="memberForm" method="post">
        <p> 아이디 : <input type="text" name="id">
        <p> 비밀번호 : <input type="password" name="passwd">
        <p> 이름 : <input type="text" name="name">
        <p> 연락처 : <select name="phone1">
                <option value="010">010</option>
                <option value="011">011</option>
                <option value="016">016</option>
                <option value="017">017</option>
                <option value="019">019</option>
            </select>
            - <input type="text" maxlength="4" size="4" name="phone2">
            - <input type="text" maxlength="4" size="4" name="phone3">
        <p> 이메일 : <input type="text" name="email">
        
        <p> <input type="submit" value="가입하기">
    </form>
</body>
</html>