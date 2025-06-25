<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>회원가입 폼페이지</title>
</head>
<body>
    <?php
        function myMethod($exception){
            echo "예외 처리 발생: ",
        $exception->getMessage(),"<br>";     
        } 
        
        set_exception_handler("myMethod");
        throw new Exception("비밀번호는 숫자만 입력해주세요!");
    ?>
</body>
</html>