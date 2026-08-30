select artist.name as ARTIST_NAME, count(artist_alias.id) as NUM_ALIASES, GROUP_CONCAT(artist_alias.name, ', ') as COMMA_SEPARATED_LIST_OF_ALIASES
from artist
join artist_alias on artist.id = artist_alias.artist
where artist.name like '%John'
and artist_alias.name is not null
and artist.id not in (select a.id
                        from artist as a 
                        join artist_alias as aa on a.id = aa.artist
                        where aa.name like '%john%')
group by artist.name
order by artist.name;