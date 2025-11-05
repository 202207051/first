select ename, hiredate 
from emp 
where job = 'ANALYST';

select distinct mgr 
from emp;

select *
from emp
where job = 'ANALYST';

select ename, sal
from emp
where sal between 3000 and 4000;

select ename, hiredate
from emp
where hiredate not between '1981-01-01' and '1981-06-30';

select empno, ename, deptno 
from emp
where deptno = 10 or deptno = 20;

select empno, ename, deptno
from emp
where deptno in (10, 20);

select ename
from emp
where job = 'PRESIDENT';

select ename, job
from emp
where job <> 'CLERK';

select ename, job
from emp 
where not job = 'CLERK';

select ename, sal
from emp
where (sal between 3000 and 4000) or (job = 'CLRERK');

select ename
from emp
where deptno = 20 and job = 'CLERK' and  mgr = 7902;

select ename, job, sal
from emp
where job not in ('ANALYST', 'MANAGER', 'SALESMAN');

select ename, job
from emp
where job like '%NA%';

select ename, job
from emp
where job like '_A%';