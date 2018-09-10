object Main extends App {

  // fake data
  // don't know the difference between Arrays and Lists
  // or doubles and floats... seems like precision
  val array1 = Array(1.0,2.0,3.0,4.0,5.0)
  val array2 = Array(3.0,4.0,5.0,6.0,7.0)

  // .reduce syntax is easy
  def mean(d:Array[Double]):Double = d.reduce(_+_) / d.length
  

  println("Hello, World!")
}