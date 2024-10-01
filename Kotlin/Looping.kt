fun main(args: Array<String>) {



    println("for range")
    for(i in 1..5)
    {
        print("$i ")
    }

    
    println("\nfor range + step")

    for(i in 1..10 step 2)
    {
        print("$i ")
    }



    println("\n\nUntil")//doesnt include upper bound

    for(i in 1 until 5)
    {
        print("$i ")
    }



    
    println("\n downTo")

    for(i in 10 downTo 1)
     {
        print("$i ")
    }


    println("\n downTO + step")

    for(i in 10 downTo 1 step 2) 
     {
        print("$i ")
    }

    println("\n\n\n\n\n\n")

    val number=2
    for(i in 1..10)
    {
        //both statements are same 
        // println(number.toString() + "*" + i + "=" + (number*i))

        //String templating
        println("$number * $i = ${number * i}")

    }




}
