--  use leetcode;
--  Create table If Not Exists Employee (Id int, Name varchar(255), Salary int, ManagerId int);
--
--  insert into Employee (Id, Name, Salary, ManagerId) values ('1', 'Joe', '70000', '3');
--  insert into Employee (Id, Name, Salary, ManagerId) values ('2', 'Henry', '80000', '4');
--  insert into Employee (Id, Name, Salary, ManagerId) values ('3', 'Sam', '60000', NULL);
--  insert into Employee (Id, Name, Salary, ManagerId) values ('4', 'Max', '90000', NULL);
--
--  select * from Employee;

select Name as Emplyee from Employee B where ManagerId is not NULL and exists(
    select * from Employee Sup where Sup.Id = B.ManagerId and Sup.Salary < B.Salary
    );
