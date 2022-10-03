-- ***********************
-- Name: Anish Budha
-- ID: 174760215
-- Date: 9/23/2022
-- Purpose: Lab 02 DBS211
-- ***********************

-- Q1 SOLUTION --
SELECT
   officecode,
   city,
   state,
   country,
   phone 
FROM
   dbs211_offices;

-- Q2 SOLUTION --
SELECT
   employeenumber,
   firstname,
   lastname,
   extension 
FROM
   dbs211_employees 
WHERE
   officecode = 1
ORDER BY
   employeenumber;

-- Q3 SOLUTION --
SELECT
   customernumber,
   customername,
   contactfirstname,
   contactlastname 
FROM
   dbs211_customers 
WHERE
   city = 'Paris' 
ORDER BY
   customernumber;

-- Q4 SOLUTION -- 
SELECT
   customernumber,
   customername,
   (
      contactfirstname || ',' || contactlastname
   )
   AS contact 
FROM
   dbs211_customers 
WHERE
   country = 'Canada' 
ORDER BY
   customernumber;

-- Q5 SOLUTION -- 
SELECT DISTINCT
   customernumber 
FROM
   dbs211_payments 
ORDER BY
   customernumber;

-- Q6 SOLUTION -- 
SELECT
   customernumber,
   checknumber,
   amount 
FROM
   dbs211_payments 
WHERE
   amount NOT BETWEEN 1500 AND 120000 
ORDER BY
   amount DESC;

-- Q7 SOLUTION -- 
SELECT
   ordernumber,
   orderdate,
   status,
   customernumber 
FROM
   dbs211_orders 
WHERE
   status = 'Cancelled' 
ORDER BY
   orderdate;

-- Q8 SOLUTION -- 
SELECT
   productcode,
   productname,
   buyprice,
   msrp,
   (
      msrp - buyprice
   )
   AS markup,
   round(((msrp - buyprice) / buyprice)*100, 1) AS percmarkup 
FROM
   dbs211_products 
WHERE
   round(((msrp - buyprice) / buyprice)*100, 1) > 140 
ORDER BY
   percmarkup;

-- Q9 SOLUTION -- 
SELECT
   productcode,
   productname,
   quantityinstock 
FROM
   dbs211_products 
WHERE
   LOWER(productname) LIKE '%co%' 
ORDER BY
   quantityinstock;
   
-- Q10 SOLUTION -- 
SELECT
   customernumber,
   contactfirstname,
   contactlastname 
FROM
   dbs211_customers 
WHERE
   LOWER(contactfirstname) LIKE 's%' 
   AND LOWER(contactfirstname) LIKE '%e%' 
ORDER BY
   customernumber;