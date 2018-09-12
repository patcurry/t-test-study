import scala.math.abs
import scala.math.pow
import scala.math.sqrt


class TTest(val a: List[Double], val b: List[Double]) {

  def mean(d:List[Double]):Double = d.reduce(_+_) / d.length


  def sampleStdDevDenom(d:List[Double]):Double = d.reduce(_+_) / (d.length - 1)

  def squareDiffs(d:List[Double]):List[Double] = d.map(v => pow((v - mean(d)), 2))
  
  def stdDev(d:List[Double]):Double = sqrt(sampleStdDevDenom(squareDiffs(d)))

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
  

}

object Main extends App {

  // fake data
  // don't know the difference between Arrays and Lists => lists are immutable
  // or doubles and floats... seems like precision
  // test the t-test
  // the answer should be {'T Score': 2.514866859365871, 'dof': 8}

  val array1 = List(1.0,2.0,3.0,4.0,5.0)
  val array2 = List(3.0,4.0,5.0,6.0,7.0)

  val ttest = new TTest(array1, array2)

  println(ttest.a)
  println(ttest.b)
}