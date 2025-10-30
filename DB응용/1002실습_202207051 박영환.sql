SELECT ename, sal
FROM emp
WHERE job = 'SALESMAN';

SELECT job
FROM emp;

SELECT DISTINCT job
FROM emp;

SELECT *
FROM emp
WHERE ename ='SCOTT';

SELECT ename, hiredate
FROM emp
WHERE hiredate >= '1981-09-01';

SELECT ename, hiredate, sal
FROM emp
WHERE hiredate >= '1981-09-01' AND sal > 1500;

SELECT ename, job, sal
FROM emp
WHERE (job <> 'SALESMAN') AND (job <> 'ANALYST');

SELECT dname
FROM dept;

SELECT ename, comm
FROM emp
WHERE comm IS NOT NULL;

SELECT ename, comm
FROM emp
WHERE comm > 0;

SELECT ename
FROM emp
WHERE comm IS NULL;

SELECT loc
FROM dept
WHERE dname = 'SALES';

SELECT ename, sal, job
FROM emp
WHERE empno = 7698;

SELECT ename, hiredate
FROM emp
WHERE hiredate < '1981-03-01';

SELECT ename, sal
FROM emp
WHERE sal BETWEEN 1000 AND 2000;

SELECT ename, sal
FROM emp
WHERE sal < 1000 OR sal > 2000;

SELECT ename, job, sal
FROM emp
WHERE job IN ('CLERK', 'ANALYST', 'MANAGER');

SELECT ename, job, sal
FROM emp
WHERE job NOT IN ('CLERK', 'ANALYST', 'MANAGER');

SELECT ename, job
FROM emp
WHERE ename LIKE '%A';

SELECT ename, job
FROM emp
WHERE ename LIKE '__A%';