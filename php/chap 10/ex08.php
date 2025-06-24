<!DOCTYPE html>
<html>
<head>
    <title>숫자 처리</title>
    <meta charset="utf-8">
</head>
<body>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $num = $_POST["number"] ?? '';

    try {
        if (!filter_var($num, FILTER_VALIDATE_INT)) {
            throw new Exception("숫자가 아닙니다.");
        } else {
            $result = $num / 2;
            echo "결과: $num / 2 = " . $result;
        }
    } catch (Exception $e) {
        echo "오류 발생 : " . $e->getMessage();
    }
}
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
    <p>숫자: <input type="text" name="number"></p>
    <p><input type="submit" value="전송"></p>
</form>

</body>
</html>