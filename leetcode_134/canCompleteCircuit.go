package main

func canCompleteCircuit(gas []int, cost []int) int {
    N := len(gas)
    if N == 0 {
        return -1
    }

    for i := 0; i < N; i++ {
        step := i
        if cost[i] > gas[i] {
            continue
        }
        distance := 0
        var g int
        for j := step; ;j = (j + 1) % N {
            g += gas[j]
            if cost[j] > g {
                break
            }
            g -= cost[j]
            distance++
            if distance == N {
                return step
            }
        }
    }
    return -1
}

func main() {

}
