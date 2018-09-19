import scala.math.abs
import scala.math.pow
import scala.math.sqrt

// why not just use scala with a small scala script file?

class TTest(val x: List[Double], val y: List[Double]) {

  def mean(d:List[Double]):Double = d.reduce(_+_) / d.length

  def sampleStdDevDenom(d:List[Double]):Double = d.reduce(_+_) / (d.length - 1)

  def squareDiffs(d:List[Double]):List[Double] = d.map(v => pow((v - mean(d)), 2))
  
  def stdDev(d:List[Double]):Double = sqrt(sampleStdDevDenom(squareDiffs(d)))

  // this is where I define the method
  def twoSampleTTest(a:List[Double], b:List[Double]):Map[String, Double] = {
    // probably all of these little functions could be broken up
    val numerator = abs(mean(a) - mean(b))
    val a_denom = stdDev(a) / a.length
    val b_denom = stdDev(b) / b.length
    val denominator = sqrt(a_denom + b_denom)
    val dof = a.length + b.length - 2
    val tScore = numerator / denominator
    return Map("T Score" -> tScore, "dof" -> dof) 
  }
  
  // this is where i call the method and return it from the class
  def tTestResult = twoSampleTTest(x,y)

}

/*
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
*/

object Main extends App {

  def parseDouble(s: String) = try { Some(s.toDouble) } catch { case _ : Throwable => None }

  val bufferedSource = io.Source.fromFile("./height-data.csv")
  val iter = bufferedSource.getLines().drop(1).map(_.split(",").map(_.trim))

  //val males = iter.map(col => parseDouble(col(0))).map(v => v.getOrElse(0)).toList
  val males = iter.map(col => col(0)).map(v => v.toDouble).toList
  val females = iter.map(col => col(1)).map(v => v.toDouble).toList

  bufferedSource.close

  //println("males: ", males) // this happens before the reduceLeft error, which means that the reduce left error is happening
  //println("females: ", females) // in the math section.

  for (m <- males) {
    println(m)
  }

  // this is empty
  for (f <- females) {
      println(f)
  } 


  // the females list is empty

  //val ttest = new TTest(males, females)
  //println(ttest.tTestResult)

  // fake data
  // don't know the difference between Arrays and Lists => lists are immutable
  // or doubles and floats... seems like precision
  // test the t-test
  // the answer should be {'T Score': 2.514866859365871, 'dof': 8}

  /*
  val array1 = List(1.0,2.0,3.0,4.0,5.0)
  val array2 = List(3.0,4.0,5.0,6.0,7.0)

  val ttest = new TTest(array1, array2)
  println(ttest.tTestResult)
  */
}