select distinct l1.num as ConsecutiveNums 
FROM Logs l1 JOIN Logs l2 
ON l2.id = l1.id + 1
JOIN Logs l3
ON l3.id = l1.id + 2
where l1.num=l2.num and l2.num=l3.num
