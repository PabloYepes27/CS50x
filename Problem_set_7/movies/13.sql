-- 1. Find the id of 'Kevin Bacon' by his name and birth
-- 2. Find the movies_id where this id has starred
-- 3.
SELECT DISTINCT name FROM stars
JOIN people ON stars.person_id = people.id
WHERE stars.movie_id IN
(SELECT stars.movie_id FROM people
JOIN stars ON stars.person_id = people.id
WHERE people.name = "Kevin Bacon" AND people.birth = 1958)
AND people.name != "Kevin Bacon";