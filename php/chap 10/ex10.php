<!DOCTYPE html>
<html>
<head>
    <title>로그인</title>
    <meta charset="utf-8">
</head>
<body>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST["id"] ?? '';
    $passed = $_POST["passed"] ?? '';

    try {
        if (empty($id)) {
            throw new Exception("<p>ID를 입력하세요!</p>");
        }
        if (empty($passed)) {
            throw new Exception("<p>비밀번호를 입력하세요!</p>");
        }

        echo "<p>로그인이 성공했습니다.</p>";

    } catch (Exception $e) {
        echo $e->getMessage();
    }
}
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
    <p>아이디: <input type="text" name="id"></p>
    <p>비밀번호: <input type="password" name="passed"></p>
    <p><input type="submit" value="로그인"></p>
</form>

</body>
</html>
