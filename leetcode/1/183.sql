--  Create table If Not Exists Customers (Id int, Name varchar(255));
--  Create table If Not Exists Orders (Id int, CustomerId int);
--
--  insert into Customers (Id, Name) values ('1', 'Joe');
--  insert into Customers (Id, Name) values ('2', 'Henry');
--  insert into Customers (Id, Name) values ('3', 'Sam');
--  insert into Customers (Id, Name) values ('4', 'Max');
--
--  insert into Orders (Id, CustomerId) values ('1', '3');
--  insert into Orders (Id, CustomerId) values ('2', '1');


select Name as Customers from Customers Top where not exists(
    select Customers.Name from Customers, Orders where Customers.Id = Orders.CustomerId and Customers.Id = Top.Id
    );
