<!DOCTYPE html>
<html>
<head>
    <title>쿠키</title>
</head>
<body>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $user_id = $_POST["id"];
        $user_pw = $_POST["passwd"];

        if ($user_id === "admin" && $user_pw === "1234") {
            setcookie("userID", $user_id);
            setcookie("userPW", $user_pw);

            echo "<h4>" . $user_id . "님 반갑습니다.</h4>";
            echo "<a href='ex10.php'>로그아웃</a>";
        } else {
            echo "쿠키 설정에 실패했습니다.";
        }
    }
    ?>
</body>
</html>