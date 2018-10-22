/* Query 1 */
SELECT city, state FROM station;

/* Query 2 */
SELECT ROUND(SUM(lat_n), 2), ROUND(SUM(long_w), 2) FROM station;

/* Query 3 */
SELECT DISTINCT city FROM station WHERE MOD(id, 2) = 0;

/* Query 4 */
SELECT COUNT(city) – COUNT(DISTINCT city) FROM station;

/* Query 5 */
SELECT MIN(city), LENGTH(city)
FROM station
WHERE LENGTH(city) = (SELECT MIN(LENGTH(city)) FROM station) OR LENGTH(city) = (SELECT MAX(LENGTH(city)) FROM station)
GROUP BY LENGTH(city);

/* Query 6 */
/* mysql */
SELECT DISTINCT city FROM statiob
WHERE city LIKE 'A%' OR city LIKE 'E%' OR city LIKE 'I%' OR city LIKE 'O%' OR city LIKE 'U%';
/* oracle */
SELECT DISTINCT city FROM station WHERE SUBSTR(city, 0, 1) IN ('A', 'E', 'I', 'O', 'U');

/* Query 7 */
/* mysql */
SELECT DISTINCT city FROM station
WHERE city LIKE '%a' OR city LIKE '%e' OR city LIKE '%i' OR city LIKE '%o' OR city LIKE '%u';
/* oracle */
SELECT DISTINCT city FROM station WHERE SUBSTR(city, -1) IN ('a', 'e', 'i', 'o', 'u');

/* Query 8 */
/* oracle */
SELECT DISTINCT city FROM station
WHERE SUBSTR(city, 0, 1) IN ('A', 'E', 'I', 'O', 'U') AND SUBSTR(city, -1) IN ('a', 'e', 'i', 'o', 'u');
/* mysql */
SELECT DISTINCT city FROM station
WHERE (city LIKE 'A%' OR city LIKE 'E%' OR city LIKE 'I%' OR city LIKE 'O%' OR city LIKE 'U%')
AND ( city LIKE '%a' OR city LIKE '%e' OR city LIKE '%i' OR city LIKE '%o' OR city LIKE '%u');

/* Query 9 */
/* oracle */
SELECT DISTINCT city FROM station WHERE SUBSTR(city, 0, 1) NOT IN ('A', 'E', 'I', 'O', 'U');
/* mysql */
SELECT DISTINCT city FROM station
WHERE city NOT LIKE 'A%' AND city NOT LIKE 'E%' AND city NOT LIKE 'I%' AND city NOT LIKE 'O%' AND city NOT LIKE 'U%';

/* Query 10 */
/* oracle */
SELECT DISTINCT city FROM station WHERE SUBSTR(city, -1) NOT IN ('a', 'e', 'i', 'o', 'u');
/* mysql */
SELECT DISTINCT city FROM station
WHERE city NOT LIKE '%a' AND city NOT LIKE '%e' AND city NOT LIKE '%i' AND city NOT LIKE '%o' AND city NOT LIKE '%u';

/* Query 11 */
/* oracle */
SELECT DISTINCT city FROM station
WHERE SUBSTR(city, 0, 1) NOT IN ('A', 'E', 'I', 'O', 'U') OR SUBSTR(city, -1) NOT IN ('a', 'e', 'i', 'o', 'u');
/* mysql */
SELECT DISTINCT city FROM station
WHERE (city NOT LIKE 'A%' AND city NOT LIKE 'E%' AND city NOT LIKE 'I%'
AND city NOT LIKE 'O%' AND city NOT LIKE 'U%')
OR (city NOT LIKE '%a' AND city NOT LIKE '%e' AND city NOT LIKE '%i'
AND city NOT LIKE '%o' AND city NOT LIKE '%u');

/* Query 12 */
/* oracle */
SELECT DISTINCT city FROM station
WHERE SUBSTR(city, 0, 1) NOT IN ('A', 'E', 'I', 'O', 'U')
AND SUBSTR(city, -1) NOT IN ('a', 'e', 'i', 'o', 'u');
/* mysql */
SELECT DISTINCT city FROM station
WHERE (city NOT LIKE 'A%' AND city NOT LIKE 'E%' AND city NOT LIKE 'I%'
AND city NOT LIKE 'O%' AND city NOT LIKE 'U%')
AND (city NOT LIKE '%a' AND city NOT LIKE '%e' AND city NOT LIKE '%i'
AND city NOT LIKE '%o' AND city NOT LIKE '%u');

/* Query 13 */
SELECT ROUND(SUM(lat_n), 4) FROM station WHERE lat_n &gt; 38.7880 AND lat_n &lt; 137.2345;

/* Query 14 */
SELECT ROUND(MAX(lat_n), 4) FROM station WHERE lat_n &lt; 137.2345;

/* Query 15 */
SELECT ROUND(MAX(long_w), 4) FROM station WHERE lat_n = (SELECT MAX(lat_n) FROM station WHERE lat_n &lt; 137.2345);

/* Query 16 */
SELECT ROUND(MIN(lat_n), 4) FROM station WHERE lat_n &gt; 38.7780;

/* Query 17 */
SELECT ROUND(long_w, 4) FROM station WHERE lat_n = (SELECT MIN(lat_n) FROM station WHERE lat_n &gt; 38.7780);

/* Query 18 */
SELECT ROUND((ABS(MIN(lat_n)-MAX(lat_n)) + ABS(MIN(long_w)-MAX(long_w))), 4) FROM station;

/* Query 19 */
SELECT ROUND(SQRT(POW((MAX(lat_n) - MIN(lat_n)), 2) + POW((MAX(long_w) - MIN(long_w)), 2)), 4) FROM station;

/* Query 20 */
SELECT ROUND(lat_n, 4) FROM
(SELECT s1.city, s1.lat_n, COUNT(s2.lat_n) AS Rank
FROM station s1, station s2
WHERE s1.lat_n &lt; s2.lat_n OR (s1.lat_n = s2.lat_n AND s1.city = s2.city)
GROUP BY s1.city, s1.lat_n ORDER BY s1.lat_n DESC) AS s3
WHERE Rank = (SELECT(COUNT(*)+1) / 2 FROM station);

