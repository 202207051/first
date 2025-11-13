select ename, hiredate
from emp
where sal >= 2500 
union 
select ename, hiredate
from emp 
where job = 'MANAGER';

select ename, hiredate 
from emp 
where sal >= 2500 
union all
select ename, hiredate 
from emp
where job = 'MANAGER';

select ename, hiredate 
from emp 
where sal >= 2500
intersect 
select ename, hiredate 
from emp 
where job = 'MANAGER';

select ename, hiredate 
from emp 
where sal >= 2500 and job = 'MANAGER';

select ename, hiredate
from emp 
where sal >= 2500
minus 
select ename, hiredate 
from emp 
where job = 'MANAGER';

select ename, hiredate 
from emp 
where sal >= 2500 and job <> 'MANAGER';

select ename, hiredate
from emp 
where sal >= (select min(sal) from emp where job = 'ANALYST');

select ename, hiredate 
from emp 
where sal >= (select max(sal) from emp);

select ename, hiredate 
from emp 
where sal >= (select avg(sal) from emp);

select ename, job, sal, hiredate 
from emp 
where sal >= (select avg(sal) from emp)
and hiredate between '1981-01-01' and '1981-12-31';

select ename, job, deptno 
from emp 
where deptno in (select deptno from dept where dname like '%S%');

select ename, job, e.deptno 
from emp e, dept d 
where e.deptno = d.deptno 
and dname like '%S%';

select ename, job, sal
from emp 
where job not in  (select job from emp where ename = 'SMITH' or ename = 'ALLEN');

select dname, loc
from dept 
where exists (select * from emp where emp.deptno = dept.deptno);

select dname, loc
from dept
where not exists (select * from emp where emp.deptno = dept.deptno);

select ename, job 
from emp 
where mgr = any (select mgr from emp e, dept d where e.deptno = d.deptno and dname = 'RESEARCH');

select ename, sal 
from emp 
where sal > all  (select sal from emp e, dept d where e.deptno = d.deptno and dname = 'RESEARCH');

CREATE PRIVATE TEMPORARY TABLE ORA$PTT_emp_high AS
SELECT *
FROM emp 
WHERE sal >= 1500;

select *
from ORA$PTT_emp_high;

select *
from ORA$PTT_emp_high
where job = 'MANAGER';

select ename, dname
from ORA$PTT_emp_high e, dept d where e.deptno = d.deptno;

drop table ORA$PTT_emp_high;