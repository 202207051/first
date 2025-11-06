select emp.ename, dept.dname, dept.loc 
from emp, dept
where emp.deptno = dept.deptno;

select emp.ename, dept.dname, dept.loc
from emp, dept
where emp.deptno = dept.deptno and emp.sal > 1500;

select ename, dname, loc
from emp, dept
where emp.deptno = dept.deptno;

select ename, dname, loc
from emp e, dept d
where e.deptno = d.deptno;

select emp.ename, dept.dname, dept.loc
from emp, dept
where emp.deptno = dept.deptno and emp.sal >= 1500;

select e.ename, d.dname, d.loc
from emp e, dept d
where e.deptno = d.deptno and e.sal >= 1500;

select ename, dname, loc
from emp e, dept d
where e.deptno = d.deptno and sal >=1500;

select e.ename as employee, m.ename as manager
from emp e, emp M
where e.mgr = m.empno;

select e.ename as employee, m.ename as manager
from emp e, emp m
where e.mgr = m.empno(+);

select ct.name, cl.language
from country co, city ct, countrylanguage cl
where co.capital = ct.id and cl.countrycode = co.code and co.name = 'Greece';

select ename, dname, hiredate
from emp e, dept d
where e.deptno = d.DEPTNO and loc = 'DALLAS';

select ename, dname, hiredate
from emp e, dept d
where e.deptno = d.deptno and hiredate < '1981-09-01';

select e.ename, e.sal, d.loc
from emp e, emp m, dept d
where e.mgr = m.empno and e.deptno = d.deptno and m.ename = 'BLAKE';