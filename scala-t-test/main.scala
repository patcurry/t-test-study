import scala.math.abs
import scala.math.pow
import scala.math.sqrt

// why not just use scala with a small scala script file?

class TTest(val x: List[Double], val y: List[Double]) {

  def mean(d:List[Double]):Double = d.reduce(_+_) / d.length
  //def mean(d:List[Double]):Double = d.foldLeft(_+_) / d.length

  def sampleStdDevDenom(d:List[Double]):Double = d.reduce(_+_) / (d.length - 1)
  //def sampleStdDevDenom(d:List[Double]):Double = d.foldLeft(_+_) / (d.length - 1)

  def squareDiffs(d:List[Double]):List[Double] = d.map(v => pow((v - mean(d)), 2))
  
  def stdDev(d:List[Double]):Double = sqrt(sampleStdDevDenom(squareDiffs(d)))

  // this is where I define the method
  def twoSampleTTest(a:List[Double], b:List[Double]):Map[String, Double] = {
    // probably all of these little functions could be broken up
    // or just put into one long thing
    val numerator = abs(mean(a) - mean(b))
    val denominator = sqrt((stdDev(a)/a.length) + (stdDev(b)/b.length))
    val dof = a.length + b.length - 2
    val tScore = numerator / denominator
    return Map("T Score" -> tScore, "dof" -> dof) 
  }
  
  // this is where i call the method and return it from the class
  def tTestResult = twoSampleTTest(x,y)
}

// I should be testing this as I go
/*
class GetDataCSV(val fileName: String) {

  def getBufferedSource(fn: String): Source = io.Source.fromFile(fileName)

  // going to cheat here, this will be specific to this particular file
  // I don't think this returns a list
  def getColumnData(val src: Source):List[Double] = {
    // get lines, then drop header line, then split by commas and trim spaces
    return src.getLines().drop(1).map(_.split(",").map(_.trim))
  }

  def turnColumnDataToList(val lst: List[Double]):List[Double] = {

  }
}
*/

// can I put all this stuff into a class?
/*
object CSVDemo extends App {
    val bufferedSource = io.Source.fromFile("./height-data.csv")

    val iter = bufferedSource.getLines()
      .drop(1)
      .map(_.split(",").map(_.trim))
    //val males = iter.map(col => col(0)) // so is this a list?
    //val females = iter.map(col => col(1))

    // so now that I have the data, how do I use the methods on it?

    
    for (col <- iter) println("male", col(0));
    for (col <- iter) println("female", col(1));
    

    //println(iter.getClass)

    bufferedSource.close
}
*/

object Main extends App {

  //def parseDouble(s: String) = try { Some(s.toDouble) } catch { case _ : Throwable => None }

  
  /*
  def sourceToIter(filename: String):Iterator[Array[String]] = {
    val bufferedSource = io.Source.fromFile(filename)
    val iter = bufferedSource.getLines.drop(1).map(_.split(",").map(_.trim))
    bufferedSource.close
    return iter
  }
  */

  def iterToDoubleList(iter:Iterator[Array[String]], i: Int):List[Double] = {
    return iter.map(col => col(i)).map(v => v.toDouble).toList
  }
  

  val bufferedSource = io.Source.fromFile("./height-data.csv")
  val iter = bufferedSource.getLines().drop(1).map(_.split(",").map(_.trim))

  //val males = iter.map(col => parseDouble(col(0))).map(v => v.getOrElse(0)).toList

  //val iter = sourceToIter("./height-data.csv")

  //val males = iter.map(col => col(0)).map(v => v.toDouble).toList
  //val females = iter.map(col => col(1)).map(v => v.toDouble).toList
  //val males = iterToDoubleList(iter, 0)
  val females = iterToDoubleList(iter, 1)

  //val females = iter.map(col => col(1)).map(v => v.toDouble).toList

  //println(iter.getClass)
  //println(females.getClass)

  //print(males)
  print(females)

  bufferedSource.close


/*
  for (m <- males) {
    println(m)
  }

  // this is empty
  for (f <- females) {
      println(f)
  } 
  */
  


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