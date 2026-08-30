WITH MaxCommentLength AS (
    SELECT 
        w.type, 
        MAX(LENGTH(w.comment)) AS max_comment_length
    FROM 
        work AS w
    WHERE 
        LENGTH(w.comment) > 0
    GROUP BY 
        w.type
)
SELECT 
    wt.name AS WORK_TYPE,
    w.name AS WORK_NAME,
    LENGTH(w.comment) AS COMMENT_LENGTH,
    w.comment AS COMMENT
FROM 
    work AS w
JOIN 
    work_type AS wt ON w.type = wt.id
JOIN 
    MaxCommentLength AS mcl ON w.type = mcl.type
WHERE 
    LENGTH(w.comment) = mcl.max_comment_length
ORDER BY 
    wt.name ASC, w.name ASC;