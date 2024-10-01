using System;
using System.Collections.Generic;
using System.Linq;

namespace HopcroftKarp
{
    static class Program
    {
        static void Main()
        {
            var lefts = new HashSet<string> { "U0", "U1", "U2", "U3", "U4" };
            var rights = new HashSet<string> { "V0", "V1", "V2", "V3", "V4" };

            var edges = new Dictionary<string, HashSet<string>>
            {
                ["U0"] = new HashSet<string> { "V0", "V1" },
                ["U1"] = new HashSet<string> { "V0", "V4" },
                ["U2"] = new HashSet<string> { "V2", "V3" },
                ["U3"] = new HashSet<string> { "V0", "V4" },
                ["U4"] = new HashSet<string> { "V1", "V3" }
            };

            var matches = HopcroftKarp(lefts, rights, edges);

            Console.WriteLine($"# of matches: {matches.Count}\n");

            foreach (var match in matches)
            {
                Console.WriteLine($"Match: {match.Key} -> {match.Value}");
            }
        }

        // BFS
        static bool HasAugmentingPath(IEnumerable<string> lefts,
                                      IReadOnlyDictionary<string, HashSet<string>> edges,
                                      IReadOnlyDictionary<string, string> toMatchedRight,
                                      IReadOnlyDictionary<string, string> toMatchedLeft,
                                      IDictionary<string, long> distances,
                                      Queue<string> q)
        {
            foreach (var left in lefts)
            {
                if (toMatchedRight[left] == "")
                {
                    distances[left] = 0;
                    q.Enqueue(left);
                }
                else
                {
                    distances[left] = long.MaxValue;
                }
            }

            distances[""] = long.MaxValue;

            while (0 < q.Count)
            {
                var left = q.Dequeue();

                if (distances[left] < distances[""])
                {
                    foreach (var right in edges[left])
                    {
                        var nextLeft = toMatchedLeft[right];
                        if (distances[nextLeft] == long.MaxValue)
                        {
                            // The nextLeft has not been visited and is being visited.
                            distances[nextLeft] = distances[left] + 1;
                            q.Enqueue(nextLeft);
                        }
                    }
                }
            }

            return distances[""] != long.MaxValue;
        }

        // DFS
        static bool TryMatching(string left,
                                IReadOnlyDictionary<string, HashSet<string>> edges,
                                IDictionary<string, string> toMatchedRight,
                                IDictionary<string, string> toMatchedLeft,
                                IDictionary<string, long> distances)
        {
            if (left == "")
            {
                return true;
            }

            foreach (var right in edges[left])
            {
                var nextLeft = toMatchedLeft[right];
                if (distances[nextLeft] == distances[left] + 1)
                {
                    if (TryMatching(nextLeft, edges, toMatchedRight, toMatchedLeft, distances))
                    {
                        toMatchedLeft[right] = left;
                        toMatchedRight[left] = right;
                        return true;
                    }
                }
            }

            // The left could not match any right.
            distances[left] = long.MaxValue;

            return false;
        }

        static Dictionary<string, string> HopcroftKarp(HashSet<string> lefts,
                                                       IEnumerable<string> rights,
                                                       IReadOnlyDictionary<string, HashSet<string>> edges)
        {
            // "distance" is from a starting left to another left when zig-zaging left, right, left, right, left in DFS.

            // Take the following for example:
            // left1 -> (unmatched edge) -> right1 -> (matched edge) -> left2 -> (unmatched edge) -> right2 -> (matched edge) -> left3
            // distance can be as follows.
            // distances[left1] = 0 (Starting left is distance 0.)
            // distances[left2] = distances[left1] + 1 = 1
            // distances[left3] = distances[left2] + 1 = 2

            // Note
            // Both a starting left and an ending left are unmatched with right.
            // Moving from left to right uses a unmatched edge.
            // Moving from right to left uses a matched edge.

            var distances = new Dictionary<string, long>();

            var q = new Queue<string>();

            // All lefts start as being unmatched with any right.
            var toMatchedRight = lefts.ToDictionary(s => s, s => "");

            // All rights start as being unmatched with any left.
            var toMatchedLeft = rights.ToDictionary(s => s, s => "");

            // Note
            // toMatchedRight and toMatchedLeft are the same thing but inverse to each other.
            // Using either of them is enough but inefficient
            // because a dictionary cannot be straightforwardly looked up bi-directionally.

            while (HasAugmentingPath(lefts, edges, toMatchedRight, toMatchedLeft, distances, q))
            {
                foreach (var unmatchedLeft in lefts.Where(left => toMatchedRight[left] == ""))
                {
                    TryMatching(unmatchedLeft, edges, toMatchedRight, toMatchedLeft, distances);
                }
            }

            // Remove unmatches
            RemoveItems(toMatchedRight, kvp => kvp.Value == "");

            // Return matches
            return toMatchedRight;
        }

        static void RemoveItems<T1, T2>(IDictionary<T1, T2> d, Func<KeyValuePair<T1, T2>, bool> isRemovable)
        {
            foreach (var kvp in d.Where(isRemovable).ToList())
            {
                d.Remove(kvp.Key);
            }
        }
    }
}
