select r.name as RELEASE_NAME, a.name as ARTIST_NAME, ri.date_year as RELEASE_YEAR
from release as r
    join release_info as ri on ri.release = r.id
    join medium as m on m.release = r.id
    join artist_credit_name as acn on r.artist_credit = acn.artist_credit
    join artist as a on a.id = acn.artist
    join medium_format as mf on mf.id = m.format
where mf.name = 'Cassette' 
order by ri.date_year desc, ri.date_month desc, ri.date_day desc, r.name asc, a.name asc
limit 10;