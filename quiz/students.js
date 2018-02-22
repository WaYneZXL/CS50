let students = [
    {name: "Stelios", dorm: "Branford"},
    {name: "Maria", dorm: "Cabot"},
    {name: "Anushree", dorm: "Ezra Stiles"},
    {name: "Brian", dorm: "Winthrop"}
];

console.log("Before:")
for (let student of students)
{
    console.log(student.name + " from " + student.dorm);
}
students.sort(cmp);
console.log("After:")
for (let student of students)
{
    console.log(student.name + " from " + student.dorm);
}

function cmp(a, b)
{
    var s1 = a.name;
    var s2 = b.name;

    if (s1 < s2)
    {
        return -1;
    }
    else if (s1 > s2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
