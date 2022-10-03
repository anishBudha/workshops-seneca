function playNumbers() {
    if(arguments.length < 1)
    {
        console.log("There are no inputs.")
        var validator01 = true
    }
    else
    {
        for (let i = 0; i < arguments.length; i++) {
            if(isNaN(arguments[i])){
                var validator02 = true
                console.log(arguments[i] + " is not a number.")
            }
           
        }
    }
    if(validator01 != true && validator02 != true) {
    const anArray = Array.from(arguments)
    var min =  Math.min(...arguments);
    let sum = 0;
    for(let i = 0; i < anArray.length; i++) {
        sum += anArray[i]
    }
    console.log("The lowest number of (" + anArray.join(", ") + ") is " + min)
    console.log("The average of (" + anArray.join(", ") + ") is " + sum/anArray.length)
    }
    
}

console.log("/***************************** Task1 *************************/");
playNumbers(); 
playNumbers("abc", 3, "hello");
playNumbers(9,3,6); 
playNumbers(3,5,1,3,5); 
playNumbers("Good day!",3,4,32,"hi", "we");


function convertCurrency(val, cf)
{
    if(arguments.length != 2) 
    {
        console.log("Incorrect number of Inputs:(")
    }
    else {
        var valid01, valid02
        if (typeof(val) != "number")
        {
            valid01 = true
            console.log("I need a number")
        }
        else if(cf != "$" && cf != "E") 
        {
            valid02 = true
            console.log("I am confused:(")
        }
        if(valid01 != true && valid02 != true) 
        {
            if (cf == "$") 
            {
                var total01 = val / 1.36
                console.log(val+ " Cad is equivalent to " + total01 + " in US $")
            }
            else if(cf == "E")
            {
                var total02 = val / 1.33
                console.log(val + " Cad is equivalent to " + total02 + " in Euro")
            }
        }

    }
  
}
console.log("/***************************** Task2 *************************/"); 
convertCurrency (100);
convertCurrency (100, "M");
convertCurrency (100, "$");
convertCurrency (100, "E");
convertCurrency ("100", "E");

