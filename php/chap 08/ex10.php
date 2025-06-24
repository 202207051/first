<!DOCTYPE html>
<html>
<head>
    <title>파일 업로드</title>
</head>
<body>
    <form method="post" enctype="multipart/form-data" action="ex10_process.php">
        <p>제목1 : <input type="text" name="subject1"></p>
        <p>파일1 : <input type="file" name="photo1"></p>
        <p>제목2 : <input type="text" name="subject2"></p>
        <p>파일2 : <input type="file" name="photo2"></p>
        <p><input type="submit" value="파일 업로드"></p>
    </form>
</body>
</html>