<?php
$nameErr = $passwdErr = "";

if($_SERVER["REQUEST_METHOD"] == "POST"){
    if (empty($_POST["name"])) {
        $nameErr = "이름을 입력해주세요.";
    }

    if(!filter_var($_POST["passwd"], FILTER_VALIDATE_INT)) {
        $passwdErr = "비밀번호는 문자만 입력 가능합니다!";
    }
}
?>

<html>
<head>
    <title>유효성 검사</title>
    <style>.error {color: #FF0001;}</style>
</head>
<body>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>">
    <p>아 이 디 : <input type="text" name="name"><span class="error">* <?php echo $nameErr;?></span></p>
    <p>비밀번호 : <input type="text" name="passwd"><span class="error">* <?php echo $passwdErr;?></span></p>
    <p><input type="submit" value="검증"></p>
</form>

</body>
</html>