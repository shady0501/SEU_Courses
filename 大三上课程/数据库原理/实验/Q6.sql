select CAST(floor(a.begin_date_year / 10) * 10 AS TEXT) || 's' AS DECADE, count(*) as NUM_ARTIST_GROUP
from artist as a
join artist_type as at
on a.type = at.id
join area
on area.id = a.area
where at.name = 'Group'
and a.begin_date_year between 1900 and 2023
and area.name = 'United States'
group by floor(a.begin_date_year/10);