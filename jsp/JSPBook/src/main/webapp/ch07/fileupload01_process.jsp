<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="com.oreilly.servlet.MultipartRequest" %>
<%@ page import="com.oreilly.servlet.multipart.*" %>
<%@ page import="java.util.*" %>
<%@ page import="java.io.*" %>

<%
    // 파일이 업로드될 디렉토리 (예시 경로)
    String uploadPath = "C:\\upload"; 
    
    // 최대 파일 크기 (5MB 설정)
    int maxFileSize = 5 * 1024 * 1024;
    
    // 파일명 인코딩 방식
    String encoding = "UTF-8";
    
    // 파일명 중복 시 처리 방식
    FileRenamePolicy policy = new DefaultFileRenamePolicy();

    // MultipartRequest (멀티파트리퀘스트) 객체 생성: 이 시점에 파일 업로드가 완료됩니다.
    MultipartRequest multi = new MultipartRequest(request, uploadPath, maxFileSize, encoding, policy);

    // 1. 일반 폼 파라미터(텍스트 필드 등) 처리
    out.println("<h3>일반 폼 파라미터 정보</h3>");
    
    // getParameterNames() : 폼에서 전송된 모든 파라미터 이름(name 속성)을 가져옴
    Enumeration params = multi.getParameterNames(); // Enumeration (이뉴머레이션)

    while (params.hasMoreElements()) {
        String name = (String) params.nextElement();
        String value = multi.getParameter(name);
        out.println(name + " = " + value + "<br>");
    }

    out.println("----------------------------------------<br>");

    // 2. 파일 파라미터(file 필드) 처리
    out.println("<h3>파일 업로드 정보</h3>");
    
    // getFileNames() : 폼에서 전송된 모든 파일 필드의 name 속성 목록을 가져옴
    Enumeration files = multi.getFileNames(); // Enumeration (이뉴머레이션)

    while (files.hasMoreElements()) {
        // 파일 필드의 name 속성 (예: filename)
        String name = (String) files.nextElement();
        
        // 실제 서버에 저장된 파일 이름 (DefaultFileRenamePolicy 적용)
        String filename = multi.getFilesystemName(name); // FilesystemName (파일시스템네임)
        
        // 사용자가 업로드한 원본 파일 이름
        String original = multi.getOriginalFileName(name); // OriginalFileName (오리지널파일네임)
        
        // 파일 콘텐츠 유형 (MIME 타입)
        String type = multi.getContentType(name); // ContentType (콘텐츠타입)
        
        // 업로드된 파일의 File 객체
        File file = multi.getFile(name); // File (파일)

        out.println("요청 파라미터 이름 : " + name + "<br>");
        out.println("실제 파일 이름 : " + original + "<br>");
        out.println("저장 파일 이름 : " + filename + "<br>");
        out.println("파일 콘텐츠 유형 : " + type + "<br>");

        // 파일 객체가 null이 아닌 경우 (파일이 실제로 전송/업로드된 경우)
        if (file != null) {
            // 파일 크기를 가져옴
            // *주의: 이미지의 file_length()는 오타로 간주하고 file.length()로 수정했습니다.*
            out.println("파일 크기 : " + file.length() + " bytes<br>"); 
            out.println("<br>");
        }
    }
%>