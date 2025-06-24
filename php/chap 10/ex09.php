<html>
<head>
    <title>exception</title>
</head>
<body>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $num1 = $_POST['number1'];
    $num2 = $_POST['number2'];

    if ($num2 == 0) {
        function exceptionMethod($exception) {
            echo "예외 처리 발생 : ", $exception->getMessage(), "<br>";
        }

        set_exception_handler('exceptionMethod');

        throw new Exception("0으로 나눌 수 없습니다.");
    }

    $result = $num1 / $num2;
    echo "결과 : $num1 / $num2 = $result";
}
?>

<form method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>">
    <p>숫자1 : <input type="text" name="number1"></p>
    <p>숫자2 : <input type="text" name="number2"></p>
    <p><input type="submit" value="계산"></p>
</form>

</body>
</html>