<!DOCTYPE html>
<html>
<head>
    <title>파일 업로드</title>
</head>
<body>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_FILES["photo"]) && $_FILES["photo"]["error"] == 0) {
    $allowed = array("jpg" => "image/jpeg", "jpeg" => "image/jpeg", "gif" => "image/gif", "png" => "image/png");
    $filename = $_FILES["photo"]["name"];
    $filetype = $_FILES["photo"]["type"];
    $filesize = $_FILES["photo"]["size"];

    $ext = pathinfo($filename, PATHINFO_EXTENSION);
    if (!array_key_exists($ext, $allowed)) die("오류: 올바른 파일 형식을 선택하세요.");

    $maxsize = 5 * 1024 * 1024;
    if ($filesize > $maxsize) die("오류: 파일 크기가 허용된 한도를 초과합니다.");

    $original_filename = $filename;

    if (file_exists("c:/upload/" . $filename)) {
        $filename = time() . "_" . $filename;
    }

    if (move_uploaded_file($_FILES["photo"]["tmp_name"], "c:/upload/" . $filename)) {
        echo "실제 파일 이름: " . $original_filename . "<br>";
        echo "저장 파일 이름: " . $filename . "<br>";
        echo "파일 콘텐츠 유형: " . $filetype . "<br>";
        echo "파일 크기: " . $filesize . " bytes<br>";
    } else {
        echo "파일 업로드 실패!<br>";
    }
} else {
    echo "오류: " . $_FILES["photo"]["error"] . "<br>";
}
?>
</body>
</html>