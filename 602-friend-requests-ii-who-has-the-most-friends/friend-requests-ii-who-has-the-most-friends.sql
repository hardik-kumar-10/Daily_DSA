select requester_id as id,count(*) as num
from (
select  requester_id from RequestAccepted

union all 

select  accepter_id from RequestAccepted
) as friend_count 
group by requester_id
order by num desc #isse top pr ajayega
limit 1 # and jo top pr hoga wahi awnser hoga