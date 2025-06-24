<html>
<head>
    <title>validation</title>
    <style>
        .error { color: #FF0000; }
    </style>
</head>
<body>

<?php
    $id = $_POST["id"] ?? '';
    $passwd = $_POST["passwd"] ?? '';

    $pattern1 = "/^[0-9]+$/";
    $pattern2 = "/^[a-zA-Z]+$/";
    $pattern3 = "/^[a-zA-Z0-9!@#$%^&*()_+\-=\[\]{};':\"\\|,.<>\/?~]+$/";

    $idValid = true;
    $passwdValid = true;
    $passwdError = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $id = $_POST["id"];
        $passwd = $_POST["passwd"];

        if (preg_match($pattern2, $passwd) && strlen($passwd) >= 8 && strlen($passwd) <= 50) {

        } else {
            $passwdError = "영문+숫자+특수기호 8자리 이상으로 구성하여야 합니다.";
            $passwdValid = false;

            echo "<p>아이디 : " . $id . "</p>";
            echo "<p>비밀번호 : " . $passwd . "</p>";
        }
    }
?>

<form name="form" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>" method="post">
    <p>아이디 : <input type="text" name="id" value="<?php echo htmlspecialchars($id); ?>"></p>
    <p>비밀번호 : <input type="text" name="passwd">
    <?php
        if (!$passwdValid):
            echo '<span class="error">' . $passwdError . '</span>';
        endif;
    ?>
    </p>
    <p><input type="submit" value="전송"></p>
</form>

</body>
</html>