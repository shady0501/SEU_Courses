select distinct artist.name as ARTIST_NAME
from artist
join artist_credit_name on artist.id = artist_credit_name.artist
join artist_credit on artist_credit.id = artist_credit_name.artist_credit
where artist_credit.name in (select ac.name
                                from artist as a
                                join artist_credit_name as acn on a.id = acn.artist
                                join artist_credit as ac on ac.id = acn.artist_credit
                                where a.name = 'Pittsburgh Symphony Orchestra')
and artist.name is not 'Pittsburgh Symphony Orchestra'
order by artist.name asc;