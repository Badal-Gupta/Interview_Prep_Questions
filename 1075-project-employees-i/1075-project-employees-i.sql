Select p.project_id, Round(avg(e.experience_years),2) as average_years from project as p 
join Employee as e on p.employee_id = e.employee_id 
group by p.project_id;