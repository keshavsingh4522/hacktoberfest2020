function getequation(){
    return document.getElementById("equation-value").innerText;
}
function printequation(num){
    document.getElementById("equation-value").innerText=num;
}
function getoutput(){
    return document.getElementById("output-value").innerText;
}
function printoutput(num){
    if(num==""){
        document.getElementById("output-value").innerText=num;
    }
    else{
    document.getElementById("output-value").innerText=getFormattedNumber(num);
    }
}
function getFormattedNumber(num){
    if(num=="-"){
        return "";
    }
    var n = Number(num);
    var value = n.toLocaleString("en");
    return value;
}
// checking:  printoutput("66778685");
function reverseNumberFormat(num){
    return Number(num.replace(/,/g,''));
}
// checked this using : alert(reverseNumberFormat(getoutput()));

var operator = document.getElementsByClassName("operator");
for(var i = 0; i<operator.length; i++)
{
    operator[i].addEventListener('click',function(){
        //check message :  alert("The operator clicked:"+ this.id);

        if(this.id == "clear"){
            printequation("");
            printoutput("");
        }
        else if(this.id == "backspace"){
            var output = reverseNumberFormat(getoutput()).toString();
            if(output){    //if output has a value
                output = output.substr(0,output.length-1);
                printoutput(output);
            }
        }
        else{
            var output = getoutput();
            var equation = getequation();
            if(output==""&&equation!=""){
                if(isNaN(equation[equation.length-1])){
                    equation=equation.substr(0,equation.length-1);
                }
            }
            if (output!="" || equation!=""){
                //using conditional ?true:false

                output= output == ""?
                output: reverseNumberFormat(output);
                equation= equation+output;
                if(this.id=="="){
                    var result= eval(equation);
                    printoutput(result);
                    printequation("");
                }
                else{
                    equation = equation + this.id;
                    printequation(equation);
                    printoutput("");
                }
            }
        }
    });
}

var number = document.getElementsByClassName("number");
for(var i = 0; i<number.length; i++)
{
    number[i].addEventListener('click',function(){
        //check message :  alert("The number clicked:"+ this.id);

        var output = reverseNumberFormat(getoutput());
        if(output!=NaN){    //if output is a number
            output= output+ this.id;
            printoutput(output);
        }
    });
}
