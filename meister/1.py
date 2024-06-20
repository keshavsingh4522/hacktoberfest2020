from typing import Callable, List
import math
import nltk

# DO NOT MAKE UNNECESSARY CHANGES


class DistanceFuncs:

    def calc_distance(
        self, point_a: List[float], point_b: List[float], dist_func: Callable, /
    ) -> float:
        """ Calculates distance between two points using the passed dist_func """
        return dist_func(point_a, point_b)

    @staticmethod
    def euclidean(point_a: List[float], point_b: List[float], /) ->float:
        """
        Calculates Euclidean Distance between two points Example:
        >>> DistanceFuncs.euclidean([1,1],[1,1])
        0.0
        """
        return math.dist(point_a, point_b)

    @staticmethod
    def manhattan_distance(point_a: List[float], point_b: List[float], /):
        """ Compute
        the manhattan_distance between two points """
        distance = 0
        for a, b in zip(point_a, point_b):
            distance += abs(a-b)
        return distance


    @staticmethod
    def jaccard_distance(point_a, point_b):
        """Compute
        the jaccard_distance between two points """ 
        return nltk.jaccard_distance(point_a, point_b)

def main():
    """Demonstrate the usage of DistanceFuncs """
    funcs = DistanceFuncs()
    A, B = [1,1], [2,2]
    calc_distance = funcs.calc_distance(A, B, math.dist)
    print(f"calc_distance: {A}, {B} = {calc_distance}")
    print(f"euclidean: {A}, {B} = {funcs.euclidean(A, B)}")
    print(f"manhattan_distance: {A}, {B} = {funcs.manhattan_distance(A, B)}")
    A, B = set('cool'), set('hello')
    print(f"jaccard_distance: {funcs.jaccard_distance(A, B)}")
    pass

if __name__ == "__main__":
    main()
