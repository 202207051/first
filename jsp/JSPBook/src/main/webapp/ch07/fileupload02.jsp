<%@ page contentType="text/html; charset=UTF-8" %>
<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <title>File Upload</title>
</head>
<body>
    <form name="fileForm" method="post" enctype="multipart/form-data"
          action="fileupload02_process.jsp">

        <p>
            이름 1 : <input type="text" name="name1" required>
        </p>
        <p>
            제목 1 : <input type="text" name="subject1" required>
        </p>
        <p>
            **파일 1** : <input type="file" name="filename1" required>
        </p>

        <hr>

        <p>
            이름 2 : <input type="text" name="name2">
        </p>
        <p>
            제목 2 : <input type="text" name="subject2">
        </p>
        <p>
            **파일 2** : <input type="file" name="filename2">
        </p>
        
        <hr>

        <p>
            이름 3 : <input type="text" name="name3">
        </p>
        <p>
            제목 3 : <input type="text" name="subject3">
        </p>
        <p>
            **파일 3** : <input type="file" name="filename3">
        </p>
        
        <hr>

        <p>
            <input type="submit" value="파일 올리기">
        </p>
    </form>
</body>
</html>