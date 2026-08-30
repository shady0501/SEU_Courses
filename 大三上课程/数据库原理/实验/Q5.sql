SELECT 
    fa.artist_name AS ARTIST_NAME, 
    fa.date_month AS RELEASE_MONTH, 
    fa.release_count AS NUM_RELEASES
FROM (
    SELECT 
        a.id AS artist_id,
        a.name AS artist_name, 
        ri.date_month, 
        COUNT(DISTINCT r.id) AS release_count
    FROM 
        artist AS a
    JOIN 
        artist_type AS at ON a.type = at.id
    JOIN 
        artist_credit_name AS acn ON a.id = acn.artist
    JOIN 
        release AS r ON r.artist_credit = acn.artist_credit
    JOIN 
        release_info AS ri ON ri.release = r.id
    WHERE 
        at.name = 'Person'
        AND a.name LIKE 'Elvis%'
        AND ri.date_month IS NOT NULL
    GROUP BY 
        a.id, a.name, ri.date_month
) AS fa
WHERE 
    fa.release_count = (
        SELECT 
            MAX(sub.release_count)
        FROM (
            SELECT 
                a2.id AS artist_id,
                COUNT(DISTINCT r2.id) AS release_count
            FROM 
                artist AS a2
            JOIN 
                artist_type AS at2 ON a2.type = at2.id
            JOIN 
                artist_credit_name AS acn2 ON a2.id = acn2.artist
            JOIN 
                release AS r2 ON r2.artist_credit = acn2.artist_credit
            JOIN 
                release_info AS ri2 ON ri2.release = r2.id
            WHERE 
                at2.name = 'Person'
                AND a2.name LIKE 'Elvis%'
                AND a2.id = fa.artist_id
                AND ri2.date_month IS NOT NULL
            GROUP BY 
                a2.id, ri2.date_month
        ) AS sub
    )
    AND fa.date_month = (
        SELECT 
            MIN(sub2.date_month)
        FROM (
            SELECT 
                a3.id AS artist_id,
                ri3.date_month,
                COUNT(DISTINCT r3.id) AS release_count
            FROM 
                artist AS a3
            JOIN 
                artist_type AS at3 ON a3.type = at3.id
            JOIN 
                artist_credit_name AS acn3 ON a3.id = acn3.artist
            JOIN 
                release AS r3 ON r3.artist_credit = acn3.artist_credit
            JOIN 
                release_info AS ri3 ON ri3.release = r3.id
            WHERE 
                at3.name = 'Person'
                AND a3.name LIKE 'Elvis%'
                AND a3.id = fa.artist_id
                AND ri3.date_month IS NOT NULL
            GROUP BY 
                a3.id, ri3.date_month
        ) AS sub2
        WHERE 
            sub2.artist_id = fa.artist_id
            AND sub2.release_count = fa.release_count
    )
ORDER BY 
    fa.release_count DESC, 
    fa.artist_name ASC;