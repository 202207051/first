<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="com.oreilly.servlet.MultipartRequest" %>
<%@ page import="com.oreilly.servlet.multipart.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.io.*" %>
<html>
<head>
    <title>File Upload</title>
</head>
<body>
<%
    // 파일 업로드 처리 (MultipartRequest 객체 생성)
    // 경로: C:\\upload, 최대 크기: 5MB, 인코딩: UTF-8, 파일명 중복 처리 정책 적용
    MultipartRequest multi = new MultipartRequest(request, "C:\\upload",
            5 * 1024 * 1024, "UTF-8", new DefaultFileRenamePolicy());

    // 1. 일반 폼 파라미터(이름, 제목)를 변수에 저장
    String name1 = multi.getParameter("name1");
    String subject1 = multi.getParameter("subject1");

    String name2 = multi.getParameter("name2");
    String subject2 = multi.getParameter("subject2");

    String name3 = multi.getParameter("name3");
    String subject3 = multi.getParameter("subject3");

    // 2. 파일 파라미터 처리 (파일 필드의 name 속성 목록을 가져옴)
    Enumeration files = multi.getFileNames();

    // Enumeration은 일반적으로 FIFO(First-In, First-Out) 순서이지만,
    // getFileNames()의 순서는 브라우저에 따라 역순(LIFO)이 될 수 있습니다.
    // 이전 폼(fileupload02.jsp)의 파일 필드 순서: filename1, filename2, filename3
    // 여기서는 역순(filename3 -> filename2 -> filename1)으로 처리하고 있습니다.

    // 첫 번째 요소 가져오기 (filename3)
    String file3 = (String) files.nextElement();
    // 저장된 파일명 가져오기
    String filename3 = multi.getFilesystemName(file3);

    // 두 번째 요소 가져오기 (filename2)
    String file2 = (String) files.nextElement();
    String filename2 = multi.getFilesystemName(file2);

    // 세 번째 요소 가져오기 (filename1)
    String file1 = (String) files.nextElement();
    String filename1 = multi.getFilesystemName(file1);
%>
    <table border="1">
        <tr>
            <th width="100">이름</th>
            <th width="100">제목</th>
            <th width="100">파일</th>
        </tr>
<%
        // 첫 번째 파일 정보 출력
        out.print("<tr><td>" + name1 + "</td>");
        out.print("<td>" + subject1 + "</td>");
        out.println("<td>" + filename1 + "</td></tr>\n");

        // 두 번째 파일 정보 출력
        out.print("<tr><td>" + name2 + "</td>");
        out.print("<td>" + subject2 + "</td>");
        out.println("<td>" + filename2 + "</td></tr>\n");

        // 세 번째 파일 정보 출력
        out.print("<tr><td>" + name3 + "</td>");
        out.print("<td>" + subject3 + "</td>");
        out.println("<td>" + filename3 + "</td></tr>\n");
%>
    </table>
</body>
</html>