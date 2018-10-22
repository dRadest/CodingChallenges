SELECT
	CASE 
		WHEN grade >= 8 THEN name
		ELSE "NULL"
	END,
grade, marks FROM Students, Grades 
WHERE marks >= min_mark AND marks <=max_mark
ORDER BY grade DESC, name ASC, marks ASC;