<%@ page contentType="text/html; charset=UTF-8" %>
<!DOCTYPE html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <title>File Upload</title>
</head>
<body>
    <form name="fileForm" method="post" enctype="multipart/form-data"
          action="fileupload01_process.jsp">

        <p>
            이름 : <input type="text" name="name" required>
        </p>
        <p>
            제목 : <input type="text" name="subject" required>
        </p>
        <p>
            **파일** : <input type="file" name="filename" required>
        </p>
        
        <p>
            <input type="submit" value="파일 올리기">
        </p>
    </form>
</body>
</html>