# Write your MySQL query statement below
SELECT(
    SELECT DISTINCT Salary as SecondHighestSalary
    FROM Employee  
    ORDER BY Salary DESC
    LIMIT 1,1
);