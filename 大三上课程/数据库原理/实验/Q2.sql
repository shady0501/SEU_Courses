select release.name as RELEASE_NSME, min(ri.date_year) as RELEASE_YEAR
from artist 
join area on area.id = artist.area
join artist_credit_name as acn on artist.id = acn.artist
join release on release.artist_credit = acn.artist_credit
join medium on medium.release = release.id
join medium_format as mf on mf.id = medium.format
join release_info as ri on ri.release = release.id
where artist.name = 'The Beatles'
and ri.area = area.id
and  area.name = 'United Kingdom'
and mf.name = '12" Vinyl'
and (ri.date_year < artist.end_date_year
	or ri.date_year = artist.end_date_year and ri.date_month < artist.end_date_month
	or ri.date_year = artist.end_date_year and ri.date_month = artist.end_date_month and ri.date_day < artist.end_date_day)
and ri.date_year is not null
group by release.name
order by ri.date_year asc, release.name asc;