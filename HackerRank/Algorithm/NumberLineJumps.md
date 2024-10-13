## Kangaroo Jumps Problem

### Formula for Speed
Speed = distance / time

Here, we consider that the kangaroo jumps 1 jump in 1 second.
- e.g., 1 jump in 1 sec, 2 jumps in 2 sec, 3 jumps in 3 sec.
- Assume the kangaroo jumps `j` jumps.

### Deriving the Distance Formula
Speed = distance / jumps

Distance = speed * jumps

### Distance Calculation for Two Kangaroos
For kangaroo starting at position `x1` with speed `v1`:
- Distance = (v1 * j) + x1 (as the kangaroo starts to jump from `x1`)

For kangaroo starting at position `x2` with speed `v2`:
- Distance = (v2 * j) + x2

### Setting the Equations Equal
Since we want to determine when the two kangaroos land at the same position:

(v1 * j) + x1 = (v2 * j) + x2

### Simplifying the Equation
(v1 * j) - (v2 * j) = x2 - x1

J(v1 - v2) = x2 - x1

### Finding the Value of `j`
J = (x2 - x1) / (v1 - v2)

### Condition for the Kangaroos to Land at the Same Spot
- If `j` is an integer, print `YES`.
- If `j` is not an integer, print `NO`.
