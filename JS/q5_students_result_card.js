// Write a program to display one result card of 100 students
// with their name and percentage
// Out of 100 students, 50 has subjects - Grammer and Accounts
// and other 50 has subjects -  Grammer and Physics

// Hint : You need to calculate percentage of 100 students having different set of subjects.
//        You can assume their scores on their respective subjects.


// Write your code here

const results=()=>{
    const studentsList=[
        {name:'shru',subjects:[{subject:'Grammer',marks:80},{subject:'Accounts',marks:79}]},
        {name:'modu',subjects:[{subject:'Grammer',marks:45},{subject:'Accounts',marks:98}]},
        {name:'Akshad', subjects: [{subject:'Grammer', marks:83}, {subject:'Accounts',marks:90}]},
        {name:'Akshay', subjects: [{subject:'Grammer', marks:79}, {subject:'Accounts',marks:75}]},
        {name:'Bela', subjects: [{subject:'Grammer', marks:83}, {subject:'Accounts',marks:72}]},
        {name:'shruti',subjects:[{subject:'Grammer',marks:100},{subject:'Accounts',marks:79}]},
        {name:'koni',subjects:[{subject:'Grammer',marks:60},{subject:'Accounts',marks:69}]},
        {name:'anjali',subjects:[{subject:'Grammer',marks:28},{subject:'Accounts',marks:53}]},
        {name:'amruta',subjects:[{subject:'Grammer',marks:35},{subject:'Accounts',marks:44}]},
        {name:'aksu',subjects:[{subject:'Grammer',marks:43},{subject:'Accounts',marks:90}]},
        {name:'Mohit', subjects: [{subject:'Grammar', marks:88}, {subject:'Accounts',marks:95}]},
        {name:'Bharat', subjects: [{subject:'Grammar', marks:90}, {subject:'Accounts',marks:86}]},
        {name:'Niharika', subjects: [{subject:'Grammar', marks:95}, {subject:'Accounts',marks:92}]},
        {name:'Abhishek', subjects: [{subject:'Grammar', marks:76}, {subject:'Accounts',marks:85}]},
        {name:'Apurva', subjects: [{subject:'Grammar', marks:83}, {subject:'Accounts',marks:79}]},
        {name:'Chaitanya', subjects: [{subject:'Grammar', marks:93}, {subject:'Accounts',marks:88}]},
        {name:'Chetan', subjects: [{subject:'Grammar', marks:69}, {subject:'Accounts',marks:65}]},
        {name:'Vaishnavi', subjects: [{subject:'Grammar', marks:74}, {subject:'Physics',marks:89}]},
        {name:'Karan', subjects: [{subject:'Grammar', marks:84}, {subject:'Physics',marks:79}]},
        {name:'Dinesh', subjects: [{subject:'Grammar', marks:77}, {subject:'Physics',marks:80}]},
        {name:'Tanvi', subjects: [{subject:'Grammar', marks:99}, {subject:'Physics',marks:81}]},
        {name:'Mayank', subjects: [{subject:'Grammar', marks:79}, {subject:'Physics',marks:82}]},
        {name:'Shashwat', subjects: [{subject:'Grammar', marks:78}, {subject:'Physics',marks:83}]},
        {name:'Priyam', subjects: [{subject:'Grammar', marks:69}, {subject:'Physics',marks:84}]},
        {name:'Shweta', subjects: [{subject:'Grammar', marks:81}, {subject:'Physics',marks:85}]},
        {name:'Binod', subjects: [{subject:'Grammar', marks:79}, {subject:'Physics',marks:86}]},
        {name:'Nished', subjects: [{subject:'Grammer', marks:99}, {subject:'Physics',marks:89}]},
        {name:'Roshni', subjects: [{subject:'Grammer', marks:79}, {subject:'Physics',marks:88}]},
        {name:'Arun', subjects: [{subject:'Grammer', marks:78}, {subject:'Physics',marks:86}]},
        {name:'Vinod', subjects: [{subject:'Grammer', marks:69}, {subject:'Physics',marks:79}]},
        {name:'Jeeja', subjects: [{subject:'Grammer', marks:81}, {subject:'Physics',marks:71}]},
        {name:'tanay', subjects: [{subject:'Grammer', marks:82}, {subject:'Physics',marks:78}]},
    ]
    const result=()=>
    studentsList.reduce((obj,item)=>{

        let percenRes=item.subjects.reduce(()=>{
            return (item.subjects[0].marks+item.subjects[1].marks)/item.subjects.length;
        }, {})
        console.log({ 'name':item.name,'percentage':percenRes});
    }, {})
    const finResult=result(studentsList);
    return finResult;
}
results();s