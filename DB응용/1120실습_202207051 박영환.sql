create table yhpark2_dept (
deptno number(2) not null,
dname varchar2(14) not null,
loc varchar2(13) not null,
constraint pk_yhpark2_deptno primary key(deptno)
) tablespace "TESTTBLS";

create table yhpark2_emp (
empno number(5) not null,
ename varchar2(10) not null,
job varchar2(9) not null,
hiredate date not null,
sal number(7, 2) not null,
deptno number(2),
constraint pk_yhpark2_empno primary key(empno),
constraint fk_yhpark2_deptno foreign key (deptno) references yhpark2_dept(deptno)
on delete set null
) tablespace "TESTTBLS";