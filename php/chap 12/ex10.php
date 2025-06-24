<!DOCTYPE html>
<html>
<head>
    <title>세션</title>
</head>
<body>
    <?php
    session_start(); // 세션 시작

    if (isset($_SESSION["userID"]) && isset($_SESSION["userPW"])) {
        $user_id = $_SESSION["userID"];
        $user_pw = $_SESSION["userPW"];

        session_unset(); // 세션 종료
        header("Location: ex09.php");
        exit(); // 리디렉션 후 스크립트 종료
    } else {
        echo "설정된 세션 없음.";
    }
    ?>
</body>
</html>