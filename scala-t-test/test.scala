import scala.io.Source

/*
val src = Source.fromFile("./height-data.csv")
//val iter = src.getLines().map(_.split(":"))

val iter = src.getLines().drop(1).map(_.split(":"))
// print the uid for Guest
iter.find(_(0) == "Guest") foreach (a => println(a(2)))
// the rest of iter is not processed
src.close()
*/

//val bufferedSource = Source.fromFile("scala-t-test/whatever.txt")


/*
val bufferedSource = Source.fromFile("height-data.csv")
val lines = bufferedSource.getLines.toList
bufferedSource.close()
for (line <- lines) {
    println(line)
}
*/

//val iter = src.getLines().drop(1).map(_.split(":"))

object CSVDemo extends App {
    val bufferedSource = io.Source.fromFile("./height-data.csv")

    val iter = bufferedSource.getLines().drop(1).map(_.split(",").map(_.trim))
    val males = iter.map(col => col(0)) // so is this a list?
    val females = iter.map(col => col(1))

    // so now that I have the data, how do I use the methods on it?

    for (f <- females) {
        println(f)
    }

    bufferedSource.close
}