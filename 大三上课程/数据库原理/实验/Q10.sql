WITH DeduplicatedReleases AS (
    SELECT DISTINCT
        artist.name AS ARTIST_NAME,
        release.name AS RELEASE_NAME,
        release_info.date_year AS RELEASE_YEAR,
        release_info.date_month AS RELEASE_MONTH,
        release_info.date_day AS RELEASE_DAY
    FROM artist
    JOIN artist_credit_name ON artist.id = artist_credit_name.artist
    JOIN artist_credit ON artist_credit.id = artist_credit_name.artist_credit
    JOIN release ON release.artist_credit = artist_credit.id
    JOIN release_info ON release_info.release = release.id
    WHERE artist.gender = 1
      AND artist.begin_date_year = 1991
      AND release_info.date_year IS NOT NULL
      AND artist_credit.artist_count = 4
),
RankedReleases AS (
    SELECT
        ARTIST_NAME,
        RELEASE_NAME,
        RELEASE_YEAR,
        RELEASE_MONTH,
        RELEASE_DAY,
        ROW_NUMBER() OVER (
            PARTITION BY ARTIST_NAME 
            ORDER BY RELEASE_YEAR DESC, RELEASE_MONTH DESC, RELEASE_DAY DESC
        ) AS row_num
    FROM DeduplicatedReleases
)
SELECT ARTIST_NAME, RELEASE_NAME, RELEASE_YEAR
FROM RankedReleases
WHERE row_num <= 3
ORDER BY ARTIST_NAME ASC, RELEASE_YEAR DESC, RELEASE_MONTH DESC, RELEASE_DAY DESC;
