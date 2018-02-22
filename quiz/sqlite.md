# SQLite Music

## Questions

2.1. Because it is a column that can reference another column of another table so that both tables can be joined to perform queries.

2.2. As both tables have ArtistId, they can be joined together in case we need to perform a query with both album and artist.
In this way the Artist table contains the minimum necessary information to 1) save storage space; 2) speed up search time.

2.3. Because string comparison is slower than integer comparison and it saves a lot of time by only using CustomerId to reference customers.

2.4. SELECT SUM Total FROM Invoice WHERE InvoiceDate BETWEEN 2010-01-01 00:00:00 and 2010-12-31 23:59:59

2.5. SELECT Name FROM Track t JOIN InvoiceLine il ON t.TrackId = il.TrackId JOIN Invoice i ON il.InvoiceId = i.InvoiceId WHERE i.CustomerId = 50

2.6. Create a new table called "Composer" with two columns: ComposerId and Composer, then change the Composer column in Tracks to ComposerId using UPDATE.
User can join two tables together to reference both track info and composer info.

## Debrief

a. NA

b. 10 minutes
