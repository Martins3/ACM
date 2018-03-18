import javax.sound.midi.Soundbank;

/**
 * code mainly derived from https://people.eecs.berkeley.edu/~jrs/61bs02/hw/hw9/set/DisjointSets.java
 * what has been added is error checking and fix the ranking bug !
 *
 *  @author Bachelar Hu
 *  
 **/

public class DisjointSets {

  private int[] array;
  private int[] Rank;

  /**
   *  Construct a disjoint sets object.
   *
   *  @param numElements the initial number of elements--also the initial
   *  number of disjoint sets, since every element is initially in its own set.
   **/
  public DisjointSets(int numElements) {
    array = new int [numElements];
    for (int i = 0; i < array.length; i++) {
      array[i] = -1;
    }

    Rank = new int[numElements];
  }

  /**
   *  union() unites two elements, elements in the same set can also applied
   *  @param i the root of the first set.
   *  @param j the root of the other set.
   **/
  public void union(int i, int j) {
    int root1 = find(i);
    int root2 = find(j);

    if(root1 == root2) return;

    int rankI = Rank[root1];
    int rankJ = Rank[root2];


    if (rankI < rankJ) {
      array[root1] = root2;         
    } else {
      if (rankI == rankJ) {
        Rank[root1] ++;            // Both trees same height; new one is taller
      }
      array[root2] = root1;       // root1 equal or taller; make root1 new root
    }
  }

  /**
   *  find() finds the (int) name of the set containing a given element.
   *  Performs path compression along the way.
   *
   *  @param x the element sought.
   *  @return the set containing x.
   **/
  public int find(int x) {
    if (array[x] < 0) {
      return x;                         // x is the root of the tree; return it
    } else {
      // Find out who the root is; compress path by making the root x's parent.
      array[x] = find(array[x]);
      return array[x];                                       // Return the root
    }
  }

  /**
   *  main() is test code.  All the find()s on the same output line should be
   *  identical.
   **/
  public static void main(String[] args) {
    int NumElements = 128;
    DisjointSets ds = new DisjointSets(NumElements);


    System.out.println(ds.find(10));
    ds.union(10, 9);
    System.out.println(ds.find(10) + " " + ds.find(9));
  }
}