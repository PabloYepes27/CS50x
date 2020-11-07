SELECT title
FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = movies.id
WHERE people.name = "Chadwick Boseman"
ORDER BY ratings.rating DESC
LIMIT 5;

--SELECT title
--FROM(SELECT DISTINCT movies.id, movies.title
--FROM movies
--JOIN ratings ON ratings.movie_id = movies.id
--JOIN stars ON stars.movie_id = ratings.movie_id
--JOIN people ON people.id = stars.person_id
--WHERE people.name LIKE "Chadwick Boseman"
--ORDER BY ratings.rating LIMIT 5);