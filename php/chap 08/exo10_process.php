<!DOCTYPE html>
<html>
<head>
    <title>파일 업로드</title>
</head>
<body>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $subject1 = $_POST['subject1'];
    $subject2 = $_POST['subject2'];
    $filename1 = $_FILES['photo1']['name'];
    $filename2 = $_FILES['photo2']['name'];

    $target_path1 = "c:/upload/" . basename($filename1);
    if (file_exists("c:/upload/" . $filename1)) {
        $filename1 = time() . "_" . $filename1; // Appends timestamp if file exists
        $target_path1 = "c:/upload/" . $filename1;
    }

    $target_path2 = "c:/upload/" . basename($filename2);
    if (file_exists("c:/upload/" . $filename2)) {
        $filename2 = time() . "_" . $filename2; // Appends timestamp if file exists
        $target_path2 = "c:/upload/" . $filename2;
    }

    if (move_uploaded_file($_FILES['photo1']['tmp_name'], $target_path1) &&
        move_uploaded_file($_FILES['photo2']['tmp_name'], $target_path2)) {
        // Files uploaded successfully, now display the data in a table
?>
        <table border="1">
            <tr>
                <th width="100">제목</th>
                <th width="100">파일</th>
            </tr>
            <tr>
                <td><?php echo $subject1; ?></td>
                <td><?php echo $filename1; ?></td>
            </tr>
            <tr>
                <td><?php echo $subject2; ?></td>
                <td><?php echo $filename2; ?></td>
            </tr>
        </table>
<?php
    } else {
        echo "파일 업로드에 실패했습니다.";
    }
} else {
    echo "잘못된 접근입니다.";
}
?>

</body>
</html>