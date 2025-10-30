select count(*)
from emp;

select count(*)
from emp
where job = 'SALESMAN';

select count(*) as cnt_salesman
from emp
where job = 'SALESMAN';

select max(sal)
from emp;

select max(sal)
from emp
where job = 'SALESMAN';

select min(hiredate)
from emp;

select max(sal), min(sal), max(sal) - min(sal)
from emp;

select round(avg(sal),2)
from emp;

select avg(comm)
from emp;

select sum(sal)
from emp;

select sum(sal)
from emp
where job = 'ANALYST';

select ename, sal, sal*1.1
from emp
where job = 'ANALYST';

select ename, sal, comm, sal+comm
from emp;

select ename, hiredate
from emp
where job = 'SALESMAN'
order by sal DESC;

select deptno, ename, job
from emp
order by deptno, ename;

select deptno, count(*) as cnt_emp
from emp
group by deptno;

select deptno, avg(sal) as avg_sal
from emp
group by deptno;

select deptno, count(*) as cnt_emp
from emp
group by deptno
having count(*) >= 5;

select deptno, count(*) as cnt_emp
from emp
group by deptno
having count(*) >= 5
order by count(*) DESC;

select *
from emp
where sal > 1500;

select *
from emp
where job = 'SALESMAN';

select *
from dept;