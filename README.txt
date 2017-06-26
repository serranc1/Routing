Author:
Christian Agbayani Serrano

How the routing algorithm works:
- The routing algorithm requires initial and final x and y coordinates with respect to a 2D array of 0's and 1's, 0's representing
  traversable areas and 1's representing obstructed areas.
- The routing algorithm chooses the shortest route using only horizontal and vertical movements. If there is an obstacle in the way of the
  optimal route, the routing algorithm compares the total distance added by each way around the obstacle and chooses the shorter route.
- The routing algorithm calculates the total distance required to travel as well as the directions to take at each step of the route
  calculation.
