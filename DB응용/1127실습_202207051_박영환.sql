DESC YHPARK2_EMP;

select DBMS_METADATA.GET_DDL('TABLE','YHPARK2_EMP')FROM DUAL;

comment on table YHPARK2_DEPT is '부서 테이블';
comment on column YHPARK2_DEPT.DEPTNO is '부서번호';
comment on column YHPARK2_DEPT.DNAME is '부서명';
comment on column YHPARK2_DEPT.LOC is '부서위치';

create table MY_EMP_SAL_HIGH
as
select * from YHPARK2_EMP where sal >= 2000;

alter table YHPARK2_DEPT
add buget number(10,2) default (0);

alter table YHPARK2_DEPT
rename column buget to dept_budget;

alter table YHPARK2_DEPT
modify dept_budget number(12,2);

alter table YHPARK2_DEPT
drop column dept_budget;

alter table YHPARK2_EMP
add constraint PK_YHPARK2_EMPNO primary key(empno);

alter table MY_EMP_SAL_HIGH
rename to MY_SAL_HIGH;

create table tmp(
   tmpid number(2));

drop table tmp;

insert into YHPARK2_DEPT(deptno,dname,loc)
values(10,'accounting','New York');

commit;

insert into YHPARK2_DEPT(deptno,dname,loc)
values(20,'Dallas','Research');

commit;

insert into YHPARK2_DEPT(deptno,dname,loc)
values(30,'Sales','NULL');

commit;

insert into YHPARK2_DEPT(deptno, danme,loc)
values(30,'Sales','SEOUL');

insert into MY_SAL_HIGH
select * from YHPARK2_EMP where sal >= 1500 and sal < 2000;

update YHPARK2_DEPT
set loc = 'JEJU'
where deptno = 10;

select  *
from YHPARK2_DEPT;

commit;

update YHPARK2_EMP
set sal = sal*1.1
where job = 'SALESMAN';

commit;


update YHPARK2_EMP 
set job = 'RESEARCH'
where job = 'ANALYST';

commit;

update YHPARK2_EMP
set sal = sal * 1.1
where sal = (SELECT MIN(sal) from YHPARK2_EMP);

commit; 

update YHPARK2_EMP
set sal = (select sal from YHPARK2_EMP where ename = 'BLAKE')
where sal = (select min(sal) from YHPARK2_EMP);

commit;

insert into YHPARK2_DEPT
values (50, 'E_COMMERCE','LONDON');

commit;

select * from YHPARK2_DEPT;

delete from YHPARK2_DEPT
where deptno = 50;

select * from YHPARK2_DEPT;
