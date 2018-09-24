I created a fake dataset for 10 males and 10 females by looking at csv files with heights by gender that I found on internet.

I will make programs in various programming languages that read the csv, and run a t-test comparing male heights to female hights.

The first thing to do will be writing a function that reads the csv data and puts it into two arrays.

Then there will be a function the takes the data from each list and essentially runs the t-test. 

Then last part will be outputting the result to the command line.

I will start with the python implementation.

Python - took a bit, but quite a simple implementation. Imported the csv, defined a class with methods that used the reduce and map functions, then called the class and methods on the data and printed the results. I originally wrote this without any class definitions. As of right now I don't see any advantage to writing it with a class.

JavaScript - Easier to write math and functions than for python, but more difficult to implement with a csv. The file had to be read, and the functions had to be used after the file was read. This was difficult due to its asynchronous nature.

Scala - The math was easy to write and the functions were very terse, and putting it into a class was not particularly difficult. Getting csv data doesn't seem like it should be too hard, but I cannot make it past a certain point. I do not know what is holding everything back. It seems like a problem with the number of times an item can be looped over (doesn't make sense) or what type of value is returned from a method. Lots of problems, not easy.

C++

C

Java

Common Lisp

Ruby - Really easy to use. I like the syntax a lot. I more or less wrote it the same as the python script, but the syntax actually seemed a little cleaner to me. Probably because I would rather rely on reduce and map methods than on for loops. I hate for loops.

Golang

Rust

Crystal - Because I just heard about it today, and it seems fresh and new. No really good reason. They made a good sales pitch.