package main

type Node struct {
	Val       int
	Neighbors []*Node
}

func bfs(node *Node, m1 map[int]bool, m2 map[int]*Node) *Node {
	if node == nil || m1[node.Val] == true {
		return node
	}

	var newNode *Node
	if tn, ok := m2[node.Val]; ok {
		newNode = tn
	} else {
		newNode = &Node{Val: node.Val}
		m1[newNode.Val] = true
		m2[newNode.Val] = newNode
	}

	l := len(node.Neighbors)
	neighbors := make([]*Node, l)

	for i := 0; i < l; i++ {
		if tn, ok := m2[node.Neighbors[i].Val]; ok {
			neighbors[i] = tn
		} else {
			neighbors[i] = bfs(node.Neighbors[i], m1, m2)
		}
	}

	newNode.Neighbors = neighbors
	return newNode
}

func cloneGraph(node *Node) *Node {
	n := bfs(node, map[int]bool{}, map[int]*Node{})
	return n
}

func main() {
    t1 := &Node{Val: 1}
    t2 := &Node{Val: 2}
    t3 := &Node{Val: 3}
    t4 := &Node{Val: 4}
    t1.Neighbors = []*Node{t2, t4}
    t2.Neighbors = []*Node{t1, t3}
    t3.Neighbors = []*Node{t2, t4}
    t4.Neighbors = []*Node{t1, t3}

    cloneGraph(t1)
}
