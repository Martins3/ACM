import scala.collection.mutable.Stack
class MyQueue() {

    /** Initialize your data structure here. */
    private val inStack = Stack[Int]()
    private val outStack = Stack[Int]()


    /** Push element x to the back of queue. */
    def push(x: Int): Unit = {
      inStack.push(x)
    }

  private def clear(): Unit ={
    if(outStack.isEmpty){
      while(inStack.nonEmpty){
        outStack.push(inStack.pop())
      }
    }
  }
    /** Removes the element from in front of queue and returns that element. */
    def pop(): Int = {
      clear()
      outStack.pop()
    }

    /** Get the front element. */
    def peek(): Int = {
      clear()
      outStack.top
    }

    /** Returns whether the queue is empty. */
    def empty(): Boolean = {
      clear()
      outStack.isEmpty
    }
}


