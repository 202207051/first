<!DOCTYPE html>
<html>
<head>
    <title>세션</title>
    <meta charset="utf-8">
</head>
<body>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $user_id = $_POST["id"] ?? '';
    $user_pw = $_POST["passed"] ?? '';

    if ($user_id === "admin" && $user_pw === "1234") {
        session_start();
        $_SESSION["userID"] = $user_id;
        $_SESSION["userPW"] = $user_pw;

        echo "<h4>" . $user_id . "님 반갑습니다.</h4>";
        echo "<a href='ex10.php'>로그아웃</a>";
    } else {
        echo "세션 설정에 실패했습니다.";
    }
}
?>

</body>
</html>