# Write your MySQL query statement below
select w1.id from weather w1
where w1.temperature > (
    select w2.temperature from weather w2
    where DATE_SUB(w1.recordDate, INTERVAL 1 DAY) = w2.recordDate 
);