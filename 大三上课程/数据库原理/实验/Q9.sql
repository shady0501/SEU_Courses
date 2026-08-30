WITH DECADE_1950 AS (
    SELECT 
        l.name AS LANGUAGE, 
        COUNT(*) AS NUM_RELEASES
    FROM 
        release
    INNER JOIN 
        language l ON release.language = l.id
    INNER JOIN 
        release_info ri ON release.id = ri.release
    WHERE 
        ri.date_year BETWEEN 1950 AND 1959
    GROUP BY 
        l.id
), 

DECADE_2010 AS (
    SELECT 
        l.name AS LANGUAGE, 
        COUNT(*) AS NUM_RELEASES
    FROM 
        release
    INNER JOIN 
        language l ON release.language = l.id
    INNER JOIN 
        release_info ri ON release.id = ri.release
    WHERE 
        ri.date_year BETWEEN 2010 AND 2019
    GROUP BY 
        l.id
), 

T1 AS (
    SELECT 
        COUNT(*) 
    FROM 
        release
    INNER JOIN 
        release_info ri ON release.id = ri.release
    WHERE 
        ri.date_year BETWEEN 1950 AND 1959
), 

T2 AS (
    SELECT 
        COUNT(*) 
    FROM 
        release
    INNER JOIN 
        release_info ri ON release.id = ri.release
    WHERE 
        ri.date_year BETWEEN 2010 AND 2019
)

SELECT 
    DECADE_2010.LANGUAGE,
    COALESCE(DECADE_1950.NUM_RELEASES, 0) AS NUM_RELEASES_IN_1950s,
    COALESCE(DECADE_2010.NUM_RELEASES, 0) AS NUM_RELEASES_IN_2010s,
    ROUND(
        (
            CAST(COALESCE(DECADE_2010.NUM_RELEASES, 0) AS FLOAT) / (SELECT * FROM T2) 
            - CAST(COALESCE(DECADE_1950.NUM_RELEASES, 0) AS FLOAT) / (SELECT * FROM T1)
        ), 
        3
    ) AS INCREASE
FROM 
    DECADE_2010
LEFT JOIN 
    DECADE_1950 ON DECADE_1950.LANGUAGE = DECADE_2010.LANGUAGE
WHERE 
    (
        CAST(COALESCE(DECADE_2010.NUM_RELEASES, 0) AS FLOAT) / (SELECT * FROM T2) 
        - CAST(COALESCE(DECADE_1950.NUM_RELEASES, 0) AS FLOAT) / (SELECT * FROM T1)
    ) > 0
ORDER BY 
    INCREASE DESC
LIMIT 1;
