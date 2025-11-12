<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>방문 횟수 카운터 및 초기화</title>
</head>
<body>

<%
    // URL 파라미터를 확인하여 초기화 요청이 있는지 확인합니다.
    String resetParam = request.getParameter("reset");

    if ("true".equals(resetParam)) {
        // "reset=true" 파라미터가 있으면 세션의 특정 속성을 제거합니다.
        session.removeAttribute("visitCount");
        
        // 새로고침 후 초기화된 상태를 보여주기 위해 페이지를 재요청합니다.
        // 현재 페이지 URL로 리다이렉트하여 reset 파라미터를 제거합니다.
        response.sendRedirect(request.getRequestURI());
        return; // 리다이렉트 후 코드 실행을 중지합니다.
    }

    // 세션에서 "visitCount" 속성(Attribute)을 가져옵니다.
    Integer count = (Integer)session.getAttribute("visitCount");

    // "visitCount"가 null이면 횟수를 1로 초기화합니다.
    if (count == null) {
        count = 1; 
    } else {
        count++; // 이미 세션에 값이 있으면 횟수를 1 증가시킵니다.
    }

    // 갱신된(증가된) 횟수를 세션에 다시 저장합니다.
    session.setAttribute("visitCount", count);
%>

    <h1>세션 기반 방문 횟수</h1>
    <p>안녕하세요! 당신의 현재 방문 횟수는 **<%= count %>** 회입니다.</p>
    <p>(브라우저를 닫거나 세션이 만료되면 횟수는 다시 1부터 시작됩니다.)</p>
    
    <hr>
    
    <form action="" method="get">
        <input type="hidden" name="reset" value="true">
        <button type="submit">세션 초기화 및 새로고침</button>
    </form>
    
    <button onclick="window.location.reload();">단순 새로고침</button>

</body>
</html>